#
# Licensed to the Apache Software Foundation (ASF) under one
# or more contributor license agreements.  See the NOTICE file
# distributed with this work for additional information
# regarding copyright ownership.  The ASF licenses this file
# to you under the Apache License, Version 2.0 (the
# "License"); you may not use this file except in compliance
# with the License.  You may obtain a copy of the License at
#
#   http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing,
# software distributed under the License is distributed on an
# "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY
# KIND, either express or implied.  See the License for the
# specific language governing permissions and limitations
# under the License.
#

SUBDIRS = . tests

# The Windows-only sources are not compiled using this Makefile, but
# are listed here to ensure they're included in releases. They are built
# using Visual Studio solutions/projects.
windows_dist = \
  qpid.sln \
  broker.vcproj \
  common.vcproj \
  client.vcproj \
  qpidbroker.vcproj \
  qmfconsole.vcproj \
  protocol_gen.mak \
  qpid/client/windows/SaslFactory.cpp \
  qpid/log/windows/SinkOptions.cpp \
  qpid/log/windows/SinkOptions.h \
  qpid/sys/windows/check.h \
  qpid/sys/windows/AsynchIO.cpp \
  qpid/sys/windows/AsynchIoResult.h \
  qpid/sys/windows/Condition.h \
  qpid/sys/windows/FileSysDir.cpp \
  qpid/sys/windows/IntegerTypes.h \
  qpid/sys/windows/IocpPoller.cpp \
  qpid/sys/windows/IOHandle.cpp \
  qpid/sys/windows/IoHandlePrivate.h \
  qpid/sys/windows/LockFile.cpp \
  qpid/sys/windows/PollableCondition.cpp \
  qpid/sys/windows/Mutex.h \
  qpid/sys/windows/Shlib.cpp \
  qpid/sys/windows/Socket.cpp \
  qpid/sys/windows/StrError.cpp \
  qpid/sys/windows/SystemInfo.cpp \
  qpid/sys/windows/Thread.cpp \
  qpid/sys/windows/Time.cpp \
  qpid/sys/windows/Time.h \
  qpid/sys/windows/uuid.cpp \
  qpid/sys/windows/uuid.h \
  windows/QpiddBroker.cpp \
  qpid/broker/windows/BrokerDefaults.cpp \
  qpid/broker/windows/SaslAuthenticator.cpp

EXTRA_DIST= $(platform_dist) $(rgen_srcs) $(windows_dist)

## Generated code

# Note: generated soure and makefiles included in distribution so a
# distribution can be built without code generation tools and XML
# sources.

# This phony target is needed by generated makefile fragments:
force:

if GENERATE

# AMQP_FINAL_XML is defined in ../configure.ac
amqp_0_10_xml=@AMQP_FINAL_XML@
specs=$(amqp_0_10_xml) $(top_srcdir)/xml/cluster.xml

# Ruby generator.
rgen_dir=$(top_srcdir)/rubygen
rgen_cmd=ruby -I $(rgen_dir) $(rgen_dir)/generate gen $(specs) all $(srcdir)/rubygen.mk

$(rgen_srcs) $(srcdir)/rubygen.mk: rgen.timestamp
rgen.timestamp: $(rgen_generator) $(specs)
	$(rgen_cmd); touch $@
$(rgen_generator):

# Management generator.
mgen_dir=$(top_srcdir)/managementgen
mgen_cmd=$(mgen_dir)/qmf-gen -m $(srcdir)/managementgen.mk -q -o gen/qmf \
	$(top_srcdir)/../specs/management-schema.xml \
	$(srcdir)/qpid/acl/management-schema.xml \
	$(srcdir)/qpid/cluster/management-schema.xml

$(srcdir)/managementgen.mk $(mgen_broker_cpp) $(dist_qpid_management_HEADERS): mgen.timestamp
mgen.timestamp: $(mgen_generator)
	$(mgen_cmd); touch $@
$(mgen_generator):

endif # GENERATE

