#ifndef QPID_FRAMING_ALLINVOKER_H
#define QPID_FRAMING_ALLINVOKER_H
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


#include "qpid/framing/AMQP_AllOperations.h"
#include "qpid/framing/Invoker.h"

namespace qpid {
namespace framing {


class AMQP_AllOperations::Invoker:
    public qpid::framing::Invoker
{
    AMQP_AllOperations& target;
  public:
    Invoker(AMQP_AllOperations& target_) : target(target_) {}
    using MethodBodyDefaultVisitor::visit;
    void visit(const ConnectionStartBody& body);
    void visit(const ConnectionStartOkBody& body);
    void visit(const ConnectionSecureBody& body);
    void visit(const ConnectionSecureOkBody& body);
    void visit(const ConnectionTuneBody& body);
    void visit(const ConnectionTuneOkBody& body);
    void visit(const ConnectionOpenBody& body);
    void visit(const ConnectionOpenOkBody& body);
    void visit(const ConnectionRedirectBody& body);
    void visit(const ConnectionHeartbeatBody& body);
    void visit(const ConnectionCloseBody& body);
    void visit(const ConnectionCloseOkBody& body);
    void visit(const SessionAttachBody& body);
    void visit(const SessionAttachedBody& body);
    void visit(const SessionDetachBody& body);
    void visit(const SessionDetachedBody& body);
    void visit(const SessionRequestTimeoutBody& body);
    void visit(const SessionTimeoutBody& body);
    void visit(const SessionCommandPointBody& body);
    void visit(const SessionExpectedBody& body);
    void visit(const SessionConfirmedBody& body);
    void visit(const SessionCompletedBody& body);
    void visit(const SessionKnownCompletedBody& body);
    void visit(const SessionFlushBody& body);
    void visit(const SessionGapBody& body);
    void visit(const ExecutionSyncBody& body);
    void visit(const ExecutionResultBody& body);
    void visit(const ExecutionExceptionBody& body);
    void visit(const MessageAcceptBody& body);
    void visit(const MessageRejectBody& body);
    void visit(const MessageReleaseBody& body);
    void visit(const MessageAcquireBody& body);
    void visit(const MessageResumeBody& body);
    void visit(const MessageSubscribeBody& body);
    void visit(const MessageCancelBody& body);
    void visit(const MessageSetFlowModeBody& body);
    void visit(const MessageFlowBody& body);
    void visit(const MessageFlushBody& body);
    void visit(const MessageStopBody& body);
    void visit(const TxSelectBody& body);
    void visit(const TxCommitBody& body);
    void visit(const TxRollbackBody& body);
    void visit(const DtxSelectBody& body);
    void visit(const DtxStartBody& body);
    void visit(const DtxEndBody& body);
    void visit(const DtxCommitBody& body);
    void visit(const DtxForgetBody& body);
    void visit(const DtxGetTimeoutBody& body);
    void visit(const DtxPrepareBody& body);
    void visit(const DtxRecoverBody& body);
    void visit(const DtxRollbackBody& body);
    void visit(const DtxSetTimeoutBody& body);
    void visit(const ExchangeDeclareBody& body);
    void visit(const ExchangeDeleteBody& body);
    void visit(const ExchangeQueryBody& body);
    void visit(const ExchangeBindBody& body);
    void visit(const ExchangeUnbindBody& body);
    void visit(const ExchangeBoundBody& body);
    void visit(const QueueDeclareBody& body);
    void visit(const QueueDeleteBody& body);
    void visit(const QueuePurgeBody& body);
    void visit(const QueueQueryBody& body);
    void visit(const FileQosBody& body);
    void visit(const FileQosOkBody& body);
    void visit(const FileConsumeBody& body);
    void visit(const FileConsumeOkBody& body);
    void visit(const FileCancelBody& body);
    void visit(const FileOpenBody& body);
    void visit(const FileOpenOkBody& body);
    void visit(const FilePublishBody& body);
    void visit(const FileDeliverBody& body);
    void visit(const FileAckBody& body);
    void visit(const FileRejectBody& body);
    void visit(const StreamQosBody& body);
    void visit(const StreamQosOkBody& body);
    void visit(const StreamConsumeBody& body);
    void visit(const StreamConsumeOkBody& body);
    void visit(const StreamCancelBody& body);
    void visit(const ClusterUpdateRequestBody& body);
    void visit(const ClusterUpdateOfferBody& body);
    void visit(const ClusterRetractOfferBody& body);
    void visit(const ClusterReadyBody& body);
    void visit(const ClusterConfigChangeBody& body);
    void visit(const ClusterMessageExpiredBody& body);
    void visit(const ClusterErrorCheckBody& body);
    void visit(const ClusterShutdownBody& body);
    void visit(const ClusterConnectionAnnounceBody& body);
    void visit(const ClusterConnectionDeliverCloseBody& body);
    void visit(const ClusterConnectionDeliverDoOutputBody& body);
    void visit(const ClusterConnectionAbortBody& body);
    void visit(const ClusterConnectionConsumerStateBody& body);
    void visit(const ClusterConnectionDeliveryRecordBody& body);
    void visit(const ClusterConnectionTxStartBody& body);
    void visit(const ClusterConnectionTxAcceptBody& body);
    void visit(const ClusterConnectionTxDequeueBody& body);
    void visit(const ClusterConnectionTxEnqueueBody& body);
    void visit(const ClusterConnectionTxPublishBody& body);
    void visit(const ClusterConnectionTxEndBody& body);
    void visit(const ClusterConnectionAccumulatedAckBody& body);
    void visit(const ClusterConnectionSessionStateBody& body);
    void visit(const ClusterConnectionShadowReadyBody& body);
    void visit(const ClusterConnectionMembershipBody& body);
    void visit(const ClusterConnectionRetractOfferBody& body);
    void visit(const ClusterConnectionQueuePositionBody& body);
    void visit(const ClusterConnectionExchangeBody& body);
    void visit(const ClusterConnectionQueueBody& body);
    void visit(const ClusterConnectionExpiryIdBody& body);
    void visit(const ClusterConnectionAddQueueListenerBody& body);
};

class AMQP_AllOperations::ConnectionHandler::Invoker:
    public qpid::framing::Invoker
{
    AMQP_AllOperations::ConnectionHandler& target;
  public:
    Invoker(AMQP_AllOperations::ConnectionHandler& target_) : target(target_) {}
    using MethodBodyDefaultVisitor::visit;
    void visit(const ConnectionStartBody& body);
    void visit(const ConnectionStartOkBody& body);
    void visit(const ConnectionSecureBody& body);
    void visit(const ConnectionSecureOkBody& body);
    void visit(const ConnectionTuneBody& body);
    void visit(const ConnectionTuneOkBody& body);
    void visit(const ConnectionOpenBody& body);
    void visit(const ConnectionOpenOkBody& body);
    void visit(const ConnectionRedirectBody& body);
    void visit(const ConnectionHeartbeatBody& body);
    void visit(const ConnectionCloseBody& body);
    void visit(const ConnectionCloseOkBody& body);
};

class AMQP_AllOperations::SessionHandler::Invoker:
    public qpid::framing::Invoker
{
    AMQP_AllOperations::SessionHandler& target;
  public:
    Invoker(AMQP_AllOperations::SessionHandler& target_) : target(target_) {}
    using MethodBodyDefaultVisitor::visit;
    void visit(const SessionAttachBody& body);
    void visit(const SessionAttachedBody& body);
    void visit(const SessionDetachBody& body);
    void visit(const SessionDetachedBody& body);
    void visit(const SessionRequestTimeoutBody& body);
    void visit(const SessionTimeoutBody& body);
    void visit(const SessionCommandPointBody& body);
    void visit(const SessionExpectedBody& body);
    void visit(const SessionConfirmedBody& body);
    void visit(const SessionCompletedBody& body);
    void visit(const SessionKnownCompletedBody& body);
    void visit(const SessionFlushBody& body);
    void visit(const SessionGapBody& body);
};

class AMQP_AllOperations::ExecutionHandler::Invoker:
    public qpid::framing::Invoker
{
    AMQP_AllOperations::ExecutionHandler& target;
  public:
    Invoker(AMQP_AllOperations::ExecutionHandler& target_) : target(target_) {}
    using MethodBodyDefaultVisitor::visit;
    void visit(const ExecutionSyncBody& body);
    void visit(const ExecutionResultBody& body);
    void visit(const ExecutionExceptionBody& body);
};

class AMQP_AllOperations::MessageHandler::Invoker:
    public qpid::framing::Invoker
{
    AMQP_AllOperations::MessageHandler& target;
  public:
    Invoker(AMQP_AllOperations::MessageHandler& target_) : target(target_) {}
    using MethodBodyDefaultVisitor::visit;
    void visit(const MessageAcceptBody& body);
    void visit(const MessageRejectBody& body);
    void visit(const MessageReleaseBody& body);
    void visit(const MessageAcquireBody& body);
    void visit(const MessageResumeBody& body);
    void visit(const MessageSubscribeBody& body);
    void visit(const MessageCancelBody& body);
    void visit(const MessageSetFlowModeBody& body);
    void visit(const MessageFlowBody& body);
    void visit(const MessageFlushBody& body);
    void visit(const MessageStopBody& body);
};

class AMQP_AllOperations::TxHandler::Invoker:
    public qpid::framing::Invoker
{
    AMQP_AllOperations::TxHandler& target;
  public:
    Invoker(AMQP_AllOperations::TxHandler& target_) : target(target_) {}
    using MethodBodyDefaultVisitor::visit;
    void visit(const TxSelectBody& body);
    void visit(const TxCommitBody& body);
    void visit(const TxRollbackBody& body);
};

class AMQP_AllOperations::DtxHandler::Invoker:
    public qpid::framing::Invoker
{
    AMQP_AllOperations::DtxHandler& target;
  public:
    Invoker(AMQP_AllOperations::DtxHandler& target_) : target(target_) {}
    using MethodBodyDefaultVisitor::visit;
    void visit(const DtxSelectBody& body);
    void visit(const DtxStartBody& body);
    void visit(const DtxEndBody& body);
    void visit(const DtxCommitBody& body);
    void visit(const DtxForgetBody& body);
    void visit(const DtxGetTimeoutBody& body);
    void visit(const DtxPrepareBody& body);
    void visit(const DtxRecoverBody& body);
    void visit(const DtxRollbackBody& body);
    void visit(const DtxSetTimeoutBody& body);
};

class AMQP_AllOperations::ExchangeHandler::Invoker:
    public qpid::framing::Invoker
{
    AMQP_AllOperations::ExchangeHandler& target;
  public:
    Invoker(AMQP_AllOperations::ExchangeHandler& target_) : target(target_) {}
    using MethodBodyDefaultVisitor::visit;
    void visit(const ExchangeDeclareBody& body);
    void visit(const ExchangeDeleteBody& body);
    void visit(const ExchangeQueryBody& body);
    void visit(const ExchangeBindBody& body);
    void visit(const ExchangeUnbindBody& body);
    void visit(const ExchangeBoundBody& body);
};

class AMQP_AllOperations::QueueHandler::Invoker:
    public qpid::framing::Invoker
{
    AMQP_AllOperations::QueueHandler& target;
  public:
    Invoker(AMQP_AllOperations::QueueHandler& target_) : target(target_) {}
    using MethodBodyDefaultVisitor::visit;
    void visit(const QueueDeclareBody& body);
    void visit(const QueueDeleteBody& body);
    void visit(const QueuePurgeBody& body);
    void visit(const QueueQueryBody& body);
};

class AMQP_AllOperations::FileHandler::Invoker:
    public qpid::framing::Invoker
{
    AMQP_AllOperations::FileHandler& target;
  public:
    Invoker(AMQP_AllOperations::FileHandler& target_) : target(target_) {}
    using MethodBodyDefaultVisitor::visit;
    void visit(const FileQosBody& body);
    void visit(const FileQosOkBody& body);
    void visit(const FileConsumeBody& body);
    void visit(const FileConsumeOkBody& body);
    void visit(const FileCancelBody& body);
    void visit(const FileOpenBody& body);
    void visit(const FileOpenOkBody& body);
    void visit(const FilePublishBody& body);
    void visit(const FileDeliverBody& body);
    void visit(const FileAckBody& body);
    void visit(const FileRejectBody& body);
};

class AMQP_AllOperations::StreamHandler::Invoker:
    public qpid::framing::Invoker
{
    AMQP_AllOperations::StreamHandler& target;
  public:
    Invoker(AMQP_AllOperations::StreamHandler& target_) : target(target_) {}
    using MethodBodyDefaultVisitor::visit;
    void visit(const StreamQosBody& body);
    void visit(const StreamQosOkBody& body);
    void visit(const StreamConsumeBody& body);
    void visit(const StreamConsumeOkBody& body);
    void visit(const StreamCancelBody& body);
};

class AMQP_AllOperations::ClusterHandler::Invoker:
    public qpid::framing::Invoker
{
    AMQP_AllOperations::ClusterHandler& target;
  public:
    Invoker(AMQP_AllOperations::ClusterHandler& target_) : target(target_) {}
    using MethodBodyDefaultVisitor::visit;
    void visit(const ClusterUpdateRequestBody& body);
    void visit(const ClusterUpdateOfferBody& body);
    void visit(const ClusterRetractOfferBody& body);
    void visit(const ClusterReadyBody& body);
    void visit(const ClusterConfigChangeBody& body);
    void visit(const ClusterMessageExpiredBody& body);
    void visit(const ClusterErrorCheckBody& body);
    void visit(const ClusterShutdownBody& body);
};

class AMQP_AllOperations::ClusterConnectionHandler::Invoker:
    public qpid::framing::Invoker
{
    AMQP_AllOperations::ClusterConnectionHandler& target;
  public:
    Invoker(AMQP_AllOperations::ClusterConnectionHandler& target_) : target(target_) {}
    using MethodBodyDefaultVisitor::visit;
    void visit(const ClusterConnectionAnnounceBody& body);
    void visit(const ClusterConnectionDeliverCloseBody& body);
    void visit(const ClusterConnectionDeliverDoOutputBody& body);
    void visit(const ClusterConnectionAbortBody& body);
    void visit(const ClusterConnectionConsumerStateBody& body);
    void visit(const ClusterConnectionDeliveryRecordBody& body);
    void visit(const ClusterConnectionTxStartBody& body);
    void visit(const ClusterConnectionTxAcceptBody& body);
    void visit(const ClusterConnectionTxDequeueBody& body);
    void visit(const ClusterConnectionTxEnqueueBody& body);
    void visit(const ClusterConnectionTxPublishBody& body);
    void visit(const ClusterConnectionTxEndBody& body);
    void visit(const ClusterConnectionAccumulatedAckBody& body);
    void visit(const ClusterConnectionSessionStateBody& body);
    void visit(const ClusterConnectionShadowReadyBody& body);
    void visit(const ClusterConnectionMembershipBody& body);
    void visit(const ClusterConnectionRetractOfferBody& body);
    void visit(const ClusterConnectionQueuePositionBody& body);
    void visit(const ClusterConnectionExchangeBody& body);
    void visit(const ClusterConnectionQueueBody& body);
    void visit(const ClusterConnectionExpiryIdBody& body);
    void visit(const ClusterConnectionAddQueueListenerBody& body);
};

}} // namespace qpid::framing

#endif  /*!QPID_FRAMING_ALLINVOKER_H*/
