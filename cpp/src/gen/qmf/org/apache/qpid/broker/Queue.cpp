
//
// Licensed to the Apache Software Foundation (ASF) under one
// or more contributor license agreements.  See the NOTICE file
// distributed with this work for additional information
// regarding copyright ownership.  The ASF licenses this file
// to you under the Apache License, Version 2.0 (the
// "License"); you may not use this file except in compliance
// with the License.  You may obtain a copy of the License at
// 
//   http://www.apache.org/licenses/LICENSE-2.0
// 
// Unless required by applicable law or agreed to in writing,
// software distributed under the License is distributed on an
// "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY
// KIND, either express or implied.  See the License for the
// specific language governing permissions and limitations
// under the License.
//

// This source file was created by a code generator.
// Please do not edit.

#include "qpid/log/Statement.h"
#include "qpid/framing/FieldTable.h"
#include "qpid/management/Manageable.h" 
#include "qpid/agent/ManagementAgent.h"
#include "Queue.h"
#include "ArgsQueuePurge.h"


using namespace qmf::org::apache::qpid::broker;
using namespace qpid::framing;
using           qpid::management::ManagementAgent;
using           qpid::management::Manageable;
using           qpid::management::ManagementObject;
using           qpid::management::Args;
using           std::string;

string  Queue::packageName  = string ("org.apache.qpid.broker");
string  Queue::className    = string ("queue");
uint8_t Queue::md5Sum[16]   =
    {0x52,0xf5,0x25,0x85,0x4e,0x4a,0xf7,0x5c,0xca,0xed,0xe1,0x20,0x27,0x5c,0x6e,0xa3};

Queue::Queue (ManagementAgent* _agent, Manageable* _core, ::qpid::management::Manageable* _parent, const std::string& _name, uint8_t _durable, uint8_t _autoDelete, uint8_t _exclusive) :
    ManagementObject(_agent, _core),name(_name),durable(_durable),autoDelete(_autoDelete),exclusive(_exclusive)
{
    vhostRef = _parent->GetManagementObject ()->getObjectId ();
    arguments = ::qpid::framing::FieldTable();
    consumerCount = 0;
    consumerCountHigh = 0;
    consumerCountLow  = 0;
    bindingCount = 0;
    bindingCountHigh = 0;
    bindingCountLow  = 0;
    unackedMessages = 0;
    unackedMessagesHigh = 0;
    unackedMessagesLow  = 0;



    maxThreads = agent->getMaxThreads();
    perThreadStatsArray = new struct PerThreadStats*[maxThreads];
    for (int idx = 0; idx < maxThreads; idx++)
        perThreadStatsArray[idx] = 0;

}

Queue::~Queue ()
{

    for (int idx = 0; idx < maxThreads; idx++)
        if (perThreadStatsArray[idx] != 0)
            delete perThreadStatsArray[idx];
    delete[] perThreadStatsArray;

}

namespace {
    const string NAME("name");
    const string TYPE("type");
    const string ACCESS("access");
    const string IS_INDEX("index");
    const string IS_OPTIONAL("optional");
    const string UNIT("unit");
    const string MIN("min");
    const string MAX("max");
    const string MAXLEN("maxlen");
    const string DESC("desc");
    const string ARGCOUNT("argCount");
    const string ARGS("args");
    const string DIR("dir");
    const string DEFAULT("default");
}

void Queue::registerSelf(ManagementAgent* agent)
{
    agent->registerClass(packageName, className, md5Sum, writeSchema);
}

