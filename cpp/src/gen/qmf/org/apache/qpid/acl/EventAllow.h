
#ifndef _MANAGEMENT_ALLOW_
#define _MANAGEMENT_ALLOW_

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

#include "qpid/management/ManagementEvent.h"
#include "qpid/framing/FieldTable.h"
#include "qpid/framing/Uuid.h"

namespace qmf {
namespace org {
namespace apache {
namespace qpid {
namespace acl {


class EventAllow : public ::qpid::management::ManagementEvent
{
  private:
    static void writeSchema (::qpid::framing::Buffer& buf);
    static std::string packageName;
    static std::string eventName;
    static uint8_t md5Sum[16];

    const std::string& userId;
    const std::string& action;
    const std::string& objectType;
    const std::string& objectName;
    const ::qpid::framing::FieldTable& arguments;


  public:
    writeSchemaCall_t getWriteSchemaCall(void) { return writeSchema; }

    EventAllow(const std::string& _userId,
        const std::string& _action,
        const std::string& _objectType,
        const std::string& _objectName,
        const ::qpid::framing::FieldTable& _arguments);
    ~EventAllow() {};

    static void registerSelf(::qpid::management::ManagementAgent* agent);
    std::string& getPackageName() const { return packageName; }
    std::string& getEventName() const { return eventName; }
    uint8_t* getMd5Sum() const { return md5Sum; }
    uint8_t getSeverity() const { return 6; }
    void encode(::qpid::framing::Buffer& buffer) const;
};

}}}}}

#endif  /*!_MANAGEMENT_ALLOW_*/
