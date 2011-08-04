
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
#include "Agent.h"


using namespace qmf::org::apache::qpid::broker;
using namespace qpid::framing;
using           qpid::management::ManagementAgent;
using           qpid::management::Manageable;
using           qpid::management::ManagementObject;
using           qpid::management::Args;
using           std::string;

string  Agent::packageName  = string ("org.apache.qpid.broker");
string  Agent::className    = string ("agent");
uint8_t Agent::md5Sum[16]   =
    {0xa8,0x13,0xb1,0x5,0x63,0x14,0x4c,0x5,0x83,0xd4,0xcb,0xd5,0x37,0x31,0x3d,0x81};

Agent::Agent (ManagementAgent* _agent, Manageable* _core) :
    ManagementObject(_agent, _core)
{
    
    connectionRef = ::qpid::management::ObjectId();
    label = "";
    registeredTo = ::qpid::management::ObjectId();
    systemId = ::qpid::framing::Uuid();
    brokerBank = 0;
    agentBank = 0;



}

Agent::~Agent ()
{

}

namespace {
    const string NAME("name");
    const string TYPE("type");
    const string ACCESS("access");
    const string IS_INDEX("index");
    const string IS_OPTIONAL("optional");
    const string UNIT("unit");
    const string MIN("min");
    const string MAX("max");
    const string MAXLEN("maxlen");
    const string DESC("desc");
    const string ARGCOUNT("argCount");
    const string ARGS("args");
    const string DIR("dir");
    const string DEFAULT("default");
}

void Agent::registerSelf(ManagementAgent* agent)
{
    agent->registerClass(packageName, className, md5Sum, writeSchema);
}

void Agent::writeSchema (Buffer& buf)
{
    FieldTable ft;

    // Schema class header:
    buf.putOctet       (CLASS_KIND_TABLE);
    buf.putShortString (packageName); // Package Name
    buf.putShortString (className);   // Class Name
    buf.putBin128      (md5Sum);      // Schema Hash
    buf.putShort       (6); // Config Element Count
    buf.putShort       (0); // Inst Element Count
    buf.putShort       (0); // Method Count

    // Properties
    ft.clear();
    ft.setString (NAME, "connectionRef");
    ft.setInt    (TYPE, TYPE_REF);
    ft.setInt    (ACCESS, ACCESS_RO);
    ft.setInt    (IS_INDEX, 1);
    ft.setInt    (IS_OPTIONAL, 0);
    buf.put (ft);

    ft.clear();
    ft.setString (NAME, "label");
    ft.setInt    (TYPE, TYPE_SSTR);
    ft.setInt    (ACCESS, ACCESS_RO);
    ft.setInt    (IS_INDEX, 0);
    ft.setInt    (IS_OPTIONAL, 0);
    ft.setString (DESC,   "Label for agent");
    buf.put (ft);

    ft.clear();
    ft.setString (NAME, "registeredTo");
    ft.setInt    (TYPE, TYPE_REF);
    ft.setInt    (ACCESS, ACCESS_RO);
    ft.setInt    (IS_INDEX, 0);
    ft.setInt    (IS_OPTIONAL, 0);
    ft.setString (DESC,   "Broker agent is registered to");
    buf.put (ft);

    ft.clear();
    ft.setString (NAME, "systemId");
    ft.setInt    (TYPE, TYPE_UUID);
    ft.setInt    (ACCESS, ACCESS_RO);
    ft.setInt    (IS_INDEX, 0);
    ft.setInt    (IS_OPTIONAL, 0);
    ft.setString (DESC,   "Identifier of system where agent resides");
    buf.put (ft);

    ft.clear();
    ft.setString (NAME, "brokerBank");
    ft.setInt    (TYPE, TYPE_U32);
    ft.setInt    (ACCESS, ACCESS_RO);
    ft.setInt    (IS_INDEX, 0);
    ft.setInt    (IS_OPTIONAL, 0);
    ft.setString (DESC,   "Assigned object-id broker bank");
    buf.put (ft);

    ft.clear();
    ft.setString (NAME, "agentBank");
    ft.setInt    (TYPE, TYPE_U32);
    ft.setInt    (ACCESS, ACCESS_RO);
    ft.setInt    (IS_INDEX, 0);
    ft.setInt    (IS_OPTIONAL, 0);
    ft.setString (DESC,   "Assigned object-id agent bank");
    buf.put (ft);


    // Statistics

    // Methods

}



void Agent::writeProperties (Buffer& buf)
{
    ::qpid::sys::Mutex::ScopedLock mutex(accessLock);
    configChanged = false;

    writeTimestamps (buf);

    connectionRef.encode(buf);
    buf.putShortString(label);
    registeredTo.encode(buf);
    systemId.encode(buf);
    buf.putLong(brokerBank);
    buf.putLong(agentBank);

}

void Agent::writeStatistics (Buffer& buf, bool skipHeaders)
{
    ::qpid::sys::Mutex::ScopedLock mutex(accessLock);
    instChanged = false;



    if (!skipHeaders)
        writeTimestamps (buf);


    // Maintenance of hi-lo statistics


}

void Agent::doMethod (string&, Buffer&, Buffer& outBuf)
{
    Manageable::status_t status = Manageable::STATUS_UNKNOWN_METHOD;
    std::string          text;


    outBuf.putLong(status);
    outBuf.putShortString(Manageable::StatusText(status, text));
}
