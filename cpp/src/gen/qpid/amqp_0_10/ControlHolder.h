#ifndef QPID_AMQP_0_10_CONTROLHOLDER_H
#define QPID_AMQP_0_10_CONTROLHOLDER_H
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

///
/// This file was automatically generated from the AMQP specification.
/// Do not edit.
///


#include "qpid/amqp_0_10/ApplyControl.h"
#include "qpid/amqp_0_10/Holder.h"
#include "qpid/amqp_0_10/specification.h"

namespace qpid {
namespace amqp_0_10 {


namespace control_max {

static const size_t MAX000=0;
static const size_t MAX001 = sizeof(connection::Start) > MAX000 ? sizeof(connection::Start) : MAX000;
static const size_t MAX002 = sizeof(connection::StartOk) > MAX001 ? sizeof(connection::StartOk) : MAX001;
static const size_t MAX003 = sizeof(connection::Secure) > MAX002 ? sizeof(connection::Secure) : MAX002;
static const size_t MAX004 = sizeof(connection::SecureOk) > MAX003 ? sizeof(connection::SecureOk) : MAX003;
static const size_t MAX005 = sizeof(connection::Tune) > MAX004 ? sizeof(connection::Tune) : MAX004;
static const size_t MAX006 = sizeof(connection::TuneOk) > MAX005 ? sizeof(connection::TuneOk) : MAX005;
static const size_t MAX007 = sizeof(connection::Open) > MAX006 ? sizeof(connection::Open) : MAX006;
static const size_t MAX008 = sizeof(connection::OpenOk) > MAX007 ? sizeof(connection::OpenOk) : MAX007;
static const size_t MAX009 = sizeof(connection::Redirect) > MAX008 ? sizeof(connection::Redirect) : MAX008;
static const size_t MAX010 = sizeof(connection::Heartbeat) > MAX009 ? sizeof(connection::Heartbeat) : MAX009;
static const size_t MAX011 = sizeof(connection::Close) > MAX010 ? sizeof(connection::Close) : MAX010;
static const size_t MAX012 = sizeof(connection::CloseOk) > MAX011 ? sizeof(connection::CloseOk) : MAX011;
static const size_t MAX013 = sizeof(session::Attach) > MAX012 ? sizeof(session::Attach) : MAX012;
static const size_t MAX014 = sizeof(session::Attached) > MAX013 ? sizeof(session::Attached) : MAX013;
static const size_t MAX015 = sizeof(session::Detach) > MAX014 ? sizeof(session::Detach) : MAX014;
static const size_t MAX016 = sizeof(session::Detached) > MAX015 ? sizeof(session::Detached) : MAX015;
static const size_t MAX017 = sizeof(session::RequestTimeout) > MAX016 ? sizeof(session::RequestTimeout) : MAX016;
static const size_t MAX018 = sizeof(session::Timeout) > MAX017 ? sizeof(session::Timeout) : MAX017;
static const size_t MAX019 = sizeof(session::CommandPoint) > MAX018 ? sizeof(session::CommandPoint) : MAX018;
static const size_t MAX020 = sizeof(session::Expected) > MAX019 ? sizeof(session::Expected) : MAX019;
static const size_t MAX021 = sizeof(session::Confirmed) > MAX020 ? sizeof(session::Confirmed) : MAX020;
static const size_t MAX022 = sizeof(session::Completed) > MAX021 ? sizeof(session::Completed) : MAX021;
static const size_t MAX023 = sizeof(session::KnownCompleted) > MAX022 ? sizeof(session::KnownCompleted) : MAX022;
static const size_t MAX024 = sizeof(session::Flush) > MAX023 ? sizeof(session::Flush) : MAX023;
static const size_t MAX025 = sizeof(session::Gap) > MAX024 ? sizeof(session::Gap) : MAX024;
static const size_t MAX026 = sizeof(cluster::UpdateRequest) > MAX025 ? sizeof(cluster::UpdateRequest) : MAX025;
static const size_t MAX027 = sizeof(cluster::UpdateOffer) > MAX026 ? sizeof(cluster::UpdateOffer) : MAX026;
static const size_t MAX028 = sizeof(cluster::RetractOffer) > MAX027 ? sizeof(cluster::RetractOffer) : MAX027;
static const size_t MAX029 = sizeof(cluster::Ready) > MAX028 ? sizeof(cluster::Ready) : MAX028;
static const size_t MAX030 = sizeof(cluster::ConfigChange) > MAX029 ? sizeof(cluster::ConfigChange) : MAX029;
static const size_t MAX031 = sizeof(cluster::MessageExpired) > MAX030 ? sizeof(cluster::MessageExpired) : MAX030;
static const size_t MAX032 = sizeof(cluster::ErrorCheck) > MAX031 ? sizeof(cluster::ErrorCheck) : MAX031;
static const size_t MAX033 = sizeof(cluster::Shutdown) > MAX032 ? sizeof(cluster::Shutdown) : MAX032;
static const size_t MAX034 = sizeof(cluster-connection::Announce) > MAX033 ? sizeof(cluster-connection::Announce) : MAX033;
static const size_t MAX035 = sizeof(cluster-connection::DeliverClose) > MAX034 ? sizeof(cluster-connection::DeliverClose) : MAX034;
static const size_t MAX036 = sizeof(cluster-connection::DeliverDoOutput) > MAX035 ? sizeof(cluster-connection::DeliverDoOutput) : MAX035;
static const size_t MAX037 = sizeof(cluster-connection::Abort) > MAX036 ? sizeof(cluster-connection::Abort) : MAX036;
static const size_t MAX038 = sizeof(cluster-connection::ConsumerState) > MAX037 ? sizeof(cluster-connection::ConsumerState) : MAX037;
static const size_t MAX039 = sizeof(cluster-connection::DeliveryRecord) > MAX038 ? sizeof(cluster-connection::DeliveryRecord) : MAX038;
static const size_t MAX040 = sizeof(cluster-connection::TxStart) > MAX039 ? sizeof(cluster-connection::TxStart) : MAX039;
static const size_t MAX041 = sizeof(cluster-connection::TxAccept) > MAX040 ? sizeof(cluster-connection::TxAccept) : MAX040;
static const size_t MAX042 = sizeof(cluster-connection::TxDequeue) > MAX041 ? sizeof(cluster-connection::TxDequeue) : MAX041;
static const size_t MAX043 = sizeof(cluster-connection::TxEnqueue) > MAX042 ? sizeof(cluster-connection::TxEnqueue) : MAX042;
static const size_t MAX044 = sizeof(cluster-connection::TxPublish) > MAX043 ? sizeof(cluster-connection::TxPublish) : MAX043;
static const size_t MAX045 = sizeof(cluster-connection::TxEnd) > MAX044 ? sizeof(cluster-connection::TxEnd) : MAX044;
static const size_t MAX046 = sizeof(cluster-connection::AccumulatedAck) > MAX045 ? sizeof(cluster-connection::AccumulatedAck) : MAX045;
static const size_t MAX047 = sizeof(cluster-connection::SessionState) > MAX046 ? sizeof(cluster-connection::SessionState) : MAX046;
static const size_t MAX048 = sizeof(cluster-connection::ShadowReady) > MAX047 ? sizeof(cluster-connection::ShadowReady) : MAX047;
static const size_t MAX049 = sizeof(cluster-connection::Membership) > MAX048 ? sizeof(cluster-connection::Membership) : MAX048;
static const size_t MAX050 = sizeof(cluster-connection::RetractOffer) > MAX049 ? sizeof(cluster-connection::RetractOffer) : MAX049;
static const size_t MAX051 = sizeof(cluster-connection::QueuePosition) > MAX050 ? sizeof(cluster-connection::QueuePosition) : MAX050;
static const size_t MAX052 = sizeof(cluster-connection::Exchange) > MAX051 ? sizeof(cluster-connection::Exchange) : MAX051;
static const size_t MAX053 = sizeof(cluster-connection::Queue) > MAX052 ? sizeof(cluster-connection::Queue) : MAX052;
static const size_t MAX054 = sizeof(cluster-connection::ExpiryId) > MAX053 ? sizeof(cluster-connection::ExpiryId) : MAX053;
static const size_t MAX055 = sizeof(cluster-connection::AddQueueListener) > MAX054 ? sizeof(cluster-connection::AddQueueListener) : MAX054;
static const int MAX=MAX055;

} // namespace control_max

struct ControlHolder:
    public amqp_0_10::Holder<ControlHolder, Control, control_max::MAX>
{
    ControlHolder() {}
    template <class T> explicit ControlHolder(const T& t) : amqp_0_10::Holder<ControlHolder, Control, control_max::MAX>(t) {}
    using amqp_0_10::Holder<ControlHolder, Control, control_max::MAX>::operator=;
    void set(uint8_t classCode, uint8_t code);
};

std::ostream& operator<<(std::ostream& o, const ControlHolder& h);

}} // namespace qpid::amqp_0_10

#endif  /*!QPID_AMQP_0_10_CONTROLHOLDER_H*/
