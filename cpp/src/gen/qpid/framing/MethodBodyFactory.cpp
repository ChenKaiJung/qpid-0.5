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


#include "qpid/framing/MethodBodyFactory.h"
#include "qpid/framing/BodyFactory.h"
#include "qpid/framing/ConnectionStartBody.h"
#include "qpid/framing/ConnectionStartOkBody.h"
#include "qpid/framing/ConnectionSecureBody.h"
#include "qpid/framing/ConnectionSecureOkBody.h"
#include "qpid/framing/ConnectionTuneBody.h"
#include "qpid/framing/ConnectionTuneOkBody.h"
#include "qpid/framing/ConnectionOpenBody.h"
#include "qpid/framing/ConnectionOpenOkBody.h"
#include "qpid/framing/ConnectionRedirectBody.h"
#include "qpid/framing/ConnectionHeartbeatBody.h"
#include "qpid/framing/ConnectionCloseBody.h"
#include "qpid/framing/ConnectionCloseOkBody.h"
#include "qpid/framing/SessionAttachBody.h"
#include "qpid/framing/SessionAttachedBody.h"
#include "qpid/framing/SessionDetachBody.h"
#include "qpid/framing/SessionDetachedBody.h"
#include "qpid/framing/SessionRequestTimeoutBody.h"
#include "qpid/framing/SessionTimeoutBody.h"
#include "qpid/framing/SessionCommandPointBody.h"
#include "qpid/framing/SessionExpectedBody.h"
#include "qpid/framing/SessionConfirmedBody.h"
#include "qpid/framing/SessionCompletedBody.h"
#include "qpid/framing/SessionKnownCompletedBody.h"
#include "qpid/framing/SessionFlushBody.h"
#include "qpid/framing/SessionGapBody.h"
#include "qpid/framing/ExecutionSyncBody.h"
#include "qpid/framing/ExecutionResultBody.h"
#include "qpid/framing/ExecutionExceptionBody.h"
#include "qpid/framing/MessageTransferBody.h"
#include "qpid/framing/MessageAcceptBody.h"
#include "qpid/framing/MessageRejectBody.h"
#include "qpid/framing/MessageReleaseBody.h"
#include "qpid/framing/MessageAcquireBody.h"
#include "qpid/framing/MessageResumeBody.h"
#include "qpid/framing/MessageSubscribeBody.h"
#include "qpid/framing/MessageCancelBody.h"
#include "qpid/framing/MessageSetFlowModeBody.h"
#include "qpid/framing/MessageFlowBody.h"
#include "qpid/framing/MessageFlushBody.h"
#include "qpid/framing/MessageStopBody.h"
#include "qpid/framing/TxSelectBody.h"
#include "qpid/framing/TxCommitBody.h"
#include "qpid/framing/TxRollbackBody.h"
#include "qpid/framing/DtxSelectBody.h"
#include "qpid/framing/DtxStartBody.h"
#include "qpid/framing/DtxEndBody.h"
#include "qpid/framing/DtxCommitBody.h"
#include "qpid/framing/DtxForgetBody.h"
#include "qpid/framing/DtxGetTimeoutBody.h"
#include "qpid/framing/DtxPrepareBody.h"
#include "qpid/framing/DtxRecoverBody.h"
#include "qpid/framing/DtxRollbackBody.h"
#include "qpid/framing/DtxSetTimeoutBody.h"
#include "qpid/framing/ExchangeDeclareBody.h"
#include "qpid/framing/ExchangeDeleteBody.h"
#include "qpid/framing/ExchangeQueryBody.h"
#include "qpid/framing/ExchangeBindBody.h"
#include "qpid/framing/ExchangeUnbindBody.h"
#include "qpid/framing/ExchangeBoundBody.h"
#include "qpid/framing/QueueDeclareBody.h"
#include "qpid/framing/QueueDeleteBody.h"
#include "qpid/framing/QueuePurgeBody.h"
#include "qpid/framing/QueueQueryBody.h"
#include "qpid/framing/FileQosBody.h"
#include "qpid/framing/FileQosOkBody.h"
#include "qpid/framing/FileConsumeBody.h"
#include "qpid/framing/FileConsumeOkBody.h"
#include "qpid/framing/FileCancelBody.h"
#include "qpid/framing/FileOpenBody.h"
#include "qpid/framing/FileOpenOkBody.h"
#include "qpid/framing/FileStageBody.h"
#include "qpid/framing/FilePublishBody.h"
#include "qpid/framing/FileReturnBody.h"
#include "qpid/framing/FileDeliverBody.h"
#include "qpid/framing/FileAckBody.h"
#include "qpid/framing/FileRejectBody.h"
#include "qpid/framing/StreamQosBody.h"
#include "qpid/framing/StreamQosOkBody.h"
#include "qpid/framing/StreamConsumeBody.h"
#include "qpid/framing/StreamConsumeOkBody.h"
#include "qpid/framing/StreamCancelBody.h"
#include "qpid/framing/StreamPublishBody.h"
#include "qpid/framing/StreamReturnBody.h"
#include "qpid/framing/StreamDeliverBody.h"
#include "qpid/framing/ClusterUpdateRequestBody.h"
#include "qpid/framing/ClusterUpdateOfferBody.h"
#include "qpid/framing/ClusterReadyBody.h"
#include "qpid/framing/ClusterConfigChangeBody.h"
#include "qpid/framing/ClusterMessageExpiredBody.h"
#include "qpid/framing/ClusterShutdownBody.h"
#include "qpid/framing/ClusterConnectionDeliverCloseBody.h"
#include "qpid/framing/ClusterConnectionDeliverDoOutputBody.h"
#include "qpid/framing/ClusterConnectionConsumerStateBody.h"
#include "qpid/framing/ClusterConnectionDeliveryRecordBody.h"
#include "qpid/framing/ClusterConnectionTxStartBody.h"
#include "qpid/framing/ClusterConnectionTxAcceptBody.h"
#include "qpid/framing/ClusterConnectionTxDequeueBody.h"
#include "qpid/framing/ClusterConnectionTxEnqueueBody.h"
#include "qpid/framing/ClusterConnectionTxPublishBody.h"
#include "qpid/framing/ClusterConnectionTxEndBody.h"
#include "qpid/framing/ClusterConnectionAccumulatedAckBody.h"
#include "qpid/framing/ClusterConnectionSessionStateBody.h"
#include "qpid/framing/ClusterConnectionShadowReadyBody.h"
#include "qpid/framing/ClusterConnectionMembershipBody.h"
#include "qpid/framing/ClusterConnectionQueuePositionBody.h"
#include "qpid/framing/ClusterConnectionExchangeBody.h"
#include "qpid/framing/ClusterConnectionQueueBody.h"
#include "qpid/framing/ClusterConnectionExpiryIdBody.h"
#include "qpid/Exception.h"


