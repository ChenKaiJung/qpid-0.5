
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
#include "Broker.h"
#include "ArgsBrokerEcho.h"
#include "ArgsBrokerConnect.h"
#include "ArgsBrokerQueueMoveMessages.h"


using namespace qmf::org::apache::qpid::broker;
using namespace qpid::framing;
using           qpid::management::ManagementAgent;
using           qpid::management::Manageable;
using           qpid::management::ManagementObject;
using           qpid::management::Args;
using           std::string;

string  Broker::packageName  = string ("org.apache.qpid.broker");
string  Broker::className    = string ("broker");
uint8_t Broker::md5Sum[16]   =
    {0xde,0x8f,0x5e,0xd2,0x81,0xa4,0x7d,0x99,0x78,0x6f,0x2c,0xb7,0x2c,0xa9,0x29,0xb9};

Broker::Broker (ManagementAgent* _agent, Manageable* _core, ::qpid::management::Manageable* _parent, uint16_t _port) :
    ManagementObject(_agent, _core),port(_port)
{
    systemRef = _parent->GetManagementObject ()->getObjectId ();
    workerThreads = 0;
    maxConns = 0;
    connBacklog = 0;
    stagingThreshold = 0;
    mgmtPubInterval = 0;
    version = "";
    dataDir = "";
    uptime = 0;


    // Optional properties start out not-present
    for (uint8_t idx = 0; idx < 1; idx++)
        presenceMask[idx] = 0;


}

Broker::~Broker ()
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

void Broker::registerSelf(ManagementAgent* agent)
{
    agent->registerClass(packageName, className, md5Sum, writeSchema);
}

