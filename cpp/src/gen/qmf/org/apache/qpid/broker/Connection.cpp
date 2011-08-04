
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
#include "Connection.h"


using namespace qmf::org::apache::qpid::broker;
using namespace qpid::framing;
using           qpid::management::ManagementAgent;
using           qpid::management::Manageable;
using           qpid::management::ManagementObject;
using           qpid::management::Args;
using           std::string;

string  Connection::packageName  = string ("org.apache.qpid.broker");
string  Connection::className    = string ("connection");
uint8_t Connection::md5Sum[16]   =
    {0xbd,0x9e,0xb4,0x7f,0x44,0xf0,0x3d,0x9c,0x87,0x56,0xd1,0x42,0x85,0x24,0xe5,0x4b};

Connection::Connection (ManagementAgent* _agent, Manageable* _core, ::qpid::management::Manageable* _parent, const std::string& _address, uint8_t _incoming, uint8_t _SystemConnection) :
    ManagementObject(_agent, _core),address(_address),incoming(_incoming),SystemConnection(_SystemConnection)
{
    vhostRef = _parent->GetManagementObject ()->getObjectId ();
    federationLink = 0;
    authIdentity = "";
    remoteProcessName = "";
    remotePid = 0;
    remoteParentPid = 0;
    closing = 0;


    // Optional properties start out not-present
    for (uint8_t idx = 0; idx < 1; idx++)
        presenceMask[idx] = 0;


    maxThreads = agent->getMaxThreads();
    perThreadStatsArray = new struct PerThreadStats*[maxThreads];
    for (int idx = 0; idx < maxThreads; idx++)
        perThreadStatsArray[idx] = 0;

}

Connection::~Connection ()
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

void Connection::registerSelf(ManagementAgent* agent)
{
    agent->registerClass(packageName, className, md5Sum, writeSchema);
}

void Connection::writeSchema (Buffer& buf)
{
    FieldTable ft;

    // Schema class header:
    buf.putOctet       (CLASS_KIND_TABLE);
    buf.putShortString (packageName); // Package Name
    buf.putShortString (className);   // Class Name
    buf.putBin128      (md5Sum);      // Schema Hash
    buf.putShort       (9); // Config Element Count
    buf.putShort       (5); // Inst Element Count
    buf.putShort       (1); // Method Count

    // Properties
    ft.clear();
    ft.setString (NAME, "vhostRef");
    ft.setInt    (TYPE, TYPE_REF);
    ft.setInt    (ACCESS, ACCESS_RC);
    ft.setInt    (IS_INDEX, 1);
    ft.setInt    (IS_OPTIONAL, 0);
    buf.put (ft);

    ft.clear();
    ft.setString (NAME, "address");
    ft.setInt    (TYPE, TYPE_SSTR);
    ft.setInt    (ACCESS, ACCESS_RC);
    ft.setInt    (IS_INDEX, 1);
    ft.setInt    (IS_OPTIONAL, 0);
    buf.put (ft);

    ft.clear();
    ft.setString (NAME, "incoming");
    ft.setInt    (TYPE, TYPE_BOOL);
    ft.setInt    (ACCESS, ACCESS_RC);
    ft.setInt    (IS_INDEX, 0);
    ft.setInt    (IS_OPTIONAL, 0);
    buf.put (ft);

    ft.clear();
    ft.setString (NAME, "SystemConnection");
    ft.setInt    (TYPE, TYPE_BOOL);
    ft.setInt    (ACCESS, ACCESS_RC);
    ft.setInt    (IS_INDEX, 0);
    ft.setInt    (IS_OPTIONAL, 0);
    ft.setString (DESC,   "Infrastucture/ Inter-system connection (Cluster, Federation, ...)");
    buf.put (ft);

    ft.clear();
    ft.setString (NAME, "federationLink");
    ft.setInt    (TYPE, TYPE_BOOL);
    ft.setInt    (ACCESS, ACCESS_RO);
    ft.setInt    (IS_INDEX, 0);
    ft.setInt    (IS_OPTIONAL, 0);
    ft.setString (DESC,   "Is this a federation link");
    buf.put (ft);

    ft.clear();
    ft.setString (NAME, "authIdentity");
    ft.setInt    (TYPE, TYPE_SSTR);
    ft.setInt    (ACCESS, ACCESS_RO);
    ft.setInt    (IS_INDEX, 0);
    ft.setInt    (IS_OPTIONAL, 0);
    ft.setString (DESC,   "authId of connection if authentication enabled");
    buf.put (ft);

    ft.clear();
    ft.setString (NAME, "remoteProcessName");
    ft.setInt    (TYPE, TYPE_SSTR);
    ft.setInt    (ACCESS, ACCESS_RO);
    ft.setInt    (IS_INDEX, 0);
    ft.setInt    (IS_OPTIONAL, 1);
    ft.setString (DESC,   "Name of executable running as remote client");
    buf.put (ft);

    ft.clear();
    ft.setString (NAME, "remotePid");
    ft.setInt    (TYPE, TYPE_U32);
    ft.setInt    (ACCESS, ACCESS_RO);
    ft.setInt    (IS_INDEX, 0);
    ft.setInt    (IS_OPTIONAL, 1);
    ft.setString (DESC,   "Process ID of remote client");
    buf.put (ft);

    ft.clear();
    ft.setString (NAME, "remoteParentPid");
    ft.setInt    (TYPE, TYPE_U32);
    ft.setInt    (ACCESS, ACCESS_RO);
    ft.setInt    (IS_INDEX, 0);
    ft.setInt    (IS_OPTIONAL, 1);
    ft.setString (DESC,   "Parent Process ID of remote client");
    buf.put (ft);


    // Statistics
    ft.clear();
    ft.setString (NAME,   "closing");
    ft.setInt    (TYPE,   TYPE_BOOL);
    ft.setString (DESC,   "This client is closing by management request");
    buf.put (ft);

    ft.clear();
    ft.setString (NAME,   "framesFromClient");
    ft.setInt    (TYPE,   TYPE_U64);
    buf.put (ft);

    ft.clear();
    ft.setString (NAME,   "framesToClient");
    ft.setInt    (TYPE,   TYPE_U64);
    buf.put (ft);

    ft.clear();
    ft.setString (NAME,   "bytesFromClient");
    ft.setInt    (TYPE,   TYPE_U64);
    buf.put (ft);

    ft.clear();
    ft.setString (NAME,   "bytesToClient");
    ft.setInt    (TYPE,   TYPE_U64);
    buf.put (ft);


    // Methods
    ft.clear();
    ft.setString (NAME,     "close");
    ft.setInt    (ARGCOUNT, 0);
    buf.put (ft);


}


