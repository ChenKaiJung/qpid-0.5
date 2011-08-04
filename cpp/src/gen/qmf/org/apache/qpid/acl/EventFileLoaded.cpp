
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
#include "EventFileLoaded.h"

using namespace qmf::org::apache::qpid::acl;
using namespace qpid::framing;
using           qpid::management::ManagementAgent;
using           qpid::management::Manageable;
using           qpid::management::ManagementObject;
using           qpid::management::Args;
using           std::string;

string  EventFileLoaded::packageName  = string ("org.apache.qpid.acl");
string  EventFileLoaded::eventName    = string ("fileLoaded");
uint8_t EventFileLoaded::md5Sum[16]   =
    {0x9b,0x79,0x80,0xfe,0xa6,0xfe,0x94,0x44,0x3c,0x21,0xf9,0xbe,0x10,0x90,0x74,0x7d};

EventFileLoaded::EventFileLoaded (const std::string& _userId) :
    userId(_userId)
{}

namespace {
    const string NAME("name");
    const string TYPE("type");
    const string DESC("desc");
    const string ARGCOUNT("argCount");
    const string ARGS("args");
}

void EventFileLoaded::registerSelf(ManagementAgent* agent)
{
    agent->registerEvent(packageName, eventName, md5Sum, writeSchema);
}

void EventFileLoaded::writeSchema (Buffer& buf)
{
    FieldTable ft;

    // Schema class header:
    buf.putOctet       (CLASS_KIND_EVENT);
    buf.putShortString (packageName); // Package Name
    buf.putShortString (eventName);   // Event Name
    buf.putBin128      (md5Sum);      // Schema Hash
    buf.putShort       (1); // Argument Count

    // Arguments
    ft.clear();
    ft.setString (NAME,    "userId");
    ft.setInt    (TYPE,    TYPE_SSTR);
    buf.put (ft);


}

void EventFileLoaded::encode(::qpid::framing::Buffer& buf) const
{
    buf.putShortString(userId);

}
