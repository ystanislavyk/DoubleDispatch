#pragma once

#include <memory>

#include "DBConnection2.hpp"

class ConnectionDispatcher {
public:
    ConnectionDispatcher() : m_mysql_connection(nullptr), m_sqlite_connection(nullptr) {};

    void dispatch(MySqlDBConnection2& connection);
    void dispatch(SqLiteDBConnection2& connection);

    MySqlDBConnection2* getMySqlConnection() const;
    SqLiteDBConnection2* getSqLiteConnection() const;

private:
    MySqlDBConnection2* m_mysql_connection;
    SqLiteDBConnection2* m_sqlite_connection;
};