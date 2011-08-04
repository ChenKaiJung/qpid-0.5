#ifndef QPID_FRAMING_EXCHANGEQUERYRESULT_H
#define QPID_FRAMING_EXCHANGEQUERYRESULT_H
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

class ExchangeQueryResult  {
    string type;
    FieldTable arguments;
    uint16_t flags;
public:
    static const uint16_t TYPE = 1793;
    ExchangeQueryResult(
        const string& _type,
        bool _durable,
        bool _notFound,
        const FieldTable& _arguments) : 
        type(_type),
        arguments(_arguments),
        flags(0){
        setDurable(_durable);
        setNotFound(_notFound);
        flags |= (1 << 8);
        flags |= (1 << 11);
    }
    ExchangeQueryResult()  : flags(0) {}
    
    void setType(const string& _type);
    const string& getType() const;
    bool hasType() const;
    void clearTypeFlag();
    void setDurable(bool _durable);
    bool getDurable() const;
    void setNotFound(bool _notFound);
    bool getNotFound() const;
    void setArguments(const FieldTable& _arguments);
    const FieldTable& getArguments() const;
    FieldTable& getArguments();
    bool hasArguments() const;
    void clearArgumentsFlag();
    friend std::ostream& operator<<(std::ostream&, const ExchangeQueryResult&);
    void encode(Buffer&) const;
    void decode(Buffer&, uint32_t=0);
    void encodeStructBody(Buffer&) const;
    void decodeStructBody(Buffer&, uint32_t=0);
    uint32_t encodedSize() const;
    uint32_t bodySize() const;
    void print(std::ostream& out) const;
}; /* class ExchangeQueryResult */

}}
#endif  /*!QPID_FRAMING_EXCHANGEQUERYRESULT_H*/
