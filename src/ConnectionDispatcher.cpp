/* Copyright (c) 2018 Yaroslav Stanislavyk <stl.ros@outlook.com> */

#include "ConnectionDispatcher.hpp"

namespace DoubleDispatch {

IConnectionDispatcher::~IConnectionDispatcher() = default;

void MySqlConnectionDispatcher::Dispatch(DoubleDispatch::MySqlDBConnection& connection) {
  m_mysql_connection = &connection;
}

void MySqlConnectionDispatcher::Dispatch(DoubleDispatch::SqLiteDBConnection&) {
  m_mysql_connection = nullptr;
}

void SqLiteConnectionDispatcher::Dispatch(DoubleDispatch::MySqlDBConnection&) {
  m_sqlite_connection = nullptr;
}

void SqLiteConnectionDispatcher::Dispatch(DoubleDispatch::SqLiteDBConnection& connection) {
  m_sqlite_connection = &connection;
}

DoubleDispatch::MySqlDBConnection* MySqlConnectionDispatcher::connection() const {
  return m_mysql_connection;
}

DoubleDispatch::SqLiteDBConnection* SqLiteConnectionDispatcher::connection() const {
  return m_sqlite_connection;
}

}  // namespace DoubleDispatch
