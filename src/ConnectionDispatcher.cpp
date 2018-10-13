/* Copyright (c) 2018 Yaroslav Stanislavyk <stl.ros@outlook.com> */

#include "ConnectionDispatcher.hpp"

namespace DoubleDispatch {

IConnectionDispatcher::~IConnectionDispatcher() = default;

MySqlConnectionDispatcher::MySqlConnectionDispatcher()
    : m_mysql_connection(nullptr) {}

void MySqlConnectionDispatcher::Dispatch(MySqlDBConnection& connection) {
  m_mysql_connection = &connection;
}

void MySqlConnectionDispatcher::Dispatch(SqLiteDBConnection&) {
  m_mysql_connection = nullptr;
}

MySqlDBConnection* MySqlConnectionDispatcher::connection() const {
  return m_mysql_connection;
}

SqLiteConnectionDispatcher::SqLiteConnectionDispatcher()
    : m_sqlite_connection(nullptr) {}

void SqLiteConnectionDispatcher::Dispatch(MySqlDBConnection&) {
  m_sqlite_connection = nullptr;
}

void SqLiteConnectionDispatcher::Dispatch(SqLiteDBConnection& connection) {
  m_sqlite_connection = &connection;
}

SqLiteDBConnection* SqLiteConnectionDispatcher::connection() const {
  return m_sqlite_connection;
}

}  // namespace DoubleDispatch
