
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
#include "Session.h"


using namespace qmf::org::apache::qpid::broker;
using namespace qpid::framing;
using           qpid::management::ManagementAgent;
using           qpid::management::Manageable;
using           qpid::management::ManagementObject;
using           qpid::management::Args;
using           std::string;

string  Session::packageName  = string ("org.apache.qpid.broker");
string  Session::className    = string ("session");
uint8_t Session::md5Sum[16]   =
    {0x9a,0x57,0xd0,0xd2,0x8b,0x17,0x8c,0x84,0x4f,0xac,0x5c,0x9a,0x96,0xc2,0xcf,0x75};

Session::Session (ManagementAgent* _agent, Manageable* _core, ::qpid::management::Manageable* _parent, const std::string& _name) :
    ManagementObject(_agent, _core),name(_name)
{
    vhostRef = _parent->GetManagementObject ()->getObjectId ();
    channelId = 0;
    connectionRef = ::qpid::management::ObjectId();
    detachedLifespan = 0;
    attached = 0;
    expireTime = 0;
    maxClientRate = 0;


    // Optional properties start out not-present
    for (uint8_t idx = 0; idx < 1; idx++)
        presenceMask[idx] = 0;


    maxThreads = agent->getMaxThreads();
    perThreadStatsArray = new struct PerThreadStats*[maxThreads];
    for (int idx = 0; idx < maxThreads; idx++)
        perThreadStatsArray[idx] = 0;

}

Session::~Session ()
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

void Session::registerSelf(ManagementAgent* agent)
{
    agent->registerClass(packageName, className, md5Sum, writeSchema);
}

void Session::writeSchema (Buffer& buf)
{
    FieldTable ft;

    // Schema class header:
    buf.putOctet       (CLASS_KIND_TABLE);
    buf.putShortString (packageName); // Package Name
    buf.putShortString (className);   // Class Name
    buf.putBin128      (md5Sum);      // Schema Hash
    buf.putShort       (8); // Config Element Count
    buf.putShort       (6); // Inst Element Count
    buf.putShort       (4); // Method Count

    // Properties
    ft.clear();
    ft.setString (NAME, "vhostRef");
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
    ft.setString (NAME, "channelId");
    ft.setInt    (TYPE, TYPE_U16);
    ft.setInt    (ACCESS, ACCESS_RO);
    ft.setInt    (IS_INDEX, 0);
    ft.setInt    (IS_OPTIONAL, 0);
    buf.put (ft);

    ft.clear();
    ft.setString (NAME, "connectionRef");
    ft.setInt    (TYPE, TYPE_REF);
    ft.setInt    (ACCESS, ACCESS_RO);
    ft.setInt    (IS_INDEX, 0);
    ft.setInt    (IS_OPTIONAL, 0);
    buf.put (ft);

    ft.clear();
    ft.setString (NAME, "detachedLifespan");
    ft.setInt    (TYPE, TYPE_U32);
    ft.setInt    (ACCESS, ACCESS_RO);
    ft.setInt    (IS_INDEX, 0);
    ft.setInt    (IS_OPTIONAL, 0);
    ft.setString (UNIT,   "second");
    buf.put (ft);

    ft.clear();
    ft.setString (NAME, "attached");
    ft.setInt    (TYPE, TYPE_BOOL);
    ft.setInt    (ACCESS, ACCESS_RO);
    ft.setInt    (IS_INDEX, 0);
    ft.setInt    (IS_OPTIONAL, 0);
    buf.put (ft);

    ft.clear();
    ft.setString (NAME, "expireTime");
    ft.setInt    (TYPE, TYPE_ABSTIME);
    ft.setInt    (ACCESS, ACCESS_RO);
    ft.setInt    (IS_INDEX, 0);
    ft.setInt    (IS_OPTIONAL, 1);
    buf.put (ft);

    ft.clear();
    ft.setString (NAME, "maxClientRate");
    ft.setInt    (TYPE, TYPE_U32);
    ft.setInt    (ACCESS, ACCESS_RO);
    ft.setInt    (IS_INDEX, 0);
    ft.setInt    (IS_OPTIONAL, 1);
    ft.setString (UNIT,   "msgs/sec");
    buf.put (ft);


    // Statistics
    ft.clear();
    ft.setString (NAME,   "framesOutstanding");
    ft.setInt    (TYPE,   TYPE_U32);
    buf.put (ft);

    ft.clear();
    ft.setString (NAME,   "TxnStarts");
    ft.setInt    (TYPE,   TYPE_U64);
    ft.setString (UNIT,   "transaction");
    ft.setString (DESC,   "Total transactions started ");
    buf.put (ft);

    ft.clear();
    ft.setString (NAME,   "TxnCommits");
    ft.setInt    (TYPE,   TYPE_U64);
    ft.setString (UNIT,   "transaction");
    ft.setString (DESC,   "Total transactions committed");
    buf.put (ft);

    ft.clear();
    ft.setString (NAME,   "TxnRejects");
    ft.setInt    (TYPE,   TYPE_U64);
    ft.setString (UNIT,   "transaction");
    ft.setString (DESC,   "Total transactions rejected");
    buf.put (ft);

    ft.clear();
    ft.setString (NAME,   "TxnCount");
    ft.setInt    (TYPE,   TYPE_U32);
    ft.setString (UNIT,   "transaction");
    ft.setString (DESC,   "Current pending transactions");
    buf.put (ft);

    ft.clear();
    ft.setString (NAME,   "clientCredit");
    ft.setInt    (TYPE,   TYPE_U32);
    ft.setString (UNIT,   "message");
    ft.setString (DESC,   "Client message credit");
    buf.put (ft);


    // Methods
    ft.clear();
    ft.setString (NAME,     "solicitAck");
    ft.setInt    (ARGCOUNT, 0);
    buf.put (ft);

    ft.clear();
    ft.setString (NAME,     "detach");
    ft.setInt    (ARGCOUNT, 0);
    buf.put (ft);

    ft.clear();
    ft.setString (NAME,     "resetLifespan");
    ft.setInt    (ARGCOUNT, 0);
    buf.put (ft);

    ft.clear();
    ft.setString (NAME,     "close");
    ft.setInt    (ARGCOUNT, 0);
    buf.put (ft);


}


