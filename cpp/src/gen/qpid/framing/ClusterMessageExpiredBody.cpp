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


#include "ClusterMessageExpiredBody.h"

#include "reply_exceptions.h"

using namespace qpid::framing;

void ClusterMessageExpiredBody::setId(uint64_t _id) {
    id = _id;
    flags |= (1 << 8);
}
uint64_t ClusterMessageExpiredBody::getId() const { return id; }
bool ClusterMessageExpiredBody::hasId() const { return flags & (1 << 8); }
void ClusterMessageExpiredBody::clearIdFlag() { flags &= ~(1 << 8); }

void ClusterMessageExpiredBody::encodeStructBody(Buffer& buffer) const
{
encodeHeader(buffer);
    buffer.putShort(flags);
    if (flags & (1 << 8))
        buffer.putLongLong(id);
}

void ClusterMessageExpiredBody::encode(Buffer& buffer) const
{
    encodeStructBody(buffer);
}

void ClusterMessageExpiredBody::decodeStructBody(Buffer& buffer, uint32_t /*size*/)
{
decodeHeader(buffer);
    flags = buffer.getShort();
    if (flags & (1 << 8))
        id = buffer.getLongLong();
}

void ClusterMessageExpiredBody::decode(Buffer& buffer, uint32_t /*size*/)
{
    decodeStructBody(buffer);
}

uint32_t ClusterMessageExpiredBody::bodySize() const
{
    uint32_t total = 0;
total += headerSize();
    total += 2;
    if (flags & (1 << 8))
        total += 8;//id
    return total;
}

uint32_t ClusterMessageExpiredBody::encodedSize() const {
    uint32_t total = bodySize();
    return total;
}

void ClusterMessageExpiredBody::print(std::ostream& out) const
{
    out << "{ClusterMessageExpiredBody: ";
    if (flags & (1 << 8))
        out << "id=" << id << "; ";
    out << "}";
}
