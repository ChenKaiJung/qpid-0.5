#ifndef QPID_FRAMING_CLUSTERCONNECTIONSHADOWREADYBODY_H
#define QPID_FRAMING_CLUSTERCONNECTIONSHADOWREADYBODY_H
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

class ClusterConnectionShadowReadyBody : public ModelMethod {
    uint64_t memberId;
    uint64_t connectionId;
    string userName;
    string fragment;
    uint16_t flags;
public:
    static const ClassId CLASS_ID = 0x81;
    static const MethodId METHOD_ID = 0x20;
    ClusterConnectionShadowReadyBody(
        ProtocolVersion, uint64_t _memberId,
        uint64_t _connectionId,
        const string& _userName,
        const string& _fragment) : 
        memberId(_memberId),
        connectionId(_connectionId),
        userName(_userName),
        fragment(_fragment),
        flags(0){
        flags |= (1 << 8);
        flags |= (1 << 9);
        flags |= (1 << 10);
        flags |= (1 << 11);
    }
    ClusterConnectionShadowReadyBody(ProtocolVersion=ProtocolVersion())  : memberId(0), connectionId(0), flags(0) {}
    
    void setMemberId(uint64_t _memberId);
    uint64_t getMemberId() const;
    bool hasMemberId() const;
    void clearMemberIdFlag();
    void setConnectionId(uint64_t _connectionId);
    uint64_t getConnectionId() const;
    bool hasConnectionId() const;
    void clearConnectionIdFlag();
    void setUserName(const string& _userName);
    const string& getUserName() const;
    bool hasUserName() const;
    void clearUserNameFlag();
    void setFragment(const string& _fragment);
    const string& getFragment() const;
    bool hasFragment() const;
    void clearFragmentFlag();
    typedef void ResultType;

    template <class T> ResultType invoke(T& invocable) const {
        return invocable.shadowReady(getMemberId(), getConnectionId(), getUserName(), getFragment());
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
}; /* class ClusterConnectionShadowReadyBody */

}}
#endif  /*!QPID_FRAMING_CLUSTERCONNECTIONSHADOWREADYBODY_H*/
