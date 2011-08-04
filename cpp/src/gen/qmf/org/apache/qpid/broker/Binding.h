
#ifndef _MANAGEMENT_BINDING_
#define _MANAGEMENT_BINDING_

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


class Binding : public ::qpid::management::ManagementObject
{
  private:

    static std::string packageName;
    static std::string className;
    static uint8_t     md5Sum[16];

    uint8_t presenceMask[1];
    static const uint8_t presenceByte_origin = 0;
    static const uint8_t presenceMask_origin = 1;



    // Properties
    ::qpid::management::ObjectId exchangeRef;
    ::qpid::management::ObjectId queueRef;
    std::string bindingKey;
    ::qpid::framing::FieldTable arguments;
    std::string origin;

    // Statistics


    // Per-Thread Statistics
    struct PerThreadStats {
        uint64_t  msgMatched;

    };

    struct PerThreadStats** perThreadStatsArray;

    inline struct PerThreadStats* getThreadStats() {
        int idx = getThreadIndex();
        struct PerThreadStats* threadStats = perThreadStatsArray[idx];
        if (threadStats == 0) {
            threadStats = new(PerThreadStats);
            perThreadStatsArray[idx] = threadStats;
            threadStats->msgMatched = 0;

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

    Binding(::qpid::management::ManagementAgent* agent,
                            ::qpid::management::Manageable* coreObject, ::qpid::management::Manageable* _parent, const ::qpid::management::ObjectId& _queueRef, const std::string& _bindingKey, const ::qpid::framing::FieldTable& _arguments);
    ~Binding();

    

    static void registerSelf(::qpid::management::ManagementAgent* agent);
    std::string& getPackageName() const { return packageName; }
    std::string& getClassName() const { return className; }
    uint8_t* getMd5Sum() const { return md5Sum; }

    // Method IDs

    // Accessor Methods
    inline void set_origin (const std::string& val) {
        ::qpid::sys::Mutex::ScopedLock mutex(accessLock);
        origin = val;
        presenceMask[presenceByte_origin] |= presenceMask_origin;
        configChanged = true;
    }
    inline const std::string& get_origin() {
        ::qpid::sys::Mutex::ScopedLock mutex(accessLock);
        return origin;
    }
    inline void clr_origin() {
        presenceMask[presenceByte_origin] &= ~presenceMask_origin;
        configChanged = true;
    }
    inline bool isSet_origin() {
        return (presenceMask[presenceByte_origin] & presenceMask_origin) != 0;
    }
    inline void inc_msgMatched (uint64_t by = 1) {
        getThreadStats()->msgMatched += by;
        instChanged = true;
    }
    inline void dec_msgMatched (uint64_t by = 1) {
        getThreadStats()->msgMatched -= by;
        instChanged = true;
    }

};

}}}}}

#endif  /*!_MANAGEMENT_BINDING_*/
