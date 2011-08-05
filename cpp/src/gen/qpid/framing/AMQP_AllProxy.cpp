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


#include <sstream>
#include "AMQP_AllProxy.h"
#include "qpid/framing/amqp_types_full.h"
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
#include "qpid/framing/ClusterRetractOfferBody.h"
#include "qpid/framing/ClusterReadyBody.h"
#include "qpid/framing/ClusterConfigChangeBody.h"
#include "qpid/framing/ClusterMessageExpiredBody.h"
#include "qpid/framing/ClusterErrorCheckBody.h"
#include "qpid/framing/ClusterShutdownBody.h"
#include "qpid/framing/ClusterConnectionAnnounceBody.h"
#include "qpid/framing/ClusterConnectionDeliverCloseBody.h"
#include "qpid/framing/ClusterConnectionDeliverDoOutputBody.h"
#include "qpid/framing/ClusterConnectionAbortBody.h"
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
#include "qpid/framing/ClusterConnectionRetractOfferBody.h"
#include "qpid/framing/ClusterConnectionQueuePositionBody.h"
#include "qpid/framing/ClusterConnectionExchangeBody.h"
#include "qpid/framing/ClusterConnectionQueueBody.h"
#include "qpid/framing/ClusterConnectionExpiryIdBody.h"
#include "qpid/framing/ClusterConnectionAddQueueListenerBody.h"


