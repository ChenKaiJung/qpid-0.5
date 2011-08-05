#ifndef QPID_FRAMING_METHODBODYDEFAULTVISITOR_H
#define QPID_FRAMING_METHODBODYDEFAULTVISITOR_H
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


#include "qpid/framing/MethodBodyConstVisitor.h"

namespace qpid {
namespace framing {

class AMQMethodBody;
class MethodBodyDefaultVisitor:
    public MethodBodyConstVisitor
{
    public:
    virtual void defaultVisit(const AMQMethodBody&) = 0;
    virtual void visit(const ConnectionStartBody&);
    virtual void visit(const ConnectionStartOkBody&);
    virtual void visit(const ConnectionSecureBody&);
    virtual void visit(const ConnectionSecureOkBody&);
    virtual void visit(const ConnectionTuneBody&);
    virtual void visit(const ConnectionTuneOkBody&);
    virtual void visit(const ConnectionOpenBody&);
    virtual void visit(const ConnectionOpenOkBody&);
    virtual void visit(const ConnectionRedirectBody&);
    virtual void visit(const ConnectionHeartbeatBody&);
    virtual void visit(const ConnectionCloseBody&);
    virtual void visit(const ConnectionCloseOkBody&);
    virtual void visit(const SessionAttachBody&);
    virtual void visit(const SessionAttachedBody&);
    virtual void visit(const SessionDetachBody&);
    virtual void visit(const SessionDetachedBody&);
    virtual void visit(const SessionRequestTimeoutBody&);
    virtual void visit(const SessionTimeoutBody&);
    virtual void visit(const SessionCommandPointBody&);
    virtual void visit(const SessionExpectedBody&);
    virtual void visit(const SessionConfirmedBody&);
    virtual void visit(const SessionCompletedBody&);
    virtual void visit(const SessionKnownCompletedBody&);
    virtual void visit(const SessionFlushBody&);
    virtual void visit(const SessionGapBody&);
    virtual void visit(const ExecutionSyncBody&);
    virtual void visit(const ExecutionResultBody&);
    virtual void visit(const ExecutionExceptionBody&);
    virtual void visit(const MessageTransferBody&);
    virtual void visit(const MessageAcceptBody&);
    virtual void visit(const MessageRejectBody&);
    virtual void visit(const MessageReleaseBody&);
    virtual void visit(const MessageAcquireBody&);
    virtual void visit(const MessageResumeBody&);
    virtual void visit(const MessageSubscribeBody&);
    virtual void visit(const MessageCancelBody&);
    virtual void visit(const MessageSetFlowModeBody&);
    virtual void visit(const MessageFlowBody&);
    virtual void visit(const MessageFlushBody&);
    virtual void visit(const MessageStopBody&);
    virtual void visit(const TxSelectBody&);
    virtual void visit(const TxCommitBody&);
    virtual void visit(const TxRollbackBody&);
    virtual void visit(const DtxSelectBody&);
    virtual void visit(const DtxStartBody&);
    virtual void visit(const DtxEndBody&);
    virtual void visit(const DtxCommitBody&);
    virtual void visit(const DtxForgetBody&);
    virtual void visit(const DtxGetTimeoutBody&);
    virtual void visit(const DtxPrepareBody&);
    virtual void visit(const DtxRecoverBody&);
    virtual void visit(const DtxRollbackBody&);
    virtual void visit(const DtxSetTimeoutBody&);
    virtual void visit(const ExchangeDeclareBody&);
    virtual void visit(const ExchangeDeleteBody&);
    virtual void visit(const ExchangeQueryBody&);
    virtual void visit(const ExchangeBindBody&);
    virtual void visit(const ExchangeUnbindBody&);
    virtual void visit(const ExchangeBoundBody&);
    virtual void visit(const QueueDeclareBody&);
    virtual void visit(const QueueDeleteBody&);
    virtual void visit(const QueuePurgeBody&);
    virtual void visit(const QueueQueryBody&);
    virtual void visit(const FileQosBody&);
    virtual void visit(const FileQosOkBody&);
    virtual void visit(const FileConsumeBody&);
    virtual void visit(const FileConsumeOkBody&);
    virtual void visit(const FileCancelBody&);
    virtual void visit(const FileOpenBody&);
    virtual void visit(const FileOpenOkBody&);
    virtual void visit(const FileStageBody&);
    virtual void visit(const FilePublishBody&);
    virtual void visit(const FileReturnBody&);
    virtual void visit(const FileDeliverBody&);
    virtual void visit(const FileAckBody&);
    virtual void visit(const FileRejectBody&);
    virtual void visit(const StreamQosBody&);
    virtual void visit(const StreamQosOkBody&);
    virtual void visit(const StreamConsumeBody&);
    virtual void visit(const StreamConsumeOkBody&);
    virtual void visit(const StreamCancelBody&);
    virtual void visit(const StreamPublishBody&);
    virtual void visit(const StreamReturnBody&);
    virtual void visit(const StreamDeliverBody&);
    virtual void visit(const ClusterUpdateRequestBody&);
    virtual void visit(const ClusterUpdateOfferBody&);
    virtual void visit(const ClusterRetractOfferBody&);
    virtual void visit(const ClusterReadyBody&);
    virtual void visit(const ClusterConfigChangeBody&);
    virtual void visit(const ClusterMessageExpiredBody&);
    virtual void visit(const ClusterErrorCheckBody&);
    virtual void visit(const ClusterShutdownBody&);
    virtual void visit(const ClusterConnectionAnnounceBody&);
    virtual void visit(const ClusterConnectionDeliverCloseBody&);
    virtual void visit(const ClusterConnectionDeliverDoOutputBody&);
    virtual void visit(const ClusterConnectionAbortBody&);
    virtual void visit(const ClusterConnectionConsumerStateBody&);
    virtual void visit(const ClusterConnectionDeliveryRecordBody&);
    virtual void visit(const ClusterConnectionTxStartBody&);
    virtual void visit(const ClusterConnectionTxAcceptBody&);
    virtual void visit(const ClusterConnectionTxDequeueBody&);
    virtual void visit(const ClusterConnectionTxEnqueueBody&);
    virtual void visit(const ClusterConnectionTxPublishBody&);
    virtual void visit(const ClusterConnectionTxEndBody&);
    virtual void visit(const ClusterConnectionAccumulatedAckBody&);
    virtual void visit(const ClusterConnectionSessionStateBody&);
    virtual void visit(const ClusterConnectionShadowReadyBody&);
    virtual void visit(const ClusterConnectionMembershipBody&);
    virtual void visit(const ClusterConnectionRetractOfferBody&);
    virtual void visit(const ClusterConnectionQueuePositionBody&);
    virtual void visit(const ClusterConnectionExchangeBody&);
    virtual void visit(const ClusterConnectionQueueBody&);
    virtual void visit(const ClusterConnectionExpiryIdBody&);
    virtual void visit(const ClusterConnectionAddQueueListenerBody&);
};

}} // namespace qpid::framing

#endif  /*!QPID_FRAMING_METHODBODYDEFAULTVISITOR_H*/
