#ifndef QPID_FRAMING_MESSAGEACQUIRERESULT_H
#define QPID_FRAMING_MESSAGEACQUIRERESULT_H
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



#include <ostream>
#include "qpid/framing/amqp_types_full.h"

namespace qpid {
namespace framing {

class MessageAcquireResult  {
    SequenceSet transfers;
    uint16_t flags;
public:
    static const uint16_t TYPE = 1028;
    MessageAcquireResult(
        const SequenceSet& _transfers) : 
        transfers(_transfers),
        flags(0){
        flags |= (1 << 8);
    }
    MessageAcquireResult()  : flags(0) {}
    
    void setTransfers(const SequenceSet& _transfers);
    const SequenceSet& getTransfers() const;
    bool hasTransfers() const;
    void clearTransfersFlag();
    friend std::ostream& operator<<(std::ostream&, const MessageAcquireResult&);
    void encode(Buffer&) const;
    void decode(Buffer&, uint32_t=0);
    void encodeStructBody(Buffer&) const;
    void decodeStructBody(Buffer&, uint32_t=0);
    uint32_t encodedSize() const;
    uint32_t bodySize() const;
    void print(std::ostream& out) const;
}; /* class MessageAcquireResult */

}}
#endif  /*!QPID_FRAMING_MESSAGEACQUIRERESULT_H*/