include $(srcdir)/rubygen.mk
include $(srcdir)/managementgen.mk

## Compiler flags
AM_CXXFLAGS = $(WARNING_CFLAGS)
AM_LDFLAGS = -version-info $(LIBTOOL_VERSION_INFO_ARG)
INCLUDES = -Igen -I$(srcdir)/gen

## Automake macros to build libraries and executables.
qpidd_CXXFLAGS = $(AM_CXXFLAGS) -DMODULE_DIR=\"$(dmoduledir)\" -DCONF_FILE=\"$(sysconfdir)/qpidd.conf\"
libqpidclient_la_CXXFLAGS = $(AM_CXXFLAGS) -DMODULE_DIR=\"$(cmoduledir)\" -DCONF_FILE=\"$(confdir)/qpidc.conf\"

qpidd_LDADD =					\
  libqpidbroker.la				\
  libqpidcommon.la

posix_qpidd_src = posix/QpiddBroker.cpp

sbin_PROGRAMS = qpidd
qpidd_SOURCES = qpidd.cpp qpidd.h $(posix_qpidd_src)

posix_plat_src = \
  qpid/log/posix/SinkOptions.cpp \
  qpid/sys/posix/IOHandle.cpp \
  qpid/sys/posix/Socket.cpp \
  qpid/sys/posix/AsynchIO.cpp \
  qpid/sys/posix/FileSysDir.cpp \
  qpid/sys/posix/LockFile.cpp \
  qpid/sys/posix/Time.cpp \
  qpid/sys/posix/Thread.cpp \
  qpid/sys/posix/Shlib.cpp \
  qpid/sys/posix/Mutex.cpp \
  qpid/sys/posix/Fork.cpp \
  qpid/sys/posix/StrError.cpp \
  qpid/sys/posix/PollableCondition.cpp

posix_plat_hdr = \
  qpid/log/posix/SinkOptions.h \
  qpid/sys/posix/check.h \
  qpid/sys/posix/Condition.h \
  qpid/sys/posix/PrivatePosix.h \
  qpid/sys/posix/Mutex.h \
  qpid/sys/posix/Fork.h \
  qpid/sys/posix/IntegerTypes.h \
  qpid/sys/posix/Time.h

if HAVE_EPOLL 
  poller = qpid/sys/epoll/EpollPoller.cpp
endif

if HAVE_ECF
  poller = qpid/sys/solaris/ECFPoller.cpp
endif

if SUNOS
  systeminfo = qpid/sys/solaris/SystemInfo.cpp
else
  systeminfo = qpid/sys/posix/SystemInfo.cpp
endif

platform_src = $(posix_plat_src) $(poller) $(systeminfo)
platform_hdr = $(posix_plat_hdr)

posix_broker_src = \
  qpid/broker/posix/BrokerDefaults.cpp

lib_LTLIBRARIES = libqpidcommon.la libqpidbroker.la libqpidclient.la

# Definitions for client and daemon plugins
PLUGINLDFLAGS=-no-undefined -module -avoid-version
confdir=$(sysconfdir)/qpid
dmoduledir=$(libdir)/qpid/daemon
cmoduledir=$(libdir)/qpid/client
dmodule_LTLIBRARIES =
cmodule_LTLIBRARIES = 
module_hdr =

include cluster.mk
include acl.mk
include qmf.mk
include qmfc.mk
if HAVE_XML
include xml.mk
endif
include replication.mk

if RDMA

# RDMA (Infiniband) protocol code
librdmawrap_la_SOURCES = \
  qpid/sys/rdma/rdma_exception.h \
  qpid/sys/rdma/rdma_factories.cpp \
  qpid/sys/rdma/rdma_factories.h \
  qpid/sys/rdma/RdmaIO.cpp \
  qpid/sys/rdma/RdmaIO.h \
  qpid/sys/rdma/rdma_wrap.cpp \
  qpid/sys/rdma/rdma_wrap.h
librdmawrap_la_LIBADD = \
  libqpidcommon.la \
  -lrdmacm \
  -libverbs
