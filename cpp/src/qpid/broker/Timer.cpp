/*
 *
 * Licensed to the Apache Software Foundation (ASF) under one
 * or more contributor license agreements.  See the NOTICE file
 * distributed with this work for additional information
 * regarding copyright ownership.  The ASF licenses this file
 * to you under the Apache License, Version 2.0 (the
 * "License"); you may not use this file except in compliance
 * with the License.  You may obtain a copy of the License at
 * 
 *   http://www.apache.org/licenses/LICENSE-2.0
 * 
 * Unless required by applicable law or agreed to in writing,
 * software distributed under the License is distributed on an
 * "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY
 * KIND, either express or implied.  See the License for the
 * specific language governing permissions and limitations
 * under the License.
 *
 */
#include "Timer.h"
#include <iostream>

using boost::intrusive_ptr;
using qpid::sys::AbsTime;
using qpid::sys::Duration;
using qpid::sys::Monitor;
using qpid::sys::Thread;
using qpid::sys::Mutex;
using qpid::sys::ScopedLock;
using namespace qpid::broker;

TimerTask::TimerTask(Duration timeout) :
    duration(timeout), time(AbsTime::now(), timeout), cancelled(false) {}

TimerTask::TimerTask(AbsTime _time) :
    duration(0), time(_time), cancelled(false) {}

TimerTask::~TimerTask(){}

void TimerTask::reset() { time = AbsTime(AbsTime::now(), duration); }

void TimerTask::cancel() {
    cancelled = true;
}

void TimerTask::cancelBlock() {
    ScopedLock<Mutex> l(cancelLock);
    cancelled = true;
}

bool TimerTask::isCancelled() const { return cancelled; }

Timer::Timer() : active(false) 
{
    start();
}

Timer::~Timer() 
{
    stop();
}

void Timer::run()
{
    Monitor::ScopedLock l(monitor);
    while(active){
        if (tasks.empty()) {
            monitor.wait();
        } else {
            intrusive_ptr<TimerTask> t = tasks.top();
            tasks.pop();
            {
            ScopedLock<Mutex> l(t->cancelLock);
            if (t->isCancelled()) {
              continue;
            } else if(t->time < AbsTime::now()) {
                Monitor::ScopedUnlock u(monitor);
                t->fire();
                continue;
            } else {
                // If the timer was adjusted into the future it might no longer
                // be the next event, so push and then get top to make sure
                tasks.push(t);
            }
            }
            monitor.wait(tasks.top()->time);
        }
    }
}

void Timer::add(intrusive_ptr<TimerTask> task)
{
    Monitor::ScopedLock l(monitor);
    tasks.push(task);
    monitor.notify();
}

void Timer::start()
{
    Monitor::ScopedLock l(monitor);
    if (!active) {
        active = true;
        runner = Thread(this);
    }
}

void Timer::stop()
{
    {
        Monitor::ScopedLock l(monitor);
        if (!active) return;
        active = false;
        monitor.notifyAll();
    }
    runner.join();
}

bool Later::operator()(const intrusive_ptr<TimerTask>& a,
                       const intrusive_ptr<TimerTask>& b) const
{
    return a.get() && b.get() && a->time > b->time;
}

