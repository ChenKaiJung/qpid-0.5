#ifndef QPID_FRAMING_CLUSTERCONNECTIONSESSIONSTATEBODY_H
#define QPID_FRAMING_CLUSTERCONNECTIONSESSIONSTATEBODY_H
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

class ClusterConnectionSessionStateBody : public ModelMethod {
    SequenceNumber replayStart;
    SequenceNumber commandPoint;
    SequenceSet sentIncomplete;
    SequenceNumber expected;
    SequenceNumber received;
    SequenceSet unknownCompleted;
    SequenceSet receivedIncomplete;
    uint16_t flags;
public:
    static const ClassId CLASS_ID = 0x81;
    static const MethodId METHOD_ID = 0x1F;
    ClusterConnectionSessionStateBody(
        ProtocolVersion, const SequenceNumber& _replayStart,
        const SequenceNumber& _commandPoint,
        const SequenceSet& _sentIncomplete,
        const SequenceNumber& _expected,
        const SequenceNumber& _received,
        const SequenceSet& _unknownCompleted,
        const SequenceSet& _receivedIncomplete) : 
        replayStart(_replayStart),
        commandPoint(_commandPoint),
        sentIncomplete(_sentIncomplete),
        expected(_expected),
        received(_received),
        unknownCompleted(_unknownCompleted),
        receivedIncomplete(_receivedIncomplete),
        flags(0){
        flags |= (1 << 8);
        flags |= (1 << 9);
        flags |= (1 << 10);
        flags |= (1 << 11);
        flags |= (1 << 12);
        flags |= (1 << 13);
        flags |= (1 << 14);
    }
    ClusterConnectionSessionStateBody(ProtocolVersion=ProtocolVersion())  : flags(0) {}
    
    void setReplayStart(const SequenceNumber& _replayStart);
    SequenceNumber getReplayStart() const;
    bool hasReplayStart() const;
    void clearReplayStartFlag();
    void setCommandPoint(const SequenceNumber& _commandPoint);
    SequenceNumber getCommandPoint() const;
    bool hasCommandPoint() const;
    void clearCommandPointFlag();
    void setSentIncomplete(const SequenceSet& _sentIncomplete);
    const SequenceSet& getSentIncomplete() const;
    bool hasSentIncomplete() const;
    void clearSentIncompleteFlag();
    void setExpected(const SequenceNumber& _expected);
    SequenceNumber getExpected() const;
    bool hasExpected() const;
    void clearExpectedFlag();
    void setReceived(const SequenceNumber& _received);
    SequenceNumber getReceived() const;
    bool hasReceived() const;
    void clearReceivedFlag();
    void setUnknownCompleted(const SequenceSet& _unknownCompleted);
    const SequenceSet& getUnknownCompleted() const;
    bool hasUnknownCompleted() const;
    void clearUnknownCompletedFlag();
    void setReceivedIncomplete(const SequenceSet& _receivedIncomplete);
    const SequenceSet& getReceivedIncomplete() const;
    bool hasReceivedIncomplete() const;
    void clearReceivedIncompleteFlag();
    typedef void ResultType;

    template <class T> ResultType invoke(T& invocable) const {
        return invocable.sessionState(getReplayStart(), getCommandPoint(), getSentIncomplete(), getExpected(), getReceived(), getUnknownCompleted(), getReceivedIncomplete());
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
}; /* class ClusterConnectionSessionStateBody */

}}
#endif  /*!QPID_FRAMING_CLUSTERCONNECTIONSESSIONSTATEBODY_H*/
