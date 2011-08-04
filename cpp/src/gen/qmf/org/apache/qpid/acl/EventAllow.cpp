
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
#include "EventAllow.h"

using namespace qmf::org::apache::qpid::acl;
using namespace qpid::framing;
using           qpid::management::ManagementAgent;
using           qpid::management::Manageable;
using           qpid::management::ManagementObject;
using           qpid::management::Args;
using           std::string;

string  EventAllow::packageName  = string ("org.apache.qpid.acl");
string  EventAllow::eventName    = string ("allow");
uint8_t EventAllow::md5Sum[16]   =
    {0x7a,0xf6,0x20,0x16,0xb7,0x10,0x15,0xb5,0x46,0x2c,0xc9,0x3e,0x2a,0x27,0x27,0x59};

EventAllow::EventAllow (const std::string& _userId,
        const std::string& _action,
        const std::string& _objectType,
        const std::string& _objectName,
        const ::qpid::framing::FieldTable& _arguments) :
    userId(_userId),
    action(_action),
    objectType(_objectType),
    objectName(_objectName),
    arguments(_arguments)
{}

namespace {
    const string NAME("name");
    const string TYPE("type");
    const string DESC("desc");
    const string ARGCOUNT("argCount");
    const string ARGS("args");
}

void EventAllow::registerSelf(ManagementAgent* agent)
{
    agent->registerEvent(packageName, eventName, md5Sum, writeSchema);
}

void EventAllow::writeSchema (Buffer& buf)
{
    FieldTable ft;

    // Schema class header:
    buf.putOctet       (CLASS_KIND_EVENT);
    buf.putShortString (packageName); // Package Name
    buf.putShortString (eventName);   // Event Name
    buf.putBin128      (md5Sum);      // Schema Hash
    buf.putShort       (5); // Argument Count

    // Arguments
    ft.clear();
    ft.setString (NAME,    "userId");
    ft.setInt    (TYPE,    TYPE_SSTR);
    buf.put (ft);

    ft.clear();
    ft.setString (NAME,    "action");
    ft.setInt    (TYPE,    TYPE_SSTR);
    buf.put (ft);

    ft.clear();
    ft.setString (NAME,    "objectType");
    ft.setInt    (TYPE,    TYPE_SSTR);
    buf.put (ft);

    ft.clear();
    ft.setString (NAME,    "objectName");
    ft.setInt    (TYPE,    TYPE_SSTR);
    buf.put (ft);

    ft.clear();
    ft.setString (NAME,    "arguments");
    ft.setInt    (TYPE,    TYPE_FTABLE);
    buf.put (ft);


}

void EventAllow::encode(::qpid::framing::Buffer& buf) const
{
    buf.putShortString(userId);
    buf.putShortString(action);
    buf.putShortString(objectType);
    buf.putShortString(objectName);
    arguments.encode(buf);

}
