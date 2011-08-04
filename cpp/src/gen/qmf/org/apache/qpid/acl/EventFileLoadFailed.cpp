
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

#include "qpid/log/Statement.h"
#include "qpid/framing/FieldTable.h"
#include "qpid/management/Manageable.h" 
#include "qpid/agent/ManagementAgent.h"
#include "EventFileLoadFailed.h"

using namespace qmf::org::apache::qpid::acl;
using namespace qpid::framing;
using           qpid::management::ManagementAgent;
using           qpid::management::Manageable;
using           qpid::management::ManagementObject;
using           qpid::management::Args;
using           std::string;

string  EventFileLoadFailed::packageName  = string ("org.apache.qpid.acl");
string  EventFileLoadFailed::eventName    = string ("fileLoadFailed");
uint8_t EventFileLoadFailed::md5Sum[16]   =
    {0x23,0xf8,0xc2,0x52,0xc1,0xf8,0x4a,0x8d,0x91,0x21,0xab,0x69,0x7b,0xeb,0xfa,0x7a};

EventFileLoadFailed::EventFileLoadFailed (const std::string& _userId,
        const std::string& _reason) :
    userId(_userId),
    reason(_reason)
{}

namespace {
    const string NAME("name");
    const string TYPE("type");
    const string DESC("desc");
    const string ARGCOUNT("argCount");
    const string ARGS("args");
}

void EventFileLoadFailed::registerSelf(ManagementAgent* agent)
{
    agent->registerEvent(packageName, eventName, md5Sum, writeSchema);
}

void EventFileLoadFailed::writeSchema (Buffer& buf)
{
    FieldTable ft;

    // Schema class header:
    buf.putOctet       (CLASS_KIND_EVENT);
    buf.putShortString (packageName); // Package Name
    buf.putShortString (eventName);   // Event Name
    buf.putBin128      (md5Sum);      // Schema Hash
    buf.putShort       (2); // Argument Count

    // Arguments
    ft.clear();
    ft.setString (NAME,    "userId");
    ft.setInt    (TYPE,    TYPE_SSTR);
    buf.put (ft);

    ft.clear();
    ft.setString (NAME,    "reason");
    ft.setInt    (TYPE,    TYPE_SSTR);
    buf.put (ft);


}

void EventFileLoadFailed::encode(::qpid::framing::Buffer& buf) const
{
    buf.putShortString(userId);
    buf.putShortString(reason);

}
