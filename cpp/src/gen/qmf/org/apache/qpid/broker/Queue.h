
#ifndef _MANAGEMENT_QUEUE_
#define _MANAGEMENT_QUEUE_

//
// Licensed to the Apache Software Foundation (ASF) under one
// or more contributor license agreements.  See the NOTICE file
// distributed with this work for additional information
// regarding copyright ownership.  The ASF licenses this file
// to you under the Apache License, Version 2.0 (the
// "License"); you may not use this file except in compliance
// with the License.  You may obtain a copy of the License at
// 
//   http://www.apache.org/licenses/LICENSE-2.0
// 
// Unless required by applicable law or agreed to in writing,
// software distributed under the License is distributed on an
// "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY
// KIND, either express or implied.  See the License for the
// specific language governing permissions and limitations
// under the License.
//

// This source file was created by a code generator.
// Please do not edit.

#include "qpid/management/ManagementObject.h"
#include "qpid/framing/FieldTable.h"
#include "qpid/framing/Uuid.h"

namespace qmf {
namespace org {
namespace apache {
namespace qpid {
namespace broker {


class Queue : public ::qpid::management::ManagementObject
{
  private:

    static std::string packageName;
    static std::string className;
    static uint8_t     md5Sum[16];


    // Properties
    ::qpid::management::ObjectId vhostRef;
    std::string name;
    uint8_t durable;
    uint8_t autoDelete;
    uint8_t exclusive;
    ::qpid::framing::FieldTable arguments;

    // Statistics
    uint32_t  consumerCount;
    uint32_t  consumerCountHigh;
    uint32_t  consumerCountLow;
    uint32_t  bindingCount;
    uint32_t  bindingCountHigh;
    uint32_t  bindingCountLow;
    uint32_t  unackedMessages;
    uint32_t  unackedMessagesHigh;
    uint32_t  unackedMessagesLow;


    // Per-Thread Statistics
    struct PerThreadStats {
        uint64_t  msgTotalEnqueues;
        uint64_t  msgTotalDequeues;
        uint64_t  msgTxnEnqueues;
        uint64_t  msgTxnDequeues;
        uint64_t  msgPersistEnqueues;
        uint64_t  msgPersistDequeues;
        uint32_t  msgDepth;
        uint32_t  byteDepth;
        uint64_t  byteTotalEnqueues;
        uint64_t  byteTotalDequeues;
        uint64_t  byteTxnEnqueues;
        uint64_t  byteTxnDequeues;
        uint64_t  bytePersistEnqueues;
        uint64_t  bytePersistDequeues;
        uint64_t  messageLatencyCount;
        uint64_t  messageLatencyTotal;
        uint64_t  messageLatencyMin;
        uint64_t  messageLatencyMax;

    };

    struct PerThreadStats** perThreadStatsArray;

    inline struct PerThreadStats* getThreadStats() {
        int idx = getThreadIndex();
        struct PerThreadStats* threadStats = perThreadStatsArray[idx];
        if (threadStats == 0) {
            threadStats = new(PerThreadStats);
            perThreadStatsArray[idx] = threadStats;
            threadStats->msgTotalEnqueues = 0;
            threadStats->msgTotalDequeues = 0;
            threadStats->msgTxnEnqueues = 0;
            threadStats->msgTxnDequeues = 0;
            threadStats->msgPersistEnqueues = 0;
            threadStats->msgPersistDequeues = 0;
            threadStats->msgDepth = 0;
            threadStats->byteDepth = 0;
            threadStats->byteTotalEnqueues = 0;
            threadStats->byteTotalDequeues = 0;
            threadStats->byteTxnEnqueues = 0;
            threadStats->byteTxnDequeues = 0;
            threadStats->bytePersistEnqueues = 0;
            threadStats->bytePersistDequeues = 0;
            threadStats->messageLatencyCount = 0;
            threadStats->messageLatencyMin   = std::numeric_limits<uint64_t>::max();
            threadStats->messageLatencyMax   = std::numeric_limits<uint64_t>::min();
            threadStats->messageLatencyTotal = 0;

        }
        return threadStats;
    }

