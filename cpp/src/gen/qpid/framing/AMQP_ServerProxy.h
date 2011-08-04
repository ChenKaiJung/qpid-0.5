#ifndef QPID_FRAMING_AMQP_SERVERPROXY_H
#define QPID_FRAMING_AMQP_SERVERPROXY_H
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

class AMQP_ServerProxy:
    public Proxy
{
  public:
    AMQP_ServerProxy(FrameHandler& out);
    
    class Connection:
        public Proxy
    {
        public:
        Connection(FrameHandler& f) : Proxy(f) {}
        static Connection& get(AMQP_ServerProxy& proxy) { return proxy.getConnection(); }
        virtual void startOk(const FieldTable& clientProperties,
                    const string& mechanism,
                    const string& response,
                    const string& locale);
        
        virtual void secureOk(const string& response);
        
        virtual void tuneOk(uint16_t channelMax,
                    uint16_t maxFrameSize,
                    uint16_t heartbeat);
        
        virtual void open(const string& virtualHost,
                    const Array& capabilities,
                    bool insist);
        
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
        static Session& get(AMQP_ServerProxy& proxy) { return proxy.getSession(); }
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
        static Execution& get(AMQP_ServerProxy& proxy) { return proxy.getExecution(); }
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
        static Message& get(AMQP_ServerProxy& proxy) { return proxy.getMessage(); }
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
        static Tx& get(AMQP_ServerProxy& proxy) { return proxy.getTx(); }
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
        static Dtx& get(AMQP_ServerProxy& proxy) { return proxy.getDtx(); }
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
        static Exchange& get(AMQP_ServerProxy& proxy) { return proxy.getExchange(); }
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
        static Queue& get(AMQP_ServerProxy& proxy) { return proxy.getQueue(); }
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
        static File& get(AMQP_ServerProxy& proxy) { return proxy.getFile(); }
        virtual void qos(uint32_t prefetchSize,
                    uint16_t prefetchCount,
                    bool global);
        
        virtual void consume(const string& queue,
                    const string& consumerTag,
                    bool noLocal,
                    bool noAck,
                    bool exclusive,
                    bool nowait,
                    const FieldTable& arguments);
        
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
        static Stream& get(AMQP_ServerProxy& proxy) { return proxy.getStream(); }
        virtual void qos(uint32_t prefetchSize,
                    uint16_t prefetchCount,
                    uint32_t consumeRate,
                    bool global);
        
        virtual void consume(const string& queue,
                    const string& consumerTag,
                    bool noLocal,
                    bool exclusive,
                    bool nowait,
                    const FieldTable& arguments);
        
        virtual void cancel(const string& consumerTag);
        
        virtual void publish(const string& exchange,
                    const string& routingKey,
                    bool mandatory,
                    bool immediate);
        
    };
    
    Stream& getStream() { return streamProxy; }
    
    class Cluster:
        public Proxy
    {
        public:
        Cluster(FrameHandler& f) : Proxy(f) {}
        static Cluster& get(AMQP_ServerProxy& proxy) { return proxy.getCluster(); }
    };
    
    Cluster& getCluster() { return clusterProxy; }
    
    class ClusterConnection:
        public Proxy
    {
        public:
        ClusterConnection(FrameHandler& f) : Proxy(f) {}
        static ClusterConnection& get(AMQP_ServerProxy& proxy) { return proxy.getClusterConnection(); }
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

#endif  /*!QPID_FRAMING_AMQP_SERVERPROXY_H*/
