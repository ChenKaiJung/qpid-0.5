#
# Licensed to the Apache Software Foundation (ASF) under one
# or more contributor license agreements.  See the NOTICE file
# distributed with this work for additional information
# regarding copyright ownership.  The ASF licenses this file
# to you under the Apache License, Version 2.0 (the
# "License"); you may not use this file except in compliance
# with the License.  You may obtain a copy of the License at
# 
#   http:#www.apache.org/licenses/LICENSE-2.0
# 
# Unless required by applicable law or agreed to in writing,
# software distributed under the License is distributed on an
# "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY
# KIND, either express or implied.  See the License for the
# specific language governing permissions and limitations
# under the License.
#

# This source file was created by a code generator.
# Please do not edit.




mgen_generator=$(mgen_dir)/qmf-gen \
    $(mgen_dir)/qmfgen/generate.py \
    $(mgen_dir)/qmfgen/schema.py \
    $(mgen_dir)/qmfgen/management-types.xml \
    $(top_srcdir)/../specs/management-schema.xml \
    $(mgen_dir)/qmfgen/templates/Class.h \
    $(mgen_dir)/qmfgen/templates/Class.cpp \
    $(mgen_dir)/qmfgen/templates/Args.h \
    $(mgen_dir)/qmfgen/templates/Event.h \
    $(mgen_dir)/qmfgen/templates/Event.cpp \
    $(mgen_dir)/qmfgen/templates/Package.h \
    $(mgen_dir)/qmfgen/templates/Package.cpp \
    $(mgen_dir)/qmfgen/templates/Class.h \
    $(mgen_dir)/qmfgen/templates/Class.cpp \
    $(mgen_dir)/qmfgen/templates/Args.h \
    $(mgen_dir)/qmfgen/templates/Event.h \
    $(mgen_dir)/qmfgen/templates/Event.cpp \
    $(mgen_dir)/qmfgen/templates/Package.h \
    $(mgen_dir)/qmfgen/templates/Package.cpp \
    $(mgen_dir)/qmfgen/templates/Class.h \
    $(mgen_dir)/qmfgen/templates/Class.cpp \
    $(mgen_dir)/qmfgen/templates/Args.h \
    $(mgen_dir)/qmfgen/templates/Event.h \
    $(mgen_dir)/qmfgen/templates/Event.cpp \
    $(mgen_dir)/qmfgen/templates/Package.h \
    $(mgen_dir)/qmfgen/templates/Package.cpp \
    $(mgen_dir)/qmfgen/templates/Makefile.mk

mgen_broker_cpp=gen/qmf/org/apache/qpid/broker/System.cpp \
    gen/qmf/org/apache/qpid/broker/Broker.cpp \
    gen/qmf/org/apache/qpid/broker/Agent.cpp \
    gen/qmf/org/apache/qpid/broker/Vhost.cpp \
    gen/qmf/org/apache/qpid/broker/Queue.cpp \
    gen/qmf/org/apache/qpid/broker/Exchange.cpp \
    gen/qmf/org/apache/qpid/broker/Binding.cpp \
    gen/qmf/org/apache/qpid/broker/Connection.cpp \
    gen/qmf/org/apache/qpid/broker/Link.cpp \
    gen/qmf/org/apache/qpid/broker/Bridge.cpp \
    gen/qmf/org/apache/qpid/broker/Session.cpp \
    gen/qmf/org/apache/qpid/broker/EventClientConnect.cpp \
    gen/qmf/org/apache/qpid/broker/EventClientConnectFail.cpp \
    gen/qmf/org/apache/qpid/broker/EventClientDisconnect.cpp \
    gen/qmf/org/apache/qpid/broker/EventBrokerLinkUp.cpp \
    gen/qmf/org/apache/qpid/broker/EventBrokerLinkDown.cpp \
    gen/qmf/org/apache/qpid/broker/EventQueueDeclare.cpp \
    gen/qmf/org/apache/qpid/broker/EventQueueDelete.cpp \
    gen/qmf/org/apache/qpid/broker/EventExchangeDeclare.cpp \
    gen/qmf/org/apache/qpid/broker/EventExchangeDelete.cpp \
    gen/qmf/org/apache/qpid/broker/EventBind.cpp \
    gen/qmf/org/apache/qpid/broker/EventUnbind.cpp \
    gen/qmf/org/apache/qpid/broker/EventSubscribe.cpp \
    gen/qmf/org/apache/qpid/broker/EventUnsubscribe.cpp \
    gen/qmf/org/apache/qpid/broker/Package.cpp \
    gen/qmf/org/apache/qpid/acl/Acl.cpp \
    gen/qmf/org/apache/qpid/acl/EventAllow.cpp \
    gen/qmf/org/apache/qpid/acl/EventDeny.cpp \
    gen/qmf/org/apache/qpid/acl/EventFileLoaded.cpp \
    gen/qmf/org/apache/qpid/acl/EventFileLoadFailed.cpp \
    gen/qmf/org/apache/qpid/acl/Package.cpp \
    gen/qmf/org/apache/qpid/cluster/Cluster.cpp \
    gen/qmf/org/apache/qpid/cluster/Package.cpp

