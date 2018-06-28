#include "ConnectionDispatcher.hpp"

void ConnectionDispatcher::dispatch(MySqlDBConnection2& connection) {
    m_mysql_connection = &connection;
}

void ConnectionDispatcher::dispatch(SqLiteDBConnection2& connection) {
    m_sqlite_connection = &connection;
}

MySqlDBConnection2* ConnectionDispatcher::getMySqlConnection() const {
    return m_mysql_connection;
}

SqLiteDBConnection2 *ConnectionDispatcher::getSqLiteConnection() const {
    return m_sqlite_connection;
}