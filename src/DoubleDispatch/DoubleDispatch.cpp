/* Copyright (c) 2018 Yaroslav Stanislavyk <stl.ros@outlook.com> */

#include "DoubleDispatch.hpp"
#include "ConnectionDispatcher.hpp"

namespace DoubleDispatch {

IDBConnection::~IDBConnection() = default;

MySqlDBConnection::MySqlDBConnection() = default;

MySqlDBConnection::MySqlDBConnection(std::string server_version,
                                     int protocol_version)
    : m_info{std::move(server_version), protocol_version} {}

void MySqlDBConnection::Dispatch(IConnectionDispatcher& connection_dispatcher) {
  connection_dispatcher.Dispatch(*this);
}

int MySqlDBConnection::Query() const { return m_info.protocol_version; }

Assertion::Info MySqlDBConnection::AdvancedQuery() const { return m_info; }

SqLiteDBConnection::SqLiteDBConnection() : m_protocol_version(0) {}

SqLiteDBConnection::SqLiteDBConnection(int protocol_version)
    : m_protocol_version(protocol_version) {}

void SqLiteDBConnection::Dispatch(
    IConnectionDispatcher& connection_dispatcher) {
  connection_dispatcher.Dispatch(*this);
}

int SqLiteDBConnection::Query() const { return m_protocol_version; }

}  // namespace DoubleDispatch
