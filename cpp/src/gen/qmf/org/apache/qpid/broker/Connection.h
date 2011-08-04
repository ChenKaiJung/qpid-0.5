
#ifndef _MANAGEMENT_CONNECTION_
#define _MANAGEMENT_CONNECTION_

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


class Connection : public ::qpid::management::ManagementObject
{
  private:

    static std::string packageName;
    static std::string className;
    static uint8_t     md5Sum[16];

    uint8_t presenceMask[1];
    static const uint8_t presenceByte_remoteProcessName = 0;
    static const uint8_t presenceMask_remoteProcessName = 1;
    static const uint8_t presenceByte_remotePid = 0;
    static const uint8_t presenceMask_remotePid = 2;
    static const uint8_t presenceByte_remoteParentPid = 0;
    static const uint8_t presenceMask_remoteParentPid = 4;



    // Properties
    ::qpid::management::ObjectId vhostRef;
    std::string address;
    uint8_t incoming;
    uint8_t SystemConnection;
    uint8_t federationLink;
    std::string authIdentity;
    std::string remoteProcessName;
    uint32_t remotePid;
    uint32_t remoteParentPid;

    // Statistics
    uint8_t  closing;


    // Per-Thread Statistics
    struct PerThreadStats {
        uint64_t  framesFromClient;
        uint64_t  framesToClient;
        uint64_t  bytesFromClient;
        uint64_t  bytesToClient;

    };

    struct PerThreadStats** perThreadStatsArray;

    inline struct PerThreadStats* getThreadStats() {
        int idx = getThreadIndex();
        struct PerThreadStats* threadStats = perThreadStatsArray[idx];
        if (threadStats == 0) {
            threadStats = new(PerThreadStats);
            perThreadStatsArray[idx] = threadStats;
            threadStats->framesFromClient = 0;
            threadStats->framesToClient = 0;
            threadStats->bytesFromClient = 0;
            threadStats->bytesToClient = 0;

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

    Connection(::qpid::management::ManagementAgent* agent,
                            ::qpid::management::Manageable* coreObject, ::qpid::management::Manageable* _parent, const std::string& _address, uint8_t _incoming, uint8_t _SystemConnection);
    ~Connection();

    

    static void registerSelf(::qpid::management::ManagementAgent* agent);
    std::string& getPackageName() const { return packageName; }
    std::string& getClassName() const { return className; }
    uint8_t* getMd5Sum() const { return md5Sum; }

    // Method IDs
    static const uint32_t METHOD_CLOSE = 1;

    // Accessor Methods
    inline void set_federationLink (uint8_t val) {
        ::qpid::sys::Mutex::ScopedLock mutex(accessLock);
        federationLink = val;
        configChanged = true;
    }
    inline uint8_t get_federationLink() {
        ::qpid::sys::Mutex::ScopedLock mutex(accessLock);
        return federationLink;
    }
    inline void set_authIdentity (const std::string& val) {
        ::qpid::sys::Mutex::ScopedLock mutex(accessLock);
        authIdentity = val;
        configChanged = true;
    }
    inline const std::string& get_authIdentity() {
        ::qpid::sys::Mutex::ScopedLock mutex(accessLock);
        return authIdentity;
    }
    inline void set_remoteProcessName (const std::string& val) {
        ::qpid::sys::Mutex::ScopedLock mutex(accessLock);
        remoteProcessName = val;
        presenceMask[presenceByte_remoteProcessName] |= presenceMask_remoteProcessName;
        configChanged = true;
    }
    inline const std::string& get_remoteProcessName() {
        ::qpid::sys::Mutex::ScopedLock mutex(accessLock);
        return remoteProcessName;
    }
    inline void clr_remoteProcessName() {
        presenceMask[presenceByte_remoteProcessName] &= ~presenceMask_remoteProcessName;
        configChanged = true;
    }
    inline bool isSet_remoteProcessName() {
        return (presenceMask[presenceByte_remoteProcessName] & presenceMask_remoteProcessName) != 0;
    }
    inline void set_remotePid (uint32_t val) {
        ::qpid::sys::Mutex::ScopedLock mutex(accessLock);
        remotePid = val;
        presenceMask[presenceByte_remotePid] |= presenceMask_remotePid;
        configChanged = true;
    }
    inline uint32_t get_remotePid() {
        ::qpid::sys::Mutex::ScopedLock mutex(accessLock);
        return remotePid;
    }
    inline void clr_remotePid() {
        presenceMask[presenceByte_remotePid] &= ~presenceMask_remotePid;
        configChanged = true;
    }
    inline bool isSet_remotePid() {
        return (presenceMask[presenceByte_remotePid] & presenceMask_remotePid) != 0;
    }
    inline void set_remoteParentPid (uint32_t val) {
        ::qpid::sys::Mutex::ScopedLock mutex(accessLock);
        remoteParentPid = val;
        presenceMask[presenceByte_remoteParentPid] |= presenceMask_remoteParentPid;
        configChanged = true;
    }
    inline uint32_t get_remoteParentPid() {
        ::qpid::sys::Mutex::ScopedLock mutex(accessLock);
        return remoteParentPid;
    }
    inline void clr_remoteParentPid() {
        presenceMask[presenceByte_remoteParentPid] &= ~presenceMask_remoteParentPid;
        configChanged = true;
    }
    inline bool isSet_remoteParentPid() {
        return (presenceMask[presenceByte_remoteParentPid] & presenceMask_remoteParentPid) != 0;
    }
    inline void set_closing (uint8_t val) {
        ::qpid::sys::Mutex::ScopedLock mutex(accessLock);
        closing = val;
        instChanged = true;
    }
    inline uint8_t get_closing() {
        ::qpid::sys::Mutex::ScopedLock mutex(accessLock);
        return closing;
    }
    inline void inc_framesFromClient (uint64_t by = 1) {
        getThreadStats()->framesFromClient += by;
        instChanged = true;
    }
    inline void dec_framesFromClient (uint64_t by = 1) {
        getThreadStats()->framesFromClient -= by;
        instChanged = true;
    }
    inline void inc_framesToClient (uint64_t by = 1) {
        getThreadStats()->framesToClient += by;
        instChanged = true;
    }
    inline void dec_framesToClient (uint64_t by = 1) {
        getThreadStats()->framesToClient -= by;
        instChanged = true;
    }
    inline void inc_bytesFromClient (uint64_t by = 1) {
        getThreadStats()->bytesFromClient += by;
        instChanged = true;
    }
    inline void dec_bytesFromClient (uint64_t by = 1) {
        getThreadStats()->bytesFromClient -= by;
        instChanged = true;
    }
    inline void inc_bytesToClient (uint64_t by = 1) {
        getThreadStats()->bytesToClient += by;
        instChanged = true;
    }
    inline void dec_bytesToClient (uint64_t by = 1) {
        getThreadStats()->bytesToClient -= by;
        instChanged = true;
    }

};

}}}}}

#endif  /*!_MANAGEMENT_CONNECTION_*/
