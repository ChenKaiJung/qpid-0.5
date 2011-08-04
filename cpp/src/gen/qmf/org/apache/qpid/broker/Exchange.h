
#ifndef _MANAGEMENT_EXCHANGE_
#define _MANAGEMENT_EXCHANGE_

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


class Exchange : public ::qpid::management::ManagementObject
{
  private:

    static std::string packageName;
    static std::string className;
    static uint8_t     md5Sum[16];


    // Properties
    ::qpid::management::ObjectId vhostRef;
    std::string name;
    std::string type;
    uint8_t durable;
    ::qpid::framing::FieldTable arguments;

    // Statistics
    uint32_t  producerCount;
    uint32_t  producerCountHigh;
    uint32_t  producerCountLow;
    uint32_t  bindingCount;
    uint32_t  bindingCountHigh;
    uint32_t  bindingCountLow;


    // Per-Thread Statistics
    struct PerThreadStats {
        uint64_t  msgReceives;
        uint64_t  msgDrops;
        uint64_t  msgRoutes;
        uint64_t  byteReceives;
        uint64_t  byteDrops;
        uint64_t  byteRoutes;

    };

    struct PerThreadStats** perThreadStatsArray;

    inline struct PerThreadStats* getThreadStats() {
        int idx = getThreadIndex();
        struct PerThreadStats* threadStats = perThreadStatsArray[idx];
        if (threadStats == 0) {
            threadStats = new(PerThreadStats);
            perThreadStatsArray[idx] = threadStats;
            threadStats->msgReceives = 0;
            threadStats->msgDrops = 0;
            threadStats->msgRoutes = 0;
            threadStats->byteReceives = 0;
            threadStats->byteDrops = 0;
            threadStats->byteRoutes = 0;

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

    Exchange(::qpid::management::ManagementAgent* agent,
                            ::qpid::management::Manageable* coreObject, ::qpid::management::Manageable* _parent, const std::string& _name, uint8_t _durable);
    ~Exchange();

    

    static void registerSelf(::qpid::management::ManagementAgent* agent);
    std::string& getPackageName() const { return packageName; }
    std::string& getClassName() const { return className; }
    uint8_t* getMd5Sum() const { return md5Sum; }

    // Method IDs

    // Accessor Methods
    inline void set_type (const std::string& val) {
        ::qpid::sys::Mutex::ScopedLock mutex(accessLock);
        type = val;
        configChanged = true;
    }
    inline const std::string& get_type() {
        ::qpid::sys::Mutex::ScopedLock mutex(accessLock);
        return type;
    }
    inline void set_arguments (const ::qpid::framing::FieldTable& val) {
        ::qpid::sys::Mutex::ScopedLock mutex(accessLock);
        arguments = val;
        configChanged = true;
    }
    inline const ::qpid::framing::FieldTable& get_arguments() {
        ::qpid::sys::Mutex::ScopedLock mutex(accessLock);
        return arguments;
    }
    inline void inc_producerCount (uint32_t by = 1) {
        ::qpid::sys::Mutex::ScopedLock mutex(accessLock);
        producerCount += by;
        if (producerCountHigh < producerCount)
            producerCountHigh = producerCount;
        instChanged = true;
    }
    inline void dec_producerCount (uint32_t by = 1) {
        ::qpid::sys::Mutex::ScopedLock mutex(accessLock);
        producerCount -= by;
        if (producerCountLow > producerCount)
            producerCountLow = producerCount;
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
    inline void inc_msgReceives (uint64_t by = 1) {
        getThreadStats()->msgReceives += by;
        instChanged = true;
    }
    inline void dec_msgReceives (uint64_t by = 1) {
        getThreadStats()->msgReceives -= by;
        instChanged = true;
    }
    inline void inc_msgDrops (uint64_t by = 1) {
        getThreadStats()->msgDrops += by;
        instChanged = true;
    }
    inline void dec_msgDrops (uint64_t by = 1) {
        getThreadStats()->msgDrops -= by;
        instChanged = true;
    }
    inline void inc_msgRoutes (uint64_t by = 1) {
        getThreadStats()->msgRoutes += by;
        instChanged = true;
    }
    inline void dec_msgRoutes (uint64_t by = 1) {
        getThreadStats()->msgRoutes -= by;
        instChanged = true;
    }
    inline void inc_byteReceives (uint64_t by = 1) {
        getThreadStats()->byteReceives += by;
        instChanged = true;
    }
    inline void dec_byteReceives (uint64_t by = 1) {
        getThreadStats()->byteReceives -= by;
        instChanged = true;
    }
    inline void inc_byteDrops (uint64_t by = 1) {
        getThreadStats()->byteDrops += by;
        instChanged = true;
    }
    inline void dec_byteDrops (uint64_t by = 1) {
        getThreadStats()->byteDrops -= by;
        instChanged = true;
    }
    inline void inc_byteRoutes (uint64_t by = 1) {
        getThreadStats()->byteRoutes += by;
        instChanged = true;
    }
    inline void dec_byteRoutes (uint64_t by = 1) {
        getThreadStats()->byteRoutes -= by;
        instChanged = true;
    }

};

}}}}}

#endif  /*!_MANAGEMENT_EXCHANGE_*/
