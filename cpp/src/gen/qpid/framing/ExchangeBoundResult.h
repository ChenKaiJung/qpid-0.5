#ifndef QPID_FRAMING_EXCHANGEBOUNDRESULT_H
#define QPID_FRAMING_EXCHANGEBOUNDRESULT_H
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

class ExchangeBoundResult  {
    uint16_t flags;
public:
    static const uint16_t TYPE = 1794;
    ExchangeBoundResult(
        bool _exchangeNotFound,
        bool _queueNotFound,
        bool _queueNotMatched,
        bool _keyNotMatched,
        bool _argsNotMatched) : 
        flags(0){
        setExchangeNotFound(_exchangeNotFound);
        setQueueNotFound(_queueNotFound);
        setQueueNotMatched(_queueNotMatched);
        setKeyNotMatched(_keyNotMatched);
        setArgsNotMatched(_argsNotMatched);
    }
    ExchangeBoundResult()  : flags(0) {}
    
    void setExchangeNotFound(bool _exchangeNotFound);
    bool getExchangeNotFound() const;
    void setQueueNotFound(bool _queueNotFound);
    bool getQueueNotFound() const;
    void setQueueNotMatched(bool _queueNotMatched);
    bool getQueueNotMatched() const;
    void setKeyNotMatched(bool _keyNotMatched);
    bool getKeyNotMatched() const;
    void setArgsNotMatched(bool _argsNotMatched);
    bool getArgsNotMatched() const;
    friend std::ostream& operator<<(std::ostream&, const ExchangeBoundResult&);
    void encode(Buffer&) const;
    void decode(Buffer&, uint32_t=0);
    void encodeStructBody(Buffer&) const;
    void decodeStructBody(Buffer&, uint32_t=0);
    uint32_t encodedSize() const;
    uint32_t bodySize() const;
    void print(std::ostream& out) const;
}; /* class ExchangeBoundResult */

}}
#endif  /*!QPID_FRAMING_EXCHANGEBOUNDRESULT_H*/