namespace qpid {
namespace framing {

AMQP_AllProxy::AMQP_AllProxy(FrameHandler& f) :
   Proxy(f),
    connectionProxy(f),
    sessionProxy(f),
    executionProxy(f),
    messageProxy(f),
    txProxy(f),
    dtxProxy(f),
    exchangeProxy(f),
    queueProxy(f),
    fileProxy(f),
    streamProxy(f),
    clusterProxy(f),
    clusterConnectionProxy(f){}

void AMQP_AllProxy::Connection::start(const FieldTable& serverProperties, const Array& mechanisms, const Array& locales)
{
    send(ConnectionStartBody(getVersion(), serverProperties, mechanisms, locales));
}
void AMQP_AllProxy::Connection::startOk(const FieldTable& clientProperties, const string& mechanism, const string& response, const string& locale)
{
    send(ConnectionStartOkBody(getVersion(), clientProperties, mechanism, response, locale));
}
void AMQP_AllProxy::Connection::secure(const string& challenge)
{
    send(ConnectionSecureBody(getVersion(), challenge));
}
void AMQP_AllProxy::Connection::secureOk(const string& response)
{
    send(ConnectionSecureOkBody(getVersion(), response));
}
void AMQP_AllProxy::Connection::tune(uint16_t channelMax, uint16_t maxFrameSize, uint16_t heartbeatMin, uint16_t heartbeatMax)
{
    send(ConnectionTuneBody(getVersion(), channelMax, maxFrameSize, heartbeatMin, heartbeatMax));
}
void AMQP_AllProxy::Connection::tuneOk(uint16_t channelMax, uint16_t maxFrameSize, uint16_t heartbeat)
{
    send(ConnectionTuneOkBody(getVersion(), channelMax, maxFrameSize, heartbeat));
}
void AMQP_AllProxy::Connection::open(const string& virtualHost, const Array& capabilities, bool insist)
{
    send(ConnectionOpenBody(getVersion(), virtualHost, capabilities, insist));
}
void AMQP_AllProxy::Connection::openOk(const Array& knownHosts)
{
    send(ConnectionOpenOkBody(getVersion(), knownHosts));
}
void AMQP_AllProxy::Connection::redirect(const string& host, const Array& knownHosts)
{
    send(ConnectionRedirectBody(getVersion(), host, knownHosts));
}
void AMQP_AllProxy::Connection::heartbeat()
{
    send(ConnectionHeartbeatBody(getVersion()));
}
void AMQP_AllProxy::Connection::close(uint16_t replyCode, const string& replyText)
{
    send(ConnectionCloseBody(getVersion(), replyCode, replyText));
}
void AMQP_AllProxy::Connection::closeOk()
{
    send(ConnectionCloseOkBody(getVersion()));
}
void AMQP_AllProxy::Session::attach(const string& name, bool force)
{
    send(SessionAttachBody(getVersion(), name, force));
}
void AMQP_AllProxy::Session::attached(const string& name)
{
    send(SessionAttachedBody(getVersion(), name));
}
void AMQP_AllProxy::Session::detach(const string& name)
{
    send(SessionDetachBody(getVersion(), name));
}
void AMQP_AllProxy::Session::detached(const string& name, uint8_t code)
{
    send(SessionDetachedBody(getVersion(), name, code));
}
void AMQP_AllProxy::Session::requestTimeout(uint32_t timeout)
{
    send(SessionRequestTimeoutBody(getVersion(), timeout));
}
void AMQP_AllProxy::Session::timeout(uint32_t timeout)
{
    send(SessionTimeoutBody(getVersion(), timeout));
}
void AMQP_AllProxy::Session::commandPoint(const SequenceNumber& commandId, uint64_t commandOffset)
{
    send(SessionCommandPointBody(getVersion(), commandId, commandOffset));
}
void AMQP_AllProxy::Session::expected(const SequenceSet& commands, const Array& fragments)
{
    send(SessionExpectedBody(getVersion(), commands, fragments));
}
void AMQP_AllProxy::Session::confirmed(const SequenceSet& commands, const Array& fragments)
{
    send(SessionConfirmedBody(getVersion(), commands, fragments));
}
void AMQP_AllProxy::Session::completed(const SequenceSet& commands, bool timelyReply)
{
    send(SessionCompletedBody(getVersion(), commands, timelyReply));
}
void AMQP_AllProxy::Session::knownCompleted(const SequenceSet& commands)
{
    send(SessionKnownCompletedBody(getVersion(), commands));
}
void AMQP_AllProxy::Session::flush(bool expected, bool confirmed, bool completed)
{
    send(SessionFlushBody(getVersion(), expected, confirmed, completed));
}
void AMQP_AllProxy::Session::gap(const SequenceSet& commands)
{
    send(SessionGapBody(getVersion(), commands));
}
void AMQP_AllProxy::Execution::sync()
{
    send(ExecutionSyncBody(getVersion()));
}
void AMQP_AllProxy::Execution::result(const SequenceNumber& commandId, const string& value)
{
    send(ExecutionResultBody(getVersion(), commandId, value));
}
void AMQP_AllProxy::Execution::exception(uint16_t errorCode, const SequenceNumber& commandId, uint8_t classCode, uint8_t commandCode, uint8_t fieldIndex, const string& description, const FieldTable& errorInfo)
{
    send(ExecutionExceptionBody(getVersion(), errorCode, commandId, classCode, commandCode, fieldIndex, description, errorInfo));
}
void AMQP_AllProxy::Message::transfer(const string& destination, uint8_t acceptMode, uint8_t acquireMode)
{
    send(MessageTransferBody(getVersion(), destination, acceptMode, acquireMode));
}
void AMQP_AllProxy::Message::accept(const SequenceSet& transfers)
{
    send(MessageAcceptBody(getVersion(), transfers));
}
void AMQP_AllProxy::Message::reject(const SequenceSet& transfers, uint16_t code, const string& text)
{
    send(MessageRejectBody(getVersion(), transfers, code, text));
}
void AMQP_AllProxy::Message::release(const SequenceSet& transfers, bool setRedelivered)
{
    send(MessageReleaseBody(getVersion(), transfers, setRedelivered));
}
void AMQP_AllProxy::Message::acquire(const SequenceSet& transfers)
{
    send(MessageAcquireBody(getVersion(), transfers));
}
void AMQP_AllProxy::Message::resume(const string& destination, const string& resumeId)
{
    send(MessageResumeBody(getVersion(), destination, resumeId));
}
void AMQP_AllProxy::Message::subscribe(const string& queue, const string& destination, uint8_t acceptMode, uint8_t acquireMode, bool exclusive, const string& resumeId, uint64_t resumeTtl, const FieldTable& arguments)
{
    send(MessageSubscribeBody(getVersion(), queue, destination, acceptMode, acquireMode, exclusive, resumeId, resumeTtl, arguments));
}
void AMQP_AllProxy::Message::cancel(const string& destination)
{
    send(MessageCancelBody(getVersion(), destination));
}
void AMQP_AllProxy::Message::setFlowMode(const string& destination, uint8_t flowMode)
{
    send(MessageSetFlowModeBody(getVersion(), destination, flowMode));
}
void AMQP_AllProxy::Message::flow(const string& destination, uint8_t unit, uint32_t value)
{
    send(MessageFlowBody(getVersion(), destination, unit, value));
}
void AMQP_AllProxy::Message::flush(const string& destination)
{
    send(MessageFlushBody(getVersion(), destination));
}
void AMQP_AllProxy::Message::stop(const string& destination)
{
    send(MessageStopBody(getVersion(), destination));
}
void AMQP_AllProxy::Tx::select()
{
    send(TxSelectBody(getVersion()));
}
void AMQP_AllProxy::Tx::commit()
{
    send(TxCommitBody(getVersion()));
}
void AMQP_AllProxy::Tx::rollback()
{
    send(TxRollbackBody(getVersion()));
}
void AMQP_AllProxy::Dtx::select()
{
    send(DtxSelectBody(getVersion()));
}
void AMQP_AllProxy::Dtx::start(const Xid& xid, bool join, bool resume)
{
    send(DtxStartBody(getVersion(), xid, join, resume));
}
void AMQP_AllProxy::Dtx::end(const Xid& xid, bool fail, bool suspend)
{
    send(DtxEndBody(getVersion(), xid, fail, suspend));
}
void AMQP_AllProxy::Dtx::commit(const Xid& xid, bool onePhase)
{
    send(DtxCommitBody(getVersion(), xid, onePhase));
}
void AMQP_AllProxy::Dtx::forget(const Xid& xid)
{
    send(DtxForgetBody(getVersion(), xid));
}
void AMQP_AllProxy::Dtx::getTimeout(const Xid& xid)
{
    send(DtxGetTimeoutBody(getVersion(), xid));
}
void AMQP_AllProxy::Dtx::prepare(const Xid& xid)
{
    send(DtxPrepareBody(getVersion(), xid));
}
void AMQP_AllProxy::Dtx::recover()
{
    send(DtxRecoverBody(getVersion()));
}
void AMQP_AllProxy::Dtx::rollback(const Xid& xid)
{
    send(DtxRollbackBody(getVersion(), xid));
}
void AMQP_AllProxy::Dtx::setTimeout(const Xid& xid, uint32_t timeout)
{
    send(DtxSetTimeoutBody(getVersion(), xid, timeout));
}
void AMQP_AllProxy::Exchange::declare(const string& exchange, const string& type, const string& alternateExchange, bool passive, bool durable, bool autoDelete, const FieldTable& arguments)
{
    send(ExchangeDeclareBody(getVersion(), exchange, type, alternateExchange, passive, durable, autoDelete, arguments));
}
void AMQP_AllProxy::Exchange::delete_(const string& exchange, bool ifUnused)
{
    send(ExchangeDeleteBody(getVersion(), exchange, ifUnused));
}
void AMQP_AllProxy::Exchange::query(const string& name)
{
    send(ExchangeQueryBody(getVersion(), name));
}
void AMQP_AllProxy::Exchange::bind(const string& queue, const string& exchange, const string& bindingKey, const FieldTable& arguments)
{
    send(ExchangeBindBody(getVersion(), queue, exchange, bindingKey, arguments));
}
void AMQP_AllProxy::Exchange::unbind(const string& queue, const string& exchange, const string& bindingKey)
{
    send(ExchangeUnbindBody(getVersion(), queue, exchange, bindingKey));
}
void AMQP_AllProxy::Exchange::bound(const string& exchange, const string& queue, const string& bindingKey, const FieldTable& arguments)
{
    send(ExchangeBoundBody(getVersion(), exchange, queue, bindingKey, arguments));
}
void AMQP_AllProxy::Queue::declare(const string& queue, const string& alternateExchange, bool passive, bool durable, bool exclusive, bool autoDelete, const FieldTable& arguments)
{
    send(QueueDeclareBody(getVersion(), queue, alternateExchange, passive, durable, exclusive, autoDelete, arguments));
}
void AMQP_AllProxy::Queue::delete_(const string& queue, bool ifUnused, bool ifEmpty)
{
    send(QueueDeleteBody(getVersion(), queue, ifUnused, ifEmpty));
}
void AMQP_AllProxy::Queue::purge(const string& queue)
{
    send(QueuePurgeBody(getVersion(), queue));
}
void AMQP_AllProxy::Queue::query(const string& queue)
{
    send(QueueQueryBody(getVersion(), queue));
}
void AMQP_AllProxy::File::qos(uint32_t prefetchSize, uint16_t prefetchCount, bool global)
{
    send(FileQosBody(getVersion(), prefetchSize, prefetchCount, global));
}
void AMQP_AllProxy::File::qosOk()
{
    send(FileQosOkBody(getVersion()));
}
void AMQP_AllProxy::File::consume(const string& queue, const string& consumerTag, bool noLocal, bool noAck, bool exclusive, bool nowait, const FieldTable& arguments)
{
    send(FileConsumeBody(getVersion(), queue, consumerTag, noLocal, noAck, exclusive, nowait, arguments));
}
void AMQP_AllProxy::File::consumeOk(const string& consumerTag)
{
    send(FileConsumeOkBody(getVersion(), consumerTag));
}
void AMQP_AllProxy::File::cancel(const string& consumerTag)
{
    send(FileCancelBody(getVersion(), consumerTag));
}
void AMQP_AllProxy::File::open(const string& identifier, uint64_t contentSize)
{
    send(FileOpenBody(getVersion(), identifier, contentSize));
}
void AMQP_AllProxy::File::openOk(uint64_t stagedSize)
{
    send(FileOpenOkBody(getVersion(), stagedSize));
}
void AMQP_AllProxy::File::stage()
{
    send(FileStageBody(getVersion()));
}
void AMQP_AllProxy::File::publish(const string& exchange, const string& routingKey, bool mandatory, bool immediate, const string& identifier)
{
    send(FilePublishBody(getVersion(), exchange, routingKey, mandatory, immediate, identifier));
}
void AMQP_AllProxy::File::return_(uint16_t replyCode, const string& replyText, const string& exchange, const string& routingKey)
{
    send(FileReturnBody(getVersion(), replyCode, replyText, exchange, routingKey));
}
void AMQP_AllProxy::File::deliver(const string& consumerTag, uint64_t deliveryTag, bool redelivered, const string& exchange, const string& routingKey, const string& identifier)
{
    send(FileDeliverBody(getVersion(), consumerTag, deliveryTag, redelivered, exchange, routingKey, identifier));
}
void AMQP_AllProxy::File::ack(uint64_t deliveryTag, bool multiple)
{
    send(FileAckBody(getVersion(), deliveryTag, multiple));
}
void AMQP_AllProxy::File::reject(uint64_t deliveryTag, bool requeue)
{
    send(FileRejectBody(getVersion(), deliveryTag, requeue));
}
void AMQP_AllProxy::Stream::qos(uint32_t prefetchSize, uint16_t prefetchCount, uint32_t consumeRate, bool global)
{
    send(StreamQosBody(getVersion(), prefetchSize, prefetchCount, consumeRate, global));
}
void AMQP_AllProxy::Stream::qosOk()
{
    send(StreamQosOkBody(getVersion()));
}
void AMQP_AllProxy::Stream::consume(const string& queue, const string& consumerTag, bool noLocal, bool exclusive, bool nowait, const FieldTable& arguments)
{
    send(StreamConsumeBody(getVersion(), queue, consumerTag, noLocal, exclusive, nowait, arguments));
}
void AMQP_AllProxy::Stream::consumeOk(const string& consumerTag)
{
    send(StreamConsumeOkBody(getVersion(), consumerTag));
}
void AMQP_AllProxy::Stream::cancel(const string& consumerTag)
{
    send(StreamCancelBody(getVersion(), consumerTag));
}
void AMQP_AllProxy::Stream::publish(const string& exchange, const string& routingKey, bool mandatory, bool immediate)
{
    send(StreamPublishBody(getVersion(), exchange, routingKey, mandatory, immediate));
}
void AMQP_AllProxy::Stream::return_(uint16_t replyCode, const string& replyText, const string& exchange, const string& routingKey)
{
    send(StreamReturnBody(getVersion(), replyCode, replyText, exchange, routingKey));
}
void AMQP_AllProxy::Stream::deliver(const string& consumerTag, uint64_t deliveryTag, const string& exchange, const string& queue)
{
    send(StreamDeliverBody(getVersion(), consumerTag, deliveryTag, exchange, queue));
}
void AMQP_AllProxy::Cluster::updateRequest(const string& url)
{
    send(ClusterUpdateRequestBody(getVersion(), url));
}
void AMQP_AllProxy::Cluster::updateOffer(uint64_t updatee, const Uuid& clusterId, uint32_t version)
{
    send(ClusterUpdateOfferBody(getVersion(), updatee, clusterId, version));
}
void AMQP_AllProxy::Cluster::retractOffer(uint64_t updatee)
{
    send(ClusterRetractOfferBody(getVersion(), updatee));
}
void AMQP_AllProxy::Cluster::ready(const string& url)
{
    send(ClusterReadyBody(getVersion(), url));
}
void AMQP_AllProxy::Cluster::configChange(const string& current)
{
    send(ClusterConfigChangeBody(getVersion(), current));
}
void AMQP_AllProxy::Cluster::messageExpired(uint64_t id)
{
    send(ClusterMessageExpiredBody(getVersion(), id));
}
void AMQP_AllProxy::Cluster::errorCheck(uint8_t type, const SequenceNumber& frameSeq)
{
    send(ClusterErrorCheckBody(getVersion(), type, frameSeq));
}
void AMQP_AllProxy::Cluster::shutdown()
{
    send(ClusterShutdownBody(getVersion()));
}
void AMQP_AllProxy::ClusterConnection::announce()
{
    send(ClusterConnectionAnnounceBody(getVersion()));
}
void AMQP_AllProxy::ClusterConnection::deliverClose()
{
    send(ClusterConnectionDeliverCloseBody(getVersion()));
}
void AMQP_AllProxy::ClusterConnection::deliverDoOutput(uint32_t limit)
{
    send(ClusterConnectionDeliverDoOutputBody(getVersion(), limit));
}
void AMQP_AllProxy::ClusterConnection::abort()
{
    send(ClusterConnectionAbortBody(getVersion()));
}
void AMQP_AllProxy::ClusterConnection::consumerState(const string& name, bool blocked, bool notifyEnabled)
{
    send(ClusterConnectionConsumerStateBody(getVersion(), name, blocked, notifyEnabled));
}
void AMQP_AllProxy::ClusterConnection::deliveryRecord(const string& queue, const SequenceNumber& position, const string& tag, const SequenceNumber& id, bool acquired, bool accepted, bool cancelled, bool completed, bool ended, bool windowing, bool enqueued, uint32_t credit)
{
    send(ClusterConnectionDeliveryRecordBody(getVersion(), queue, position, tag, id, acquired, accepted, cancelled, completed, ended, windowing, enqueued, credit));
}
void AMQP_AllProxy::ClusterConnection::txStart()
{
    send(ClusterConnectionTxStartBody(getVersion()));
}
void AMQP_AllProxy::ClusterConnection::txAccept(const SequenceSet& commands)
{
    send(ClusterConnectionTxAcceptBody(getVersion(), commands));
}
void AMQP_AllProxy::ClusterConnection::txDequeue(const string& queue)
{
    send(ClusterConnectionTxDequeueBody(getVersion(), queue));
}
void AMQP_AllProxy::ClusterConnection::txEnqueue(const string& queue)
{
    send(ClusterConnectionTxEnqueueBody(getVersion(), queue));
}
void AMQP_AllProxy::ClusterConnection::txPublish(const Array& queues, bool delivered)
{
    send(ClusterConnectionTxPublishBody(getVersion(), queues, delivered));
}
void AMQP_AllProxy::ClusterConnection::txEnd()
{
    send(ClusterConnectionTxEndBody(getVersion()));
}
void AMQP_AllProxy::ClusterConnection::accumulatedAck(const SequenceSet& commands)
{
    send(ClusterConnectionAccumulatedAckBody(getVersion(), commands));
}
void AMQP_AllProxy::ClusterConnection::sessionState(const SequenceNumber& replayStart, const SequenceNumber& commandPoint, const SequenceSet& sentIncomplete, const SequenceNumber& expected, const SequenceNumber& received, const SequenceSet& unknownCompleted, const SequenceSet& receivedIncomplete)
{
    send(ClusterConnectionSessionStateBody(getVersion(), replayStart, commandPoint, sentIncomplete, expected, received, unknownCompleted, receivedIncomplete));
}
void AMQP_AllProxy::ClusterConnection::shadowReady(uint64_t memberId, uint64_t connectionId, const string& userName, const string& fragment, uint32_t sendMax)
{
    send(ClusterConnectionShadowReadyBody(getVersion(), memberId, connectionId, userName, fragment, sendMax));
}
void AMQP_AllProxy::ClusterConnection::membership(const FieldTable& joiners, const FieldTable& members, const SequenceNumber& frameSeq)
{
    send(ClusterConnectionMembershipBody(getVersion(), joiners, members, frameSeq));
}
void AMQP_AllProxy::ClusterConnection::retractOffer()
{
    send(ClusterConnectionRetractOfferBody(getVersion()));
}
void AMQP_AllProxy::ClusterConnection::queuePosition(const string& queue, const SequenceNumber& position)
{
    send(ClusterConnectionQueuePositionBody(getVersion(), queue, position));
}
void AMQP_AllProxy::ClusterConnection::exchange(const string& encoded)
{
    send(ClusterConnectionExchangeBody(getVersion(), encoded));
}
void AMQP_AllProxy::ClusterConnection::queue(const string& encoded)
{
    send(ClusterConnectionQueueBody(getVersion(), encoded));
}
void AMQP_AllProxy::ClusterConnection::expiryId(uint64_t expiryId)
{
    send(ClusterConnectionExpiryIdBody(getVersion(), expiryId));
}
void AMQP_AllProxy::ClusterConnection::addQueueListener(const string& queue, uint32_t consumer)
{
    send(ClusterConnectionAddQueueListenerBody(getVersion(), queue, consumer));
}

}} // namespace qpid::framing

