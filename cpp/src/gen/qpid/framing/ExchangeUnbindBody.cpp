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


#include "ExchangeUnbindBody.h"

#include "reply_exceptions.h"

using namespace qpid::framing;

void ExchangeUnbindBody::setQueue(const string& _queue) {
    queue = _queue;
    flags |= (1 << 8);
}
const string& ExchangeUnbindBody::getQueue() const { return queue; }
bool ExchangeUnbindBody::hasQueue() const { return flags & (1 << 8); }
void ExchangeUnbindBody::clearQueueFlag() { flags &= ~(1 << 8); }

void ExchangeUnbindBody::setExchange(const string& _exchange) {
    exchange = _exchange;
    flags |= (1 << 9);
}
const string& ExchangeUnbindBody::getExchange() const { return exchange; }
bool ExchangeUnbindBody::hasExchange() const { return flags & (1 << 9); }
void ExchangeUnbindBody::clearExchangeFlag() { flags &= ~(1 << 9); }

void ExchangeUnbindBody::setBindingKey(const string& _bindingKey) {
    bindingKey = _bindingKey;
    flags |= (1 << 10);
}
const string& ExchangeUnbindBody::getBindingKey() const { return bindingKey; }
bool ExchangeUnbindBody::hasBindingKey() const { return flags & (1 << 10); }
void ExchangeUnbindBody::clearBindingKeyFlag() { flags &= ~(1 << 10); }

void ExchangeUnbindBody::encodeStructBody(Buffer& buffer) const
{
encodeHeader(buffer);
    buffer.putShort(flags);
    if (flags & (1 << 8))
        buffer.putShortString(queue);
    if (flags & (1 << 9))
        buffer.putShortString(exchange);
    if (flags & (1 << 10))
        buffer.putShortString(bindingKey);
}

void ExchangeUnbindBody::encode(Buffer& buffer) const
{
    encodeStructBody(buffer);
}

void ExchangeUnbindBody::decodeStructBody(Buffer& buffer, uint32_t /*size*/)
{
decodeHeader(buffer);
    flags = buffer.getShort();
    if (flags & (1 << 8))
        buffer.getShortString(queue);
    if (flags & (1 << 9))
        buffer.getShortString(exchange);
    if (flags & (1 << 10))
        buffer.getShortString(bindingKey);
}

void ExchangeUnbindBody::decode(Buffer& buffer, uint32_t /*size*/)
{
    decodeStructBody(buffer);
}

uint32_t ExchangeUnbindBody::bodySize() const
{
    uint32_t total = 0;
total += headerSize();
    total += 2;
    if (flags & (1 << 8))
        total += 1 + queue.size();
    if (flags & (1 << 9))
        total += 1 + exchange.size();
    if (flags & (1 << 10))
        total += 1 + bindingKey.size();
    return total;
}

uint32_t ExchangeUnbindBody::encodedSize() const {
    uint32_t total = bodySize();
    return total;
}

void ExchangeUnbindBody::print(std::ostream& out) const
{
    out << "{ExchangeUnbindBody: ";
    if (flags & (1 << 8))
        out << "queue=" << queue << "; ";
    if (flags & (1 << 9))
        out << "exchange=" << exchange << "; ";
    if (flags & (1 << 10))
        out << "binding-key=" << bindingKey << "; ";
    out << "}";
}
