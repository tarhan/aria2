/* <!-- copyright */
/*
 * aria2 - The high speed download utility
 *
 * Copyright (C) 2006 Tatsuhiro Tsujikawa
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
 *
 * In addition, as a special exception, the copyright holders give
 * permission to link the code of portions of this program with the
 * OpenSSL library under certain conditions as described in each
 * individual source file, and distribute linked combinations
 * including the two.
 * You must obey the GNU General Public License in all respects
 * for all of the code used other than OpenSSL.  If you modify
 * file(s) with this exception, you may extend this exception to your
 * version of the file(s), but you are not obligated to do so.  If you
 * do not wish to do so, delete this exception statement from your
 * version.  If you delete this exception statement from all source
 * files in the program, then also delete it here.
 */
/* copyright --> */
#ifndef _D_DHT_NODE_H_
#define _D_DHT_NODE_H_

#include "common.h"
#include "SharedHandle.h"
#include "DHTConstants.h"
#include "TimeA2.h"
#include <string>

namespace aria2 {

class DHTNode {
private:
  unsigned char _id[DHT_ID_LENGTH];

  std::string _ipaddr;

  uint16_t _port;

  // in milli sec
  int32_t _rtt;

  uint32_t _condition;

  Time _lastContact;
public:
  DHTNode();
  
  /**
   * id must be 20 bytes length
   */
  DHTNode(const unsigned char* id);

  void generateID();

  const unsigned char* getID() const
  {
    return _id;
  }

  void updateRTT(int32_t millisec)
  {
    _rtt = millisec;
  }

  std::string getIPAddress() const
  {
    return _ipaddr;
  }

  void setIPAddress(const std::string& ipaddr)
  {
    _ipaddr = ipaddr;
  }

  void setID(const unsigned char* id);

  uint16_t getPort() const
  {
    return _port;
  }

  void setPort(uint16_t port)
  {
    _port = port;
  }

  bool isGood() const;

  bool isBad() const;

  bool isQuestionable() const;

  void updateLastContact();

  void markGood();

  void markBad();

  void timeout();

  bool operator==(const DHTNode& node) const;

  bool operator<(const DHTNode& node) const;

  std::string toString() const;
};

} // namespace aria2

#endif // _D_DHT_NODE_H_
