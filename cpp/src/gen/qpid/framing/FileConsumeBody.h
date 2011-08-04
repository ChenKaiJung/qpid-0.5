#ifndef QPID_FRAMING_FILECONSUMEBODY_H
#define QPID_FRAMING_FILECONSUMEBODY_H
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

class FileConsumeBody : public ModelMethod {
    string queue;
    string consumerTag;
    FieldTable arguments;
    uint16_t flags;
public:
    static const ClassId CLASS_ID = 0x9;
    static const MethodId METHOD_ID = 0x3;
    FileConsumeBody(
        ProtocolVersion, const string& _queue,
        const string& _consumerTag,
        bool _noLocal,
        bool _noAck,
        bool _exclusive,
        bool _nowait,
        const FieldTable& _arguments) : 
        queue(_queue),
        consumerTag(_consumerTag),
        arguments(_arguments),
        flags(0){
        setNoLocal(_noLocal);
        setNoAck(_noAck);
        setExclusive(_exclusive);
        setNowait(_nowait);
        flags |= (1 << 8);
        flags |= (1 << 9);
        flags |= (1 << 14);
    }
    FileConsumeBody(ProtocolVersion=ProtocolVersion())  : flags(0) {}
    
    void setQueue(const string& _queue);
    const string& getQueue() const;
    bool hasQueue() const;
    void clearQueueFlag();
    void setConsumerTag(const string& _consumerTag);
    const string& getConsumerTag() const;
    bool hasConsumerTag() const;
    void clearConsumerTagFlag();
    void setNoLocal(bool _noLocal);
    bool getNoLocal() const;
    void setNoAck(bool _noAck);
    bool getNoAck() const;
    void setExclusive(bool _exclusive);
    bool getExclusive() const;
    void setNowait(bool _nowait);
    bool getNowait() const;
    void setArguments(const FieldTable& _arguments);
    const FieldTable& getArguments() const;
    FieldTable& getArguments();
    bool hasArguments() const;
    void clearArgumentsFlag();
    typedef void ResultType;

    template <class T> ResultType invoke(T& invocable) const {
        return invocable.consume(getQueue(), getConsumerTag(), getNoLocal(), getNoAck(), getExclusive(), getNowait(), getArguments());
    }

    using  AMQMethodBody::accept;
    void accept(MethodBodyConstVisitor& v) const { v.visit(*this); }
    boost::intrusive_ptr<AMQBody> clone() const { return BodyFactory::copy(*this); }

    ClassId amqpClassId() const { return CLASS_ID; }
    MethodId amqpMethodId() const { return METHOD_ID; }
    bool isContentBearing() const { return  false; }
    bool resultExpected() const { return  false; }
    bool responseExpected() const { return  true; }
    void encode(Buffer&) const;
    void decode(Buffer&, uint32_t=0);
    void encodeStructBody(Buffer&) const;
    void decodeStructBody(Buffer&, uint32_t=0);
    uint32_t encodedSize() const;
    uint32_t bodySize() const;
    void print(std::ostream& out) const;
}; /* class FileConsumeBody */

}}
#endif  /*!QPID_FRAMING_FILECONSUMEBODY_H*/
