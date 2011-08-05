
#ifndef _ARGS_BROKERECHO_
#define _ARGS_BROKERECHO_

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

#include "qpid/management/Args.h"
#include "qpid/framing/FieldTable.h"
#include "qpid/framing/Uuid.h"
#include <string>

namespace qmf { 
namespace org {
namespace apache {
namespace qpid {
namespace broker {


    class ArgsBrokerEcho : public ::qpid::management::Args
{
  public:
    uint32_t io_sequence;
    std::string io_body;

};

}}}}}

#endif  /*!_ARGS_BROKERECHO_*/