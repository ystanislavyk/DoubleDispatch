/* Copyright (c) 2018 Yaroslav Stanislavyk <stl.ros@outlook.com> */

#include "DBConnection2.hpp"
#include "ConnectionDispatcher.hpp"

namespace DoubleDispatch {

IDBConnection::~IDBConnection() = default;

void MySqlDBConnection::Dispatch(
    IConnectionDispatcher& connection_dispatcher) {
  connection_dispatcher.Dispatch(*this);
}

int MySqlDBConnection::Query() const { return m_info.protocol_version; }

Origin::Info MySqlDBConnection::AdvancedQuery() const { return m_info; }

void SqLiteDBConnection::Dispatch(
    IConnectionDispatcher& connection_dispatcher) {
  connection_dispatcher.Dispatch(*this);
}

int SqLiteDBConnection::Query() const { return m_protocol_version; }

}  // namespace DoubleDispatch
