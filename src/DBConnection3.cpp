/* Copyright (c) 2018 Yaroslav Stanislavyk <stl.ros@outlook.com> */

#include "DBConnection3.hpp"

namespace TypeStoring {

IDBConnection::~IDBConnection() = default;

ConnectionType MySqlDBConnection::GetConnectionType() const {
  return ConnectionType::MYSQL;
}

int MySqlDBConnection::Query() const { return m_info.protocol_version; }

Origin::Info MySqlDBConnection::AdvancedQuery() const { return m_info; }

int SqLiteDBConnection::Query() const { return m_protocol_version; }

ConnectionType SqLiteDBConnection::GetConnectionType() const {
  return ConnectionType::SQLITE;
}

}  // namespace TypeStoring
