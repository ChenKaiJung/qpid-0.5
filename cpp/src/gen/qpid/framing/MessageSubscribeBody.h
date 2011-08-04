#ifndef QPID_FRAMING_MESSAGESUBSCRIBEBODY_H
#define QPID_FRAMING_MESSAGESUBSCRIBEBODY_H
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
#include "qpid/framing/ModelMethod.h"

#include <ostream>
#include "qpid/framing/amqp_types_full.h"

namespace qpid {
namespace framing {

class MessageSubscribeBody : public ModelMethod {
    string queue;
    string destination;
    uint8_t acceptMode;
    uint8_t acquireMode;
    string resumeId;
    uint64_t resumeTtl;
    FieldTable arguments;
    uint16_t flags;
public:
    static const ClassId CLASS_ID = 0x4;
    static const MethodId METHOD_ID = 0x7;
    MessageSubscribeBody(
        ProtocolVersion, const string& _queue,
        const string& _destination,
        uint8_t _acceptMode,
        uint8_t _acquireMode,
        bool _exclusive,
        const string& _resumeId,
        uint64_t _resumeTtl,
        const FieldTable& _arguments) : 
        queue(_queue),
        destination(_destination),
        acceptMode(_acceptMode),
        acquireMode(_acquireMode),
        resumeId(_resumeId),
        resumeTtl(_resumeTtl),
        arguments(_arguments),
        flags(0){
        setExclusive(_exclusive);
        flags |= (1 << 8);
        flags |= (1 << 9);
        flags |= (1 << 10);
        flags |= (1 << 11);
        flags |= (1 << 13);
        flags |= (1 << 14);
        flags |= (1 << 15);
    }
    MessageSubscribeBody(ProtocolVersion=ProtocolVersion())  : acceptMode(0), acquireMode(0), resumeTtl(0), flags(0) {}
    
    void setQueue(const string& _queue);
    const string& getQueue() const;
    bool hasQueue() const;
    void clearQueueFlag();
    void setDestination(const string& _destination);
    const string& getDestination() const;
    bool hasDestination() const;
    void clearDestinationFlag();
    void setAcceptMode(uint8_t _acceptMode);
    uint8_t getAcceptMode() const;
    bool hasAcceptMode() const;
    void clearAcceptModeFlag();
    void setAcquireMode(uint8_t _acquireMode);
    uint8_t getAcquireMode() const;
    bool hasAcquireMode() const;
    void clearAcquireModeFlag();
    void setExclusive(bool _exclusive);
    bool getExclusive() const;
    void setResumeId(const string& _resumeId);
    const string& getResumeId() const;
    bool hasResumeId() const;
    void clearResumeIdFlag();
    void setResumeTtl(uint64_t _resumeTtl);
    uint64_t getResumeTtl() const;
    bool hasResumeTtl() const;
    void clearResumeTtlFlag();
    void setArguments(const FieldTable& _arguments);
    const FieldTable& getArguments() const;
    FieldTable& getArguments();
    bool hasArguments() const;
    void clearArgumentsFlag();
    typedef void ResultType;

    template <class T> ResultType invoke(T& invocable) const {
        return invocable.subscribe(getQueue(), getDestination(), getAcceptMode(), getAcquireMode(), getExclusive(), getResumeId(), getResumeTtl(), getArguments());
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
}; /* class MessageSubscribeBody */

}}
#endif  /*!QPID_FRAMING_MESSAGESUBSCRIBEBODY_H*/
