
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
#include "EventExchangeDeclare.h"

using namespace qmf::org::apache::qpid::broker;
using namespace qpid::framing;
using           qpid::management::ManagementAgent;
using           qpid::management::Manageable;
using           qpid::management::ManagementObject;
using           qpid::management::Args;
using           std::string;

string  EventExchangeDeclare::packageName  = string ("org.apache.qpid.broker");
string  EventExchangeDeclare::eventName    = string ("exchangeDeclare");
uint8_t EventExchangeDeclare::md5Sum[16]   =
    {0xac,0x64,0xab,0xd6,0x49,0x4c,0x59,0x50,0x5d,0x78,0x28,0x9e,0x42,0xc1,0x53,0x7};

EventExchangeDeclare::EventExchangeDeclare (const std::string& _rhost,
        const std::string& _user,
        const std::string& _exName,
        const std::string& _exType,
        const std::string& _altEx,
        const uint8_t _durable,
        const uint8_t _autoDel,
        const ::qpid::framing::FieldTable& _args,
        const std::string& _disp) :
    rhost(_rhost),
    user(_user),
    exName(_exName),
    exType(_exType),
    altEx(_altEx),
    durable(_durable),
    autoDel(_autoDel),
    args(_args),
    disp(_disp)
{}

namespace {
    const string NAME("name");
    const string TYPE("type");
    const string DESC("desc");
    const string ARGCOUNT("argCount");
    const string ARGS("args");
}

void EventExchangeDeclare::registerSelf(ManagementAgent* agent)
{
    agent->registerEvent(packageName, eventName, md5Sum, writeSchema);
}

void EventExchangeDeclare::writeSchema (Buffer& buf)
{
    FieldTable ft;

    // Schema class header:
    buf.putOctet       (CLASS_KIND_EVENT);
    buf.putShortString (packageName); // Package Name
    buf.putShortString (eventName);   // Event Name
    buf.putBin128      (md5Sum);      // Schema Hash
    buf.putShort       (9); // Argument Count

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
    ft.setString (NAME,    "exType");
    ft.setInt    (TYPE,    TYPE_SSTR);
    ft.setString (DESC,    "Type of an exchange");
    buf.put (ft);

    ft.clear();
    ft.setString (NAME,    "altEx");
    ft.setInt    (TYPE,    TYPE_SSTR);
    ft.setString (DESC,    "Name of the alternate exchange");
    buf.put (ft);

    ft.clear();
    ft.setString (NAME,    "durable");
    ft.setInt    (TYPE,    TYPE_BOOL);
    ft.setString (DESC,    "Created object is durable");
    buf.put (ft);

    ft.clear();
    ft.setString (NAME,    "autoDel");
    ft.setInt    (TYPE,    TYPE_BOOL);
    ft.setString (DESC,    "Created object is automatically deleted when no longer in use");
    buf.put (ft);

    ft.clear();
    ft.setString (NAME,    "args");
    ft.setInt    (TYPE,    TYPE_FTABLE);
    ft.setString (DESC,    "Supplemental arguments or parameters supplied");
    buf.put (ft);

    ft.clear();
    ft.setString (NAME,    "disp");
    ft.setInt    (TYPE,    TYPE_SSTR);
    ft.setString (DESC,    "Disposition of a declaration: 'created' if object was created, 'existing' if object already existed");
    buf.put (ft);


}

void EventExchangeDeclare::encode(::qpid::framing::Buffer& buf) const
{
    buf.putShortString(rhost);
    buf.putShortString(user);
    buf.putShortString(exName);
    buf.putShortString(exType);
    buf.putShortString(altEx);
    buf.putOctet(durable?1:0);
    buf.putOctet(autoDel?1:0);
    args.encode(buf);
    buf.putShortString(disp);

}
