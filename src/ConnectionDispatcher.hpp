#pragma once

#include <memory>

#include "DBConnection2.hpp"

class ConnectionDispatcher {
public:
    ConnectionDispatcher() = default;
    ~ConnectionDispatcher();

    void dispatchConnection(MySqlDBConnection2& connection);
    MySqlDBConnection2& getMySqlConnection() const;

private:
    std::unique_ptr<MySqlDBConnection2> m_connection;
};
