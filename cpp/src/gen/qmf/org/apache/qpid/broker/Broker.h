
#ifndef _MANAGEMENT_BROKER_
#define _MANAGEMENT_BROKER_

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


class Broker : public ::qpid::management::ManagementObject
{
  private:

    static std::string packageName;
    static std::string className;
    static uint8_t     md5Sum[16];

    uint8_t presenceMask[1];
    static const uint8_t presenceByte_dataDir = 0;
    static const uint8_t presenceMask_dataDir = 1;



    // Properties
    ::qpid::management::ObjectId systemRef;
    uint16_t port;
    uint16_t workerThreads;
    uint16_t maxConns;
    uint16_t connBacklog;
    uint32_t stagingThreshold;
    uint16_t mgmtPubInterval;
    std::string version;
    std::string dataDir;

    // Statistics
    uint64_t  uptime;


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

    Broker(::qpid::management::ManagementAgent* agent,
                            ::qpid::management::Manageable* coreObject, ::qpid::management::Manageable* _parent, uint16_t _port);
    ~Broker();

    

    static void registerSelf(::qpid::management::ManagementAgent* agent);
    std::string& getPackageName() const { return packageName; }
    std::string& getClassName() const { return className; }
    uint8_t* getMd5Sum() const { return md5Sum; }

    // Method IDs
    static const uint32_t METHOD_ECHO = 1;
    static const uint32_t METHOD_CONNECT = 2;
    static const uint32_t METHOD_QUEUEMOVEMESSAGES = 3;

    // Accessor Methods
    inline void set_workerThreads (uint16_t val) {
        ::qpid::sys::Mutex::ScopedLock mutex(accessLock);
        workerThreads = val;
        configChanged = true;
    }
    inline uint16_t get_workerThreads() {
        ::qpid::sys::Mutex::ScopedLock mutex(accessLock);
        return workerThreads;
    }
    inline void set_maxConns (uint16_t val) {
        ::qpid::sys::Mutex::ScopedLock mutex(accessLock);
        maxConns = val;
        configChanged = true;
    }
    inline uint16_t get_maxConns() {
        ::qpid::sys::Mutex::ScopedLock mutex(accessLock);
        return maxConns;
    }
    inline void set_connBacklog (uint16_t val) {
        ::qpid::sys::Mutex::ScopedLock mutex(accessLock);
        connBacklog = val;
        configChanged = true;
    }
    inline uint16_t get_connBacklog() {
        ::qpid::sys::Mutex::ScopedLock mutex(accessLock);
        return connBacklog;
    }
    inline void set_stagingThreshold (uint32_t val) {
        ::qpid::sys::Mutex::ScopedLock mutex(accessLock);
        stagingThreshold = val;
        configChanged = true;
    }
    inline uint32_t get_stagingThreshold() {
        ::qpid::sys::Mutex::ScopedLock mutex(accessLock);
        return stagingThreshold;
    }
    inline void set_mgmtPubInterval (uint16_t val) {
        ::qpid::sys::Mutex::ScopedLock mutex(accessLock);
        mgmtPubInterval = val;
        configChanged = true;
    }
    inline uint16_t get_mgmtPubInterval() {
        ::qpid::sys::Mutex::ScopedLock mutex(accessLock);
        return mgmtPubInterval;
    }
    inline void set_version (const std::string& val) {
        ::qpid::sys::Mutex::ScopedLock mutex(accessLock);
        version = val;
        configChanged = true;
    }
    inline const std::string& get_version() {
        ::qpid::sys::Mutex::ScopedLock mutex(accessLock);
        return version;
    }
    inline void set_dataDir (const std::string& val) {
        ::qpid::sys::Mutex::ScopedLock mutex(accessLock);
        dataDir = val;
        presenceMask[presenceByte_dataDir] |= presenceMask_dataDir;
        configChanged = true;
    }
    inline const std::string& get_dataDir() {
        ::qpid::sys::Mutex::ScopedLock mutex(accessLock);
        return dataDir;
    }
    inline void clr_dataDir() {
        presenceMask[presenceByte_dataDir] &= ~presenceMask_dataDir;
        configChanged = true;
    }
    inline bool isSet_dataDir() {
        return (presenceMask[presenceByte_dataDir] & presenceMask_dataDir) != 0;
    }
    inline void set_uptime (uint64_t val) {
        ::qpid::sys::Mutex::ScopedLock mutex(accessLock);
        uptime = val;
        instChanged = true;
    }
    inline uint64_t get_uptime() {
        ::qpid::sys::Mutex::ScopedLock mutex(accessLock);
        return uptime;
    }

};

}}}}}

#endif  /*!_MANAGEMENT_BROKER_*/
