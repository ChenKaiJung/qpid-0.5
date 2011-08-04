
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
#include "EventClientConnectFail.h"

using namespace qmf::org::apache::qpid::broker;
using namespace qpid::framing;
using           qpid::management::ManagementAgent;
using           qpid::management::Manageable;
using           qpid::management::ManagementObject;
using           qpid::management::Args;
using           std::string;

string  EventClientConnectFail::packageName  = string ("org.apache.qpid.broker");
string  EventClientConnectFail::eventName    = string ("clientConnectFail");
uint8_t EventClientConnectFail::md5Sum[16]   =
    {0xe6,0x58,0x6,0xac,0x3a,0x74,0x47,0x8f,0x1,0x90,0x2e,0xa6,0xe6,0xee,0x21,0xe1};

EventClientConnectFail::EventClientConnectFail (const std::string& _rhost,
        const std::string& _user,
        const std::string& _reason) :
    rhost(_rhost),
    user(_user),
    reason(_reason)
{}

namespace {
    const string NAME("name");
    const string TYPE("type");
    const string DESC("desc");
    const string ARGCOUNT("argCount");
    const string ARGS("args");
}

void EventClientConnectFail::registerSelf(ManagementAgent* agent)
{
    agent->registerEvent(packageName, eventName, md5Sum, writeSchema);
}

void EventClientConnectFail::writeSchema (Buffer& buf)
{
    FieldTable ft;

    // Schema class header:
    buf.putOctet       (CLASS_KIND_EVENT);
    buf.putShortString (packageName); // Package Name
    buf.putShortString (eventName);   // Event Name
    buf.putBin128      (md5Sum);      // Schema Hash
    buf.putShort       (3); // Argument Count

    // Arguments
    ft.clear();
    ft.setString (NAME,    "rhost");
    ft.setInt    (TYPE,    TYPE_SSTR);
    ft.setString (DESC,    "Address (i.e. DNS name, IP address, etc.) of a remotely connected host");
    buf.put (ft);

    ft.clear();
    ft.setString (NAME,    "user");
    ft.setInt    (TYPE,    TYPE_SSTR);
    ft.setString (DESC,    "Authentication identity");
    buf.put (ft);

    ft.clear();
    ft.setString (NAME,    "reason");
    ft.setInt    (TYPE,    TYPE_LSTR);
    ft.setString (DESC,    "Reason for a failure");
    buf.put (ft);


}

void EventClientConnectFail::encode(::qpid::framing::Buffer& buf) const
{
    buf.putShortString(rhost);
    buf.putShortString(user);
    buf.putMediumString(reason);

}
