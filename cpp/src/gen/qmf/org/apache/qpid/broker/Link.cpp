
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
#include "Link.h"
#include "ArgsLinkBridge.h"


using namespace qmf::org::apache::qpid::broker;
using namespace qpid::framing;
using           qpid::management::ManagementAgent;
using           qpid::management::Manageable;
using           qpid::management::ManagementObject;
using           qpid::management::Args;
using           std::string;

string  Link::packageName  = string ("org.apache.qpid.broker");
string  Link::className    = string ("link");
uint8_t Link::md5Sum[16]   =
    {0x62,0x7f,0xbf,0xee,0xe8,0x67,0xf6,0x9a,0x41,0x27,0xce,0xf,0x3,0x3,0xb,0xe7};

Link::Link (ManagementAgent* _agent, Manageable* _core, ::qpid::management::Manageable* _parent, const std::string& _host, uint16_t _port, const std::string& _transport, uint8_t _durable) :
    ManagementObject(_agent, _core),host(_host),port(_port),transport(_transport),durable(_durable)
{
    vhostRef = _parent->GetManagementObject ()->getObjectId ();
    state = "";
    lastError = "";



}

Link::~Link ()
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

void Link::registerSelf(ManagementAgent* agent)
{
    agent->registerClass(packageName, className, md5Sum, writeSchema);
}

void Link::writeSchema (Buffer& buf)
{
    FieldTable ft;

    // Schema class header:
    buf.putOctet       (CLASS_KIND_TABLE);
    buf.putShortString (packageName); // Package Name
    buf.putShortString (className);   // Class Name
    buf.putBin128      (md5Sum);      // Schema Hash
    buf.putShort       (5); // Config Element Count
    buf.putShort       (2); // Inst Element Count
    buf.putShort       (2); // Method Count

    // Properties
    ft.clear();
    ft.setString (NAME, "vhostRef");
    ft.setInt    (TYPE, TYPE_REF);
    ft.setInt    (ACCESS, ACCESS_RC);
    ft.setInt    (IS_INDEX, 1);
    ft.setInt    (IS_OPTIONAL, 0);
    buf.put (ft);

    ft.clear();
    ft.setString (NAME, "host");
    ft.setInt    (TYPE, TYPE_SSTR);
    ft.setInt    (ACCESS, ACCESS_RC);
    ft.setInt    (IS_INDEX, 1);
    ft.setInt    (IS_OPTIONAL, 0);
    buf.put (ft);

    ft.clear();
    ft.setString (NAME, "port");
    ft.setInt    (TYPE, TYPE_U16);
    ft.setInt    (ACCESS, ACCESS_RC);
    ft.setInt    (IS_INDEX, 1);
    ft.setInt    (IS_OPTIONAL, 0);
    buf.put (ft);

    ft.clear();
    ft.setString (NAME, "transport");
    ft.setInt    (TYPE, TYPE_SSTR);
    ft.setInt    (ACCESS, ACCESS_RC);
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


    // Statistics
    ft.clear();
    ft.setString (NAME,   "state");
    ft.setInt    (TYPE,   TYPE_SSTR);
    ft.setString (DESC,   "Operational state of the link");
    buf.put (ft);

    ft.clear();
    ft.setString (NAME,   "lastError");
    ft.setInt    (TYPE,   TYPE_SSTR);
    ft.setString (DESC,   "Reason link is not operational");
    buf.put (ft);


    // Methods
    ft.clear();
    ft.setString (NAME,     "close");
    ft.setInt    (ARGCOUNT, 0);
    buf.put (ft);

    ft.clear();
    ft.setString (NAME,     "bridge");
    ft.setInt    (ARGCOUNT, 10);
    ft.setString (DESC,     "Bridge messages over the link");
    buf.put (ft);

    ft.clear();
    ft.setString (NAME,    "durable");
    ft.setInt    (TYPE,    TYPE_BOOL);
    ft.setString (DIR,     "I");
    buf.put (ft);

    ft.clear();
    ft.setString (NAME,    "src");
    ft.setInt    (TYPE,    TYPE_SSTR);
    ft.setString (DIR,     "I");
    buf.put (ft);

    ft.clear();
    ft.setString (NAME,    "dest");
    ft.setInt    (TYPE,    TYPE_SSTR);
    ft.setString (DIR,     "I");
    buf.put (ft);

    ft.clear();
    ft.setString (NAME,    "key");
    ft.setInt    (TYPE,    TYPE_SSTR);
    ft.setString (DIR,     "I");
    buf.put (ft);

    ft.clear();
    ft.setString (NAME,    "tag");
    ft.setInt    (TYPE,    TYPE_SSTR);
    ft.setString (DIR,     "I");
    buf.put (ft);

    ft.clear();
    ft.setString (NAME,    "excludes");
    ft.setInt    (TYPE,    TYPE_SSTR);
    ft.setString (DIR,     "I");
    buf.put (ft);

    ft.clear();
    ft.setString (NAME,    "srcIsQueue");
    ft.setInt    (TYPE,    TYPE_BOOL);
    ft.setString (DIR,     "I");
    buf.put (ft);

    ft.clear();
    ft.setString (NAME,    "srcIsLocal");
    ft.setInt    (TYPE,    TYPE_BOOL);
    ft.setString (DIR,     "I");
    buf.put (ft);

    ft.clear();
    ft.setString (NAME,    "dynamic");
    ft.setInt    (TYPE,    TYPE_BOOL);
    ft.setString (DIR,     "I");
    buf.put (ft);

    ft.clear();
    ft.setString (NAME,    "sync");
    ft.setInt    (TYPE,    TYPE_U16);
    ft.setString (DIR,     "I");
    buf.put (ft);


}



void Link::writeProperties (Buffer& buf)
{
    ::qpid::sys::Mutex::ScopedLock mutex(accessLock);
    configChanged = false;

    writeTimestamps (buf);

    vhostRef.encode(buf);
    buf.putShortString(host);
    buf.putShort(port);
    buf.putShortString(transport);
    buf.putOctet(durable?1:0);

}

void Link::writeStatistics (Buffer& buf, bool skipHeaders)
{
    ::qpid::sys::Mutex::ScopedLock mutex(accessLock);
    instChanged = false;



    if (!skipHeaders)
        writeTimestamps (buf);
    buf.putShortString(state);
    buf.putShortString(lastError);


    // Maintenance of hi-lo statistics


}

void Link::doMethod (string& methodName, Buffer& inBuf, Buffer& outBuf)
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

    if (methodName == "bridge") {
        ArgsLinkBridge ioArgs;
        ioArgs.i_durable = inBuf.getOctet()==1;
        inBuf.getShortString(ioArgs.i_src);
        inBuf.getShortString(ioArgs.i_dest);
        inBuf.getShortString(ioArgs.i_key);
        inBuf.getShortString(ioArgs.i_tag);
        inBuf.getShortString(ioArgs.i_excludes);
        ioArgs.i_srcIsQueue = inBuf.getOctet()==1;
        ioArgs.i_srcIsLocal = inBuf.getOctet()==1;
        ioArgs.i_dynamic = inBuf.getOctet()==1;
        ioArgs.i_sync = inBuf.getShort();
        status = coreObject->ManagementMethod (METHOD_BRIDGE, ioArgs, text);
        outBuf.putLong        (status);
        outBuf.putMediumString(::qpid::management::Manageable::StatusText (status, text));
        return;
    }

    outBuf.putLong(status);
    outBuf.putShortString(Manageable::StatusText(status, text));
}
