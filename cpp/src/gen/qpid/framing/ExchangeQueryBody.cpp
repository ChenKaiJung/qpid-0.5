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


#include "ExchangeQueryBody.h"

#include "reply_exceptions.h"

using namespace qpid::framing;

void ExchangeQueryBody::setName(const string& _name) {
    name = _name;
    flags |= (1 << 8);
}
const string& ExchangeQueryBody::getName() const { return name; }
bool ExchangeQueryBody::hasName() const { return flags & (1 << 8); }
void ExchangeQueryBody::clearNameFlag() { flags &= ~(1 << 8); }

void ExchangeQueryBody::encodeStructBody(Buffer& buffer) const
{
encodeHeader(buffer);
    buffer.putShort(flags);
    if (flags & (1 << 8))
        buffer.putShortString(name);
}

void ExchangeQueryBody::encode(Buffer& buffer) const
{
    encodeStructBody(buffer);
}

void ExchangeQueryBody::decodeStructBody(Buffer& buffer, uint32_t /*size*/)
{
decodeHeader(buffer);
    flags = buffer.getShort();
    if (flags & (1 << 8))
        buffer.getShortString(name);
}

void ExchangeQueryBody::decode(Buffer& buffer, uint32_t /*size*/)
{
    decodeStructBody(buffer);
}

uint32_t ExchangeQueryBody::bodySize() const
{
    uint32_t total = 0;
total += headerSize();
    total += 2;
    if (flags & (1 << 8))
        total += 1 + name.size();
    return total;
}

uint32_t ExchangeQueryBody::encodedSize() const {
    uint32_t total = bodySize();
    return total;
}

void ExchangeQueryBody::print(std::ostream& out) const
{
    out << "{ExchangeQueryBody: ";
    if (flags & (1 << 8))
        out << "name=" << name << "; ";
    out << "}";
}
