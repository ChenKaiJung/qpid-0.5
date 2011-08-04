#ifndef QPID_FRAMING_SERVERINVOKER_H
#define QPID_FRAMING_SERVERINVOKER_H
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


#include "qpid/framing/AMQP_ServerOperations.h"
#include "qpid/framing/Invoker.h"

namespace qpid {
namespace framing {


class AMQP_ServerOperations::Invoker:
    public qpid::framing::Invoker
{
    AMQP_ServerOperations& target;
  public:
    Invoker(AMQP_ServerOperations& target_) : target(target_) {}
    using MethodBodyDefaultVisitor::visit;
    void visit(const ConnectionStartOkBody& body);
    void visit(const ConnectionSecureOkBody& body);
    void visit(const ConnectionTuneOkBody& body);
    void visit(const ConnectionOpenBody& body);
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
    void visit(const FileConsumeBody& body);
    void visit(const FileCancelBody& body);
    void visit(const FileOpenBody& body);
    void visit(const FileOpenOkBody& body);
    void visit(const FilePublishBody& body);
    void visit(const FileAckBody& body);
    void visit(const FileRejectBody& body);
    void visit(const StreamQosBody& body);
    void visit(const StreamConsumeBody& body);
    void visit(const StreamCancelBody& body);
};

class AMQP_ServerOperations::ConnectionHandler::Invoker:
    public qpid::framing::Invoker
{
    AMQP_ServerOperations::ConnectionHandler& target;
  public:
    Invoker(AMQP_ServerOperations::ConnectionHandler& target_) : target(target_) {}
    using MethodBodyDefaultVisitor::visit;
    void visit(const ConnectionStartOkBody& body);
    void visit(const ConnectionSecureOkBody& body);
    void visit(const ConnectionTuneOkBody& body);
    void visit(const ConnectionOpenBody& body);
    void visit(const ConnectionHeartbeatBody& body);
    void visit(const ConnectionCloseBody& body);
    void visit(const ConnectionCloseOkBody& body);
};

class AMQP_ServerOperations::SessionHandler::Invoker:
    public qpid::framing::Invoker
{
    AMQP_ServerOperations::SessionHandler& target;
  public:
    Invoker(AMQP_ServerOperations::SessionHandler& target_) : target(target_) {}
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

class AMQP_ServerOperations::ExecutionHandler::Invoker:
    public qpid::framing::Invoker
{
    AMQP_ServerOperations::ExecutionHandler& target;
  public:
    Invoker(AMQP_ServerOperations::ExecutionHandler& target_) : target(target_) {}
    using MethodBodyDefaultVisitor::visit;
    void visit(const ExecutionSyncBody& body);
    void visit(const ExecutionResultBody& body);
    void visit(const ExecutionExceptionBody& body);
};

class AMQP_ServerOperations::MessageHandler::Invoker:
    public qpid::framing::Invoker
{
    AMQP_ServerOperations::MessageHandler& target;
  public:
    Invoker(AMQP_ServerOperations::MessageHandler& target_) : target(target_) {}
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

class AMQP_ServerOperations::TxHandler::Invoker:
    public qpid::framing::Invoker
{
    AMQP_ServerOperations::TxHandler& target;
  public:
    Invoker(AMQP_ServerOperations::TxHandler& target_) : target(target_) {}
    using MethodBodyDefaultVisitor::visit;
    void visit(const TxSelectBody& body);
    void visit(const TxCommitBody& body);
    void visit(const TxRollbackBody& body);
};

class AMQP_ServerOperations::DtxHandler::Invoker:
    public qpid::framing::Invoker
{
    AMQP_ServerOperations::DtxHandler& target;
  public:
    Invoker(AMQP_ServerOperations::DtxHandler& target_) : target(target_) {}
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

class AMQP_ServerOperations::ExchangeHandler::Invoker:
    public qpid::framing::Invoker
{
    AMQP_ServerOperations::ExchangeHandler& target;
  public:
    Invoker(AMQP_ServerOperations::ExchangeHandler& target_) : target(target_) {}
    using MethodBodyDefaultVisitor::visit;
    void visit(const ExchangeDeclareBody& body);
    void visit(const ExchangeDeleteBody& body);
    void visit(const ExchangeQueryBody& body);
    void visit(const ExchangeBindBody& body);
    void visit(const ExchangeUnbindBody& body);
    void visit(const ExchangeBoundBody& body);
};

class AMQP_ServerOperations::QueueHandler::Invoker:
    public qpid::framing::Invoker
{
    AMQP_ServerOperations::QueueHandler& target;
  public:
    Invoker(AMQP_ServerOperations::QueueHandler& target_) : target(target_) {}
    using MethodBodyDefaultVisitor::visit;
    void visit(const QueueDeclareBody& body);
    void visit(const QueueDeleteBody& body);
    void visit(const QueuePurgeBody& body);
    void visit(const QueueQueryBody& body);
};

class AMQP_ServerOperations::FileHandler::Invoker:
    public qpid::framing::Invoker
{
    AMQP_ServerOperations::FileHandler& target;
  public:
    Invoker(AMQP_ServerOperations::FileHandler& target_) : target(target_) {}
    using MethodBodyDefaultVisitor::visit;
    void visit(const FileQosBody& body);
    void visit(const FileConsumeBody& body);
    void visit(const FileCancelBody& body);
    void visit(const FileOpenBody& body);
    void visit(const FileOpenOkBody& body);
    void visit(const FilePublishBody& body);
    void visit(const FileAckBody& body);
    void visit(const FileRejectBody& body);
};

class AMQP_ServerOperations::StreamHandler::Invoker:
    public qpid::framing::Invoker
{
    AMQP_ServerOperations::StreamHandler& target;
  public:
    Invoker(AMQP_ServerOperations::StreamHandler& target_) : target(target_) {}
    using MethodBodyDefaultVisitor::visit;
    void visit(const StreamQosBody& body);
    void visit(const StreamConsumeBody& body);
    void visit(const StreamCancelBody& body);
};

}} // namespace qpid::framing

#endif  /*!QPID_FRAMING_SERVERINVOKER_H*/
