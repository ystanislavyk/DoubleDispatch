/* Copyright (c) 2018 Yaroslav Stanislavyk <stl.ros@outlook.com> */

#pragma once

#include <string>
#include <utility>

namespace Origin {

struct Info {
  Info();
  explicit Info(std::string server_ver, int protocol_ver);

  std::string server_version;
  int protocol_version;
};

class IDBConnection {
 public:
  virtual ~IDBConnection();

  virtual int Query() const = 0;
};

class MySqlDBConnection : public IDBConnection {
 public:
  explicit MySqlDBConnection(std::string server_version, int protocol_version);

  int Query() const override;
  Info AdvancedQuery() const;

 private:
  Info m_info;
};

}  // namespace Origin
