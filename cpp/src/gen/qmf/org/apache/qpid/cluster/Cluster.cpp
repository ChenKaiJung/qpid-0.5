
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
#include "Cluster.h"
#include "ArgsClusterStopClusterNode.h"


using namespace qmf::org::apache::qpid::cluster;
using namespace qpid::framing;
using           qpid::management::ManagementAgent;
using           qpid::management::Manageable;
using           qpid::management::ManagementObject;
using           qpid::management::Args;
using           std::string;

string  Cluster::packageName  = string ("org.apache.qpid.cluster");
string  Cluster::className    = string ("cluster");
uint8_t Cluster::md5Sum[16]   =
    {0x21,0x76,0xfa,0xed,0xc1,0x65,0x9,0x13,0x77,0x40,0x17,0xf7,0xd1,0x4f,0xcc,0xa1};

Cluster::Cluster (ManagementAgent* _agent, Manageable* _core, ::qpid::management::Manageable* _parent, const std::string& _clusterName, const std::string& _publishedURL) :
    ManagementObject(_agent, _core),clusterName(_clusterName),publishedURL(_publishedURL)
{
    brokerRef = _parent->GetManagementObject ()->getObjectId ();
    clusterID = "";
    memberID = "";
    clusterSize = 0;
    status = "";
    members = "";
    memberIDs = "";



}

Cluster::~Cluster ()
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

void Cluster::registerSelf(ManagementAgent* agent)
{
    agent->registerClass(packageName, className, md5Sum, writeSchema);
}

void Cluster::writeSchema (Buffer& buf)
{
    FieldTable ft;

    // Schema class header:
    buf.putOctet       (CLASS_KIND_TABLE);
    buf.putShortString (packageName); // Package Name
    buf.putShortString (className);   // Class Name
    buf.putBin128      (md5Sum);      // Schema Hash
    buf.putShort       (9); // Config Element Count
    buf.putShort       (0); // Inst Element Count
    buf.putShort       (2); // Method Count

    // Properties
    ft.clear();
    ft.setString (NAME, "brokerRef");
    ft.setInt    (TYPE, TYPE_REF);
    ft.setInt    (ACCESS, ACCESS_RC);
    ft.setInt    (IS_INDEX, 1);
    ft.setInt    (IS_OPTIONAL, 0);
    buf.put (ft);

    ft.clear();
    ft.setString (NAME, "clusterName");
    ft.setInt    (TYPE, TYPE_SSTR);
    ft.setInt    (ACCESS, ACCESS_RC);
    ft.setInt    (IS_INDEX, 0);
    ft.setInt    (IS_OPTIONAL, 0);
    ft.setString (DESC,   "Name of cluster this server is a member of");
    buf.put (ft);

    ft.clear();
    ft.setString (NAME, "clusterID");
    ft.setInt    (TYPE, TYPE_SSTR);
    ft.setInt    (ACCESS, ACCESS_RO);
    ft.setInt    (IS_INDEX, 0);
    ft.setInt    (IS_OPTIONAL, 0);
    ft.setString (DESC,   "Globally unique ID (UUID) for this cluster instance");
    buf.put (ft);

    ft.clear();
    ft.setString (NAME, "memberID");
    ft.setInt    (TYPE, TYPE_SSTR);
    ft.setInt    (ACCESS, ACCESS_RO);
    ft.setInt    (IS_INDEX, 0);
    ft.setInt    (IS_OPTIONAL, 0);
    ft.setString (DESC,   "ID of this member of the cluster");
    buf.put (ft);

    ft.clear();
    ft.setString (NAME, "publishedURL");
    ft.setInt    (TYPE, TYPE_SSTR);
    ft.setInt    (ACCESS, ACCESS_RC);
    ft.setInt    (IS_INDEX, 0);
    ft.setInt    (IS_OPTIONAL, 0);
    ft.setString (DESC,   "URL this node advertizes itself as");
    buf.put (ft);

    ft.clear();
    ft.setString (NAME, "clusterSize");
    ft.setInt    (TYPE, TYPE_U16);
    ft.setInt    (ACCESS, ACCESS_RO);
    ft.setInt    (IS_INDEX, 0);
    ft.setInt    (IS_OPTIONAL, 0);
    ft.setString (DESC,   "Number of brokers currently in the cluster");
    buf.put (ft);

    ft.clear();
    ft.setString (NAME, "status");
    ft.setInt    (TYPE, TYPE_SSTR);
    ft.setInt    (ACCESS, ACCESS_RO);
    ft.setInt    (IS_INDEX, 0);
    ft.setInt    (IS_OPTIONAL, 0);
    ft.setString (DESC,   "Cluster node status (STALLED,ACTIVE,JOINING)");
    buf.put (ft);

    ft.clear();
    ft.setString (NAME, "members");
    ft.setInt    (TYPE, TYPE_LSTR);
    ft.setInt    (ACCESS, ACCESS_RO);
    ft.setInt    (IS_INDEX, 0);
    ft.setInt    (IS_OPTIONAL, 0);
    ft.setString (DESC,   "List of member URLs delimited by ';'");
    buf.put (ft);

    ft.clear();
    ft.setString (NAME, "memberIDs");
    ft.setInt    (TYPE, TYPE_LSTR);
    ft.setInt    (ACCESS, ACCESS_RO);
    ft.setInt    (IS_INDEX, 0);
    ft.setInt    (IS_OPTIONAL, 0);
    ft.setString (DESC,   "List of member IDs delimited by ';'");
    buf.put (ft);


    // Statistics

    // Methods
    ft.clear();
    ft.setString (NAME,     "stopClusterNode");
    ft.setInt    (ARGCOUNT, 1);
    buf.put (ft);

    ft.clear();
    ft.setString (NAME,    "brokerId");
    ft.setInt    (TYPE,    TYPE_SSTR);
    ft.setString (DIR,     "I");
    buf.put (ft);

    ft.clear();
    ft.setString (NAME,     "stopFullCluster");
    ft.setInt    (ARGCOUNT, 0);
    buf.put (ft);


}



