
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
#include "Acl.h"


using namespace qmf::org::apache::qpid::acl;
using namespace qpid::framing;
using           qpid::management::ManagementAgent;
using           qpid::management::Manageable;
using           qpid::management::ManagementObject;
using           qpid::management::Args;
using           std::string;

string  Acl::packageName  = string ("org.apache.qpid.acl");
string  Acl::className    = string ("acl");
uint8_t Acl::md5Sum[16]   =
    {0x2d,0xcc,0x84,0xb4,0x55,0xcc,0xcd,0x86,0xad,0x9e,0x51,0xff,0x1a,0x84,0xe2,0xc7};

Acl::Acl (ManagementAgent* _agent, Manageable* _core, ::qpid::management::Manageable* _parent) :
    ManagementObject(_agent, _core)
{
    brokerRef = _parent->GetManagementObject ()->getObjectId ();
    policyFile = "";
    enforcingAcl = 0;
    transferAcl = 0;
    lastAclLoad = 0;



    maxThreads = agent->getMaxThreads();
    perThreadStatsArray = new struct PerThreadStats*[maxThreads];
    for (int idx = 0; idx < maxThreads; idx++)
        perThreadStatsArray[idx] = 0;

}

Acl::~Acl ()
{

    for (int idx = 0; idx < maxThreads; idx++)
        if (perThreadStatsArray[idx] != 0)
            delete perThreadStatsArray[idx];
    delete[] perThreadStatsArray;

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

void Acl::registerSelf(ManagementAgent* agent)
{
    agent->registerClass(packageName, className, md5Sum, writeSchema);
}

void Acl::writeSchema (Buffer& buf)
{
    FieldTable ft;

    // Schema class header:
    buf.putOctet       (CLASS_KIND_TABLE);
    buf.putShortString (packageName); // Package Name
    buf.putShortString (className);   // Class Name
    buf.putBin128      (md5Sum);      // Schema Hash
    buf.putShort       (5); // Config Element Count
    buf.putShort       (1); // Inst Element Count
    buf.putShort       (1); // Method Count

    // Properties
    ft.clear();
    ft.setString (NAME, "brokerRef");
    ft.setInt    (TYPE, TYPE_REF);
    ft.setInt    (ACCESS, ACCESS_RO);
    ft.setInt    (IS_INDEX, 1);
    ft.setInt    (IS_OPTIONAL, 0);
    buf.put (ft);

    ft.clear();
    ft.setString (NAME, "policyFile");
    ft.setInt    (TYPE, TYPE_SSTR);
    ft.setInt    (ACCESS, ACCESS_RO);
    ft.setInt    (IS_INDEX, 0);
    ft.setInt    (IS_OPTIONAL, 0);
    ft.setString (DESC,   "Name of the policy file");
    buf.put (ft);

    ft.clear();
    ft.setString (NAME, "enforcingAcl");
    ft.setInt    (TYPE, TYPE_BOOL);
    ft.setInt    (ACCESS, ACCESS_RO);
    ft.setInt    (IS_INDEX, 0);
    ft.setInt    (IS_OPTIONAL, 0);
    ft.setString (DESC,   "Currently Enforcing ACL");
    buf.put (ft);

    ft.clear();
    ft.setString (NAME, "transferAcl");
    ft.setInt    (TYPE, TYPE_BOOL);
    ft.setInt    (ACCESS, ACCESS_RO);
    ft.setInt    (IS_INDEX, 0);
    ft.setInt    (IS_OPTIONAL, 0);
    ft.setString (DESC,   "Any transfer ACL rules in force");
    buf.put (ft);

    ft.clear();
    ft.setString (NAME, "lastAclLoad");
    ft.setInt    (TYPE, TYPE_ABSTIME);
    ft.setInt    (ACCESS, ACCESS_RO);
    ft.setInt    (IS_INDEX, 0);
    ft.setInt    (IS_OPTIONAL, 0);
    ft.setString (DESC,   "Timestamp of last successful load of ACL");
    buf.put (ft);


    // Statistics
    ft.clear();
    ft.setString (NAME,   "aclDenyCount");
    ft.setInt    (TYPE,   TYPE_U64);
    ft.setString (UNIT,   "request");
    ft.setString (DESC,   "Number of ACL requests denied");
    buf.put (ft);


    // Methods
    ft.clear();
    ft.setString (NAME,     "reloadACLFile");
    ft.setInt    (ARGCOUNT, 0);
    ft.setString (DESC,     "Reload the ACL file");
    buf.put (ft);


}


void Acl::aggregatePerThreadStats(struct PerThreadStats* totals)
{
    totals->aclDenyCount = 0;

    for (int idx = 0; idx < maxThreads; idx++) {
        struct PerThreadStats* threadStats = perThreadStatsArray[idx];
        if (threadStats != 0) {
            totals->aclDenyCount += threadStats->aclDenyCount;

        }
    }
}


void Acl::writeProperties (Buffer& buf)
{
    ::qpid::sys::Mutex::ScopedLock mutex(accessLock);
    configChanged = false;

    writeTimestamps (buf);

    brokerRef.encode(buf);
    buf.putShortString(policyFile);
    buf.putOctet(enforcingAcl?1:0);
    buf.putOctet(transferAcl?1:0);
    buf.putLongLong(lastAclLoad);

}

void Acl::writeStatistics (Buffer& buf, bool skipHeaders)
{
    ::qpid::sys::Mutex::ScopedLock mutex(accessLock);
    instChanged = false;


    struct PerThreadStats totals;
    aggregatePerThreadStats(&totals);


    if (!skipHeaders)
        writeTimestamps (buf);
    buf.putLongLong(totals.aclDenyCount);


    // Maintenance of hi-lo statistics


}

void Acl::doMethod (string& methodName, Buffer&, Buffer& outBuf)
{
    Manageable::status_t status = Manageable::STATUS_UNKNOWN_METHOD;
    std::string          text;


    if (methodName == "reloadACLFile") {
        ::qpid::management::ArgsNone ioArgs;
        status = coreObject->ManagementMethod (METHOD_RELOADACLFILE, ioArgs, text);
        outBuf.putLong        (status);
        outBuf.putMediumString(::qpid::management::Manageable::StatusText (status, text));
        return;
    }

    outBuf.putLong(status);
    outBuf.putShortString(Manageable::StatusText(status, text));
}
