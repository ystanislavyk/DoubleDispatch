/* Copyright (c) 2018 Yaroslav Stanislavyk <stl.ros@outlook.com> */

#pragma once

#include <string>
#include <utility>

namespace Origin {

struct Info {
  Info() : server_version{""}, protocol_version(0) {}
  explicit Info(std::string server_ver, int protocol_ver)
      : server_version(std::move(server_ver)), protocol_version(protocol_ver) {}

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
  explicit MySqlDBConnection(std::string server_version, int protocol_version)
      : m_info{std::move(server_version), protocol_version} {}

  int Query() const override;
  Info AdvancedQuery() const;

 private:
  Info m_info;
};

}  // namespace Origin
