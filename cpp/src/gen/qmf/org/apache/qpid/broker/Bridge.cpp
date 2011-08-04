
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
#include "Bridge.h"


using namespace qmf::org::apache::qpid::broker;
using namespace qpid::framing;
using           qpid::management::ManagementAgent;
using           qpid::management::Manageable;
using           qpid::management::ManagementObject;
using           qpid::management::Args;
using           std::string;

string  Bridge::packageName  = string ("org.apache.qpid.broker");
string  Bridge::className    = string ("bridge");
uint8_t Bridge::md5Sum[16]   =
    {0x74,0x88,0x0,0x11,0x8c,0xaf,0xe2,0x1b,0xf,0x24,0xb0,0x84,0x60,0x41,0x2a,0x90};

Bridge::Bridge (ManagementAgent* _agent, Manageable* _core, ::qpid::management::Manageable* _parent, uint16_t _channelId, uint8_t _durable, const std::string& _src, const std::string& _dest, const std::string& _key, uint8_t _srcIsQueue, uint8_t _srcIsLocal, const std::string& _tag, const std::string& _excludes, uint8_t _dynamic, uint16_t _sync) :
    ManagementObject(_agent, _core),channelId(_channelId),durable(_durable),src(_src),dest(_dest),key(_key),srcIsQueue(_srcIsQueue),srcIsLocal(_srcIsLocal),tag(_tag),excludes(_excludes),dynamic(_dynamic),sync(_sync)
{
    linkRef = _parent->GetManagementObject ()->getObjectId ();



}

Bridge::~Bridge ()
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

void Bridge::registerSelf(ManagementAgent* agent)
{
    agent->registerClass(packageName, className, md5Sum, writeSchema);
}

void Bridge::writeSchema (Buffer& buf)
{
    FieldTable ft;

    // Schema class header:
    buf.putOctet       (CLASS_KIND_TABLE);
    buf.putShortString (packageName); // Package Name
    buf.putShortString (className);   // Class Name
    buf.putBin128      (md5Sum);      // Schema Hash
    buf.putShort       (12); // Config Element Count
    buf.putShort       (0); // Inst Element Count
    buf.putShort       (1); // Method Count

    // Properties
    ft.clear();
    ft.setString (NAME, "linkRef");
    ft.setInt    (TYPE, TYPE_REF);
    ft.setInt    (ACCESS, ACCESS_RC);
    ft.setInt    (IS_INDEX, 1);
    ft.setInt    (IS_OPTIONAL, 0);
    buf.put (ft);

    ft.clear();
    ft.setString (NAME, "channelId");
    ft.setInt    (TYPE, TYPE_U16);
    ft.setInt    (ACCESS, ACCESS_RC);
    ft.setInt    (IS_INDEX, 1);
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
    ft.setString (NAME, "src");
    ft.setInt    (TYPE, TYPE_SSTR);
    ft.setInt    (ACCESS, ACCESS_RC);
    ft.setInt    (IS_INDEX, 0);
    ft.setInt    (IS_OPTIONAL, 0);
    buf.put (ft);

    ft.clear();
    ft.setString (NAME, "dest");
    ft.setInt    (TYPE, TYPE_SSTR);
    ft.setInt    (ACCESS, ACCESS_RC);
    ft.setInt    (IS_INDEX, 0);
    ft.setInt    (IS_OPTIONAL, 0);
    buf.put (ft);

    ft.clear();
    ft.setString (NAME, "key");
    ft.setInt    (TYPE, TYPE_SSTR);
    ft.setInt    (ACCESS, ACCESS_RC);
    ft.setInt    (IS_INDEX, 0);
    ft.setInt    (IS_OPTIONAL, 0);
    buf.put (ft);

    ft.clear();
    ft.setString (NAME, "srcIsQueue");
    ft.setInt    (TYPE, TYPE_BOOL);
    ft.setInt    (ACCESS, ACCESS_RC);
    ft.setInt    (IS_INDEX, 0);
    ft.setInt    (IS_OPTIONAL, 0);
    buf.put (ft);

    ft.clear();
    ft.setString (NAME, "srcIsLocal");
    ft.setInt    (TYPE, TYPE_BOOL);
    ft.setInt    (ACCESS, ACCESS_RC);
    ft.setInt    (IS_INDEX, 0);
    ft.setInt    (IS_OPTIONAL, 0);
    buf.put (ft);

    ft.clear();
    ft.setString (NAME, "tag");
    ft.setInt    (TYPE, TYPE_SSTR);
    ft.setInt    (ACCESS, ACCESS_RC);
    ft.setInt    (IS_INDEX, 0);
    ft.setInt    (IS_OPTIONAL, 0);
    buf.put (ft);

    ft.clear();
    ft.setString (NAME, "excludes");
    ft.setInt    (TYPE, TYPE_SSTR);
    ft.setInt    (ACCESS, ACCESS_RC);
    ft.setInt    (IS_INDEX, 0);
    ft.setInt    (IS_OPTIONAL, 0);
    buf.put (ft);

    ft.clear();
    ft.setString (NAME, "dynamic");
    ft.setInt    (TYPE, TYPE_BOOL);
    ft.setInt    (ACCESS, ACCESS_RC);
    ft.setInt    (IS_INDEX, 0);
    ft.setInt    (IS_OPTIONAL, 0);
    buf.put (ft);

    ft.clear();
    ft.setString (NAME, "sync");
    ft.setInt    (TYPE, TYPE_U16);
    ft.setInt    (ACCESS, ACCESS_RC);
    ft.setInt    (IS_INDEX, 0);
    ft.setInt    (IS_OPTIONAL, 0);
    buf.put (ft);


    // Statistics

    // Methods
    ft.clear();
    ft.setString (NAME,     "close");
    ft.setInt    (ARGCOUNT, 0);
    buf.put (ft);


}



void Bridge::writeProperties (Buffer& buf)
{
    ::qpid::sys::Mutex::ScopedLock mutex(accessLock);
    configChanged = false;

    writeTimestamps (buf);

    linkRef.encode(buf);
    buf.putShort(channelId);
    buf.putOctet(durable?1:0);
    buf.putShortString(src);
    buf.putShortString(dest);
    buf.putShortString(key);
    buf.putOctet(srcIsQueue?1:0);
    buf.putOctet(srcIsLocal?1:0);
    buf.putShortString(tag);
    buf.putShortString(excludes);
    buf.putOctet(dynamic?1:0);
    buf.putShort(sync);

}

void Bridge::writeStatistics (Buffer& buf, bool skipHeaders)
{
    ::qpid::sys::Mutex::ScopedLock mutex(accessLock);
    instChanged = false;



    if (!skipHeaders)
        writeTimestamps (buf);


    // Maintenance of hi-lo statistics


}

void Bridge::doMethod (string& methodName, Buffer&, Buffer& outBuf)
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
