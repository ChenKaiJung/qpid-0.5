#ifndef QPID_FRAMING_DELIVERYPROPERTIES_H
#define QPID_FRAMING_DELIVERYPROPERTIES_H
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

class DeliveryProperties  {
    uint8_t priority;
    uint8_t deliveryMode;
    uint64_t ttl;
    uint64_t timestamp;
    uint64_t expiration;
    string exchange;
    string routingKey;
    string resumeId;
    uint64_t resumeTtl;
    uint16_t flags;
public:
    static const uint16_t TYPE = 1025;
    DeliveryProperties(
        bool _discardUnroutable,
        bool _immediate,
        bool _redelivered,
        uint8_t _priority,
        uint8_t _deliveryMode,
        uint64_t _ttl,
        uint64_t _timestamp,
        uint64_t _expiration,
        const string& _exchange,
        const string& _routingKey,
        const string& _resumeId,
        uint64_t _resumeTtl) : 
        priority(_priority),
        deliveryMode(_deliveryMode),
        ttl(_ttl),
        timestamp(_timestamp),
        expiration(_expiration),
        exchange(_exchange),
        routingKey(_routingKey),
        resumeId(_resumeId),
        resumeTtl(_resumeTtl),
        flags(0){
        setDiscardUnroutable(_discardUnroutable);
        setImmediate(_immediate);
        setRedelivered(_redelivered);
        flags |= (1 << 11);
        flags |= (1 << 12);
        flags |= (1 << 13);
        flags |= (1 << 14);
        flags |= (1 << 15);
        flags |= (1 << 0);
        flags |= (1 << 1);
        flags |= (1 << 2);
        flags |= (1 << 3);
    }
    DeliveryProperties()  : priority(0), deliveryMode(0), ttl(0), timestamp(0), expiration(0), resumeTtl(0), flags(0) {}
    
    void setDiscardUnroutable(bool _discardUnroutable);
    bool getDiscardUnroutable() const;
    void setImmediate(bool _immediate);
    bool getImmediate() const;
    void setRedelivered(bool _redelivered);
    bool getRedelivered() const;
    void setPriority(uint8_t _priority);
    uint8_t getPriority() const;
    bool hasPriority() const;
    void clearPriorityFlag();
    void setDeliveryMode(uint8_t _deliveryMode);
    uint8_t getDeliveryMode() const;
    bool hasDeliveryMode() const;
    void clearDeliveryModeFlag();
    void setTtl(uint64_t _ttl);
    uint64_t getTtl() const;
    bool hasTtl() const;
    void clearTtlFlag();
    void setTimestamp(uint64_t _timestamp);
    uint64_t getTimestamp() const;
    bool hasTimestamp() const;
    void clearTimestampFlag();
    void setExpiration(uint64_t _expiration);
    uint64_t getExpiration() const;
    bool hasExpiration() const;
    void clearExpirationFlag();
    void setExchange(const string& _exchange);
    const string& getExchange() const;
    bool hasExchange() const;
    void clearExchangeFlag();
    void setRoutingKey(const string& _routingKey);
    const string& getRoutingKey() const;
    bool hasRoutingKey() const;
    void clearRoutingKeyFlag();
    void setResumeId(const string& _resumeId);
    const string& getResumeId() const;
    bool hasResumeId() const;
    void clearResumeIdFlag();
    void setResumeTtl(uint64_t _resumeTtl);
    uint64_t getResumeTtl() const;
    bool hasResumeTtl() const;
    void clearResumeTtlFlag();
    friend std::ostream& operator<<(std::ostream&, const DeliveryProperties&);
    void encode(Buffer&) const;
    void decode(Buffer&, uint32_t=0);
    void encodeStructBody(Buffer&) const;
    void decodeStructBody(Buffer&, uint32_t=0);
    uint32_t encodedSize() const;
    uint32_t bodySize() const;
    void print(std::ostream& out) const;
}; /* class DeliveryProperties */

}}
#endif  /*!QPID_FRAMING_DELIVERYPROPERTIES_H*/