void Connection::aggregatePerThreadStats(struct PerThreadStats* totals)
{
    totals->framesFromClient = 0;
    totals->framesToClient = 0;
    totals->bytesFromClient = 0;
    totals->bytesToClient = 0;

    for (int idx = 0; idx < maxThreads; idx++) {
        struct PerThreadStats* threadStats = perThreadStatsArray[idx];
        if (threadStats != 0) {
            totals->framesFromClient += threadStats->framesFromClient;
            totals->framesToClient += threadStats->framesToClient;
            totals->bytesFromClient += threadStats->bytesFromClient;
            totals->bytesToClient += threadStats->bytesToClient;

        }
    }
}


void Connection::writeProperties (Buffer& buf)
{
    ::qpid::sys::Mutex::ScopedLock mutex(accessLock);
    configChanged = false;

    writeTimestamps (buf);

    for (uint8_t idx = 0; idx < 1; idx++)
        buf.putOctet(presenceMask[idx]);

    vhostRef.encode(buf);
    buf.putShortString(address);
    buf.putOctet(incoming?1:0);
    buf.putOctet(SystemConnection?1:0);
    buf.putOctet(federationLink?1:0);
    buf.putShortString(authIdentity);
    if (presenceMask[presenceByte_remoteProcessName] & presenceMask_remoteProcessName) {
        buf.putShortString(remoteProcessName);
    }
    if (presenceMask[presenceByte_remotePid] & presenceMask_remotePid) {
        buf.putLong(remotePid);
    }
    if (presenceMask[presenceByte_remoteParentPid] & presenceMask_remoteParentPid) {
        buf.putLong(remoteParentPid);
    }

}

void Connection::writeStatistics (Buffer& buf, bool skipHeaders)
{
    ::qpid::sys::Mutex::ScopedLock mutex(accessLock);
    instChanged = false;


    struct PerThreadStats totals;
    aggregatePerThreadStats(&totals);


    if (!skipHeaders)
        writeTimestamps (buf);
    buf.putOctet(closing?1:0);
    buf.putLongLong(totals.framesFromClient);
    buf.putLongLong(totals.framesToClient);
    buf.putLongLong(totals.bytesFromClient);
    buf.putLongLong(totals.bytesToClient);


    // Maintenance of hi-lo statistics


}

void Connection::doMethod (string& methodName, Buffer&, Buffer& outBuf)
{
    Manageable::status_t status = Manageable::STATUS_UNKNOWN_METHOD;
    std::string          text;


    if (methodName == "close") {
        ::qpid::management::ArgsNone ioArgs;
        status = coreObject->ManagementMethod (METHOD_CLOSE, ioArgs, text);
        outBuf.putLong        (status);
        outBuf.putMediumString(::qpid::management::Manageable::StatusText (status, text));
        return;
    }

    outBuf.putLong(status);
    outBuf.putShortString(Manageable::StatusText(status, text));
}
