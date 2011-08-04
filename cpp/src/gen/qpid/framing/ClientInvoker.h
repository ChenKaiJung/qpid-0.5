#ifndef QPID_FRAMING_CLIENTINVOKER_H
#define QPID_FRAMING_CLIENTINVOKER_H
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


#include "qpid/framing/AMQP_ClientOperations.h"
#include "qpid/framing/Invoker.h"

namespace qpid {
namespace framing {


class AMQP_ClientOperations::Invoker:
    public qpid::framing::Invoker
{
    AMQP_ClientOperations& target;
  public:
    Invoker(AMQP_ClientOperations& target_) : target(target_) {}
    using MethodBodyDefaultVisitor::visit;
    void visit(const ConnectionStartBody& body);
    void visit(const ConnectionSecureBody& body);
    void visit(const ConnectionTuneBody& body);
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
    void visit(const MessageResumeBody& body);
    void visit(const MessageSetFlowModeBody& body);
    void visit(const MessageFlowBody& body);
    void visit(const MessageStopBody& body);
    void visit(const FileQosOkBody& body);
    void visit(const FileConsumeOkBody& body);
    void visit(const FileOpenBody& body);
    void visit(const FileOpenOkBody& body);
    void visit(const FileDeliverBody& body);
    void visit(const StreamQosOkBody& body);
    void visit(const StreamConsumeOkBody& body);
};

class AMQP_ClientOperations::ConnectionHandler::Invoker:
    public qpid::framing::Invoker
{
    AMQP_ClientOperations::ConnectionHandler& target;
  public:
    Invoker(AMQP_ClientOperations::ConnectionHandler& target_) : target(target_) {}
    using MethodBodyDefaultVisitor::visit;
    void visit(const ConnectionStartBody& body);
    void visit(const ConnectionSecureBody& body);
    void visit(const ConnectionTuneBody& body);
    void visit(const ConnectionOpenOkBody& body);
    void visit(const ConnectionRedirectBody& body);
    void visit(const ConnectionHeartbeatBody& body);
    void visit(const ConnectionCloseBody& body);
    void visit(const ConnectionCloseOkBody& body);
};

class AMQP_ClientOperations::SessionHandler::Invoker:
    public qpid::framing::Invoker
{
    AMQP_ClientOperations::SessionHandler& target;
  public:
    Invoker(AMQP_ClientOperations::SessionHandler& target_) : target(target_) {}
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

class AMQP_ClientOperations::ExecutionHandler::Invoker:
    public qpid::framing::Invoker
{
    AMQP_ClientOperations::ExecutionHandler& target;
  public:
    Invoker(AMQP_ClientOperations::ExecutionHandler& target_) : target(target_) {}
    using MethodBodyDefaultVisitor::visit;
    void visit(const ExecutionSyncBody& body);
    void visit(const ExecutionResultBody& body);
    void visit(const ExecutionExceptionBody& body);
};

class AMQP_ClientOperations::MessageHandler::Invoker:
    public qpid::framing::Invoker
{
    AMQP_ClientOperations::MessageHandler& target;
  public:
    Invoker(AMQP_ClientOperations::MessageHandler& target_) : target(target_) {}
    using MethodBodyDefaultVisitor::visit;
    void visit(const MessageAcceptBody& body);
    void visit(const MessageRejectBody& body);
    void visit(const MessageReleaseBody& body);
    void visit(const MessageResumeBody& body);
    void visit(const MessageSetFlowModeBody& body);
    void visit(const MessageFlowBody& body);
    void visit(const MessageStopBody& body);
};

class AMQP_ClientOperations::FileHandler::Invoker:
    public qpid::framing::Invoker
{
    AMQP_ClientOperations::FileHandler& target;
  public:
    Invoker(AMQP_ClientOperations::FileHandler& target_) : target(target_) {}
    using MethodBodyDefaultVisitor::visit;
    void visit(const FileQosOkBody& body);
    void visit(const FileConsumeOkBody& body);
    void visit(const FileOpenBody& body);
    void visit(const FileOpenOkBody& body);
    void visit(const FileDeliverBody& body);
};

class AMQP_ClientOperations::StreamHandler::Invoker:
    public qpid::framing::Invoker
{
    AMQP_ClientOperations::StreamHandler& target;
  public:
    Invoker(AMQP_ClientOperations::StreamHandler& target_) : target(target_) {}
    using MethodBodyDefaultVisitor::visit;
    void visit(const StreamQosOkBody& body);
    void visit(const StreamConsumeOkBody& body);
};

}} // namespace qpid::framing

#endif  /*!QPID_FRAMING_CLIENTINVOKER_H*/