void Queue::writeSchema (Buffer& buf)
{
    FieldTable ft;

    // Schema class header:
    buf.putOctet       (CLASS_KIND_TABLE);
    buf.putShortString (packageName); // Package Name
    buf.putShortString (className);   // Class Name
    buf.putBin128      (md5Sum);      // Schema Hash
    buf.putShort       (6); // Config Element Count
    buf.putShort       (27); // Inst Element Count
    buf.putShort       (1); // Method Count

    // Properties
    ft.clear();
    ft.setString (NAME, "vhostRef");
    ft.setInt    (TYPE, TYPE_REF);
    ft.setInt    (ACCESS, ACCESS_RC);
    ft.setInt    (IS_INDEX, 1);
    ft.setInt    (IS_OPTIONAL, 0);
    buf.put (ft);

    ft.clear();
    ft.setString (NAME, "name");
    ft.setInt    (TYPE, TYPE_SSTR);
    ft.setInt    (ACCESS, ACCESS_RC);
    ft.setInt    (IS_INDEX, 1);
    ft.setInt    (IS_OPTIONAL, 0);
    buf.put (ft);

    ft.clear();
    ft.setString (NAME, "durable");
    ft.setInt    (TYPE, TYPE_BOOL);
    ft.setInt    (ACCESS, ACCESS_RC);
    ft.setInt    (IS_INDEX, 0);
    ft.setInt    (IS_OPTIONAL, 0);
    buf.put (ft);

    ft.clear();
    ft.setString (NAME, "autoDelete");
    ft.setInt    (TYPE, TYPE_BOOL);
    ft.setInt    (ACCESS, ACCESS_RC);
    ft.setInt    (IS_INDEX, 0);
    ft.setInt    (IS_OPTIONAL, 0);
    buf.put (ft);

    ft.clear();
    ft.setString (NAME, "exclusive");
    ft.setInt    (TYPE, TYPE_BOOL);
    ft.setInt    (ACCESS, ACCESS_RC);
    ft.setInt    (IS_INDEX, 0);
    ft.setInt    (IS_OPTIONAL, 0);
    buf.put (ft);

    ft.clear();
    ft.setString (NAME, "arguments");
    ft.setInt    (TYPE, TYPE_FTABLE);
    ft.setInt    (ACCESS, ACCESS_RO);
    ft.setInt    (IS_INDEX, 0);
    ft.setInt    (IS_OPTIONAL, 0);
    ft.setString (DESC,   "Arguments supplied in queue.declare");
    buf.put (ft);


    // Statistics
    ft.clear();
    ft.setString (NAME,   "msgTotalEnqueues");
    ft.setInt    (TYPE,   TYPE_U64);
    ft.setString (UNIT,   "message");
    ft.setString (DESC,   "Total messages enqueued");
    buf.put (ft);

    ft.clear();
    ft.setString (NAME,   "msgTotalDequeues");
    ft.setInt    (TYPE,   TYPE_U64);
    ft.setString (UNIT,   "message");
    ft.setString (DESC,   "Total messages dequeued");
    buf.put (ft);

    ft.clear();
    ft.setString (NAME,   "msgTxnEnqueues");
    ft.setInt    (TYPE,   TYPE_U64);
    ft.setString (UNIT,   "message");
    ft.setString (DESC,   "Transactional messages enqueued");
    buf.put (ft);

    ft.clear();
    ft.setString (NAME,   "msgTxnDequeues");
    ft.setInt    (TYPE,   TYPE_U64);
    ft.setString (UNIT,   "message");
    ft.setString (DESC,   "Transactional messages dequeued");
    buf.put (ft);

    ft.clear();
    ft.setString (NAME,   "msgPersistEnqueues");
    ft.setInt    (TYPE,   TYPE_U64);
    ft.setString (UNIT,   "message");
    ft.setString (DESC,   "Persistent messages enqueued");
    buf.put (ft);

    ft.clear();
    ft.setString (NAME,   "msgPersistDequeues");
    ft.setInt    (TYPE,   TYPE_U64);
    ft.setString (UNIT,   "message");
    ft.setString (DESC,   "Persistent messages dequeued");
    buf.put (ft);

    ft.clear();
    ft.setString (NAME,   "msgDepth");
    ft.setInt    (TYPE,   TYPE_U32);
    ft.setString (UNIT,   "message");
    ft.setString (DESC,   "Current size of queue in messages");
    buf.put (ft);

    ft.clear();
    ft.setString (NAME,   "byteDepth");
    ft.setInt    (TYPE,   TYPE_U32);
    ft.setString (UNIT,   "octet");
    ft.setString (DESC,   "Current size of queue in bytes");
    buf.put (ft);

    ft.clear();
    ft.setString (NAME,   "byteTotalEnqueues");
    ft.setInt    (TYPE,   TYPE_U64);
    ft.setString (UNIT,   "octet");
    ft.setString (DESC,   "Total messages enqueued");
    buf.put (ft);

    ft.clear();
    ft.setString (NAME,   "byteTotalDequeues");
    ft.setInt    (TYPE,   TYPE_U64);
    ft.setString (UNIT,   "octet");
    ft.setString (DESC,   "Total messages dequeued");
    buf.put (ft);

    ft.clear();
    ft.setString (NAME,   "byteTxnEnqueues");
    ft.setInt    (TYPE,   TYPE_U64);
    ft.setString (UNIT,   "octet");
    ft.setString (DESC,   "Transactional messages enqueued");
    buf.put (ft);

    ft.clear();
    ft.setString (NAME,   "byteTxnDequeues");
    ft.setInt    (TYPE,   TYPE_U64);
    ft.setString (UNIT,   "octet");
    ft.setString (DESC,   "Transactional messages dequeued");
    buf.put (ft);

    ft.clear();
    ft.setString (NAME,   "bytePersistEnqueues");
    ft.setInt    (TYPE,   TYPE_U64);
    ft.setString (UNIT,   "octet");
    ft.setString (DESC,   "Persistent messages enqueued");
    buf.put (ft);

    ft.clear();
    ft.setString (NAME,   "bytePersistDequeues");
    ft.setInt    (TYPE,   TYPE_U64);
    ft.setString (UNIT,   "octet");
    ft.setString (DESC,   "Persistent messages dequeued");
    buf.put (ft);

    ft.clear();
    ft.setString (NAME,   "consumerCount");
    ft.setInt    (TYPE,   TYPE_U32);
    ft.setString (UNIT,   "consumer");
    ft.setString (DESC,   "Current consumers on queue");
    buf.put (ft);

    ft.clear();
    ft.setString (NAME,   "consumerCountHigh");
    ft.setInt    (TYPE,   TYPE_U32);
    ft.setString (UNIT,   "consumer");
    ft.setString (DESC,   "Current consumers on queue (High)");
    buf.put (ft);

    ft.clear();
    ft.setString (NAME,   "consumerCountLow");
    ft.setInt    (TYPE,   TYPE_U32);
    ft.setString (UNIT,   "consumer");
    ft.setString (DESC,   "Current consumers on queue (Low)");
    buf.put (ft);

    ft.clear();
    ft.setString (NAME,   "bindingCount");
    ft.setInt    (TYPE,   TYPE_U32);
    ft.setString (UNIT,   "binding");
    ft.setString (DESC,   "Current bindings");
    buf.put (ft);

    ft.clear();
    ft.setString (NAME,   "bindingCountHigh");
    ft.setInt    (TYPE,   TYPE_U32);
    ft.setString (UNIT,   "binding");
    ft.setString (DESC,   "Current bindings (High)");
    buf.put (ft);

    ft.clear();
    ft.setString (NAME,   "bindingCountLow");
    ft.setInt    (TYPE,   TYPE_U32);
    ft.setString (UNIT,   "binding");
    ft.setString (DESC,   "Current bindings (Low)");
    buf.put (ft);

    ft.clear();
    ft.setString (NAME,   "unackedMessages");
    ft.setInt    (TYPE,   TYPE_U32);
    ft.setString (UNIT,   "message");
    ft.setString (DESC,   "Messages consumed but not yet acked");
    buf.put (ft);

    ft.clear();
    ft.setString (NAME,   "unackedMessagesHigh");
    ft.setInt    (TYPE,   TYPE_U32);
    ft.setString (UNIT,   "message");
    ft.setString (DESC,   "Messages consumed but not yet acked (High)");
    buf.put (ft);

    ft.clear();
    ft.setString (NAME,   "unackedMessagesLow");
    ft.setInt    (TYPE,   TYPE_U32);
    ft.setString (UNIT,   "message");
    ft.setString (DESC,   "Messages consumed but not yet acked (Low)");
    buf.put (ft);

    ft.clear();
    ft.setString (NAME,   "messageLatencySamples");
    ft.setInt    (TYPE,   TYPE_DELTATIME);
    ft.setString (UNIT,   "nanosecond");
    ft.setString (DESC,   "Broker latency through this queue (Samples)");
    buf.put (ft);

    ft.clear();
    ft.setString (NAME,   "messageLatencyMin");
    ft.setInt    (TYPE,   TYPE_DELTATIME);
    ft.setString (UNIT,   "nanosecond");
    ft.setString (DESC,   "Broker latency through this queue (Min)");
    buf.put (ft);

    ft.clear();
    ft.setString (NAME,   "messageLatencyMax");
    ft.setInt    (TYPE,   TYPE_DELTATIME);
    ft.setString (UNIT,   "nanosecond");
    ft.setString (DESC,   "Broker latency through this queue (Max)");
    buf.put (ft);

    ft.clear();
    ft.setString (NAME,   "messageLatencyAverage");
    ft.setInt    (TYPE,   TYPE_DELTATIME);
    ft.setString (UNIT,   "nanosecond");
    ft.setString (DESC,   "Broker latency through this queue (Average)");
    buf.put (ft);


    // Methods
    ft.clear();
    ft.setString (NAME,     "purge");
    ft.setInt    (ARGCOUNT, 1);
    ft.setString (DESC,     "Discard all or some messages on a queue");
    buf.put (ft);

    ft.clear();
    ft.setString (NAME,    "request");
    ft.setInt    (TYPE,    TYPE_U32);
    ft.setString (DIR,     "I");
    ft.setString (DESC,    "0 for all messages or n>0 for n messages");
    buf.put (ft);


}


