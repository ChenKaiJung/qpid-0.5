
#ifndef _MANAGEMENT_CLUSTER_
#define _MANAGEMENT_CLUSTER_

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
namespace cluster {


class Cluster : public ::qpid::management::ManagementObject
{
  private:

    static std::string packageName;
    static std::string className;
    static uint8_t     md5Sum[16];


    // Properties
    ::qpid::management::ObjectId brokerRef;
    std::string clusterName;
    std::string clusterID;
    std::string memberID;
    std::string publishedURL;
    uint16_t clusterSize;
    std::string status;
    std::string members;
    std::string memberIDs;

    // Statistics


    // Private Methods
    static void writeSchema(::qpid::framing::Buffer& buf);
    void writeProperties(::qpid::framing::Buffer& buf);
    void writeStatistics(::qpid::framing::Buffer& buf,
                         bool skipHeaders = false);
    void doMethod(std::string& methodName,
                  ::qpid::framing::Buffer& inBuf,
                  ::qpid::framing::Buffer& outBuf);
    writeSchemaCall_t getWriteSchemaCall() { return writeSchema; }

    // Stub for getInstChanged.  There are no statistics in this class.
    bool getInstChanged() { return false; }
    bool hasInst() { return false; }

  public:

    Cluster(::qpid::management::ManagementAgent* agent,
                            ::qpid::management::Manageable* coreObject, ::qpid::management::Manageable* _parent, const std::string& _clusterName, const std::string& _publishedURL);
    ~Cluster();

    

    static void registerSelf(::qpid::management::ManagementAgent* agent);
    std::string& getPackageName() const { return packageName; }
    std::string& getClassName() const { return className; }
    uint8_t* getMd5Sum() const { return md5Sum; }

    // Method IDs
    static const uint32_t METHOD_STOPCLUSTERNODE = 1;
    static const uint32_t METHOD_STOPFULLCLUSTER = 2;

    // Accessor Methods
    inline void set_clusterID (const std::string& val) {
        ::qpid::sys::Mutex::ScopedLock mutex(accessLock);
        clusterID = val;
        configChanged = true;
    }
    inline const std::string& get_clusterID() {
        ::qpid::sys::Mutex::ScopedLock mutex(accessLock);
        return clusterID;
    }
    inline void set_memberID (const std::string& val) {
        ::qpid::sys::Mutex::ScopedLock mutex(accessLock);
        memberID = val;
        configChanged = true;
    }
    inline const std::string& get_memberID() {
        ::qpid::sys::Mutex::ScopedLock mutex(accessLock);
        return memberID;
    }
    inline void set_clusterSize (uint16_t val) {
        ::qpid::sys::Mutex::ScopedLock mutex(accessLock);
        clusterSize = val;
        configChanged = true;
    }
    inline uint16_t get_clusterSize() {
        ::qpid::sys::Mutex::ScopedLock mutex(accessLock);
        return clusterSize;
    }
    inline void set_status (const std::string& val) {
        ::qpid::sys::Mutex::ScopedLock mutex(accessLock);
        status = val;
        configChanged = true;
    }
    inline const std::string& get_status() {
        ::qpid::sys::Mutex::ScopedLock mutex(accessLock);
        return status;
    }
    inline void set_members (const std::string& val) {
        ::qpid::sys::Mutex::ScopedLock mutex(accessLock);
        members = val;
        configChanged = true;
    }
    inline const std::string& get_members() {
        ::qpid::sys::Mutex::ScopedLock mutex(accessLock);
        return members;
    }
    inline void set_memberIDs (const std::string& val) {
        ::qpid::sys::Mutex::ScopedLock mutex(accessLock);
        memberIDs = val;
        configChanged = true;
    }
    inline const std::string& get_memberIDs() {
        ::qpid::sys::Mutex::ScopedLock mutex(accessLock);
        return memberIDs;
    }

};

}}}}}

#endif  /*!_MANAGEMENT_CLUSTER_*/
