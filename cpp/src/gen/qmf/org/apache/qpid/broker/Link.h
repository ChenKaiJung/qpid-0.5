
#ifndef _MANAGEMENT_LINK_
#define _MANAGEMENT_LINK_

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


class Link : public ::qpid::management::ManagementObject
{
  private:

    static std::string packageName;
    static std::string className;
    static uint8_t     md5Sum[16];


    // Properties
    ::qpid::management::ObjectId vhostRef;
    std::string host;
    uint16_t port;
    std::string transport;
    uint8_t durable;

    // Statistics
    std::string  state;
    std::string  lastError;


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

    Link(::qpid::management::ManagementAgent* agent,
                            ::qpid::management::Manageable* coreObject, ::qpid::management::Manageable* _parent, const std::string& _host, uint16_t _port, const std::string& _transport, uint8_t _durable);
    ~Link();

    

    static void registerSelf(::qpid::management::ManagementAgent* agent);
    std::string& getPackageName() const { return packageName; }
    std::string& getClassName() const { return className; }
    uint8_t* getMd5Sum() const { return md5Sum; }

    // Method IDs
    static const uint32_t METHOD_CLOSE = 1;
    static const uint32_t METHOD_BRIDGE = 2;

    // Accessor Methods
    inline void set_state (const std::string& val) {
        ::qpid::sys::Mutex::ScopedLock mutex(accessLock);
        state = val;
        instChanged = true;
    }
    inline const std::string& get_state() {
        ::qpid::sys::Mutex::ScopedLock mutex(accessLock);
        return state;
    }
    inline void set_lastError (const std::string& val) {
        ::qpid::sys::Mutex::ScopedLock mutex(accessLock);
        lastError = val;
        instChanged = true;
    }
    inline const std::string& get_lastError() {
        ::qpid::sys::Mutex::ScopedLock mutex(accessLock);
        return lastError;
    }

};

}}}}}

#endif  /*!_MANAGEMENT_LINK_*/
