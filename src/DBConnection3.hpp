/* Copyright (c) 2018 Yaroslav Stanislavyk <stl.ros@outlook.com> */

#pragma once

#include "DBConnection.hpp"

namespace TypeStoring {

enum class ConnectionType { MYSQL, SQLITE };

class IDBConnection {
 public:
  virtual ~IDBConnection();

  virtual ConnectionType GetConnectionType() const = 0;

  virtual int Query() const = 0;
};

class MySqlDBConnection : public IDBConnection {
 public:
  explicit MySqlDBConnection(std::string server_version, int protocol_version);

  ConnectionType GetConnectionType() const override;

  int Query() const override;
  Origin::Info AdvancedQuery() const;

 private:
  Origin::Info m_info;
};

class SqLiteDBConnection : public IDBConnection {
 public:
  SqLiteDBConnection();
  explicit SqLiteDBConnection(int protocol_version);

  ConnectionType GetConnectionType() const override;

  int Query() const override;

 private:
  int m_protocol_version;
};

}  // namespace TypeStoring