void Broker::writeSchema (Buffer& buf)
{
    FieldTable ft;

    // Schema class header:
    buf.putOctet       (CLASS_KIND_TABLE);
    buf.putShortString (packageName); // Package Name
    buf.putShortString (className);   // Class Name
    buf.putBin128      (md5Sum);      // Schema Hash
    buf.putShort       (9); // Config Element Count
    buf.putShort       (1); // Inst Element Count
    buf.putShort       (3); // Method Count

    // Properties
    ft.clear();
    ft.setString (NAME, "systemRef");
    ft.setInt    (TYPE, TYPE_REF);
    ft.setInt    (ACCESS, ACCESS_RC);
    ft.setInt    (IS_INDEX, 1);
    ft.setInt    (IS_OPTIONAL, 0);
    ft.setString (DESC,   "System ID");
    buf.put (ft);

    ft.clear();
    ft.setString (NAME, "port");
    ft.setInt    (TYPE, TYPE_U16);
    ft.setInt    (ACCESS, ACCESS_RC);
    ft.setInt    (IS_INDEX, 1);
    ft.setInt    (IS_OPTIONAL, 0);
    ft.setString (DESC,   "TCP Port for AMQP Service");
    buf.put (ft);

    ft.clear();
    ft.setString (NAME, "workerThreads");
    ft.setInt    (TYPE, TYPE_U16);
    ft.setInt    (ACCESS, ACCESS_RO);
    ft.setInt    (IS_INDEX, 0);
    ft.setInt    (IS_OPTIONAL, 0);
    ft.setString (DESC,   "Thread pool size");
    buf.put (ft);

    ft.clear();
    ft.setString (NAME, "maxConns");
    ft.setInt    (TYPE, TYPE_U16);
    ft.setInt    (ACCESS, ACCESS_RO);
    ft.setInt    (IS_INDEX, 0);
    ft.setInt    (IS_OPTIONAL, 0);
    ft.setString (DESC,   "Maximum allowed connections");
    buf.put (ft);

    ft.clear();
    ft.setString (NAME, "connBacklog");
    ft.setInt    (TYPE, TYPE_U16);
    ft.setInt    (ACCESS, ACCESS_RO);
    ft.setInt    (IS_INDEX, 0);
    ft.setInt    (IS_OPTIONAL, 0);
    ft.setString (DESC,   "Connection backlog limit for listening socket");
    buf.put (ft);

    ft.clear();
    ft.setString (NAME, "stagingThreshold");
    ft.setInt    (TYPE, TYPE_U32);
    ft.setInt    (ACCESS, ACCESS_RO);
    ft.setInt    (IS_INDEX, 0);
    ft.setInt    (IS_OPTIONAL, 0);
    ft.setString (DESC,   "Broker stages messages over this size to disk");
    buf.put (ft);

    ft.clear();
    ft.setString (NAME, "mgmtPubInterval");
    ft.setInt    (TYPE, TYPE_U16);
    ft.setInt    (ACCESS, ACCESS_RW);
    ft.setInt    (IS_INDEX, 0);
    ft.setInt    (IS_OPTIONAL, 0);
    ft.setString (UNIT,   "second");
    ft.setInt    (MIN,    1);
    ft.setString (DESC,   "Interval for management broadcasts");
    buf.put (ft);

    ft.clear();
    ft.setString (NAME, "version");
    ft.setInt    (TYPE, TYPE_SSTR);
    ft.setInt    (ACCESS, ACCESS_RO);
    ft.setInt    (IS_INDEX, 0);
    ft.setInt    (IS_OPTIONAL, 0);
    ft.setString (DESC,   "Running software version");
    buf.put (ft);

    ft.clear();
    ft.setString (NAME, "dataDir");
    ft.setInt    (TYPE, TYPE_SSTR);
    ft.setInt    (ACCESS, ACCESS_RO);
    ft.setInt    (IS_INDEX, 0);
    ft.setInt    (IS_OPTIONAL, 1);
    ft.setString (DESC,   "Persistent configuration storage location");
    buf.put (ft);


    // Statistics
    ft.clear();
    ft.setString (NAME,   "uptime");
    ft.setInt    (TYPE,   TYPE_DELTATIME);
    buf.put (ft);


    // Methods
    ft.clear();
    ft.setString (NAME,     "echo");
    ft.setInt    (ARGCOUNT, 2);
    ft.setString (DESC,     "Request a response to test the path to the management broker");
    buf.put (ft);

    ft.clear();
    ft.setString (NAME,    "sequence");
    ft.setInt    (TYPE,    TYPE_U32);
    ft.setString (DIR,     "IO");
    ft.setString (DEFAULT, "0");
    buf.put (ft);

    ft.clear();
    ft.setString (NAME,    "body");
    ft.setInt    (TYPE,    TYPE_LSTR);
    ft.setString (DIR,     "IO");
    ft.setString (DEFAULT, "");
    buf.put (ft);

    ft.clear();
    ft.setString (NAME,     "connect");
    ft.setInt    (ARGCOUNT, 7);
    ft.setString (DESC,     "Establish a connection to another broker");
    buf.put (ft);

    ft.clear();
    ft.setString (NAME,    "host");
    ft.setInt    (TYPE,    TYPE_SSTR);
    ft.setString (DIR,     "I");
    buf.put (ft);

    ft.clear();
    ft.setString (NAME,    "port");
    ft.setInt    (TYPE,    TYPE_U32);
    ft.setString (DIR,     "I");
    buf.put (ft);

    ft.clear();
    ft.setString (NAME,    "durable");
    ft.setInt    (TYPE,    TYPE_BOOL);
    ft.setString (DIR,     "I");
    buf.put (ft);

    ft.clear();
    ft.setString (NAME,    "authMechanism");
    ft.setInt    (TYPE,    TYPE_SSTR);
    ft.setString (DIR,     "I");
    buf.put (ft);

    ft.clear();
    ft.setString (NAME,    "username");
    ft.setInt    (TYPE,    TYPE_SSTR);
    ft.setString (DIR,     "I");
    buf.put (ft);

    ft.clear();
    ft.setString (NAME,    "password");
    ft.setInt    (TYPE,    TYPE_SSTR);
    ft.setString (DIR,     "I");
    buf.put (ft);

    ft.clear();
    ft.setString (NAME,    "transport");
    ft.setInt    (TYPE,    TYPE_SSTR);
    ft.setString (DIR,     "I");
    buf.put (ft);

    ft.clear();
    ft.setString (NAME,     "queueMoveMessages");
    ft.setInt    (ARGCOUNT, 3);
    ft.setString (DESC,     "Move messages from one queue to another");
    buf.put (ft);

    ft.clear();
    ft.setString (NAME,    "srcQueue");
    ft.setInt    (TYPE,    TYPE_SSTR);
    ft.setString (DIR,     "I");
    ft.setString (DESC,    "Source queue");
    buf.put (ft);

    ft.clear();
    ft.setString (NAME,    "destQueue");
    ft.setInt    (TYPE,    TYPE_SSTR);
    ft.setString (DIR,     "I");
    ft.setString (DESC,    "Destination queue");
    buf.put (ft);

    ft.clear();
    ft.setString (NAME,    "qty");
    ft.setInt    (TYPE,    TYPE_U32);
    ft.setString (DIR,     "I");
    ft.setString (DESC,    "# of messages to move. 0 means all messages");
    buf.put (ft);


}



