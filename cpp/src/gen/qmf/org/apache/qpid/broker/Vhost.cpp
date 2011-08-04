
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
#include "Vhost.h"


using namespace qmf::org::apache::qpid::broker;
using namespace qpid::framing;
using           qpid::management::ManagementAgent;
using           qpid::management::Manageable;
using           qpid::management::ManagementObject;
using           qpid::management::Args;
using           std::string;

string  Vhost::packageName  = string ("org.apache.qpid.broker");
string  Vhost::className    = string ("vhost");
uint8_t Vhost::md5Sum[16]   =
    {0x14,0xa3,0xfa,0x67,0x8a,0xe2,0x89,0x88,0xcd,0x94,0x40,0xef,0x63,0xd,0x1b,0x49};

Vhost::Vhost (ManagementAgent* _agent, Manageable* _core, ::qpid::management::Manageable* _parent, const std::string& _name) :
    ManagementObject(_agent, _core),name(_name)
{
    brokerRef = _parent->GetManagementObject ()->getObjectId ();
    federationTag = "";



}

Vhost::~Vhost ()
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

void Vhost::registerSelf(ManagementAgent* agent)
{
    agent->registerClass(packageName, className, md5Sum, writeSchema);
}

void Vhost::writeSchema (Buffer& buf)
{
    FieldTable ft;

    // Schema class header:
    buf.putOctet       (CLASS_KIND_TABLE);
    buf.putShortString (packageName); // Package Name
    buf.putShortString (className);   // Class Name
    buf.putBin128      (md5Sum);      // Schema Hash
    buf.putShort       (3); // Config Element Count
    buf.putShort       (0); // Inst Element Count
    buf.putShort       (0); // Method Count

    // Properties
    ft.clear();
    ft.setString (NAME, "brokerRef");
    ft.setInt    (TYPE, TYPE_REF);
    ft.setInt    (ACCESS, ACCESS_RC);
    ft.setInt    (IS_INDEX, 1);
    ft.setInt    (IS_OPTIONAL, 0);
    buf.put (ft);

    ft.clear();
    ft.setString (NAME, "name");
    ft.setInt    (TYPE, TYPE_SSTR);
    ft.setInt    (ACCESS, ACCESS_RC);
    ft.setInt    (IS_INDEX, 1);
    ft.setInt    (IS_OPTIONAL, 0);
    buf.put (ft);

    ft.clear();
    ft.setString (NAME, "federationTag");
    ft.setInt    (TYPE, TYPE_SSTR);
    ft.setInt    (ACCESS, ACCESS_RO);
    ft.setInt    (IS_INDEX, 0);
    ft.setInt    (IS_OPTIONAL, 0);
    buf.put (ft);


    // Statistics

    // Methods

}



void Vhost::writeProperties (Buffer& buf)
{
    ::qpid::sys::Mutex::ScopedLock mutex(accessLock);
    configChanged = false;

    writeTimestamps (buf);

    brokerRef.encode(buf);
    buf.putShortString(name);
    buf.putShortString(federationTag);

}

void Vhost::writeStatistics (Buffer& buf, bool skipHeaders)
{
    ::qpid::sys::Mutex::ScopedLock mutex(accessLock);
    instChanged = false;



    if (!skipHeaders)
        writeTimestamps (buf);


    // Maintenance of hi-lo statistics


}

void Vhost::doMethod (string&, Buffer&, Buffer& outBuf)
{
    Manageable::status_t status = Manageable::STATUS_UNKNOWN_METHOD;
    std::string          text;


    outBuf.putLong(status);
    outBuf.putShortString(Manageable::StatusText(status, text));
}
