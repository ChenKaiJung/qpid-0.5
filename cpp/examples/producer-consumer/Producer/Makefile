#
# Makefile for Billing Agent
#
# $Id: Makefile 125 2009-03-01 16:37:11Z cdsheen $

OSNAME=centos5

DEFINES=-D_PRODUCTION
DEFINES+=

TARGET=producer

CC=g++

RM=rm

revision := $(shell svnversion|sed 's/[\:MS].*//')

CFLAGS=-Wall -g -I $(DEFINES) -DSVN_REVISION=$(revision) -D_LARGEFILE_SOURCE -D_FILE_OFFSET_BITS=64

LDFLAGS=-lqpidclient.a -lqpidcommon.a -luuid -lboost_program_options -lsasl2  -lsasl2 -lpthread -ldl -lrt
OBJS=producer.o



all:	$(TARGET)

producer:
	$(CC) $(INCLUDE) $(CFLAGS) -c producer.cpp
	$(CC) -o $(TARGET) $(OBJS) $(LDFLAGS)


clean:
	$(RM) *.o *~ $(TARGET)
