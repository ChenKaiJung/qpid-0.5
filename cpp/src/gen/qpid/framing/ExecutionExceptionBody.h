#ifndef QPID_FRAMING_EXECUTIONEXCEPTIONBODY_H
#define QPID_FRAMING_EXECUTIONEXCEPTIONBODY_H
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

class ExecutionExceptionBody : public ModelMethod {
    uint16_t errorCode;
    SequenceNumber commandId;
    uint8_t classCode;
    uint8_t commandCode;
    uint8_t fieldIndex;
    string description;
    FieldTable errorInfo;
    uint16_t flags;
public:
    static const ClassId CLASS_ID = 0x3;
    static const MethodId METHOD_ID = 0x3;
    ExecutionExceptionBody(
        ProtocolVersion, uint16_t _errorCode,
        const SequenceNumber& _commandId,
        uint8_t _classCode,
        uint8_t _commandCode,
        uint8_t _fieldIndex,
        const string& _description,
        const FieldTable& _errorInfo) : 
        errorCode(_errorCode),
        commandId(_commandId),
        classCode(_classCode),
        commandCode(_commandCode),
        fieldIndex(_fieldIndex),
        description(_description),
        errorInfo(_errorInfo),
        flags(0){
        flags |= (1 << 8);
        flags |= (1 << 9);
        flags |= (1 << 10);
        flags |= (1 << 11);
        flags |= (1 << 12);
        flags |= (1 << 13);
        flags |= (1 << 14);
    }
    ExecutionExceptionBody(ProtocolVersion=ProtocolVersion())  : errorCode(0), classCode(0), commandCode(0), fieldIndex(0), flags(0) {}
    
    void setErrorCode(uint16_t _errorCode);
    uint16_t getErrorCode() const;
    bool hasErrorCode() const;
    void clearErrorCodeFlag();
    void setCommandId(const SequenceNumber& _commandId);
    SequenceNumber getCommandId() const;
    bool hasCommandId() const;
    void clearCommandIdFlag();
    void setClassCode(uint8_t _classCode);
    uint8_t getClassCode() const;
    bool hasClassCode() const;
    void clearClassCodeFlag();
    void setCommandCode(uint8_t _commandCode);
    uint8_t getCommandCode() const;
    bool hasCommandCode() const;
    void clearCommandCodeFlag();
    void setFieldIndex(uint8_t _fieldIndex);
    uint8_t getFieldIndex() const;
    bool hasFieldIndex() const;
    void clearFieldIndexFlag();
    void setDescription(const string& _description);
    const string& getDescription() const;
    bool hasDescription() const;
    void clearDescriptionFlag();
    void setErrorInfo(const FieldTable& _errorInfo);
    const FieldTable& getErrorInfo() const;
    FieldTable& getErrorInfo();
    bool hasErrorInfo() const;
    void clearErrorInfoFlag();
    typedef void ResultType;

    template <class T> ResultType invoke(T& invocable) const {
        return invocable.exception(getErrorCode(), getCommandId(), getClassCode(), getCommandCode(), getFieldIndex(), getDescription(), getErrorInfo());
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
}; /* class ExecutionExceptionBody */

}}
#endif  /*!QPID_FRAMING_EXECUTIONEXCEPTIONBODY_H*/
