
#ifndef _MANAGEMENT_ACL_
#define _MANAGEMENT_ACL_

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
namespace acl {


class Acl : public ::qpid::management::ManagementObject
{
  private:

    static std::string packageName;
    static std::string className;
    static uint8_t     md5Sum[16];


    // Properties
    ::qpid::management::ObjectId brokerRef;
    std::string policyFile;
    uint8_t enforcingAcl;
    uint8_t transferAcl;
    int64_t lastAclLoad;

    // Statistics


    // Per-Thread Statistics
    struct PerThreadStats {
        uint64_t  aclDenyCount;

    };

    struct PerThreadStats** perThreadStatsArray;

    inline struct PerThreadStats* getThreadStats() {
        int idx = getThreadIndex();
        struct PerThreadStats* threadStats = perThreadStatsArray[idx];
        if (threadStats == 0) {
            threadStats = new(PerThreadStats);
            perThreadStatsArray[idx] = threadStats;
            threadStats->aclDenyCount = 0;

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

    Acl(::qpid::management::ManagementAgent* agent,
                            ::qpid::management::Manageable* coreObject, ::qpid::management::Manageable* _parent);
    ~Acl();

    

    static void registerSelf(::qpid::management::ManagementAgent* agent);
    std::string& getPackageName() const { return packageName; }
    std::string& getClassName() const { return className; }
    uint8_t* getMd5Sum() const { return md5Sum; }

    // Method IDs
    static const uint32_t METHOD_RELOADACLFILE = 1;

    // Accessor Methods
    inline void set_brokerRef (const ::qpid::management::ObjectId& val) {
        ::qpid::sys::Mutex::ScopedLock mutex(accessLock);
        brokerRef = val;
        configChanged = true;
    }
    inline const ::qpid::management::ObjectId& get_brokerRef() {
        ::qpid::sys::Mutex::ScopedLock mutex(accessLock);
        return brokerRef;
    }
    inline void set_policyFile (const std::string& val) {
        ::qpid::sys::Mutex::ScopedLock mutex(accessLock);
        policyFile = val;
        configChanged = true;
    }
    inline const std::string& get_policyFile() {
        ::qpid::sys::Mutex::ScopedLock mutex(accessLock);
        return policyFile;
    }
    inline void set_enforcingAcl (uint8_t val) {
        ::qpid::sys::Mutex::ScopedLock mutex(accessLock);
        enforcingAcl = val;
        configChanged = true;
    }
    inline uint8_t get_enforcingAcl() {
        ::qpid::sys::Mutex::ScopedLock mutex(accessLock);
        return enforcingAcl;
    }
    inline void set_transferAcl (uint8_t val) {
        ::qpid::sys::Mutex::ScopedLock mutex(accessLock);
        transferAcl = val;
        configChanged = true;
    }
    inline uint8_t get_transferAcl() {
        ::qpid::sys::Mutex::ScopedLock mutex(accessLock);
        return transferAcl;
    }
    inline void set_lastAclLoad (int64_t val) {
        ::qpid::sys::Mutex::ScopedLock mutex(accessLock);
        lastAclLoad = val;
        configChanged = true;
    }
    inline int64_t get_lastAclLoad() {
        ::qpid::sys::Mutex::ScopedLock mutex(accessLock);
        return lastAclLoad;
    }
    inline void inc_aclDenyCount (uint64_t by = 1) {
        getThreadStats()->aclDenyCount += by;
        instChanged = true;
    }
    inline void dec_aclDenyCount (uint64_t by = 1) {
        getThreadStats()->aclDenyCount -= by;
        instChanged = true;
    }

};

}}}}}

#endif  /*!_MANAGEMENT_ACL_*/
