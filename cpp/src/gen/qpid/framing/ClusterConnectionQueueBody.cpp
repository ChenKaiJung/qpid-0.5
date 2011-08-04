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


#include "ClusterConnectionQueueBody.h"

#include "reply_exceptions.h"

using namespace qpid::framing;

void ClusterConnectionQueueBody::setEncoded(const string& _encoded) {
    encoded = _encoded;
    flags |= (1 << 8);
}
const string& ClusterConnectionQueueBody::getEncoded() const { return encoded; }
bool ClusterConnectionQueueBody::hasEncoded() const { return flags & (1 << 8); }
void ClusterConnectionQueueBody::clearEncodedFlag() { flags &= ~(1 << 8); }

void ClusterConnectionQueueBody::encodeStructBody(Buffer& buffer) const
{
encodeHeader(buffer);
    buffer.putShort(flags);
    if (flags & (1 << 8))
        buffer.putLongString(encoded);
}

void ClusterConnectionQueueBody::encode(Buffer& buffer) const
{
    encodeStructBody(buffer);
}

void ClusterConnectionQueueBody::decodeStructBody(Buffer& buffer, uint32_t /*size*/)
{
decodeHeader(buffer);
    flags = buffer.getShort();
    if (flags & (1 << 8))
        buffer.getLongString(encoded);
}

void ClusterConnectionQueueBody::decode(Buffer& buffer, uint32_t /*size*/)
{
    decodeStructBody(buffer);
}

uint32_t ClusterConnectionQueueBody::bodySize() const
{
    uint32_t total = 0;
total += headerSize();
    total += 2;
    if (flags & (1 << 8))
        total += 4 + encoded.size();
    return total;
}

uint32_t ClusterConnectionQueueBody::encodedSize() const {
    uint32_t total = bodySize();
    return total;
}

void ClusterConnectionQueueBody::print(std::ostream& out) const
{
    out << "{ClusterConnectionQueueBody: ";
    if (flags & (1 << 8))
        out << "encoded=" << encoded << "; ";
    out << "}";
}
