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


#include "ClusterConnectionRetractOfferBody.h"

#include "reply_exceptions.h"

using namespace qpid::framing;

void ClusterConnectionRetractOfferBody::encodeStructBody(Buffer& buffer) const
{
encodeHeader(buffer);
    buffer.putShort(flags);
}

void ClusterConnectionRetractOfferBody::encode(Buffer& buffer) const
{
    encodeStructBody(buffer);
}

void ClusterConnectionRetractOfferBody::decodeStructBody(Buffer& buffer, uint32_t /*size*/)
{
decodeHeader(buffer);
    flags = buffer.getShort();
}

void ClusterConnectionRetractOfferBody::decode(Buffer& buffer, uint32_t /*size*/)
{
    decodeStructBody(buffer);
}

uint32_t ClusterConnectionRetractOfferBody::bodySize() const
{
    uint32_t total = 0;
total += headerSize();
    total += 2;
    return total;
}

uint32_t ClusterConnectionRetractOfferBody::encodedSize() const {
    uint32_t total = bodySize();
    return total;
}

void ClusterConnectionRetractOfferBody::print(std::ostream& out) const
{
    out << "{ClusterConnectionRetractOfferBody: ";
    out << "}";
}
