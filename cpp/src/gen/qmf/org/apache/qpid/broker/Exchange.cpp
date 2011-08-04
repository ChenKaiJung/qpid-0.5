
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
#include "Exchange.h"


using namespace qmf::org::apache::qpid::broker;
using namespace qpid::framing;
using           qpid::management::ManagementAgent;
using           qpid::management::Manageable;
using           qpid::management::ManagementObject;
using           qpid::management::Args;
using           std::string;

string  Exchange::packageName  = string ("org.apache.qpid.broker");
string  Exchange::className    = string ("exchange");
uint8_t Exchange::md5Sum[16]   =
    {0xca,0x66,0xd7,0x54,0xab,0xa5,0xbf,0xe1,0x46,0x7b,0x1,0x53,0x1c,0xdf,0x84,0x2};

Exchange::Exchange (ManagementAgent* _agent, Manageable* _core, ::qpid::management::Manageable* _parent, const std::string& _name, uint8_t _durable) :
    ManagementObject(_agent, _core),name(_name),durable(_durable)
{
    vhostRef = _parent->GetManagementObject ()->getObjectId ();
    type = "";
    arguments = ::qpid::framing::FieldTable();
    producerCount = 0;
    producerCountHigh = 0;
    producerCountLow  = 0;
    bindingCount = 0;
    bindingCountHigh = 0;
    bindingCountLow  = 0;



    maxThreads = agent->getMaxThreads();
    perThreadStatsArray = new struct PerThreadStats*[maxThreads];
    for (int idx = 0; idx < maxThreads; idx++)
        perThreadStatsArray[idx] = 0;

}

Exchange::~Exchange ()
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

void Exchange::registerSelf(ManagementAgent* agent)
{
    agent->registerClass(packageName, className, md5Sum, writeSchema);
}

void Exchange::writeSchema (Buffer& buf)
{
    FieldTable ft;

    // Schema class header:
    buf.putOctet       (CLASS_KIND_TABLE);
    buf.putShortString (packageName); // Package Name
    buf.putShortString (className);   // Class Name
    buf.putBin128      (md5Sum);      // Schema Hash
    buf.putShort       (5); // Config Element Count
    buf.putShort       (12); // Inst Element Count
    buf.putShort       (0); // Method Count

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
    ft.setString (NAME, "type");
    ft.setInt    (TYPE, TYPE_SSTR);
    ft.setInt    (ACCESS, ACCESS_RO);
    ft.setInt    (IS_INDEX, 0);
    ft.setInt    (IS_OPTIONAL, 0);
    buf.put (ft);

    ft.clear();
    ft.setString (NAME, "durable");
    ft.setInt    (TYPE, TYPE_BOOL);
    ft.setInt    (ACCESS, ACCESS_RC);
    ft.setInt    (IS_INDEX, 0);
    ft.setInt    (IS_OPTIONAL, 0);
    buf.put (ft);

    ft.clear();
    ft.setString (NAME, "arguments");
    ft.setInt    (TYPE, TYPE_FTABLE);
    ft.setInt    (ACCESS, ACCESS_RO);
    ft.setInt    (IS_INDEX, 0);
    ft.setInt    (IS_OPTIONAL, 0);
    ft.setString (DESC,   "Arguments supplied in exchange.declare");
    buf.put (ft);


    // Statistics
    ft.clear();
    ft.setString (NAME,   "producerCount");
    ft.setInt    (TYPE,   TYPE_U32);
    ft.setString (DESC,   "Current producers on exchange");
    buf.put (ft);

    ft.clear();
    ft.setString (NAME,   "producerCountHigh");
    ft.setInt    (TYPE,   TYPE_U32);
    ft.setString (DESC,   "Current producers on exchange (High)");
    buf.put (ft);

    ft.clear();
    ft.setString (NAME,   "producerCountLow");
    ft.setInt    (TYPE,   TYPE_U32);
    ft.setString (DESC,   "Current producers on exchange (Low)");
    buf.put (ft);

    ft.clear();
    ft.setString (NAME,   "bindingCount");
    ft.setInt    (TYPE,   TYPE_U32);
    ft.setString (DESC,   "Current bindings");
    buf.put (ft);

    ft.clear();
    ft.setString (NAME,   "bindingCountHigh");
    ft.setInt    (TYPE,   TYPE_U32);
    ft.setString (DESC,   "Current bindings (High)");
    buf.put (ft);

    ft.clear();
    ft.setString (NAME,   "bindingCountLow");
    ft.setInt    (TYPE,   TYPE_U32);
    ft.setString (DESC,   "Current bindings (Low)");
    buf.put (ft);

    ft.clear();
    ft.setString (NAME,   "msgReceives");
    ft.setInt    (TYPE,   TYPE_U64);
    ft.setString (DESC,   "Total messages received");
    buf.put (ft);

    ft.clear();
    ft.setString (NAME,   "msgDrops");
    ft.setInt    (TYPE,   TYPE_U64);
    ft.setString (DESC,   "Total messages dropped (no matching key)");
    buf.put (ft);

    ft.clear();
    ft.setString (NAME,   "msgRoutes");
    ft.setInt    (TYPE,   TYPE_U64);
    ft.setString (DESC,   "Total routed messages");
    buf.put (ft);

    ft.clear();
    ft.setString (NAME,   "byteReceives");
    ft.setInt    (TYPE,   TYPE_U64);
    ft.setString (DESC,   "Total bytes received");
    buf.put (ft);

    ft.clear();
    ft.setString (NAME,   "byteDrops");
    ft.setInt    (TYPE,   TYPE_U64);
    ft.setString (DESC,   "Total bytes dropped (no matching key)");
    buf.put (ft);

    ft.clear();
    ft.setString (NAME,   "byteRoutes");
    ft.setInt    (TYPE,   TYPE_U64);
    ft.setString (DESC,   "Total routed bytes");
    buf.put (ft);


    // Methods

}


