#include "ConnectionDispatcher.hpp"

void MySqlConnectionDispatcher::connect(MySqlDBConnection2& connection) {
    m_mysql_connection = &connection;
}

void MySqlConnectionDispatcher::connect(SqLiteDBConnection2& connection) {
    m_mysql_connection = nullptr;
}

void SqLiteConnectionDispatcher::connect(MySqlDBConnection2& connection) {
    m_sqlite_connection = nullptr;
}

void SqLiteConnectionDispatcher::connect(SqLiteDBConnection2& connection) {
    m_sqlite_connection = &connection;
}

MySqlDBConnection2* MySqlConnectionDispatcher::connection() const {
    return m_mysql_connection;
}

SqLiteDBConnection2 *SqLiteConnectionDispatcher::connection() const {
    return m_sqlite_connection;
}