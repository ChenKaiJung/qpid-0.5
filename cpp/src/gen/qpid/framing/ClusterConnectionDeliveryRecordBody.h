#ifndef QPID_FRAMING_CLUSTERCONNECTIONDELIVERYRECORDBODY_H
#define QPID_FRAMING_CLUSTERCONNECTIONDELIVERYRECORDBODY_H
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

class ClusterConnectionDeliveryRecordBody : public ModelMethod {
    string queue;
    SequenceNumber position;
    string tag;
    SequenceNumber id;
    uint32_t credit;
    uint16_t flags;
public:
    static const ClassId CLASS_ID = 0x81;
    static const MethodId METHOD_ID = 0x11;
    ClusterConnectionDeliveryRecordBody(
        ProtocolVersion, const string& _queue,
        const SequenceNumber& _position,
        const string& _tag,
        const SequenceNumber& _id,
        bool _acquired,
        bool _accepted,
        bool _cancelled,
        bool _completed,
        bool _ended,
        bool _windowing,
        bool _enqueued,
        uint32_t _credit) : 
        queue(_queue),
        position(_position),
        tag(_tag),
        id(_id),
        credit(_credit),
        flags(0){
        setAcquired(_acquired);
        setAccepted(_accepted);
        setCancelled(_cancelled);
        setCompleted(_completed);
        setEnded(_ended);
        setWindowing(_windowing);
        setEnqueued(_enqueued);
        flags |= (1 << 8);
        flags |= (1 << 9);
        flags |= (1 << 10);
        flags |= (1 << 11);
        flags |= (1 << 3);
    }
    ClusterConnectionDeliveryRecordBody(ProtocolVersion=ProtocolVersion())  : credit(0), flags(0) {}
    
    void setQueue(const string& _queue);
    const string& getQueue() const;
    bool hasQueue() const;
    void clearQueueFlag();
    void setPosition(const SequenceNumber& _position);
    SequenceNumber getPosition() const;
    bool hasPosition() const;
    void clearPositionFlag();
    void setTag(const string& _tag);
    const string& getTag() const;
    bool hasTag() const;
    void clearTagFlag();
    void setId(const SequenceNumber& _id);
    SequenceNumber getId() const;
    bool hasId() const;
    void clearIdFlag();
    void setAcquired(bool _acquired);
    bool getAcquired() const;
    void setAccepted(bool _accepted);
    bool getAccepted() const;
    void setCancelled(bool _cancelled);
    bool getCancelled() const;
    void setCompleted(bool _completed);
    bool getCompleted() const;
    void setEnded(bool _ended);
    bool getEnded() const;
    void setWindowing(bool _windowing);
    bool getWindowing() const;
    void setEnqueued(bool _enqueued);
    bool getEnqueued() const;
    void setCredit(uint32_t _credit);
    uint32_t getCredit() const;
    bool hasCredit() const;
    void clearCreditFlag();
    typedef void ResultType;

    template <class T> ResultType invoke(T& invocable) const {
        return invocable.deliveryRecord(getQueue(), getPosition(), getTag(), getId(), getAcquired(), getAccepted(), getCancelled(), getCompleted(), getEnded(), getWindowing(), getEnqueued(), getCredit());
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
}; /* class ClusterConnectionDeliveryRecordBody */

}}
#endif  /*!QPID_FRAMING_CLUSTERCONNECTIONDELIVERYRECORDBODY_H*/