librdmawrap_la_CXXFLAGS = \
  $(AM_CXXFLAGS) -Wno-missing-field-initializers
lib_LTLIBRARIES += \
  librdmawrap.la
librdmawrap_la_LDFLAGS = \
  -no-undefined

rdma_la_SOURCES = \
  qpid/sys/RdmaIOPlugin.cpp
rdma_la_LIBADD = \
  libqpidbroker.la \
  librdmawrap.la
rdma_la_LDFLAGS = $(PLUGINLDFLAGS)
rdma_la_CXXFLAGS = \
  $(AM_CXXFLAGS) -Wno-missing-field-initializers
dmodule_LTLIBRARIES += \
  rdma.la

rdmaconnector_la_SOURCES = \
  qpid/client/RdmaConnector.cpp
rdmaconnector_la_LIBADD = \
  libqpidclient.la \
  librdmawrap.la
rdmaconnector_la_LDFLAGS = $(PLUGINLDFLAGS)
rdmaconnector_la_CXXFLAGS = \
  $(AM_CXXFLAGS) -Wno-missing-field-initializers
cmodule_LTLIBRARIES += \
  rdmaconnector.la

# RDMA test/sample programs
noinst_PROGRAMS = RdmaServer RdmaClient
RdmaServer_SOURCES = qpid/sys/rdma/RdmaServer.cpp
RdmaServer_LDADD = \
  librdmawrap.la libqpidcommon.la
RdmaClient_SOURCES = qpid/sys/rdma/RdmaClient.cpp
RdmaClient_CXXFLAGS = \
  $(AM_CXXFLAGS) -Wno-missing-field-initializers
RdmaClient_LDADD = \
  librdmawrap.la libqpidcommon.la

endif

if SSL
include ssl.mk
endif

# New 0-10 codec, to be integrated in future.
# libqpidamqp_0_10_la_SOURCES= 
EXTRA_DIST +=\
  $(rgen_amqp_0_10_srcs) \
  qpid/amqp_0_10/apply.h \
  qpid/amqp_0_10/built_in_types.h \
  qpid/amqp_0_10/complex_types.cpp \
  qpid/amqp_0_10/Array.h \
  qpid/amqp_0_10/Array.cpp \
  qpid/amqp_0_10/Body.h \
  qpid/amqp_0_10/Command.h \
  qpid/amqp_0_10/CommmandPacker.h \
  qpid/amqp_0_10/Control.h \
  qpid/amqp_0_10/Header.h \
  qpid/amqp_0_10/Header.cpp \
  qpid/amqp_0_10/FrameHeader.h \
  qpid/amqp_0_10/FrameHeader.cpp \
  qpid/amqp_0_10/Holder.h \
  qpid/amqp_0_10/Codec.h \
  qpid/amqp_0_10/Packer.h \
  qpid/amqp_0_10/Decimal.h \
  qpid/amqp_0_10/SerializableString.h \
  qpid/amqp_0_10/Map.h \
  qpid/amqp_0_10/Map.cpp \
  qpid/amqp_0_10/Struct.h \
  qpid/amqp_0_10/Struct32.h \
  qpid/amqp_0_10/Struct32.cpp \
  qpid/amqp_0_10/Unit.h \
  qpid/amqp_0_10/Unit.cpp \
  qpid/amqp_0_10/UnitHandler.h \
  qpid/amqp_0_10/UnknownType.h \
  qpid/amqp_0_10/UnknownType.cpp \
  qpid/amqp_0_10/UnknownStruct.h \
  qpid/amqp_0_10/UnknownStruct.cpp 

libqpidcommon_la_LIBADD = \
  -lboost_program_options \
  -lboost_filesystem \
  -luuid \
  $(LIB_DLOPEN) \
  $(LIB_CLOCK_GETTIME)

