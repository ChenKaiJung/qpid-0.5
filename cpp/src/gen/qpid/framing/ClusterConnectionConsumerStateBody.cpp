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


#include "ClusterConnectionConsumerStateBody.h"

#include "reply_exceptions.h"

using namespace qpid::framing;

void ClusterConnectionConsumerStateBody::setName(const string& _name) {
    name = _name;
    flags |= (1 << 8);
}
const string& ClusterConnectionConsumerStateBody::getName() const { return name; }
bool ClusterConnectionConsumerStateBody::hasName() const { return flags & (1 << 8); }
void ClusterConnectionConsumerStateBody::clearNameFlag() { flags &= ~(1 << 8); }

void ClusterConnectionConsumerStateBody::setBlocked(bool _blocked) {
    if (_blocked) flags |= (1 << 9);
    else flags &= ~(1 << 9);
}
bool ClusterConnectionConsumerStateBody::getBlocked() const { return flags & (1 << 9); }

void ClusterConnectionConsumerStateBody::setNotifyEnabled(bool _notifyEnabled) {
    if (_notifyEnabled) flags |= (1 << 10);
    else flags &= ~(1 << 10);
}
bool ClusterConnectionConsumerStateBody::getNotifyEnabled() const { return flags & (1 << 10); }

void ClusterConnectionConsumerStateBody::encodeStructBody(Buffer& buffer) const
{
encodeHeader(buffer);
    buffer.putShort(flags);
    if (flags & (1 << 8))
        buffer.putShortString(name);
}

void ClusterConnectionConsumerStateBody::encode(Buffer& buffer) const
{
    encodeStructBody(buffer);
}

void ClusterConnectionConsumerStateBody::decodeStructBody(Buffer& buffer, uint32_t /*size*/)
{
decodeHeader(buffer);
    flags = buffer.getShort();
    if (flags & (1 << 8))
        buffer.getShortString(name);
}

void ClusterConnectionConsumerStateBody::decode(Buffer& buffer, uint32_t /*size*/)
{
    decodeStructBody(buffer);
}

uint32_t ClusterConnectionConsumerStateBody::bodySize() const
{
    uint32_t total = 0;
total += headerSize();
    total += 2;
    if (flags & (1 << 8))
        total += 1 + name.size();
    return total;
}

uint32_t ClusterConnectionConsumerStateBody::encodedSize() const {
    uint32_t total = bodySize();
    return total;
}

void ClusterConnectionConsumerStateBody::print(std::ostream& out) const
{
    out << "{ClusterConnectionConsumerStateBody: ";
    if (flags & (1 << 8))
        out << "name=" << name << "; ";
    if (flags & (1 << 9))
        out << "blocked=" << getBlocked() << "; ";
    if (flags & (1 << 10))
        out << "notifyEnabled=" << getNotifyEnabled() << "; ";
    out << "}";
}
