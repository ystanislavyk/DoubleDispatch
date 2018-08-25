/* Copyright (c) 2018 Yaroslav Stanislavyk <stl.ros@outlook.com> */

#include "DBConnection2.hpp"
#include "ConnectionDispatcher.hpp"

IDBConnection2::~IDBConnection2() = default;

void MySqlDBConnection2::Dispatch(
    IConnectionDispatcher& connection_dispatcher) {
  connection_dispatcher.Dispatch(*this);
}

int MySqlDBConnection2::Query() const { return m_info.protocol_version; }

Info MySqlDBConnection2::AdvancedQuery() const { return m_info; }

void SqLiteDBConnection2::Dispatch(
    IConnectionDispatcher& connection_dispatcher) {
  connection_dispatcher.Dispatch(*this);
}

int SqLiteDBConnection2::Query() const { return m_protocol_version; }