namespace qpid {
namespace framing {

boost::intrusive_ptr<AMQMethodBody> MethodBodyFactory::create(ClassId c, MethodId m) {
    switch (c) {
        case 0x1: switch(m) {
            case 0x1: return BodyFactory::create<ConnectionStartBody>();
            case 0x2: return BodyFactory::create<ConnectionStartOkBody>();
            case 0x3: return BodyFactory::create<ConnectionSecureBody>();
            case 0x4: return BodyFactory::create<ConnectionSecureOkBody>();
            case 0x5: return BodyFactory::create<ConnectionTuneBody>();
            case 0x6: return BodyFactory::create<ConnectionTuneOkBody>();
            case 0x7: return BodyFactory::create<ConnectionOpenBody>();
            case 0x8: return BodyFactory::create<ConnectionOpenOkBody>();
            case 0x9: return BodyFactory::create<ConnectionRedirectBody>();
            case 0xa: return BodyFactory::create<ConnectionHeartbeatBody>();
            case 0xb: return BodyFactory::create<ConnectionCloseBody>();
            case 0xc: return BodyFactory::create<ConnectionCloseOkBody>();
            default: throw Exception(QPID_MSG("Invalid method id " << int(m) << " for class connection "));
        }
        break;
        case 0x2: switch(m) {
            case 0x1: return BodyFactory::create<SessionAttachBody>();
            case 0x2: return BodyFactory::create<SessionAttachedBody>();
            case 0x3: return BodyFactory::create<SessionDetachBody>();
            case 0x4: return BodyFactory::create<SessionDetachedBody>();
            case 0x5: return BodyFactory::create<SessionRequestTimeoutBody>();
            case 0x6: return BodyFactory::create<SessionTimeoutBody>();
            case 0x7: return BodyFactory::create<SessionCommandPointBody>();
            case 0x8: return BodyFactory::create<SessionExpectedBody>();
            case 0x9: return BodyFactory::create<SessionConfirmedBody>();
            case 0xa: return BodyFactory::create<SessionCompletedBody>();
            case 0xb: return BodyFactory::create<SessionKnownCompletedBody>();
            case 0xc: return BodyFactory::create<SessionFlushBody>();
            case 0xd: return BodyFactory::create<SessionGapBody>();
            default: throw Exception(QPID_MSG("Invalid method id " << int(m) << " for class session "));
        }
        break;
        case 0x3: switch(m) {
            case 0x1: return BodyFactory::create<ExecutionSyncBody>();
            case 0x2: return BodyFactory::create<ExecutionResultBody>();
            case 0x3: return BodyFactory::create<ExecutionExceptionBody>();
            default: throw Exception(QPID_MSG("Invalid method id " << int(m) << " for class execution "));
        }
        break;
        case 0x4: switch(m) {
            case 0x1: return BodyFactory::create<MessageTransferBody>();
            case 0x2: return BodyFactory::create<MessageAcceptBody>();
            case 0x3: return BodyFactory::create<MessageRejectBody>();
            case 0x4: return BodyFactory::create<MessageReleaseBody>();
            case 0x5: return BodyFactory::create<MessageAcquireBody>();
            case 0x6: return BodyFactory::create<MessageResumeBody>();
            case 0x7: return BodyFactory::create<MessageSubscribeBody>();
            case 0x8: return BodyFactory::create<MessageCancelBody>();
            case 0x9: return BodyFactory::create<MessageSetFlowModeBody>();
            case 0xa: return BodyFactory::create<MessageFlowBody>();
            case 0xb: return BodyFactory::create<MessageFlushBody>();
            case 0xc: return BodyFactory::create<MessageStopBody>();
            default: throw Exception(QPID_MSG("Invalid method id " << int(m) << " for class message "));
        }
        break;
        case 0x5: switch(m) {
            case 0x1: return BodyFactory::create<TxSelectBody>();
            case 0x2: return BodyFactory::create<TxCommitBody>();
            case 0x3: return BodyFactory::create<TxRollbackBody>();
            default: throw Exception(QPID_MSG("Invalid method id " << int(m) << " for class tx "));
        }
        break;
        case 0x6: switch(m) {
            case 0x1: return BodyFactory::create<DtxSelectBody>();
            case 0x2: return BodyFactory::create<DtxStartBody>();
            case 0x3: return BodyFactory::create<DtxEndBody>();
            case 0x4: return BodyFactory::create<DtxCommitBody>();
            case 0x5: return BodyFactory::create<DtxForgetBody>();
            case 0x6: return BodyFactory::create<DtxGetTimeoutBody>();
            case 0x7: return BodyFactory::create<DtxPrepareBody>();
            case 0x8: return BodyFactory::create<DtxRecoverBody>();
            case 0x9: return BodyFactory::create<DtxRollbackBody>();
            case 0xa: return BodyFactory::create<DtxSetTimeoutBody>();
            default: throw Exception(QPID_MSG("Invalid method id " << int(m) << " for class dtx "));
        }
        break;
        case 0x7: switch(m) {
            case 0x1: return BodyFactory::create<ExchangeDeclareBody>();
            case 0x2: return BodyFactory::create<ExchangeDeleteBody>();
            case 0x3: return BodyFactory::create<ExchangeQueryBody>();
            case 0x4: return BodyFactory::create<ExchangeBindBody>();
            case 0x5: return BodyFactory::create<ExchangeUnbindBody>();
            case 0x6: return BodyFactory::create<ExchangeBoundBody>();
            default: throw Exception(QPID_MSG("Invalid method id " << int(m) << " for class exchange "));
        }
        break;
        case 0x8: switch(m) {
            case 0x1: return BodyFactory::create<QueueDeclareBody>();
            case 0x2: return BodyFactory::create<QueueDeleteBody>();
            case 0x3: return BodyFactory::create<QueuePurgeBody>();
            case 0x4: return BodyFactory::create<QueueQueryBody>();
            default: throw Exception(QPID_MSG("Invalid method id " << int(m) << " for class queue "));
        }
        break;
        case 0x9: switch(m) {
            case 0x1: return BodyFactory::create<FileQosBody>();
            case 0x2: return BodyFactory::create<FileQosOkBody>();
            case 0x3: return BodyFactory::create<FileConsumeBody>();
            case 0x4: return BodyFactory::create<FileConsumeOkBody>();
            case 0x5: return BodyFactory::create<FileCancelBody>();
            case 0x6: return BodyFactory::create<FileOpenBody>();
            case 0x7: return BodyFactory::create<FileOpenOkBody>();
            case 0x8: return BodyFactory::create<FileStageBody>();
            case 0x9: return BodyFactory::create<FilePublishBody>();
            case 0xa: return BodyFactory::create<FileReturnBody>();
            case 0xb: return BodyFactory::create<FileDeliverBody>();
            case 0xc: return BodyFactory::create<FileAckBody>();
            case 0xd: return BodyFactory::create<FileRejectBody>();
            default: throw Exception(QPID_MSG("Invalid method id " << int(m) << " for class file "));
        }
        break;
        case 0xa: switch(m) {
            case 0x1: return BodyFactory::create<StreamQosBody>();
            case 0x2: return BodyFactory::create<StreamQosOkBody>();
            case 0x3: return BodyFactory::create<StreamConsumeBody>();
            case 0x4: return BodyFactory::create<StreamConsumeOkBody>();
            case 0x5: return BodyFactory::create<StreamCancelBody>();
            case 0x6: return BodyFactory::create<StreamPublishBody>();
            case 0x7: return BodyFactory::create<StreamReturnBody>();
            case 0x8: return BodyFactory::create<StreamDeliverBody>();
            default: throw Exception(QPID_MSG("Invalid method id " << int(m) << " for class stream "));
        }
        break;
        case 0x80: switch(m) {
            case 0x1: return BodyFactory::create<ClusterUpdateRequestBody>();
            case 0x2: return BodyFactory::create<ClusterUpdateOfferBody>();
            case 0x10: return BodyFactory::create<ClusterReadyBody>();
            case 0x11: return BodyFactory::create<ClusterConfigChangeBody>();
            case 0x12: return BodyFactory::create<ClusterMessageExpiredBody>();
            case 0x20: return BodyFactory::create<ClusterShutdownBody>();
            default: throw Exception(QPID_MSG("Invalid method id " << int(m) << " for class cluster "));
        }
        break;
        case 0x81: switch(m) {
            case 0x2: return BodyFactory::create<ClusterConnectionDeliverCloseBody>();
            case 0x3: return BodyFactory::create<ClusterConnectionDeliverDoOutputBody>();
            case 0x10: return BodyFactory::create<ClusterConnectionConsumerStateBody>();
            case 0x11: return BodyFactory::create<ClusterConnectionDeliveryRecordBody>();
            case 0x12: return BodyFactory::create<ClusterConnectionTxStartBody>();
            case 0x13: return BodyFactory::create<ClusterConnectionTxAcceptBody>();
            case 0x14: return BodyFactory::create<ClusterConnectionTxDequeueBody>();
            case 0x15: return BodyFactory::create<ClusterConnectionTxEnqueueBody>();
            case 0x16: return BodyFactory::create<ClusterConnectionTxPublishBody>();
            case 0x17: return BodyFactory::create<ClusterConnectionTxEndBody>();
            case 0x18: return BodyFactory::create<ClusterConnectionAccumulatedAckBody>();
            case 0x1F: return BodyFactory::create<ClusterConnectionSessionStateBody>();
            case 0x20: return BodyFactory::create<ClusterConnectionShadowReadyBody>();
            case 0x21: return BodyFactory::create<ClusterConnectionMembershipBody>();
            case 0x30: return BodyFactory::create<ClusterConnectionQueuePositionBody>();
            case 0x31: return BodyFactory::create<ClusterConnectionExchangeBody>();
            case 0x32: return BodyFactory::create<ClusterConnectionQueueBody>();
            case 0x33: return BodyFactory::create<ClusterConnectionExpiryIdBody>();
            default: throw Exception(QPID_MSG("Invalid method id " << int(m) << " for class cluster-connection "));
        }
        break;
        default: throw Exception(QPID_MSG("Invalid class id " << int(c)));
    }
}

}} // namespace qpid::framing