libqpidcommon_la_SOURCES = \
  $(rgen_framing_srcs) \
  $(platform_src) \
  qpid/assert.cpp qpid/assert.h \
  qpid/pointer_to_other.h \
  qpid/Address.cpp \
  qpid/DataDir.cpp \
  qpid/Exception.cpp \
  qpid/Modules.cpp \
  qpid/Options.cpp \
  qpid/Plugin.cpp \
  qpid/RefCountedBuffer.h \
  qpid/RefCountedBuffer.cpp \
  qpid/Serializer.h \
  qpid/SessionState.h \
  qpid/SessionState.cpp \
  qpid/SessionId.cpp \
  qpid/StringUtils.cpp \
  qpid/Url.cpp \
  qpid/amqp_0_10/SessionHandler.h \
  qpid/amqp_0_10/SessionHandler.cpp \
  qpid/framing/AccumulatedAck.cpp \
  qpid/framing/AMQBody.cpp \
  qpid/framing/AMQMethodBody.cpp \
  qpid/framing/AMQContentBody.cpp \
  qpid/framing/AMQFrame.cpp \
  qpid/framing/AMQHeaderBody.cpp \
  qpid/framing/AMQHeartbeatBody.cpp \
  qpid/framing/Array.cpp \
  qpid/framing/BodyHandler.cpp \
  qpid/framing/Buffer.cpp \
  qpid/framing/Endian.cpp \
  qpid/framing/FieldTable.cpp \
  qpid/framing/FieldValue.cpp \
  qpid/framing/FrameSet.cpp \
  qpid/framing/FrameDecoder.cpp \
  qpid/framing/ProtocolInitiation.cpp \
  qpid/framing/ProtocolVersion.cpp \
  qpid/framing/SendContent.cpp \
  qpid/framing/SequenceNumber.cpp \
  qpid/framing/SequenceNumberSet.cpp \
  qpid/framing/SequenceSet.cpp \
  qpid/framing/Proxy.cpp \
  qpid/framing/Uuid.cpp \
  qpid/framing/AMQP_HighestVersion.h \
  qpid/framing/TransferContent.cpp \
  qpid/log/Logger.cpp \
  qpid/log/Options.cpp \
  qpid/log/OstreamOutput.cpp \
  qpid/log/Selector.cpp \
  qpid/log/Statement.cpp \
  qpid/management/Manageable.cpp \
  qpid/management/ManagementObject.cpp \
  qpid/sys/AggregateOutput.cpp \
  qpid/sys/AsynchIOHandler.cpp \
  qpid/sys/Dispatcher.cpp \
  qpid/sys/DispatchHandle.cpp \
  qpid/sys/LatencyMetric.cpp \
  qpid/sys/Runnable.cpp \
  qpid/sys/Shlib.cpp \
  qpid/sys/Timer.cpp

if HAVE_SASL
libqpidcommon_la_SOURCES += qpid/sys/cyrus/CyrusSecurityLayer.h
libqpidcommon_la_SOURCES += qpid/sys/cyrus/CyrusSecurityLayer.cpp
libqpidcommon_la_LIBADD += -lsasl2
endif

libqpidbroker_la_LIBADD = libqpidcommon.la -luuid

