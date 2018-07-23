/* Copyright (c) 2018 Yaroslav Stanislavyk <stl.ros@outlook.com> */

#pragma once

#include "DBConnection.hpp"

enum class ConnectionType { MYSQL, SQLITE };

class IDBConnection4 {
 public:
  virtual ~IDBConnection4() = default;

  virtual ConnectionType GetConnectionType() const = 0;

  virtual int Query() const = 0;
};

class MySqlDBConnection4 : public IDBConnection4 {
 public:
  explicit MySqlDBConnection4(std::string server_version, int protocol_version)
      : m_info{std::move(server_version), protocol_version} {};

  ConnectionType GetConnectionType() const override;

  int Query() const override;
  Info AdvancedQuery() const;

 private:
  Info m_info;
};

class SqLiteDBConnection4 : public IDBConnection4 {
 public:
  SqLiteDBConnection4() : m_protocol_version(0){};
  explicit SqLiteDBConnection4(int protocol_version)
      : m_protocol_version(protocol_version){};

  ConnectionType GetConnectionType() const override;

  int Query() const override;

 private:
  int m_protocol_version;
};