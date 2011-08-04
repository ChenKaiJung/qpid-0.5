
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
#include "EventBind.h"

using namespace qmf::org::apache::qpid::broker;
using namespace qpid::framing;
using           qpid::management::ManagementAgent;
using           qpid::management::Manageable;
using           qpid::management::ManagementObject;
using           qpid::management::Args;
using           std::string;

string  EventBind::packageName  = string ("org.apache.qpid.broker");
string  EventBind::eventName    = string ("bind");
uint8_t EventBind::md5Sum[16]   =
    {0x4,0x2a,0xf4,0x9f,0xee,0xa7,0x5c,0xd1,0xa,0xc1,0x10,0xb0,0xe0,0x57,0x3c,0xab};

EventBind::EventBind (const std::string& _rhost,
        const std::string& _user,
        const std::string& _exName,
        const std::string& _qName,
        const std::string& _key,
        const ::qpid::framing::FieldTable& _args) :
    rhost(_rhost),
    user(_user),
    exName(_exName),
    qName(_qName),
    key(_key),
    args(_args)
{}

namespace {
    const string NAME("name");
    const string TYPE("type");
    const string DESC("desc");
    const string ARGCOUNT("argCount");
    const string ARGS("args");
}

void EventBind::registerSelf(ManagementAgent* agent)
{
    agent->registerEvent(packageName, eventName, md5Sum, writeSchema);
}

void EventBind::writeSchema (Buffer& buf)
{
    FieldTable ft;

    // Schema class header:
    buf.putOctet       (CLASS_KIND_EVENT);
    buf.putShortString (packageName); // Package Name
    buf.putShortString (eventName);   // Event Name
    buf.putBin128      (md5Sum);      // Schema Hash
    buf.putShort       (6); // Argument Count

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
    ft.setString (NAME,    "exName");
    ft.setInt    (TYPE,    TYPE_SSTR);
    ft.setString (DESC,    "Name of an exchange");
    buf.put (ft);

    ft.clear();
    ft.setString (NAME,    "qName");
    ft.setInt    (TYPE,    TYPE_SSTR);
    ft.setString (DESC,    "Name of a queue");
    buf.put (ft);

    ft.clear();
    ft.setString (NAME,    "key");
    ft.setInt    (TYPE,    TYPE_LSTR);
    ft.setString (DESC,    "Key text used for routing or binding");
    buf.put (ft);

    ft.clear();
    ft.setString (NAME,    "args");
    ft.setInt    (TYPE,    TYPE_FTABLE);
    ft.setString (DESC,    "Supplemental arguments or parameters supplied");
    buf.put (ft);


}

void EventBind::encode(::qpid::framing::Buffer& buf) const
{
    buf.putShortString(rhost);
    buf.putShortString(user);
    buf.putShortString(exName);
    buf.putShortString(qName);
    buf.putMediumString(key);
    args.encode(buf);

}
