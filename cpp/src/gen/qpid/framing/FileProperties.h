#ifndef QPID_FRAMING_FILEPROPERTIES_H
#define QPID_FRAMING_FILEPROPERTIES_H
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

class FileProperties  {
    string contentType;
    string contentEncoding;
    FieldTable headers;
    uint8_t priority;
    string replyTo;
    string messageId;
    string filename;
    uint64_t timestamp;
    string clusterId;
    uint16_t flags;
public:
    static const uint16_t TYPE = 2305;
    FileProperties(
        const string& _contentType,
        const string& _contentEncoding,
        const FieldTable& _headers,
        uint8_t _priority,
        const string& _replyTo,
        const string& _messageId,
        const string& _filename,
        uint64_t _timestamp,
        const string& _clusterId) : 
        contentType(_contentType),
        contentEncoding(_contentEncoding),
        headers(_headers),
        priority(_priority),
        replyTo(_replyTo),
        messageId(_messageId),
        filename(_filename),
        timestamp(_timestamp),
        clusterId(_clusterId),
        flags(0){
        flags |= (1 << 8);
        flags |= (1 << 9);
        flags |= (1 << 10);
        flags |= (1 << 11);
        flags |= (1 << 12);
        flags |= (1 << 13);
        flags |= (1 << 14);
        flags |= (1 << 15);
        flags |= (1 << 0);
    }
    FileProperties()  : priority(0), timestamp(0), flags(0) {}
    
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
    void setReplyTo(const string& _replyTo);
    const string& getReplyTo() const;
    bool hasReplyTo() const;
    void clearReplyToFlag();
    void setMessageId(const string& _messageId);
    const string& getMessageId() const;
    bool hasMessageId() const;
    void clearMessageIdFlag();
    void setFilename(const string& _filename);
    const string& getFilename() const;
    bool hasFilename() const;
    void clearFilenameFlag();
    void setTimestamp(uint64_t _timestamp);
    uint64_t getTimestamp() const;
    bool hasTimestamp() const;
    void clearTimestampFlag();
    void setClusterId(const string& _clusterId);
    const string& getClusterId() const;
    bool hasClusterId() const;
    void clearClusterIdFlag();
    friend std::ostream& operator<<(std::ostream&, const FileProperties&);
    void encode(Buffer&) const;
    void decode(Buffer&, uint32_t=0);
    void encodeStructBody(Buffer&) const;
    void decodeStructBody(Buffer&, uint32_t=0);
    uint32_t encodedSize() const;
    uint32_t bodySize() const;
    void print(std::ostream& out) const;
}; /* class FileProperties */

}}
#endif  /*!QPID_FRAMING_FILEPROPERTIES_H*/