void Queue::aggregatePerThreadStats(struct PerThreadStats* totals)
{
    totals->msgTotalEnqueues = 0;
    totals->msgTotalDequeues = 0;
    totals->msgTxnEnqueues = 0;
    totals->msgTxnDequeues = 0;
    totals->msgPersistEnqueues = 0;
    totals->msgPersistDequeues = 0;
    totals->msgDepth = 0;
    totals->byteDepth = 0;
    totals->byteTotalEnqueues = 0;
    totals->byteTotalDequeues = 0;
    totals->byteTxnEnqueues = 0;
    totals->byteTxnDequeues = 0;
    totals->bytePersistEnqueues = 0;
    totals->bytePersistDequeues = 0;
    totals->messageLatencyCount = 0;
    totals->messageLatencyMin   = std::numeric_limits<uint64_t>::max();
    totals->messageLatencyMax   = std::numeric_limits<uint64_t>::min();
    totals->messageLatencyTotal = 0;

    for (int idx = 0; idx < maxThreads; idx++) {
        struct PerThreadStats* threadStats = perThreadStatsArray[idx];
        if (threadStats != 0) {
            totals->msgTotalEnqueues += threadStats->msgTotalEnqueues;
            totals->msgTotalDequeues += threadStats->msgTotalDequeues;
            totals->msgTxnEnqueues += threadStats->msgTxnEnqueues;
            totals->msgTxnDequeues += threadStats->msgTxnDequeues;
            totals->msgPersistEnqueues += threadStats->msgPersistEnqueues;
            totals->msgPersistDequeues += threadStats->msgPersistDequeues;
            totals->msgDepth += threadStats->msgDepth;
            totals->byteDepth += threadStats->byteDepth;
            totals->byteTotalEnqueues += threadStats->byteTotalEnqueues;
            totals->byteTotalDequeues += threadStats->byteTotalDequeues;
            totals->byteTxnEnqueues += threadStats->byteTxnEnqueues;
            totals->byteTxnDequeues += threadStats->byteTxnDequeues;
            totals->bytePersistEnqueues += threadStats->bytePersistEnqueues;
            totals->bytePersistDequeues += threadStats->bytePersistDequeues;
            totals->messageLatencyCount += threadStats->messageLatencyCount;
            if (totals->messageLatencyMin > threadStats->messageLatencyMin)
                totals->messageLatencyMin = threadStats->messageLatencyMin;
            if (totals->messageLatencyMax < threadStats->messageLatencyMax)
                totals->messageLatencyMax = threadStats->messageLatencyMax;
            totals->messageLatencyTotal += threadStats->messageLatencyTotal;

        }
    }
}


