#ifndef QPID_FRAMING_STREAMPROPERTIES_H
#define QPID_FRAMING_STREAMPROPERTIES_H
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

class StreamProperties  {
    string contentType;
    string contentEncoding;
    FieldTable headers;
    uint8_t priority;
    uint64_t timestamp;
    uint16_t flags;
public:
    static const uint16_t TYPE = 2561;
    StreamProperties(
        const string& _contentType,
        const string& _contentEncoding,
        const FieldTable& _headers,
        uint8_t _priority,
        uint64_t _timestamp) : 
        contentType(_contentType),
        contentEncoding(_contentEncoding),
        headers(_headers),
        priority(_priority),
        timestamp(_timestamp),
        flags(0){
        flags |= (1 << 8);
        flags |= (1 << 9);
        flags |= (1 << 10);
        flags |= (1 << 11);
        flags |= (1 << 12);
    }
    StreamProperties()  : priority(0), timestamp(0), flags(0) {}
    
    void setContentType(const string& _contentType);
    const string& getContentType() const;
    bool hasContentType() const;
    void clearContentTypeFlag();
    void setContentEncoding(const string& _contentEncoding);
    const string& getContentEncoding() const;
    bool hasContentEncoding() const;
    void clearContentEncodingFlag();
    void setHeaders(const FieldTable& _headers);
    const FieldTable& getHeaders() const;
    FieldTable& getHeaders();
    bool hasHeaders() const;
    void clearHeadersFlag();
    void setPriority(uint8_t _priority);
    uint8_t getPriority() const;
    bool hasPriority() const;
    void clearPriorityFlag();
    void setTimestamp(uint64_t _timestamp);
    uint64_t getTimestamp() const;
    bool hasTimestamp() const;
    void clearTimestampFlag();
    friend std::ostream& operator<<(std::ostream&, const StreamProperties&);
    void encode(Buffer&) const;
    void decode(Buffer&, uint32_t=0);
    void encodeStructBody(Buffer&) const;
    void decodeStructBody(Buffer&, uint32_t=0);
    uint32_t encodedSize() const;
    uint32_t bodySize() const;
    void print(std::ostream& out) const;
}; /* class StreamProperties */

}}
#endif  /*!QPID_FRAMING_STREAMPROPERTIES_H*/
