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


#include "FileProperties.h"

#include "reply_exceptions.h"

using namespace qpid::framing;

void FileProperties::setContentType(const string& _contentType) {
    contentType = _contentType;
    flags |= (1 << 8);
}
const string& FileProperties::getContentType() const { return contentType; }
bool FileProperties::hasContentType() const { return flags & (1 << 8); }
void FileProperties::clearContentTypeFlag() { flags &= ~(1 << 8); }

void FileProperties::setContentEncoding(const string& _contentEncoding) {
    contentEncoding = _contentEncoding;
    flags |= (1 << 9);
}
const string& FileProperties::getContentEncoding() const { return contentEncoding; }
bool FileProperties::hasContentEncoding() const { return flags & (1 << 9); }
void FileProperties::clearContentEncodingFlag() { flags &= ~(1 << 9); }

void FileProperties::setHeaders(const FieldTable& _headers) {
    headers = _headers;
    flags |= (1 << 10);
}
const FieldTable& FileProperties::getHeaders() const { return headers; }
FieldTable& FileProperties::getHeaders() {
    flags |= (1 << 10);
    return headers;
}
bool FileProperties::hasHeaders() const { return flags & (1 << 10); }
void FileProperties::clearHeadersFlag() { flags &= ~(1 << 10); }

void FileProperties::setPriority(uint8_t _priority) {
    priority = _priority;
    flags |= (1 << 11);
}
uint8_t FileProperties::getPriority() const { return priority; }
bool FileProperties::hasPriority() const { return flags & (1 << 11); }
void FileProperties::clearPriorityFlag() { flags &= ~(1 << 11); }

void FileProperties::setReplyTo(const string& _replyTo) {
    replyTo = _replyTo;
    flags |= (1 << 12);
}
const string& FileProperties::getReplyTo() const { return replyTo; }
bool FileProperties::hasReplyTo() const { return flags & (1 << 12); }
void FileProperties::clearReplyToFlag() { flags &= ~(1 << 12); }

void FileProperties::setMessageId(const string& _messageId) {
    messageId = _messageId;
    flags |= (1 << 13);
}
const string& FileProperties::getMessageId() const { return messageId; }
bool FileProperties::hasMessageId() const { return flags & (1 << 13); }
void FileProperties::clearMessageIdFlag() { flags &= ~(1 << 13); }

void FileProperties::setFilename(const string& _filename) {
    filename = _filename;
    flags |= (1 << 14);
}
const string& FileProperties::getFilename() const { return filename; }
bool FileProperties::hasFilename() const { return flags & (1 << 14); }
void FileProperties::clearFilenameFlag() { flags &= ~(1 << 14); }

void FileProperties::setTimestamp(uint64_t _timestamp) {
    timestamp = _timestamp;
    flags |= (1 << 15);
}
uint64_t FileProperties::getTimestamp() const { return timestamp; }
bool FileProperties::hasTimestamp() const { return flags & (1 << 15); }
void FileProperties::clearTimestampFlag() { flags &= ~(1 << 15); }

void FileProperties::setClusterId(const string& _clusterId) {
    clusterId = _clusterId;
    flags |= (1 << 0);
}
const string& FileProperties::getClusterId() const { return clusterId; }
bool FileProperties::hasClusterId() const { return flags & (1 << 0); }
void FileProperties::clearClusterIdFlag() { flags &= ~(1 << 0); }

void FileProperties::encodeStructBody(Buffer& buffer) const
{
    buffer.putShort(flags);
    if (flags & (1 << 8))
        buffer.putShortString(contentType);
    if (flags & (1 << 9))
        buffer.putShortString(contentEncoding);
    if (flags & (1 << 10))
        headers.encode(buffer);
    if (flags & (1 << 11))
        buffer.putOctet(priority);
    if (flags & (1 << 12))
        buffer.putShortString(replyTo);
    if (flags & (1 << 13))
        buffer.putShortString(messageId);
    if (flags & (1 << 14))
        buffer.putShortString(filename);
    if (flags & (1 << 15))
        buffer.putLongLong(timestamp);
    if (flags & (1 << 0))
        buffer.putShortString(clusterId);
}

void FileProperties::encode(Buffer& buffer) const
{
    buffer.putLong(bodySize() + 2/*typecode*/);
    buffer.putShort(TYPE);
    encodeStructBody(buffer);
}

void FileProperties::decodeStructBody(Buffer& buffer, uint32_t /*size*/)
{
    flags = buffer.getShort();
    if (flags & (1 << 8))
        buffer.getShortString(contentType);
    if (flags & (1 << 9))
        buffer.getShortString(contentEncoding);
    if (flags & (1 << 10))
        headers.decode(buffer);
    if (flags & (1 << 11))
        priority = buffer.getOctet();
    if (flags & (1 << 12))
        buffer.getShortString(replyTo);
    if (flags & (1 << 13))
        buffer.getShortString(messageId);
    if (flags & (1 << 14))
        buffer.getShortString(filename);
    if (flags & (1 << 15))
        timestamp = buffer.getLongLong();
    if (flags & (1 << 0))
        buffer.getShortString(clusterId);
}

void FileProperties::decode(Buffer& buffer, uint32_t /*size*/)
{
    buffer.getLong();
    if (TYPE != buffer.getShort()) throw FramingErrorException("Bad type code for struct");
    decodeStructBody(buffer);
}

uint32_t FileProperties::bodySize() const
{
    uint32_t total = 0;
    total += 2;
    if (flags & (1 << 8))
        total += 1 + contentType.size();
    if (flags & (1 << 9))
        total += 1 + contentEncoding.size();
    if (flags & (1 << 10))
        total += headers.encodedSize();
    if (flags & (1 << 11))
        total += 1;//priority
    if (flags & (1 << 12))
        total += 1 + replyTo.size();
    if (flags & (1 << 13))
        total += 1 + messageId.size();
    if (flags & (1 << 14))
        total += 1 + filename.size();
    if (flags & (1 << 15))
        total += 8;//timestamp
    if (flags & (1 << 0))
        total += 1 + clusterId.size();
    return total;
}

uint32_t FileProperties::encodedSize() const {
    uint32_t total = bodySize();
total += 4/*size field*/;
total += 2/*typecode*/;
    return total;
}

void FileProperties::print(std::ostream& out) const
{
    out << "{FileProperties: ";
    if (flags & (1 << 8))
        out << "content-type=" << contentType << "; ";
    if (flags & (1 << 9))
        out << "content-encoding=" << contentEncoding << "; ";
    if (flags & (1 << 10))
        out << "headers=" << headers << "; ";
    if (flags & (1 << 11))
        out << "priority=" << (int) priority << "; ";
    if (flags & (1 << 12))
        out << "reply-to=" << replyTo << "; ";
    if (flags & (1 << 13))
        out << "message-id=" << messageId << "; ";
    if (flags & (1 << 14))
        out << "filename=" << filename << "; ";
    if (flags & (1 << 15))
        out << "timestamp=" << timestamp << "; ";
    if (flags & (1 << 0))
        out << "cluster-id=" << clusterId << "; ";
    out << "}";
}
namespace qpid{
namespace framing{

    std::ostream& operator<<(std::ostream& out, const FileProperties& s) 
    {
      s.print(out);
      return out;
    }

}
}
