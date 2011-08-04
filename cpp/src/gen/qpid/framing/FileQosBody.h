#ifndef QPID_FRAMING_FILEQOSBODY_H
#define QPID_FRAMING_FILEQOSBODY_H
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

class FileQosBody : public ModelMethod {
    uint32_t prefetchSize;
    uint16_t prefetchCount;
    uint16_t flags;
public:
    static const ClassId CLASS_ID = 0x9;
    static const MethodId METHOD_ID = 0x1;
    FileQosBody(
        ProtocolVersion, uint32_t _prefetchSize,
        uint16_t _prefetchCount,
        bool _global) : 
        prefetchSize(_prefetchSize),
        prefetchCount(_prefetchCount),
        flags(0){
        setGlobal(_global);
        flags |= (1 << 8);
        flags |= (1 << 9);
    }
    FileQosBody(ProtocolVersion=ProtocolVersion())  : prefetchSize(0), prefetchCount(0), flags(0) {}
    
    void setPrefetchSize(uint32_t _prefetchSize);
    uint32_t getPrefetchSize() const;
    bool hasPrefetchSize() const;
    void clearPrefetchSizeFlag();
    void setPrefetchCount(uint16_t _prefetchCount);
    uint16_t getPrefetchCount() const;
    bool hasPrefetchCount() const;
    void clearPrefetchCountFlag();
    void setGlobal(bool _global);
    bool getGlobal() const;
    typedef void ResultType;

    template <class T> ResultType invoke(T& invocable) const {
        return invocable.qos(getPrefetchSize(), getPrefetchCount(), getGlobal());
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
}; /* class FileQosBody */

}}
#endif  /*!QPID_FRAMING_FILEQOSBODY_H*/
