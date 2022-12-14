/*
 * Licensed to the Apache Software Foundation (ASF) under one or more
 * contributor license agreements.  See the NOTICE file distributed with
 * this work for additional information regarding copyright ownership.
 * The ASF licenses this file to You under the Apache License, Version 2.0
 * (the "License"); you may not use this file except in compliance with
 * the License.  You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
#include "SendResult.h"
#include <sstream>
#include "UtilAll.h"
#include "VirtualEnvUtil.h"

namespace rocketmq {
//<!***************************************************************************
SendResult::SendResult() : m_sendStatus(SEND_OK), m_queueOffset(0) {}

SendResult::SendResult(const SendStatus& sendStatus,
                       const std::string& msgId,
                       const std::string& offsetMsgId,
                       const MQMessageQueue& messageQueue,
                       int64 queueOffset)
    : m_sendStatus(sendStatus),
      m_msgId(msgId),
      m_offsetMsgId(offsetMsgId),
      m_messageQueue(messageQueue),
      m_queueOffset(queueOffset) {}

SendResult::SendResult(const SendStatus& sendStatus,
                       const std::string& msgId,
                       const std::string& offsetMsgId,
                       const MQMessageQueue& messageQueue,
                       int64 queueOffset,
                       const string& regionId,
                       const bool traceOn)
    : m_sendStatus(sendStatus),
      m_msgId(msgId),
      m_offsetMsgId(offsetMsgId),
      m_messageQueue(messageQueue),
      m_queueOffset(queueOffset),
      m_regionId(regionId),
      m_traceOn(traceOn) {}

SendResult::SendResult(const SendResult& other) {
  m_sendStatus = other.m_sendStatus;
  m_msgId = other.m_msgId;
  m_offsetMsgId = other.m_offsetMsgId;
  m_messageQueue = other.m_messageQueue;
  m_queueOffset = other.m_queueOffset;
  m_regionId = other.m_regionId;
  m_traceOn = other.m_traceOn;
}

SendResult& SendResult::operator=(const SendResult& other) {
  if (this != &other) {
    m_sendStatus = other.m_sendStatus;
    m_msgId = other.m_msgId;
    m_offsetMsgId = other.m_offsetMsgId;
    m_messageQueue = other.m_messageQueue;
    m_queueOffset = other.m_queueOffset;
    m_regionId = other.m_regionId;
    m_traceOn = other.m_traceOn;
  }
  return *this;
}

SendResult::~SendResult() {}

const string& SendResult::getMsgId() const {
  return m_msgId;
}

const string& SendResult::getOffsetMsgId() const {
  return m_offsetMsgId;
}

const string& SendResult::getRegionId() const {
  return m_regionId;
}
void SendResult::setRegionId(const string& regionId) {
  m_regionId = regionId;
}
SendStatus SendResult::getSendStatus() const {
  return m_sendStatus;
}

MQMessageQueue SendResult::getMessageQueue() const {
  return m_messageQueue;
}

int64 SendResult::getQueueOffset() const {
  return m_queueOffset;
}

bool SendResult::getTraceOn() const {
  return m_traceOn;
}

std::string SendResult::toString() const {
  stringstream ss;
  ss << "SendResult: ";
  ss << "sendStatus:" << m_sendStatus;
  ss << ",msgId:" << m_msgId;
  ss << ",offsetMsgId:" << m_offsetMsgId;
  ss << ",queueOffset:" << m_queueOffset;
  ss << ",transactionId:" << m_transactionId;
  ss << ",messageQueue:" << m_messageQueue.toString();
  ss << ",regionId:" << m_regionId;
  ss << ",traceOn:" << m_traceOn;
  return ss.str();
}

//<!************************************************************************
}  // namespace rocketmq
