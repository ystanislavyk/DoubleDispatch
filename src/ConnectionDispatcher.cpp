#include "ConnectionDispatcher.hpp"

void MySqlConnectionDispatcher::dispatch(MySqlDBConnection2& connection) {
    m_mysql_connection = &connection;
}

void MySqlConnectionDispatcher::dispatch(SqLiteDBConnection2& connection) {
    m_mysql_connection = nullptr;
}

void SqLiteConnectionDispatcher::dispatch(MySqlDBConnection2& connection) {
    m_sqlite_connection = nullptr;
}

void SqLiteConnectionDispatcher::dispatch(SqLiteDBConnection2& connection) {
    m_sqlite_connection = &connection;
}

MySqlDBConnection2* MySqlConnectionDispatcher::connection() const {
    return m_mysql_connection;
}

SqLiteDBConnection2 *SqLiteConnectionDispatcher::connection() const {
    return m_sqlite_connection;
}