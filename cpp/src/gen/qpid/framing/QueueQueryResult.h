#ifndef QPID_FRAMING_QUEUEQUERYRESULT_H
#define QPID_FRAMING_QUEUEQUERYRESULT_H
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

class QueueQueryResult  {
    string queue;
    string alternateExchange;
    FieldTable arguments;
    uint32_t messageCount;
    uint32_t subscriberCount;
    uint16_t flags;
public:
    static const uint16_t TYPE = 2049;
    QueueQueryResult(
        const string& _queue,
        const string& _alternateExchange,
        bool _durable,
        bool _exclusive,
        bool _autoDelete,
        const FieldTable& _arguments,
        uint32_t _messageCount,
        uint32_t _subscriberCount) : 
        queue(_queue),
        alternateExchange(_alternateExchange),
        arguments(_arguments),
        messageCount(_messageCount),
        subscriberCount(_subscriberCount),
        flags(0){
        setDurable(_durable);
        setExclusive(_exclusive);
        setAutoDelete(_autoDelete);
        flags |= (1 << 8);
        flags |= (1 << 9);
        flags |= (1 << 13);
        flags |= (1 << 14);
        flags |= (1 << 15);
    }
    QueueQueryResult()  : messageCount(0), subscriberCount(0), flags(0) {}
    
    void setQueue(const string& _queue);
    const string& getQueue() const;
    bool hasQueue() const;
    void clearQueueFlag();
    void setAlternateExchange(const string& _alternateExchange);
    const string& getAlternateExchange() const;
    bool hasAlternateExchange() const;
    void clearAlternateExchangeFlag();
    void setDurable(bool _durable);
    bool getDurable() const;
    void setExclusive(bool _exclusive);
    bool getExclusive() const;
    void setAutoDelete(bool _autoDelete);
    bool getAutoDelete() const;
    void setArguments(const FieldTable& _arguments);
    const FieldTable& getArguments() const;
    FieldTable& getArguments();
    bool hasArguments() const;
    void clearArgumentsFlag();
    void setMessageCount(uint32_t _messageCount);
    uint32_t getMessageCount() const;
    bool hasMessageCount() const;
    void clearMessageCountFlag();
    void setSubscriberCount(uint32_t _subscriberCount);
    uint32_t getSubscriberCount() const;
    bool hasSubscriberCount() const;
    void clearSubscriberCountFlag();
    friend std::ostream& operator<<(std::ostream&, const QueueQueryResult&);
    void encode(Buffer&) const;
    void decode(Buffer&, uint32_t=0);
    void encodeStructBody(Buffer&) const;
    void decodeStructBody(Buffer&, uint32_t=0);
    uint32_t encodedSize() const;
    uint32_t bodySize() const;
    void print(std::ostream& out) const;
}; /* class QueueQueryResult */

}}
#endif  /*!QPID_FRAMING_QUEUEQUERYRESULT_H*/