libqpidbroker_la_SOURCES = \
  $(mgen_broker_cpp) \
  $(posix_broker_src) \
  qpid/amqp_0_10/Connection.h \
  qpid/amqp_0_10/Connection.cpp \
  qpid/broker/Broker.cpp \
  qpid/broker/BrokerSingleton.cpp \
  qpid/broker/Exchange.cpp \
  qpid/broker/ExpiryPolicy.cpp \
  qpid/broker/Queue.cpp \
  qpid/broker/QueueCleaner.cpp \
  qpid/broker/QueueListeners.cpp \
  qpid/broker/PersistableMessage.cpp \
  qpid/broker/Bridge.cpp \
  qpid/broker/Connection.cpp \
  qpid/broker/ConnectionHandler.cpp \
  qpid/broker/ConnectionFactory.cpp \
  qpid/broker/Daemon.cpp \
  qpid/broker/DeliverableMessage.cpp \
  qpid/broker/DeliveryRecord.cpp \
  qpid/broker/DirectExchange.cpp \
  qpid/broker/DtxAck.cpp \
  qpid/broker/DtxBuffer.cpp \
  qpid/broker/DtxManager.cpp \
  qpid/broker/DtxTimeout.cpp \
  qpid/broker/DtxWorkRecord.cpp \
  qpid/broker/ExchangeRegistry.cpp \
  qpid/broker/FanOutExchange.cpp \
  qpid/broker/HeadersExchange.cpp \
  qpid/broker/IncompleteMessageList.cpp \
  qpid/broker/Link.cpp \
  qpid/broker/LinkRegistry.cpp \
  qpid/broker/Message.cpp \
  qpid/broker/MessageAdapter.cpp \
  qpid/broker/MessageBuilder.cpp \
  qpid/broker/MessageStoreModule.cpp \
  qpid/broker/NameGenerator.cpp \
  qpid/broker/NullMessageStore.cpp \
  qpid/broker/QueueBindings.cpp \
  qpid/broker/QueueEvents.cpp \
  qpid/broker/QueuePolicy.cpp \
  qpid/broker/QueueRegistry.cpp \
  qpid/broker/RateTracker.cpp \
  qpid/broker/RecoveryManagerImpl.cpp \
  qpid/broker/RecoveredEnqueue.cpp \
  qpid/broker/RecoveredDequeue.cpp \
  qpid/broker/RetryList.cpp \
  qpid/broker/SaslAuthenticator.cpp \
  qpid/broker/SecureConnection.cpp \
  qpid/broker/SecureConnectionFactory.cpp \
  qpid/broker/SemanticState.h \
  qpid/broker/SemanticState.cpp \
  qpid/broker/SessionAdapter.cpp \
  qpid/broker/SessionState.h \
  qpid/broker/SessionState.cpp \
  qpid/broker/SessionManager.h \
  qpid/broker/SessionManager.cpp \
  qpid/broker/SessionContext.h \
  qpid/broker/SessionHandler.h \
  qpid/broker/SessionHandler.cpp \
  qpid/broker/SignalHandler.h \
  qpid/broker/SignalHandler.cpp \
  qpid/broker/System.cpp \
  qpid/broker/Timer.cpp \
  qpid/broker/TopicExchange.cpp \
  qpid/broker/TxAccept.cpp \
  qpid/broker/TxBuffer.cpp \
  qpid/broker/TxPublish.cpp \
  qpid/broker/Vhost.cpp \
  qpid/management/ManagementBroker.cpp \
  qpid/management/ManagementExchange.cpp \
  qpid/sys/TCPIOPlugin.cpp


libqpidclient_la_LIBADD = libqpidcommon.la  -luuid

libqpidclient_la_SOURCES =			\
  $(rgen_client_srcs)				\
  qpid/client/Bounds.cpp			\
  qpid/client/Connection.cpp			\
  qpid/client/ConnectionHandler.cpp		\
  qpid/client/ConnectionImpl.cpp                \
  qpid/client/ConnectionSettings.cpp		\
  qpid/client/Connector.cpp	                \
  qpid/client/Demux.cpp				\
  qpid/client/Dispatcher.cpp			\
  qpid/client/FailoverManager.cpp            \
  qpid/client/FailoverListener.h		\
  qpid/client/FailoverListener.cpp		\
  qpid/client/Future.cpp			\
  qpid/client/FutureCompletion.cpp		\
  qpid/client/FutureResult.cpp			\
  qpid/client/HandlePrivate.h			\
  qpid/client/LoadPlugins.cpp			\
  qpid/client/LocalQueue.cpp			\
  qpid/client/Message.cpp			\
  qpid/client/MessageListener.cpp		\
  qpid/client/MessageReplayTracker.cpp		\
  qpid/client/QueueOptions.cpp			\
  qpid/client/Results.cpp			\
  qpid/client/SaslFactory.cpp			\
  qpid/client/SessionBase_0_10.cpp		\
  qpid/client/SessionBase_0_10.h		\
  qpid/client/SessionBase_0_10Access.h		\
  qpid/client/ConnectionAccess.h		\
  qpid/client/SessionImpl.cpp			\
  qpid/client/StateManager.cpp			\
  qpid/client/Subscription.cpp			\
  qpid/client/SubscriptionImpl.cpp		\
  qpid/client/SubscriptionManager.cpp

