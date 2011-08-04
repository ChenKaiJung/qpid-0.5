#ifndef QPID_FRAMING_CONNECTIONSTARTOKBODY_H
#define QPID_FRAMING_CONNECTIONSTARTOKBODY_H
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

class ConnectionStartOkBody : public AMQMethodBody {
    FieldTable clientProperties;
    string mechanism;
    string response;
    string locale;
    uint16_t flags;
public:
    static const ClassId CLASS_ID = 0x1;
    static const MethodId METHOD_ID = 0x2;
    ConnectionStartOkBody(
        ProtocolVersion, const FieldTable& _clientProperties,
        const string& _mechanism,
        const string& _response,
        const string& _locale) : 
        clientProperties(_clientProperties),
        mechanism(_mechanism),
        response(_response),
        locale(_locale),
        flags(0){
        flags |= (1 << 8);
        flags |= (1 << 9);
        flags |= (1 << 10);
        flags |= (1 << 11);
    }
    ConnectionStartOkBody(ProtocolVersion=ProtocolVersion())  : flags(0) {}
    
    void setClientProperties(const FieldTable& _clientProperties);
    const FieldTable& getClientProperties() const;
    FieldTable& getClientProperties();
    bool hasClientProperties() const;
    void clearClientPropertiesFlag();
    void setMechanism(const string& _mechanism);
    const string& getMechanism() const;
    bool hasMechanism() const;
    void clearMechanismFlag();
    void setResponse(const string& _response);
    const string& getResponse() const;
    bool hasResponse() const;
    void clearResponseFlag();
    void setLocale(const string& _locale);
    const string& getLocale() const;
    bool hasLocale() const;
    void clearLocaleFlag();
virtual uint8_t type() const { return 0;/*control segment*/ }
    typedef void ResultType;

    template <class T> ResultType invoke(T& invocable) const {
        return invocable.startOk(getClientProperties(), getMechanism(), getResponse(), getLocale());
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
}; /* class ConnectionStartOkBody */

}}
#endif  /*!QPID_FRAMING_CONNECTIONSTARTOKBODY_H*/