void Session::aggregatePerThreadStats(struct PerThreadStats* totals)
{
    totals->framesOutstanding = 0;
    totals->TxnStarts = 0;
    totals->TxnCommits = 0;
    totals->TxnRejects = 0;
    totals->TxnCount = 0;
    totals->clientCredit = 0;

    for (int idx = 0; idx < maxThreads; idx++) {
        struct PerThreadStats* threadStats = perThreadStatsArray[idx];
        if (threadStats != 0) {
            totals->framesOutstanding += threadStats->framesOutstanding;
            totals->TxnStarts += threadStats->TxnStarts;
            totals->TxnCommits += threadStats->TxnCommits;
            totals->TxnRejects += threadStats->TxnRejects;
            totals->TxnCount += threadStats->TxnCount;
            totals->clientCredit += threadStats->clientCredit;

        }
    }
}


void Session::writeProperties (Buffer& buf)
{
    ::qpid::sys::Mutex::ScopedLock mutex(accessLock);
    configChanged = false;

    writeTimestamps (buf);

    for (uint8_t idx = 0; idx < 1; idx++)
        buf.putOctet(presenceMask[idx]);

    vhostRef.encode(buf);
    buf.putShortString(name);
    buf.putShort(channelId);
    connectionRef.encode(buf);
    buf.putLong(detachedLifespan);
    buf.putOctet(attached?1:0);
    if (presenceMask[presenceByte_expireTime] & presenceMask_expireTime) {
        buf.putLongLong(expireTime);
    }
    if (presenceMask[presenceByte_maxClientRate] & presenceMask_maxClientRate) {
        buf.putLong(maxClientRate);
    }

}

void Session::writeStatistics (Buffer& buf, bool skipHeaders)
{
    ::qpid::sys::Mutex::ScopedLock mutex(accessLock);
    instChanged = false;


    struct PerThreadStats totals;
    aggregatePerThreadStats(&totals);


    if (!skipHeaders)
        writeTimestamps (buf);
    buf.putLong(totals.framesOutstanding);
    buf.putLongLong(totals.TxnStarts);
    buf.putLongLong(totals.TxnCommits);
    buf.putLongLong(totals.TxnRejects);
    buf.putLong(totals.TxnCount);
    buf.putLong(totals.clientCredit);


    // Maintenance of hi-lo statistics


}

void Session::doMethod (string& methodName, Buffer&, Buffer& outBuf)
{
    Manageable::status_t status = Manageable::STATUS_UNKNOWN_METHOD;
    std::string          text;


    if (methodName == "solicitAck") {
        ::qpid::management::ArgsNone ioArgs;
        status = coreObject->ManagementMethod (METHOD_SOLICITACK, ioArgs, text);
        outBuf.putLong        (status);
        outBuf.putMediumString(::qpid::management::Manageable::StatusText (status, text));
        return;
    }

    if (methodName == "detach") {
        ::qpid::management::ArgsNone ioArgs;
        status = coreObject->ManagementMethod (METHOD_DETACH, ioArgs, text);
        outBuf.putLong        (status);
        outBuf.putMediumString(::qpid::management::Manageable::StatusText (status, text));
        return;
    }

    if (methodName == "resetLifespan") {
        ::qpid::management::ArgsNone ioArgs;
        status = coreObject->ManagementMethod (METHOD_RESETLIFESPAN, ioArgs, text);
        outBuf.putLong        (status);
        outBuf.putMediumString(::qpid::management::Manageable::StatusText (status, text));
        return;
    }

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
