#ifndef QPID_FRAMING_MESSAGEPROPERTIES_H
#define QPID_FRAMING_MESSAGEPROPERTIES_H
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


#include "qpid/framing/ReplyTo.h"

#include <ostream>
#include "qpid/framing/amqp_types_full.h"

namespace qpid {
namespace framing {

class MessageProperties  {
    uint64_t contentLength;
    Uuid messageId;
    string correlationId;
    ReplyTo replyTo;
    string contentType;
    string contentEncoding;
    string userId;
    string appId;
    FieldTable applicationHeaders;
    uint16_t flags;
public:
    static const uint16_t TYPE = 1027;
    MessageProperties(
        uint64_t _contentLength,
        const Uuid& _messageId,
        const string& _correlationId,
        const ReplyTo& _replyTo,
        const string& _contentType,
        const string& _contentEncoding,
        const string& _userId,
        const string& _appId,
        const FieldTable& _applicationHeaders) : 
        contentLength(_contentLength),
        messageId(_messageId),
        correlationId(_correlationId),
        replyTo(_replyTo),
        contentType(_contentType),
        contentEncoding(_contentEncoding),
        userId(_userId),
        appId(_appId),
        applicationHeaders(_applicationHeaders),
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
    MessageProperties()  : contentLength(0), flags(0) {}
    
    void setContentLength(uint64_t _contentLength);
    uint64_t getContentLength() const;
    bool hasContentLength() const;
    void clearContentLengthFlag();
    void setMessageId(const Uuid& _messageId);
    const Uuid& getMessageId() const;
    bool hasMessageId() const;
    void clearMessageIdFlag();
    void setCorrelationId(const string& _correlationId);
    const string& getCorrelationId() const;
    bool hasCorrelationId() const;
    void clearCorrelationIdFlag();
    void setReplyTo(const ReplyTo& _replyTo);
    const ReplyTo& getReplyTo() const;
    bool hasReplyTo() const;
    void clearReplyToFlag();
    void setContentType(const string& _contentType);
    const string& getContentType() const;
    bool hasContentType() const;
    void clearContentTypeFlag();
    void setContentEncoding(const string& _contentEncoding);
    const string& getContentEncoding() const;
    bool hasContentEncoding() const;
    void clearContentEncodingFlag();
    void setUserId(const string& _userId);
    const string& getUserId() const;
    bool hasUserId() const;
    void clearUserIdFlag();
    void setAppId(const string& _appId);
    const string& getAppId() const;
    bool hasAppId() const;
    void clearAppIdFlag();
    void setApplicationHeaders(const FieldTable& _applicationHeaders);
    const FieldTable& getApplicationHeaders() const;
    FieldTable& getApplicationHeaders();
    bool hasApplicationHeaders() const;
    void clearApplicationHeadersFlag();
    friend std::ostream& operator<<(std::ostream&, const MessageProperties&);
    void encode(Buffer&) const;
    void decode(Buffer&, uint32_t=0);
    void encodeStructBody(Buffer&) const;
    void decodeStructBody(Buffer&, uint32_t=0);
    uint32_t encodedSize() const;
    uint32_t bodySize() const;
    void print(std::ostream& out) const;
}; /* class MessageProperties */

}}
#endif  /*!QPID_FRAMING_MESSAGEPROPERTIES_H*/