# Header file install rules.
org_apache_qpid_brokerdir = $(includedir)/qmf/org/apache/qpid/broker
dist_org_apache_qpid_broker_HEADERS = gen/qmf/org/apache/qpid/broker/System.h \
    gen/qmf/org/apache/qpid/broker/Broker.h \
    gen/qmf/org/apache/qpid/broker/Agent.h \
    gen/qmf/org/apache/qpid/broker/Vhost.h \
    gen/qmf/org/apache/qpid/broker/Queue.h \
    gen/qmf/org/apache/qpid/broker/Exchange.h \
    gen/qmf/org/apache/qpid/broker/Binding.h \
    gen/qmf/org/apache/qpid/broker/Connection.h \
    gen/qmf/org/apache/qpid/broker/Link.h \
    gen/qmf/org/apache/qpid/broker/Bridge.h \
    gen/qmf/org/apache/qpid/broker/Session.h \
    gen/qmf/org/apache/qpid/broker/ArgsBrokerEcho.h \
    gen/qmf/org/apache/qpid/broker/ArgsBrokerConnect.h \
    gen/qmf/org/apache/qpid/broker/ArgsBrokerQueueMoveMessages.h \
    gen/qmf/org/apache/qpid/broker/ArgsQueuePurge.h \
    gen/qmf/org/apache/qpid/broker/ArgsLinkBridge.h \
    gen/qmf/org/apache/qpid/broker/EventClientConnect.h \
    gen/qmf/org/apache/qpid/broker/EventClientConnectFail.h \
    gen/qmf/org/apache/qpid/broker/EventClientDisconnect.h \
    gen/qmf/org/apache/qpid/broker/EventBrokerLinkUp.h \
    gen/qmf/org/apache/qpid/broker/EventBrokerLinkDown.h \
    gen/qmf/org/apache/qpid/broker/EventQueueDeclare.h \
    gen/qmf/org/apache/qpid/broker/EventQueueDelete.h \
    gen/qmf/org/apache/qpid/broker/EventExchangeDeclare.h \
    gen/qmf/org/apache/qpid/broker/EventExchangeDelete.h \
    gen/qmf/org/apache/qpid/broker/EventBind.h \
    gen/qmf/org/apache/qpid/broker/EventUnbind.h \
    gen/qmf/org/apache/qpid/broker/EventSubscribe.h \
    gen/qmf/org/apache/qpid/broker/EventUnsubscribe.h \
    gen/qmf/org/apache/qpid/broker/Package.h

org_apache_qpid_acldir = $(includedir)/qmf/org/apache/qpid/acl
dist_org_apache_qpid_acl_HEADERS = gen/qmf/org/apache/qpid/acl/Acl.h \
    gen/qmf/org/apache/qpid/acl/EventAllow.h \
    gen/qmf/org/apache/qpid/acl/EventDeny.h \
    gen/qmf/org/apache/qpid/acl/EventFileLoaded.h \
    gen/qmf/org/apache/qpid/acl/EventFileLoadFailed.h \
    gen/qmf/org/apache/qpid/acl/Package.h

org_apache_qpid_clusterdir = $(includedir)/qmf/org/apache/qpid/cluster
dist_org_apache_qpid_cluster_HEADERS = gen/qmf/org/apache/qpid/cluster/Cluster.h \
    gen/qmf/org/apache/qpid/cluster/ArgsClusterStopClusterNode.h \
    gen/qmf/org/apache/qpid/cluster/Package.h


if GENERATE
$(srcdir)/managementgen.mk: $(mgen_generator)
	$(mgen_cmd)

$(mgen_generator):
endif


