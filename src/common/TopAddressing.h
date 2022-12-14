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
#ifndef __TOPADDRESSING_H__
#define __TOPADDRESSING_H__

#include <boost/thread/thread.hpp>
#include <list>
#include <map>
#include <string>
#include "Logging.h"
#include "UtilAll.h"

namespace rocketmq {
class TopAddressing {
 public:
  TopAddressing(const std::string& unitName);
  virtual ~TopAddressing();

 public:
  virtual string fetchNSAddr(const string& NSDomain);

 private:
  string clearNewLine(const string& str);
  void updateNameServerAddressList(const string& adds);
  int IsIPAddr(const char* sValue);

 private:
  boost::mutex m_addrLock;
  list<string> m_addrs;
  string m_unitName;
};
}  // namespace rocketmq
#endif
