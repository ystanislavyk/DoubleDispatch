/* Copyright (c) 2018 Yaroslav Stanislavyk <stl.ros@outlook.com> */

#include "ConnectionDispatcher.hpp"

void MySqlConnectionDispatcher::Dispatch(MySqlDBConnection2& connection) {
    m_mysql_connection = &connection;
}

void MySqlConnectionDispatcher::Dispatch(SqLiteDBConnection2& connection) {
    m_mysql_connection = nullptr;
}

void SqLiteConnectionDispatcher::Dispatch(MySqlDBConnection2& connection) {
    m_sqlite_connection = nullptr;
}

void SqLiteConnectionDispatcher::Dispatch(SqLiteDBConnection2& connection) {
    m_sqlite_connection = &connection;
}

MySqlDBConnection2* MySqlConnectionDispatcher::connection() const {
    return m_mysql_connection;
}

SqLiteDBConnection2* SqLiteConnectionDispatcher::connection() const {
    return m_sqlite_connection;
}