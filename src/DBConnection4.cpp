/* Copyright (c) 2018 Yaroslav Stanislavyk <stl.ros@outlook.com> */

#include "DBConnection4.hpp"

IDBConnection4::~IDBConnection4() = default;

ConnectionType MySqlDBConnection4::GetConnectionType() const {
  return ConnectionType::MYSQL;
}

int MySqlDBConnection4::Query() const { return m_info.protocol_version; }

Info MySqlDBConnection4::AdvancedQuery() const { return m_info; }

int SqLiteDBConnection4::Query() const { return m_protocol_version; }

ConnectionType SqLiteDBConnection4::GetConnectionType() const {
  return ConnectionType::SQLITE;
}
