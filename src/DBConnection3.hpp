/* Copyright (c) 2018 Yaroslav Stanislavyk <stl.ros@outlook.com> */

#pragma once

#include "DBConnection.hpp"

enum class ConnectionType { MYSQL, SQLITE };

class IDBConnection3 {
 public:
  virtual ~IDBConnection3();

  virtual ConnectionType GetConnectionType() const = 0;

  virtual int Query() const = 0;
};

class MySqlDBConnection3 : public IDBConnection3 {
 public:
  explicit MySqlDBConnection3(std::string server_version, int protocol_version)
      : m_info{std::move(server_version), protocol_version} {}

  ConnectionType GetConnectionType() const override;

  int Query() const override;
  Info AdvancedQuery() const;

 private:
  Info m_info;
};

class SqLiteDBConnection3 : public IDBConnection3 {
 public:
  SqLiteDBConnection3() : m_protocol_version(0) {}
  explicit SqLiteDBConnection3(int protocol_version)
      : m_protocol_version(protocol_version) {}

  ConnectionType GetConnectionType() const override;

  int Query() const override;

 private:
  int m_protocol_version;
};
