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


#include "ClusterConnectionShadowReadyBody.h"

#include "reply_exceptions.h"

using namespace qpid::framing;

void ClusterConnectionShadowReadyBody::setMemberId(uint64_t _memberId) {
    memberId = _memberId;
    flags |= (1 << 8);
}
uint64_t ClusterConnectionShadowReadyBody::getMemberId() const { return memberId; }
bool ClusterConnectionShadowReadyBody::hasMemberId() const { return flags & (1 << 8); }
void ClusterConnectionShadowReadyBody::clearMemberIdFlag() { flags &= ~(1 << 8); }

void ClusterConnectionShadowReadyBody::setConnectionId(uint64_t _connectionId) {
    connectionId = _connectionId;
    flags |= (1 << 9);
}
uint64_t ClusterConnectionShadowReadyBody::getConnectionId() const { return connectionId; }
bool ClusterConnectionShadowReadyBody::hasConnectionId() const { return flags & (1 << 9); }
void ClusterConnectionShadowReadyBody::clearConnectionIdFlag() { flags &= ~(1 << 9); }

void ClusterConnectionShadowReadyBody::setUserName(const string& _userName) {
    userName = _userName;
    flags |= (1 << 10);
}
const string& ClusterConnectionShadowReadyBody::getUserName() const { return userName; }
bool ClusterConnectionShadowReadyBody::hasUserName() const { return flags & (1 << 10); }
void ClusterConnectionShadowReadyBody::clearUserNameFlag() { flags &= ~(1 << 10); }

void ClusterConnectionShadowReadyBody::setFragment(const string& _fragment) {
    fragment = _fragment;
    flags |= (1 << 11);
}
const string& ClusterConnectionShadowReadyBody::getFragment() const { return fragment; }
bool ClusterConnectionShadowReadyBody::hasFragment() const { return flags & (1 << 11); }
void ClusterConnectionShadowReadyBody::clearFragmentFlag() { flags &= ~(1 << 11); }

void ClusterConnectionShadowReadyBody::encodeStructBody(Buffer& buffer) const
{
encodeHeader(buffer);
    buffer.putShort(flags);
    if (flags & (1 << 8))
        buffer.putLongLong(memberId);
    if (flags & (1 << 9))
        buffer.putLongLong(connectionId);
    if (flags & (1 << 10))
        buffer.putShortString(userName);
    if (flags & (1 << 11))
        buffer.putLongString(fragment);
}

void ClusterConnectionShadowReadyBody::encode(Buffer& buffer) const
{
    encodeStructBody(buffer);
}

void ClusterConnectionShadowReadyBody::decodeStructBody(Buffer& buffer, uint32_t /*size*/)
{
decodeHeader(buffer);
    flags = buffer.getShort();
    if (flags & (1 << 8))
        memberId = buffer.getLongLong();
    if (flags & (1 << 9))
        connectionId = buffer.getLongLong();
    if (flags & (1 << 10))
        buffer.getShortString(userName);
    if (flags & (1 << 11))
        buffer.getLongString(fragment);
}

void ClusterConnectionShadowReadyBody::decode(Buffer& buffer, uint32_t /*size*/)
{
    decodeStructBody(buffer);
}

uint32_t ClusterConnectionShadowReadyBody::bodySize() const
{
    uint32_t total = 0;
total += headerSize();
    total += 2;
    if (flags & (1 << 8))
        total += 8;//memberId
    if (flags & (1 << 9))
        total += 8;//connectionId
    if (flags & (1 << 10))
        total += 1 + userName.size();
    if (flags & (1 << 11))
        total += 4 + fragment.size();
    return total;
}

uint32_t ClusterConnectionShadowReadyBody::encodedSize() const {
    uint32_t total = bodySize();
    return total;
}

void ClusterConnectionShadowReadyBody::print(std::ostream& out) const
{
    out << "{ClusterConnectionShadowReadyBody: ";
    if (flags & (1 << 8))
        out << "member-id=" << memberId << "; ";
    if (flags & (1 << 9))
        out << "connection-id=" << connectionId << "; ";
    if (flags & (1 << 10))
        out << "user-name=" << userName << "; ";
    if (flags & (1 << 11))
        out << "fragment=" << fragment << "; ";
    out << "}";
}
