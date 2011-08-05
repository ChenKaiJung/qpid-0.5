#ifndef QPID_FRAMING_AMQP_ALLPROXY_H
#define QPID_FRAMING_AMQP_ALLPROXY_H
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


#include "qpid/framing/Proxy.h"
#include "qpid/framing/Array.h"
#include "qpid/framing/amqp_types.h"
#include "qpid/framing/amqp_structs.h"

namespace qpid {
namespace framing {

class AMQP_AllProxy:
    public Proxy
{
  public:
    AMQP_AllProxy(FrameHandler& out);
    
    class Connection:
        public Proxy
    {
        public:
        Connection(FrameHandler& f) : Proxy(f) {}
        static Connection& get(AMQP_AllProxy& proxy) { return proxy.getConnection(); }
        virtual void start(const FieldTable& serverProperties,
                    const Array& mechanisms,
                    const Array& locales);
        
        virtual void startOk(const FieldTable& clientProperties,
                    const string& mechanism,
                    const string& response,
                    const string& locale);
        
        virtual void secure(const string& challenge);
        
        virtual void secureOk(const string& response);
        
        virtual void tune(uint16_t channelMax,
                    uint16_t maxFrameSize,
                    uint16_t heartbeatMin,
                    uint16_t heartbeatMax);
        
        virtual void tuneOk(uint16_t channelMax,
                    uint16_t maxFrameSize,
                    uint16_t heartbeat);
        
        virtual void open(const string& virtualHost,
                    const Array& capabilities,
                    bool insist);
        
        virtual void openOk(const Array& knownHosts);
        
        virtual void redirect(const string& host,
                    const Array& knownHosts);
        
        virtual void heartbeat();
        
        virtual void close(uint16_t replyCode,
                    const string& replyText);
        
        virtual void closeOk();
        
    };
    
    Connection& getConnection() { return connectionProxy; }
    
    class Session:
        public Proxy
    {
        public:
        Session(FrameHandler& f) : Proxy(f) {}
        static Session& get(AMQP_AllProxy& proxy) { return proxy.getSession(); }
        virtual void attach(const string& name,
                    bool force);
        
        virtual void attached(const string& name);
        
        virtual void detach(const string& name);
        
        virtual void detached(const string& name,
                    uint8_t code);
        
        virtual void requestTimeout(uint32_t timeout);
        
        virtual void timeout(uint32_t timeout);
        
        virtual void commandPoint(const SequenceNumber& commandId,
                    uint64_t commandOffset);
        
        virtual void expected(const SequenceSet& commands,
                    const Array& fragments);
        
        virtual void confirmed(const SequenceSet& commands,
                    const Array& fragments);
        
        virtual void completed(const SequenceSet& commands,
                    bool timelyReply);
        
        virtual void knownCompleted(const SequenceSet& commands);
        
        virtual void flush(bool expected,
                    bool confirmed,
                    bool completed);
        
        virtual void gap(const SequenceSet& commands);
        
    };
    
    Session& getSession() { return sessionProxy; }
    
    class Execution:
        public Proxy
    {
        public:
        Execution(FrameHandler& f) : Proxy(f) {}
        static Execution& get(AMQP_AllProxy& proxy) { return proxy.getExecution(); }
        virtual void sync();
        
        virtual void result(const SequenceNumber& commandId,
                    const string& value);
        
        virtual void exception(uint16_t errorCode,
                    const SequenceNumber& commandId,
                    uint8_t classCode,
                    uint8_t commandCode,
                    uint8_t fieldIndex,
                    const string& description,
                    const FieldTable& errorInfo);
        
    };
    
    Execution& getExecution() { return executionProxy; }
    
    class Message:
        public Proxy
    {
        public:
        Message(FrameHandler& f) : Proxy(f) {}
        static Message& get(AMQP_AllProxy& proxy) { return proxy.getMessage(); }
        virtual void transfer(const string& destination,
                    uint8_t acceptMode,
                    uint8_t acquireMode);
        
        virtual void accept(const SequenceSet& transfers);
        
        virtual void reject(const SequenceSet& transfers,
                    uint16_t code,
                    const string& text);
        
        virtual void release(const SequenceSet& transfers,
                    bool setRedelivered);
        
        virtual void acquire(const SequenceSet& transfers);
        
        virtual void resume(const string& destination,
                    const string& resumeId);
        
        virtual void subscribe(const string& queue,
                    const string& destination,
                    uint8_t acceptMode,
                    uint8_t acquireMode,
                    bool exclusive,
                    const string& resumeId,
                    uint64_t resumeTtl,
                    const FieldTable& arguments);
        
        virtual void cancel(const string& destination);
        
        virtual void setFlowMode(const string& destination,
                    uint8_t flowMode);
        
        virtual void flow(const string& destination,
                    uint8_t unit,
                    uint32_t value);
        
        virtual void flush(const string& destination);
        
        virtual void stop(const string& destination);
        
    };
    
    Message& getMessage() { return messageProxy; }
    
    class Tx:
        public Proxy
    {
        public:
        Tx(FrameHandler& f) : Proxy(f) {}
        static Tx& get(AMQP_AllProxy& proxy) { return proxy.getTx(); }
        virtual void select();
        
        virtual void commit();
        
        virtual void rollback();
        
    };
    
    Tx& getTx() { return txProxy; }
    
    class Dtx:
        public Proxy
    {
        public:
        Dtx(FrameHandler& f) : Proxy(f) {}
        static Dtx& get(AMQP_AllProxy& proxy) { return proxy.getDtx(); }
        virtual void select();
        
        virtual void start(const Xid& xid,
                    bool join,
                    bool resume);
        
        virtual void end(const Xid& xid,
                    bool fail,
                    bool suspend);
        
        virtual void commit(const Xid& xid,
                    bool onePhase);
        
        virtual void forget(const Xid& xid);
        
        virtual void getTimeout(const Xid& xid);
        
        virtual void prepare(const Xid& xid);
        
        virtual void recover();
        
        virtual void rollback(const Xid& xid);
        
        virtual void setTimeout(const Xid& xid,
                    uint32_t timeout);
        
    };
    
    Dtx& getDtx() { return dtxProxy; }
    
    class Exchange:
        public Proxy
    {
        public:
        Exchange(FrameHandler& f) : Proxy(f) {}
        static Exchange& get(AMQP_AllProxy& proxy) { return proxy.getExchange(); }
        virtual void declare(const string& exchange,
                    const string& type,
                    const string& alternateExchange,
                    bool passive,
                    bool durable,
                    bool autoDelete,
                    const FieldTable& arguments);
        
        virtual void delete_(const string& exchange,
                    bool ifUnused);
        
        virtual void query(const string& name);
        
        virtual void bind(const string& queue,
                    const string& exchange,
                    const string& bindingKey,
                    const FieldTable& arguments);
        
        virtual void unbind(const string& queue,
                    const string& exchange,
                    const string& bindingKey);
        
        virtual void bound(const string& exchange,
                    const string& queue,
                    const string& bindingKey,
                    const FieldTable& arguments);
        
    };
    
    Exchange& getExchange() { return exchangeProxy; }
    
    class Queue:
        public Proxy
    {
        public:
        Queue(FrameHandler& f) : Proxy(f) {}
        static Queue& get(AMQP_AllProxy& proxy) { return proxy.getQueue(); }
        virtual void declare(const string& queue,
                    const string& alternateExchange,
                    bool passive,
                    bool durable,
                    bool exclusive,
                    bool autoDelete,
                    const FieldTable& arguments);
        
        virtual void delete_(const string& queue,
                    bool ifUnused,
                    bool ifEmpty);
        
        virtual void purge(const string& queue);
        
        virtual void query(const string& queue);
        
    };
    
    Queue& getQueue() { return queueProxy; }
    
    class File:
        public Proxy
    {
        public:
        File(FrameHandler& f) : Proxy(f) {}
        static File& get(AMQP_AllProxy& proxy) { return proxy.getFile(); }
        virtual void qos(uint32_t prefetchSize,
                    uint16_t prefetchCount,
                    bool global);
        
        virtual void qosOk();
        
        virtual void consume(const string& queue,
                    const string& consumerTag,
                    bool noLocal,
                    bool noAck,
                    bool exclusive,
                    bool nowait,
                    const FieldTable& arguments);
        
        virtual void consumeOk(const string& consumerTag);
        
        virtual void cancel(const string& consumerTag);
        
        virtual void open(const string& identifier,
                    uint64_t contentSize);
        
        virtual void openOk(uint64_t stagedSize);
        
        virtual void stage();
        
        virtual void publish(const string& exchange,
                    const string& routingKey,
                    bool mandatory,
                    bool immediate,
                    const string& identifier);
        
        virtual void return_(uint16_t replyCode,
                    const string& replyText,
                    const string& exchange,
                    const string& routingKey);
        
        virtual void deliver(const string& consumerTag,
                    uint64_t deliveryTag,
                    bool redelivered,
                    const string& exchange,
                    const string& routingKey,
                    const string& identifier);
        
        virtual void ack(uint64_t deliveryTag,
                    bool multiple);
        
        virtual void reject(uint64_t deliveryTag,
                    bool requeue);
        
    };
    
    File& getFile() { return fileProxy; }
    
    class Stream:
        public Proxy
    {
        public:
        Stream(FrameHandler& f) : Proxy(f) {}
        static Stream& get(AMQP_AllProxy& proxy) { return proxy.getStream(); }
        virtual void qos(uint32_t prefetchSize,
                    uint16_t prefetchCount,
                    uint32_t consumeRate,
                    bool global);
        
        virtual void qosOk();
        
        virtual void consume(const string& queue,
                    const string& consumerTag,
                    bool noLocal,
                    bool exclusive,
                    bool nowait,
                    const FieldTable& arguments);
        
        virtual void consumeOk(const string& consumerTag);
        
        virtual void cancel(const string& consumerTag);
        
        virtual void publish(const string& exchange,
                    const string& routingKey,
                    bool mandatory,
                    bool immediate);
        
        virtual void return_(uint16_t replyCode,
                    const string& replyText,
                    const string& exchange,
                    const string& routingKey);
        
        virtual void deliver(const string& consumerTag,
                    uint64_t deliveryTag,
                    const string& exchange,
                    const string& queue);
        
    };
    
    Stream& getStream() { return streamProxy; }
    
    class Cluster:
        public Proxy
    {
        public:
        Cluster(FrameHandler& f) : Proxy(f) {}
        static Cluster& get(AMQP_AllProxy& proxy) { return proxy.getCluster(); }
        virtual void updateRequest(const string& url);
        
        virtual void updateOffer(uint64_t updatee,
                    const Uuid& clusterId,
                    uint32_t version);
        
        virtual void retractOffer(uint64_t updatee);
        
        virtual void ready(const string& url);
        
        virtual void configChange(const string& current);
        
        virtual void messageExpired(uint64_t id);
        
        virtual void errorCheck(uint8_t type,
                    const SequenceNumber& frameSeq);
        
        virtual void shutdown();
        
    };
    
    Cluster& getCluster() { return clusterProxy; }
    
    class ClusterConnection:
        public Proxy
    {
        public:
        ClusterConnection(FrameHandler& f) : Proxy(f) {}
        static ClusterConnection& get(AMQP_AllProxy& proxy) { return proxy.getClusterConnection(); }
        virtual void announce();
        
        virtual void deliverClose();
        
        virtual void deliverDoOutput(uint32_t limit);
        
        virtual void abort();
        
        virtual void consumerState(const string& name,
                    bool blocked,
                    bool notifyEnabled);
        
        virtual void deliveryRecord(const string& queue,
                    const SequenceNumber& position,
                    const string& tag,
                    const SequenceNumber& id,
                    bool acquired,
                    bool accepted,
                    bool cancelled,
                    bool completed,
                    bool ended,
                    bool windowing,
                    bool enqueued,
                    uint32_t credit);
        
        virtual void txStart();
        
        virtual void txAccept(const SequenceSet& commands);
        
        virtual void txDequeue(const string& queue);
        
        virtual void txEnqueue(const string& queue);
        
        virtual void txPublish(const Array& queues,
                    bool delivered);
        
        virtual void txEnd();
        
        virtual void accumulatedAck(const SequenceSet& commands);
        
        virtual void sessionState(const SequenceNumber& replayStart,
                    const SequenceNumber& commandPoint,
                    const SequenceSet& sentIncomplete,
                    const SequenceNumber& expected,
                    const SequenceNumber& received,
                    const SequenceSet& unknownCompleted,
                    const SequenceSet& receivedIncomplete);
        
        virtual void shadowReady(uint64_t memberId,
                    uint64_t connectionId,
                    const string& userName,
                    const string& fragment,
                    uint32_t sendMax);
        
        virtual void membership(const FieldTable& joiners,
                    const FieldTable& members,
                    const SequenceNumber& frameSeq);
        
        virtual void retractOffer();
        
        virtual void queuePosition(const string& queue,
                    const SequenceNumber& position);
        
        virtual void exchange(const string& encoded);
        
        virtual void queue(const string& encoded);
        
        virtual void expiryId(uint64_t expiryId);
        
        virtual void addQueueListener(const string& queue,
                    uint32_t consumer);
        
    };
    
    ClusterConnection& getClusterConnection() { return clusterConnectionProxy; }
    
  private:
    Connection connectionProxy;
    Session sessionProxy;
    Execution executionProxy;
    Message messageProxy;
    Tx txProxy;
    Dtx dtxProxy;
    Exchange exchangeProxy;
    Queue queueProxy;
    File fileProxy;
    Stream streamProxy;
    Cluster clusterProxy;
    ClusterConnection clusterConnectionProxy;
};

}} // namespace qpid::framing

#endif  /*!QPID_FRAMING_AMQP_ALLPROXY_H*/