qmfgen_sources=gen/qmf/org/apache/qpid/broker/System.h \
    gen/qmf/org/apache/qpid/broker/Broker.h \
    gen/qmf/org/apache/qpid/broker/Agent.h \
    gen/qmf/org/apache/qpid/broker/Vhost.h \
    gen/qmf/org/apache/qpid/broker/Queue.h \
    gen/qmf/org/apache/qpid/broker/Exchange.h \
    gen/qmf/org/apache/qpid/broker/Binding.h \
    gen/qmf/org/apache/qpid/broker/Connection.h \
    gen/qmf/org/apache/qpid/broker/Link.h \
    gen/qmf/org/apache/qpid/broker/Bridge.h \
    gen/qmf/org/apache/qpid/broker/Session.h \
    gen/qmf/org/apache/qpid/broker/ArgsBrokerEcho.h \
    gen/qmf/org/apache/qpid/broker/ArgsBrokerConnect.h \
    gen/qmf/org/apache/qpid/broker/ArgsBrokerQueueMoveMessages.h \
    gen/qmf/org/apache/qpid/broker/ArgsQueuePurge.h \
    gen/qmf/org/apache/qpid/broker/ArgsLinkBridge.h \
    gen/qmf/org/apache/qpid/broker/EventClientConnect.h \
    gen/qmf/org/apache/qpid/broker/EventClientConnectFail.h \
    gen/qmf/org/apache/qpid/broker/EventClientDisconnect.h \
    gen/qmf/org/apache/qpid/broker/EventBrokerLinkUp.h \
    gen/qmf/org/apache/qpid/broker/EventBrokerLinkDown.h \
    gen/qmf/org/apache/qpid/broker/EventQueueDeclare.h \
    gen/qmf/org/apache/qpid/broker/EventQueueDelete.h \
    gen/qmf/org/apache/qpid/broker/EventExchangeDeclare.h \
    gen/qmf/org/apache/qpid/broker/EventExchangeDelete.h \
    gen/qmf/org/apache/qpid/broker/EventBind.h \
    gen/qmf/org/apache/qpid/broker/EventUnbind.h \
    gen/qmf/org/apache/qpid/broker/EventSubscribe.h \
    gen/qmf/org/apache/qpid/broker/EventUnsubscribe.h \
    gen/qmf/org/apache/qpid/broker/Package.h \
    gen/qmf/org/apache/qpid/acl/Acl.h \
    gen/qmf/org/apache/qpid/acl/EventAllow.h \
    gen/qmf/org/apache/qpid/acl/EventDeny.h \
    gen/qmf/org/apache/qpid/acl/EventFileLoaded.h \
    gen/qmf/org/apache/qpid/acl/EventFileLoadFailed.h \
    gen/qmf/org/apache/qpid/acl/Package.h \
    gen/qmf/org/apache/qpid/cluster/Cluster.h \
    gen/qmf/org/apache/qpid/cluster/ArgsClusterStopClusterNode.h \
    gen/qmf/org/apache/qpid/cluster/Package.h \
    gen/qmf/org/apache/qpid/broker/System.cpp \
    gen/qmf/org/apache/qpid/broker/Broker.cpp \
    gen/qmf/org/apache/qpid/broker/Agent.cpp \
    gen/qmf/org/apache/qpid/broker/Vhost.cpp \
    gen/qmf/org/apache/qpid/broker/Queue.cpp \
    gen/qmf/org/apache/qpid/broker/Exchange.cpp \
    gen/qmf/org/apache/qpid/broker/Binding.cpp \
    gen/qmf/org/apache/qpid/broker/Connection.cpp \
    gen/qmf/org/apache/qpid/broker/Link.cpp \
    gen/qmf/org/apache/qpid/broker/Bridge.cpp \
    gen/qmf/org/apache/qpid/broker/Session.cpp \
    gen/qmf/org/apache/qpid/broker/EventClientConnect.cpp \
    gen/qmf/org/apache/qpid/broker/EventClientConnectFail.cpp \
    gen/qmf/org/apache/qpid/broker/EventClientDisconnect.cpp \
    gen/qmf/org/apache/qpid/broker/EventBrokerLinkUp.cpp \
    gen/qmf/org/apache/qpid/broker/EventBrokerLinkDown.cpp \
    gen/qmf/org/apache/qpid/broker/EventQueueDeclare.cpp \
    gen/qmf/org/apache/qpid/broker/EventQueueDelete.cpp \
    gen/qmf/org/apache/qpid/broker/EventExchangeDeclare.cpp \
    gen/qmf/org/apache/qpid/broker/EventExchangeDelete.cpp \
    gen/qmf/org/apache/qpid/broker/EventBind.cpp \
    gen/qmf/org/apache/qpid/broker/EventUnbind.cpp \
    gen/qmf/org/apache/qpid/broker/EventSubscribe.cpp \
    gen/qmf/org/apache/qpid/broker/EventUnsubscribe.cpp \
    gen/qmf/org/apache/qpid/broker/Package.cpp \
    gen/qmf/org/apache/qpid/acl/Acl.cpp \
    gen/qmf/org/apache/qpid/acl/EventAllow.cpp \
    gen/qmf/org/apache/qpid/acl/EventDeny.cpp \
    gen/qmf/org/apache/qpid/acl/EventFileLoaded.cpp \
    gen/qmf/org/apache/qpid/acl/EventFileLoadFailed.cpp \
    gen/qmf/org/apache/qpid/acl/Package.cpp \
    gen/qmf/org/apache/qpid/cluster/Cluster.cpp \
    gen/qmf/org/apache/qpid/cluster/Package.cpp

