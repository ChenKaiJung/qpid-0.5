#ifndef QPID_CLUSTER_EVENTFRAME_H
#define QPID_CLUSTER_EVENTFRAME_H

/*
 *
 * Licensed to the Apache Software Foundation (ASF) under one
 * or more contributor license agreements.  See the NOTICE file
 * distributed with this work for additional information
 * regarding copyright ownership.  The ASF licenses this file
 * to you under the Apache License, Version 2.0 (the
 * "License"); you may not use this file except in compliance
 * with the License.  You may obtain a copy of the License at
 * 
 *   http://www.apache.org/licenses/LICENSE-2.0
 * 
 * Unless required by applicable law or agreed to in writing,
 * software distributed under the License is distributed on an
 * "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY
 * KIND, either express or implied.  See the License for the
 * specific language governing permissions and limitations
 * under the License.
 *
 */

#include "types.h"
#include "Event.h"
#include "qpid/framing/AMQFrame.h"
#include <boost/intrusive_ptr.hpp>
#include <iosfwd>

namespace qpid {
namespace cluster {

/**
 * A frame decoded from an Event.
 */
struct EventFrame
{
  public:
    EventFrame();

    EventFrame(const EventHeader& e, const framing::AMQFrame& f, int rc=0);

    bool isCluster() const { return connectionId.getNumber() == 0; }
    bool isConnection() const { return connectionId.getNumber() != 0; }
    bool isLastInEvent() const { return readCredit; }
    MemberId getMemberId() const { return connectionId.getMember(); }


    ConnectionId connectionId;
    framing::AMQFrame frame;   
    int readCredit; ///< last frame in an event, give credit when processed.
    EventType type;
};

std::ostream& operator<<(std::ostream& o, const EventFrame& e);

}} // namespace qpid::cluster

#endif  /*!QPID_CLUSTER_EVENTFRAME_H*/
