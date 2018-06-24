#include "ConnectionDispatcher.hpp"

ConnectionDispatcher::~ConnectionDispatcher() {
    m_connection.release();
}

void ConnectionDispatcher::dispatchConnection(const MySqlDBConnection2& connection) const {
    m_connection.reset(&connection);
}

const MySqlDBConnection2 &ConnectionDispatcher::getMySqlConnection() const {
    return *m_connection;
}