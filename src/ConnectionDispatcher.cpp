#include "ConnectionDispatcher.hpp"

ConnectionDispatcher::~ConnectionDispatcher() {
    m_connection.release();
}

void ConnectionDispatcher::dispatchConnection(MySqlDBConnection2& connection) {
    m_connection.reset(&connection);
}

MySqlDBConnection2 &ConnectionDispatcher::getMySqlConnection() const {
    return *m_connection;
}