nobase_include_HEADERS = \
  $(platform_hdr) \
  $(module_hdr) \
  qpid/amqp_0_10/apply.h \
  qpid/assert.h \
  qpid/Address.h \
  qpid/DataDir.h \
  qpid/Exception.h \
  qpid/sys/ExceptionHolder.h \
  qpid/amqp_0_10/Exception.h \
  qpid/Modules.h \
  qpid/Msg.h \
  qpid/Options.h \
  qpid/Plugin.h \
  qpid/ptr_map.h \
  qpid/RangeSet.h \
  qpid/RefCounted.h \
  qpid/SessionId.h \
  qpid/SessionState.h \
  qpid/SharedObject.h \
  qpid/StringUtils.h \
  qpid/Url.h \
  qpid/InlineVector.h \
  qpid/InlineAllocator.h \
  qpid/memory.h \
  qpid/shared_ptr.h \
  qpid/Version.h \
  qpid/broker/Broker.h \
  qpid/broker/AclModule.h \
  qpid/broker/SessionAdapter.h \
  qpid/broker/Exchange.h \
  qpid/broker/Queue.h \
  qpid/broker/QueueListeners.h \
  qpid/broker/QueueCleaner.h \
  qpid/broker/BrokerImportExport.h \
  qpid/broker/BrokerSingleton.h \
  qpid/broker/Bridge.h \
  qpid/broker/Connection.h \
  qpid/broker/ConnectionState.h \
  qpid/broker/ConnectionFactory.h \
  qpid/broker/ConnectionHandler.h \
  qpid/broker/ConnectionToken.h \
  qpid/broker/OwnershipToken.h \
  qpid/broker/Consumer.h \
  qpid/broker/Daemon.h \
  qpid/broker/Deliverable.h \
  qpid/broker/DeliverableMessage.h \
  qpid/broker/DeliveryAdapter.h \
  qpid/broker/DeliveryId.h \
  qpid/broker/DeliveryRecord.h \
  qpid/broker/DirectExchange.h \
  qpid/broker/DtxAck.h \
  qpid/broker/DtxBuffer.h \
  qpid/broker/DtxManager.h \
  qpid/broker/DtxTimeout.h \
  qpid/broker/DtxWorkRecord.h \
  qpid/broker/ExchangeRegistry.h \
  qpid/broker/ExpiryPolicy.h \
  qpid/broker/FanOutExchange.h \
  qpid/broker/HandlerImpl.h \
  qpid/broker/HeadersExchange.h \
  qpid/broker/IncompleteMessageList.h \
  qpid/broker/Link.h \
  qpid/broker/LinkRegistry.h \
  qpid/broker/Message.h \
  qpid/broker/MessageAdapter.h \
  qpid/broker/MessageBuilder.h \
  qpid/broker/MessageStore.h \
  qpid/broker/MessageStoreModule.h \
  qpid/broker/NameGenerator.h \
  qpid/broker/NullMessageStore.h \
  qpid/broker/Persistable.h \
  qpid/broker/PersistableConfig.h \
  qpid/broker/PersistableExchange.h \
  qpid/broker/PersistableMessage.h \
  qpid/broker/PersistableQueue.h \
  qpid/broker/QueueBindings.h \
  qpid/broker/QueueEvents.h \
  qpid/broker/QueuedMessage.h \
  qpid/broker/QueuePolicy.h \
  qpid/broker/QueueRegistry.h \
  qpid/broker/RateFlowcontrol.h \
  qpid/broker/RateTracker.h \
  qpid/broker/RecoverableConfig.h \
  qpid/broker/RecoverableExchange.h \
  qpid/broker/RecoverableMessage.h \
  qpid/broker/RecoverableQueue.h \
  qpid/broker/RecoverableTransaction.h \
  qpid/broker/RecoveredDequeue.h \
  qpid/broker/RecoveredEnqueue.h \
  qpid/broker/RecoveryManager.h \
  qpid/broker/RecoveryManagerImpl.h \
  qpid/broker/RetryList.h \
  qpid/broker/SaslAuthenticator.h \
  qpid/broker/SecureConnection.h \
  qpid/broker/SecureConnectionFactory.h \
  qpid/broker/SessionAdapter.h \
  qpid/broker/SessionManager.h \
  qpid/broker/System.h \
  qpid/broker/Timer.h \
  qpid/broker/TopicExchange.h \
  qpid/broker/TransactionalStore.h \
  qpid/broker/TxAccept.h \
  qpid/broker/TxBuffer.h \
  qpid/broker/TxOp.h \
  qpid/broker/TxOpVisitor.h \
  qpid/broker/TxPublish.h \
  qpid/broker/Vhost.h \
  qpid/client/AckMode.h \
  qpid/client/Bounds.h \
  qpid/client/ChainableFrameHandler.h \
  qpid/client/ClientImportExport.h \
  qpid/client/Completion.h \
  qpid/client/Connection.h \
  qpid/client/ConnectionHandler.h \
  qpid/client/ConnectionImpl.h \
  qpid/client/ConnectionSettings.h \
  qpid/client/Connector.h \
  qpid/client/Demux.h \
  qpid/client/Dispatcher.h \
  qpid/client/Execution.h \
  qpid/client/FailoverManager.h \
  qpid/client/Subscription.h \
  qpid/client/SubscriptionImpl.h \
  qpid/client/SubscriptionSettings.h \
  qpid/client/FlowControl.h \
  qpid/client/Future.h \
  qpid/client/FutureCompletion.h \
  qpid/client/FutureResult.h \
  qpid/client/Handle.h \
  qpid/client/LocalQueue.h \
  qpid/client/QueueOptions.h \
  qpid/client/Message.h \
  qpid/client/MessageListener.h \
  qpid/client/MessageReplayTracker.h \
  qpid/client/Results.h \
  qpid/client/Sasl.h \
  qpid/client/SaslFactory.h \
  qpid/client/SessionBase_0_10.h \
  qpid/client/Session.h \
  qpid/client/SessionImpl.h \
  qpid/client/AsyncSession.h \
  qpid/client/StateManager.h \
  qpid/client/SubscriptionManager.h \
  qpid/client/TypedResult.h \
  qpid/framing/AMQBody.h \
  qpid/framing/AMQCommandControlBody.h \
  qpid/framing/AMQContentBody.h \
  qpid/framing/AMQDataBlock.h \
  qpid/framing/AMQFrame.h \
  qpid/framing/AMQHeaderBody.h \
  qpid/framing/AMQHeartbeatBody.h \
  qpid/framing/AMQMethodBody.h \
  qpid/framing/AMQP_HighestVersion.h \
  qpid/framing/AccumulatedAck.h \
  qpid/framing/Array.h \
  qpid/framing/BodyHandler.h \
  qpid/framing/BodyFactory.h \
  qpid/framing/MethodBodyFactory.h \
  qpid/framing/Buffer.h \
  qpid/framing/ChannelHandler.h \
  qpid/framing/Endian.h \
  qpid/framing/FieldTable.h \
  qpid/framing/FieldValue.h \
  qpid/framing/FrameDefaultVisitor.h \
  qpid/framing/FrameDecoder.h \
  qpid/framing/FrameHandler.h \
  qpid/framing/FrameSet.h \
  qpid/framing/Handler.h \
  qpid/framing/HeaderProperties.h \
  qpid/framing/Invoker.h \
  qpid/framing/InputHandler.h \
  qpid/framing/InitiationHandler.h \
  qpid/framing/MethodContent.h \
  qpid/framing/ModelMethod.h \
  qpid/framing/OutputHandler.h \
  qpid/framing/ProtocolInitiation.h \
  qpid/framing/ProtocolVersion.h \
  qpid/framing/Proxy.h \
  qpid/framing/SendContent.h \
  qpid/framing/SequenceNumber.h \
  qpid/framing/SequenceSet.h \
  qpid/framing/SequenceNumberSet.h \
  qpid/framing/StructHelper.h \
  qpid/framing/TransferContent.h \
  qpid/framing/TypeFilter.h \
  qpid/framing/Uuid.h \
  qpid/framing/Visitor.h \
  qpid/framing/amqp_framing.h \
  qpid/framing/amqp_types.h \
  qpid/framing/amqp_types_full.h \
  qpid/framing/frame_functors.h \
  qpid/framing/variant.h \
  qpid/log/Helpers.h \
  qpid/log/Options.h \
  qpid/log/Logger.h \
  qpid/log/OstreamOutput.h \
  qpid/log/Selector.h \
  qpid/log/SinkOptions.h \
  qpid/log/Statement.h \
  qpid/management/Args.h \
  qpid/management/IdAllocator.h \
  qpid/management/Manageable.h \
  qpid/management/ManagementBroker.h \
  qpid/management/ManagementEvent.h \
  qpid/management/ManagementExchange.h \
  qpid/management/ManagementObject.h \
  qpid/sys/alloca.h \
  qpid/sys/AggregateOutput.h \
  qpid/sys/AsynchIO.h \
  qpid/sys/AsynchIOHandler.h \
  qpid/sys/AtomicCount.h \
  qpid/sys/AtomicValue.h \
  qpid/sys/AtomicValue_gcc.h \
  qpid/sys/AtomicValue_mutex.h \
  qpid/sys/BlockingQueue.h \
  qpid/sys/Codec.h \
  qpid/sys/CopyOnWriteArray.h \
  qpid/sys/Condition.h \
  qpid/sys/ConnectionCodec.h \
  qpid/sys/ConnectionInputHandler.h \
  qpid/sys/ConnectionInputHandlerFactory.h \
  qpid/sys/ConnectionOutputHandler.h \
  qpid/sys/ConnectionOutputHandlerPtr.h \
  qpid/sys/DeletionManager.h \
  qpid/sys/Dispatcher.h \
  qpid/sys/DispatchHandle.h \
  qpid/sys/FileSysDir.h \
  qpid/sys/IntegerTypes.h \
  qpid/sys/IOHandle.h \
  qpid/sys/LatencyMetric.h \
  qpid/sys/LockFile.h \
  qpid/sys/LockPtr.h \
  qpid/sys/Monitor.h \
  qpid/sys/Mutex.h \
  qpid/sys/OutputControl.h \
  qpid/sys/OutputTask.h \
  qpid/sys/PollableCondition.h \
  qpid/sys/PollableQueue.h \
  qpid/sys/Poller.h \
  qpid/sys/ProtocolFactory.h \
  qpid/sys/Runnable.h \
  qpid/sys/Fork.h \
  qpid/sys/ScopedIncrement.h \
  qpid/sys/SecurityLayer.h \
  qpid/sys/Semaphore.h \
  qpid/sys/SystemInfo.h \
  qpid/sys/Shlib.h \
  qpid/sys/ShutdownHandler.h \
  qpid/sys/Socket.h \
  qpid/sys/StateMonitor.h \
  qpid/sys/StrError.h \
  qpid/sys/Waitable.h \
  qpid/sys/Thread.h \
  qpid/sys/Time.h \
  qpid/sys/Timer.h \
  qpid/sys/TimeoutHandler.h \
  qpid/sys/uuid.h \
  qpid/CommonImportExport.h

# Force build of qpidd during dist phase so help2man will work.
dist-hook: $(BUILT_SOURCES)
	$(MAKE) qpidd

# Create the default data directory
install-data-local:
	$(mkinstalldirs) $(DESTDIR)/$(localstatedir)/lib/qpidd