void Queue::writeProperties (Buffer& buf)
{
    ::qpid::sys::Mutex::ScopedLock mutex(accessLock);
    configChanged = false;

    writeTimestamps (buf);

    vhostRef.encode(buf);
    buf.putShortString(name);
    buf.putOctet(durable?1:0);
    buf.putOctet(autoDelete?1:0);
    buf.putOctet(exclusive?1:0);
    arguments.encode(buf);

}

void Queue::writeStatistics (Buffer& buf, bool skipHeaders)
{
    ::qpid::sys::Mutex::ScopedLock mutex(accessLock);
    instChanged = false;

    for (int idx = 0; idx < maxThreads; idx++) {
        struct PerThreadStats* threadStats = perThreadStatsArray[idx];
        if (threadStats != 0) {
        threadStats->msgDepth = (uint32_t) (threadStats->msgTotalEnqueues - threadStats->msgTotalDequeues);
        threadStats->byteDepth = (uint32_t) (threadStats->byteTotalEnqueues - threadStats->byteTotalDequeues);

        }
    }


    struct PerThreadStats totals;
    aggregatePerThreadStats(&totals);


    if (!skipHeaders)
        writeTimestamps (buf);
    buf.putLongLong(totals.msgTotalEnqueues);
    buf.putLongLong(totals.msgTotalDequeues);
    buf.putLongLong(totals.msgTxnEnqueues);
    buf.putLongLong(totals.msgTxnDequeues);
    buf.putLongLong(totals.msgPersistEnqueues);
    buf.putLongLong(totals.msgPersistDequeues);
    buf.putLong(totals.msgDepth);
    buf.putLong(totals.byteDepth);
    buf.putLongLong(totals.byteTotalEnqueues);
    buf.putLongLong(totals.byteTotalDequeues);
    buf.putLongLong(totals.byteTxnEnqueues);
    buf.putLongLong(totals.byteTxnDequeues);
    buf.putLongLong(totals.bytePersistEnqueues);
    buf.putLongLong(totals.bytePersistDequeues);
    buf.putLong(consumerCount);
    buf.putLong(consumerCountHigh);
    buf.putLong(consumerCountLow);
    buf.putLong(bindingCount);
    buf.putLong(bindingCountHigh);
    buf.putLong(bindingCountLow);
    buf.putLong(unackedMessages);
    buf.putLong(unackedMessagesHigh);
    buf.putLong(unackedMessagesLow);
    buf.putLongLong(totals.messageLatencyCount);
    buf.putLongLong(totals.messageLatencyCount ? totals.messageLatencyMin : 0);
    buf.putLongLong(totals.messageLatencyMax);
    buf.putLongLong(totals.messageLatencyCount ? totals.messageLatencyTotal / totals.messageLatencyCount : 0);


    // Maintenance of hi-lo statistics
    consumerCountHigh = consumerCount;
    consumerCountLow  = consumerCount;
    bindingCountHigh = bindingCount;
    bindingCountLow  = bindingCount;
    unackedMessagesHigh = unackedMessages;
    unackedMessagesLow  = unackedMessages;


    for (int idx = 0; idx < maxThreads; idx++) {
        struct PerThreadStats* threadStats = perThreadStatsArray[idx];
        if (threadStats != 0) {
        threadStats->messageLatencyCount = 0;
        threadStats->messageLatencyTotal = 0;
        threadStats->messageLatencyMin   = std::numeric_limits<uint64_t>::max();
        threadStats->messageLatencyMax   = std::numeric_limits<uint64_t>::min();

        }
    }

}

void Queue::doMethod (string& methodName, Buffer& inBuf, Buffer& outBuf)
{
    Manageable::status_t status = Manageable::STATUS_UNKNOWN_METHOD;
    std::string          text;


    if (methodName == "purge") {
        ArgsQueuePurge ioArgs;
        ioArgs.i_request = inBuf.getLong();
        status = coreObject->ManagementMethod (METHOD_PURGE, ioArgs, text);
        outBuf.putLong        (status);
        outBuf.putMediumString(::qpid::management::Manageable::StatusText (status, text));
        return;
    }

    outBuf.putLong(status);
    outBuf.putShortString(Manageable::StatusText(status, text));
}
