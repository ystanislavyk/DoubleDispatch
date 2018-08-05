/* Copyright (c) 2018 Yaroslav Stanislavyk <stl.ros@outlook.com> */

#pragma once

#include "DBConnection.hpp"

class IDBConnection5 {
 public:
  virtual ~IDBConnection5() = default;

  virtual int Query() const = 0;
};

namespace MySqlConnection {

class MySqlDBConnection5 : public IDBConnection5 {
 public:
  explicit MySqlDBConnection5(std::string server_version, int protocol_version)
      : m_info{std::move(server_version), protocol_version} {};

  int Query() const override;
  Info AdvancedQuery() const;

 private:
  Info m_info;
};

}  // namespace MySqlConnection

namespace SqLiteConnection {

class SqLiteDBConnection5 : public IDBConnection5 {
 public:
  SqLiteDBConnection5() : m_protocol_version(0){};
  explicit SqLiteDBConnection5(int protocol_version)
      : m_protocol_version(protocol_version){};

  int Query() const override;

 private:
  int m_protocol_version;
};

}  // namespace SqLiteConnection
