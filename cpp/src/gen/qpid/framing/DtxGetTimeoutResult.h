#ifndef QPID_FRAMING_DTXGETTIMEOUTRESULT_H
#define QPID_FRAMING_DTXGETTIMEOUTRESULT_H
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

class DtxGetTimeoutResult  {
    uint32_t timeout;
    uint16_t flags;
public:
    static const uint16_t TYPE = 1538;
    DtxGetTimeoutResult(
        uint32_t _timeout) : 
        timeout(_timeout),
        flags(0){
        flags |= (1 << 8);
    }
    DtxGetTimeoutResult()  : timeout(0), flags(0) {}
    
    void setTimeout(uint32_t _timeout);
    uint32_t getTimeout() const;
    bool hasTimeout() const;
    void clearTimeoutFlag();
    friend std::ostream& operator<<(std::ostream&, const DtxGetTimeoutResult&);
    void encode(Buffer&) const;
    void decode(Buffer&, uint32_t=0);
    void encodeStructBody(Buffer&) const;
    void decodeStructBody(Buffer&, uint32_t=0);
    uint32_t encodedSize() const;
    uint32_t bodySize() const;
    void print(std::ostream& out) const;
}; /* class DtxGetTimeoutResult */

}}
#endif  /*!QPID_FRAMING_DTXGETTIMEOUTRESULT_H*/
