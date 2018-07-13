/* Copyright (c) 2018 Yaroslav Stanislavyk <stl.ros@outlook.com> */

#pragma once

#include "DBConnection2.hpp"

class IConnectionDispatcher {
public:
    virtual void Dispatch(MySqlDBConnection2& connection) = 0;
    virtual void Dispatch(SqLiteDBConnection2& connection) = 0;
};

class MySqlConnectionDispatcher : public IConnectionDispatcher {
public:
    MySqlConnectionDispatcher() : m_mysql_connection(nullptr) {};

    void Dispatch(MySqlDBConnection2& connection) override;
    void Dispatch(SqLiteDBConnection2& connection) override;

    MySqlDBConnection2* connection() const;

private:
    MySqlDBConnection2* m_mysql_connection;
};

class SqLiteConnectionDispatcher : public IConnectionDispatcher {
public:
    SqLiteConnectionDispatcher() : m_sqlite_connection(nullptr) {};

    void Dispatch(MySqlDBConnection2& connection) override;
    void Dispatch(SqLiteDBConnection2& connection) override;

    SqLiteDBConnection2* connection() const;

private:
    SqLiteDBConnection2* m_sqlite_connection;
};