void Exchange::aggregatePerThreadStats(struct PerThreadStats* totals)
{
    totals->msgReceives = 0;
    totals->msgDrops = 0;
    totals->msgRoutes = 0;
    totals->byteReceives = 0;
    totals->byteDrops = 0;
    totals->byteRoutes = 0;

    for (int idx = 0; idx < maxThreads; idx++) {
        struct PerThreadStats* threadStats = perThreadStatsArray[idx];
        if (threadStats != 0) {
            totals->msgReceives += threadStats->msgReceives;
            totals->msgDrops += threadStats->msgDrops;
            totals->msgRoutes += threadStats->msgRoutes;
            totals->byteReceives += threadStats->byteReceives;
            totals->byteDrops += threadStats->byteDrops;
            totals->byteRoutes += threadStats->byteRoutes;

        }
    }
}


void Exchange::writeProperties (Buffer& buf)
{
    ::qpid::sys::Mutex::ScopedLock mutex(accessLock);
    configChanged = false;

    writeTimestamps (buf);

    vhostRef.encode(buf);
    buf.putShortString(name);
    buf.putShortString(type);
    buf.putOctet(durable?1:0);
    arguments.encode(buf);

}

void Exchange::writeStatistics (Buffer& buf, bool skipHeaders)
{
    ::qpid::sys::Mutex::ScopedLock mutex(accessLock);
    instChanged = false;


    struct PerThreadStats totals;
    aggregatePerThreadStats(&totals);


    if (!skipHeaders)
        writeTimestamps (buf);
    buf.putLong(producerCount);
    buf.putLong(producerCountHigh);
    buf.putLong(producerCountLow);
    buf.putLong(bindingCount);
    buf.putLong(bindingCountHigh);
    buf.putLong(bindingCountLow);
    buf.putLongLong(totals.msgReceives);
    buf.putLongLong(totals.msgDrops);
    buf.putLongLong(totals.msgRoutes);
    buf.putLongLong(totals.byteReceives);
    buf.putLongLong(totals.byteDrops);
    buf.putLongLong(totals.byteRoutes);


    // Maintenance of hi-lo statistics
    producerCountHigh = producerCount;
    producerCountLow  = producerCount;
    bindingCountHigh = bindingCount;
    bindingCountLow  = bindingCount;


}

void Exchange::doMethod (string&, Buffer&, Buffer& outBuf)
{
    Manageable::status_t status = Manageable::STATUS_UNKNOWN_METHOD;
    std::string          text;


    outBuf.putLong(status);
    outBuf.putShortString(Manageable::StatusText(status, text));
}
