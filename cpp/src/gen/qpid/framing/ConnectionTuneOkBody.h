#ifndef QPID_FRAMING_CONNECTIONTUNEOKBODY_H
#define QPID_FRAMING_CONNECTIONTUNEOKBODY_H
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


#include "qpid/framing/AMQMethodBody.h"
#include "qpid/framing/AMQP_ServerOperations.h"
#include "qpid/framing/MethodBodyConstVisitor.h"

#include <ostream>
#include "qpid/framing/amqp_types_full.h"

namespace qpid {
namespace framing {

class ConnectionTuneOkBody : public AMQMethodBody {
    uint16_t channelMax;
    uint16_t maxFrameSize;
    uint16_t heartbeat;
    uint16_t flags;
public:
    static const ClassId CLASS_ID = 0x1;
    static const MethodId METHOD_ID = 0x6;
    ConnectionTuneOkBody(
        ProtocolVersion, uint16_t _channelMax,
        uint16_t _maxFrameSize,
        uint16_t _heartbeat) : 
        channelMax(_channelMax),
        maxFrameSize(_maxFrameSize),
        heartbeat(_heartbeat),
        flags(0){
        flags |= (1 << 8);
        flags |= (1 << 9);
        flags |= (1 << 10);
    }
    ConnectionTuneOkBody(ProtocolVersion=ProtocolVersion())  : channelMax(0), maxFrameSize(0), heartbeat(0), flags(0) {}
    
    void setChannelMax(uint16_t _channelMax);
    uint16_t getChannelMax() const;
    bool hasChannelMax() const;
    void clearChannelMaxFlag();
    void setMaxFrameSize(uint16_t _maxFrameSize);
    uint16_t getMaxFrameSize() const;
    bool hasMaxFrameSize() const;
    void clearMaxFrameSizeFlag();
    void setHeartbeat(uint16_t _heartbeat);
    uint16_t getHeartbeat() const;
    bool hasHeartbeat() const;
    void clearHeartbeatFlag();
virtual uint8_t type() const { return 0;/*control segment*/ }
    typedef void ResultType;

    template <class T> ResultType invoke(T& invocable) const {
        return invocable.tuneOk(getChannelMax(), getMaxFrameSize(), getHeartbeat());
    }

    using  AMQMethodBody::accept;
    void accept(MethodBodyConstVisitor& v) const { v.visit(*this); }
    boost::intrusive_ptr<AMQBody> clone() const { return BodyFactory::copy(*this); }

    ClassId amqpClassId() const { return CLASS_ID; }
    MethodId amqpMethodId() const { return METHOD_ID; }
    bool isContentBearing() const { return  false; }
    bool resultExpected() const { return  false; }
    bool responseExpected() const { return  false; }
    void encode(Buffer&) const;
    void decode(Buffer&, uint32_t=0);
    void encodeStructBody(Buffer&) const;
    void decodeStructBody(Buffer&, uint32_t=0);
    uint32_t encodedSize() const;
    uint32_t bodySize() const;
    void print(std::ostream& out) const;
}; /* class ConnectionTuneOkBody */

}}
#endif  /*!QPID_FRAMING_CONNECTIONTUNEOKBODY_H*/
