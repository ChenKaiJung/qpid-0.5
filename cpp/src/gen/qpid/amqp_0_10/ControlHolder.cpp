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


#include "ControlHolder.h"
#include "exceptions.h"

namespace qpid {
namespace amqp_0_10 {

using framing::in_place;

void ControlHolder::set(uint8_t classCode, uint8_t code) {
    uint16_t key=(classCode<<8)+code;
    switch(key) {
        case 0x101: *this=in_place<connection::Start>(); break;
        case 0x102: *this=in_place<connection::StartOk>(); break;
        case 0x103: *this=in_place<connection::Secure>(); break;
        case 0x104: *this=in_place<connection::SecureOk>(); break;
        case 0x105: *this=in_place<connection::Tune>(); break;
        case 0x106: *this=in_place<connection::TuneOk>(); break;
        case 0x107: *this=in_place<connection::Open>(); break;
        case 0x108: *this=in_place<connection::OpenOk>(); break;
        case 0x109: *this=in_place<connection::Redirect>(); break;
        case 0x10a: *this=in_place<connection::Heartbeat>(); break;
        case 0x10b: *this=in_place<connection::Close>(); break;
        case 0x10c: *this=in_place<connection::CloseOk>(); break;
        case 0x201: *this=in_place<session::Attach>(); break;
        case 0x202: *this=in_place<session::Attached>(); break;
        case 0x203: *this=in_place<session::Detach>(); break;
        case 0x204: *this=in_place<session::Detached>(); break;
        case 0x205: *this=in_place<session::RequestTimeout>(); break;
        case 0x206: *this=in_place<session::Timeout>(); break;
        case 0x207: *this=in_place<session::CommandPoint>(); break;
        case 0x208: *this=in_place<session::Expected>(); break;
        case 0x209: *this=in_place<session::Confirmed>(); break;
        case 0x20a: *this=in_place<session::Completed>(); break;
        case 0x20b: *this=in_place<session::KnownCompleted>(); break;
        case 0x20c: *this=in_place<session::Flush>(); break;
        case 0x20d: *this=in_place<session::Gap>(); break;
        case 0x8001: *this=in_place<cluster::UpdateRequest>(); break;
        case 0x8002: *this=in_place<cluster::UpdateOffer>(); break;
        case 0x8010: *this=in_place<cluster::Ready>(); break;
        case 0x8011: *this=in_place<cluster::ConfigChange>(); break;
        case 0x8012: *this=in_place<cluster::MessageExpired>(); break;
        case 0x8020: *this=in_place<cluster::Shutdown>(); break;
        case 0x8102: *this=in_place<cluster-connection::DeliverClose>(); break;
        case 0x8103: *this=in_place<cluster-connection::DeliverDoOutput>(); break;
        case 0x8110: *this=in_place<cluster-connection::ConsumerState>(); break;
        case 0x8111: *this=in_place<cluster-connection::DeliveryRecord>(); break;
        case 0x8112: *this=in_place<cluster-connection::TxStart>(); break;
        case 0x8113: *this=in_place<cluster-connection::TxAccept>(); break;
        case 0x8114: *this=in_place<cluster-connection::TxDequeue>(); break;
        case 0x8115: *this=in_place<cluster-connection::TxEnqueue>(); break;
        case 0x8116: *this=in_place<cluster-connection::TxPublish>(); break;
        case 0x8117: *this=in_place<cluster-connection::TxEnd>(); break;
        case 0x8118: *this=in_place<cluster-connection::AccumulatedAck>(); break;
        case 0x811f: *this=in_place<cluster-connection::SessionState>(); break;
        case 0x8120: *this=in_place<cluster-connection::ShadowReady>(); break;
        case 0x8121: *this=in_place<cluster-connection::Membership>(); break;
        case 0x8130: *this=in_place<cluster-connection::QueuePosition>(); break;
        case 0x8131: *this=in_place<cluster-connection::Exchange>(); break;
        case 0x8132: *this=in_place<cluster-connection::Queue>(); break;
        case 0x8133: *this=in_place<cluster-connection::ExpiryId>(); break;
        default: 
            throw CommandInvalidException(QPID_MSG("Invalid class-control key " << std::hex << key));
    }
}

std::ostream& operator<<(std::ostream& o, const ControlHolder& h) { return h.get() ? (o << *h.get()) : (o << "<empty ControlHolder>"); }

}} // namespace qpid::amqp_0_10

