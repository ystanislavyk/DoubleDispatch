/* Copyright (c) 2018 Yaroslav Stanislavyk <stl.ros@outlook.com> */

#include "TypeStoring.hpp"

namespace TypeStoring {

IDBConnection::~IDBConnection() = default;

MySqlDBConnection::MySqlDBConnection(std::string server_version,
                                     int protocol_version)
    : m_info{std::move(server_version), protocol_version} {}

ConnectionType MySqlDBConnection::GetConnectionType() const {
  return ConnectionType::MYSQL;
}

int MySqlDBConnection::Query() const { return m_info.protocol_version; }

Assertion::Info MySqlDBConnection::AdvancedQuery() const { return m_info; }

SqLiteDBConnection::SqLiteDBConnection() : m_protocol_version(0) {}

SqLiteDBConnection::SqLiteDBConnection(int protocol_version)
    : m_protocol_version(protocol_version) {}

ConnectionType SqLiteDBConnection::GetConnectionType() const {
  return ConnectionType::SQLITE;
}

int SqLiteDBConnection::Query() const { return m_protocol_version; }

}  // namespace TypeStoring