    void aggregatePerThreadStats(struct PerThreadStats*);

    // Private Methods
    static void writeSchema(::qpid::framing::Buffer& buf);
    void writeProperties(::qpid::framing::Buffer& buf);
    void writeStatistics(::qpid::framing::Buffer& buf,
                         bool skipHeaders = false);
    void doMethod(std::string& methodName,
                  ::qpid::framing::Buffer& inBuf,
                  ::qpid::framing::Buffer& outBuf);
    writeSchemaCall_t getWriteSchemaCall() { return writeSchema; }

  public:

    Queue(::qpid::management::ManagementAgent* agent,
                            ::qpid::management::Manageable* coreObject, ::qpid::management::Manageable* _parent, const std::string& _name, uint8_t _durable, uint8_t _autoDelete, uint8_t _exclusive);
    ~Queue();

    

    static void registerSelf(::qpid::management::ManagementAgent* agent);
    std::string& getPackageName() const { return packageName; }
    std::string& getClassName() const { return className; }
    uint8_t* getMd5Sum() const { return md5Sum; }

    // Method IDs
    static const uint32_t METHOD_PURGE = 1;

    // Accessor Methods
    inline void set_arguments (const ::qpid::framing::FieldTable& val) {
        ::qpid::sys::Mutex::ScopedLock mutex(accessLock);
        arguments = val;
        configChanged = true;
    }
    inline const ::qpid::framing::FieldTable& get_arguments() {
        ::qpid::sys::Mutex::ScopedLock mutex(accessLock);
        return arguments;
    }
    inline void inc_msgTotalEnqueues (uint64_t by = 1) {
        getThreadStats()->msgTotalEnqueues += by;
        instChanged = true;
    }
    inline void dec_msgTotalEnqueues (uint64_t by = 1) {
        getThreadStats()->msgTotalEnqueues -= by;
        instChanged = true;
    }
    inline void inc_msgTotalDequeues (uint64_t by = 1) {
        getThreadStats()->msgTotalDequeues += by;
        instChanged = true;
    }
    inline void dec_msgTotalDequeues (uint64_t by = 1) {
        getThreadStats()->msgTotalDequeues -= by;
        instChanged = true;
    }
    inline void inc_msgTxnEnqueues (uint64_t by = 1) {
        getThreadStats()->msgTxnEnqueues += by;
        instChanged = true;
    }
    inline void dec_msgTxnEnqueues (uint64_t by = 1) {
        getThreadStats()->msgTxnEnqueues -= by;
        instChanged = true;
    }
    inline void inc_msgTxnDequeues (uint64_t by = 1) {
        getThreadStats()->msgTxnDequeues += by;
        instChanged = true;
    }
    inline void dec_msgTxnDequeues (uint64_t by = 1) {
        getThreadStats()->msgTxnDequeues -= by;
        instChanged = true;
    }
    inline void inc_msgPersistEnqueues (uint64_t by = 1) {
        getThreadStats()->msgPersistEnqueues += by;
        instChanged = true;
    }
    inline void dec_msgPersistEnqueues (uint64_t by = 1) {
        getThreadStats()->msgPersistEnqueues -= by;
        instChanged = true;
    }
    inline void inc_msgPersistDequeues (uint64_t by = 1) {
        getThreadStats()->msgPersistDequeues += by;
        instChanged = true;
    }
    inline void dec_msgPersistDequeues (uint64_t by = 1) {
        getThreadStats()->msgPersistDequeues -= by;
        instChanged = true;
    }
    inline void inc_byteTotalEnqueues (uint64_t by = 1) {
        getThreadStats()->byteTotalEnqueues += by;
        instChanged = true;
    }
    inline void dec_byteTotalEnqueues (uint64_t by = 1) {
        getThreadStats()->byteTotalEnqueues -= by;
        instChanged = true;
    }
    inline void inc_byteTotalDequeues (uint64_t by = 1) {
        getThreadStats()->byteTotalDequeues += by;
        instChanged = true;
    }
    inline void dec_byteTotalDequeues (uint64_t by = 1) {
        getThreadStats()->byteTotalDequeues -= by;
        instChanged = true;
    }
    inline void inc_byteTxnEnqueues (uint64_t by = 1) {
        getThreadStats()->byteTxnEnqueues += by;
        instChanged = true;
    }
    inline void dec_byteTxnEnqueues (uint64_t by = 1) {
        getThreadStats()->byteTxnEnqueues -= by;
        instChanged = true;
    }
    inline void inc_byteTxnDequeues (uint64_t by = 1) {
        getThreadStats()->byteTxnDequeues += by;
        instChanged = true;
    }
    inline void dec_byteTxnDequeues (uint64_t by = 1) {
        getThreadStats()->byteTxnDequeues -= by;
        instChanged = true;
    }
    inline void inc_bytePersistEnqueues (uint64_t by = 1) {
        getThreadStats()->bytePersistEnqueues += by;
        instChanged = true;
    }
    inline void dec_bytePersistEnqueues (uint64_t by = 1) {
        getThreadStats()->bytePersistEnqueues -= by;
        instChanged = true;
    }
    inline void inc_bytePersistDequeues (uint64_t by = 1) {
        getThreadStats()->bytePersistDequeues += by;
        instChanged = true;
    }
    inline void dec_bytePersistDequeues (uint64_t by = 1) {
        getThreadStats()->bytePersistDequeues -= by;
        instChanged = true;
    }
    inline void inc_consumerCount (uint32_t by = 1) {
        ::qpid::sys::Mutex::ScopedLock mutex(accessLock);
        consumerCount += by;
        if (consumerCountHigh < consumerCount)
            consumerCountHigh = consumerCount;
        instChanged = true;
    }
    inline void dec_consumerCount (uint32_t by = 1) {
        ::qpid::sys::Mutex::ScopedLock mutex(accessLock);
        consumerCount -= by;
        if (consumerCountLow > consumerCount)
            consumerCountLow = consumerCount;
        instChanged = true;
    }
    inline void inc_bindingCount (uint32_t by = 1) {
        ::qpid::sys::Mutex::ScopedLock mutex(accessLock);
        bindingCount += by;
        if (bindingCountHigh < bindingCount)
            bindingCountHigh = bindingCount;
        instChanged = true;
    }
    inline void dec_bindingCount (uint32_t by = 1) {
        ::qpid::sys::Mutex::ScopedLock mutex(accessLock);
        bindingCount -= by;
        if (bindingCountLow > bindingCount)
            bindingCountLow = bindingCount;
        instChanged = true;
    }
    inline void inc_unackedMessages (uint32_t by = 1) {
        ::qpid::sys::Mutex::ScopedLock mutex(accessLock);
        unackedMessages += by;
        if (unackedMessagesHigh < unackedMessages)
            unackedMessagesHigh = unackedMessages;
        instChanged = true;
    }
    inline void dec_unackedMessages (uint32_t by = 1) {
        ::qpid::sys::Mutex::ScopedLock mutex(accessLock);
        unackedMessages -= by;
        if (unackedMessagesLow > unackedMessages)
            unackedMessagesLow = unackedMessages;
        instChanged = true;
    }
    inline void set_messageLatency (uint64_t val) {
        getThreadStats()->messageLatencyCount++;
        getThreadStats()->messageLatencyTotal += val;
        if (getThreadStats()->messageLatencyMin > val)
            getThreadStats()->messageLatencyMin = val;
        if (getThreadStats()->messageLatencyMax < val)
            getThreadStats()->messageLatencyMax = val;
        instChanged = true;
    }

};

}}}}}

#endif  /*!_MANAGEMENT_QUEUE_*/