void Cluster::writeProperties (Buffer& buf)
{
    ::qpid::sys::Mutex::ScopedLock mutex(accessLock);
    configChanged = false;

    writeTimestamps (buf);

    brokerRef.encode(buf);
    buf.putShortString(clusterName);
    buf.putShortString(clusterID);
    buf.putShortString(memberID);
    buf.putShortString(publishedURL);
    buf.putShort(clusterSize);
    buf.putShortString(status);
    buf.putMediumString(members);
    buf.putMediumString(memberIDs);

}

void Cluster::writeStatistics (Buffer& buf, bool skipHeaders)
{
    ::qpid::sys::Mutex::ScopedLock mutex(accessLock);
    instChanged = false;



    if (!skipHeaders)
        writeTimestamps (buf);


    // Maintenance of hi-lo statistics


}

void Cluster::doMethod (string& methodName, Buffer& inBuf, Buffer& outBuf)
{
    Manageable::status_t status = Manageable::STATUS_UNKNOWN_METHOD;
    std::string          text;


    if (methodName == "stopClusterNode") {
        ArgsClusterStopClusterNode ioArgs;
        inBuf.getShortString(ioArgs.i_brokerId);
        status = coreObject->ManagementMethod (METHOD_STOPCLUSTERNODE, ioArgs, text);
        outBuf.putLong        (status);
        outBuf.putMediumString(::qpid::management::Manageable::StatusText (status, text));
        return;
    }

    if (methodName == "stopFullCluster") {
        ::qpid::management::ArgsNone ioArgs;
        status = coreObject->ManagementMethod (METHOD_STOPFULLCLUSTER, ioArgs, text);
        outBuf.putLong        (status);
        outBuf.putMediumString(::qpid::management::Manageable::StatusText (status, text));
        return;
    }

    outBuf.putLong(status);
    outBuf.putShortString(Manageable::StatusText(status, text));
}