void Broker::writeProperties (Buffer& buf)
{
    ::qpid::sys::Mutex::ScopedLock mutex(accessLock);
    configChanged = false;

    writeTimestamps (buf);

    for (uint8_t idx = 0; idx < 1; idx++)
        buf.putOctet(presenceMask[idx]);

    systemRef.encode(buf);
    buf.putShort(port);
    buf.putShort(workerThreads);
    buf.putShort(maxConns);
    buf.putShort(connBacklog);
    buf.putLong(stagingThreshold);
    buf.putShort(mgmtPubInterval);
    buf.putShortString(version);
    if (presenceMask[presenceByte_dataDir] & presenceMask_dataDir) {
        buf.putShortString(dataDir);
    }

}

void Broker::writeStatistics (Buffer& buf, bool skipHeaders)
{
    ::qpid::sys::Mutex::ScopedLock mutex(accessLock);
    instChanged = false;



    if (!skipHeaders)
        writeTimestamps (buf);
    buf.putLongLong(uptime);


    // Maintenance of hi-lo statistics


}

void Broker::doMethod (string& methodName, Buffer& inBuf, Buffer& outBuf)
{
    Manageable::status_t status = Manageable::STATUS_UNKNOWN_METHOD;
    std::string          text;


    if (methodName == "echo") {
        ArgsBrokerEcho ioArgs;
        ioArgs.io_sequence = inBuf.getLong();
        inBuf.getMediumString(ioArgs.io_body);
        status = coreObject->ManagementMethod (METHOD_ECHO, ioArgs, text);
        outBuf.putLong        (status);
        outBuf.putMediumString(::qpid::management::Manageable::StatusText (status, text));
        outBuf.putLong(ioArgs.io_sequence);
        outBuf.putMediumString(ioArgs.io_body);
        return;
    }

    if (methodName == "connect") {
        ArgsBrokerConnect ioArgs;
        inBuf.getShortString(ioArgs.i_host);
        ioArgs.i_port = inBuf.getLong();
        ioArgs.i_durable = inBuf.getOctet()==1;
        inBuf.getShortString(ioArgs.i_authMechanism);
        inBuf.getShortString(ioArgs.i_username);
        inBuf.getShortString(ioArgs.i_password);
        inBuf.getShortString(ioArgs.i_transport);
        status = coreObject->ManagementMethod (METHOD_CONNECT, ioArgs, text);
        outBuf.putLong        (status);
        outBuf.putMediumString(::qpid::management::Manageable::StatusText (status, text));
        return;
    }

    if (methodName == "queueMoveMessages") {
        ArgsBrokerQueueMoveMessages ioArgs;
        inBuf.getShortString(ioArgs.i_srcQueue);
        inBuf.getShortString(ioArgs.i_destQueue);
        ioArgs.i_qty = inBuf.getLong();
        status = coreObject->ManagementMethod (METHOD_QUEUEMOVEMESSAGES, ioArgs, text);
        outBuf.putLong        (status);
        outBuf.putMediumString(::qpid::management::Manageable::StatusText (status, text));
        return;
    }

    outBuf.putLong(status);
    outBuf.putShortString(Manageable::StatusText(status, text));
}
