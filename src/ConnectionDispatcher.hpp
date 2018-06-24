#pragma once

#include "DBConnection2.hpp"

class ConnectionDispatcher {
public:
    ConnectionDispatcher() = default;
    ~ConnectionDispatcher();

    void dispatchConnection(const MySqlDBConnection2& connection) const;
    const MySqlDBConnection2& getMySqlConnection() const;

private:
    mutable std::unique_ptr<const MySqlDBConnection2> m_connection;
};