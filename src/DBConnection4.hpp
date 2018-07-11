/* Copyright (c) 2018 Yaroslav Stanislavyk <stl.ros@outlook.com> */

#pragma once

#include "DBConnection.hpp"

enum class ConnectionType {
    MYSQL,
    SQLITE
};

class IDBConnection4 {
public:
    virtual ~IDBConnection4() = default;

    virtual ConnectionType connectionType() const = 0;

    virtual int query() const = 0;
};

class MySqlDBConnection4 : public IDBConnection4 {
public:
    explicit MySqlDBConnection4(std::string serverVersion, int protocolVersion) :
            m_info{std::move(serverVersion), protocolVersion} {};

    ConnectionType connectionType() const override;

    int query() const override;
    Info advancedQuery() const;

private:
    Info m_info;
};

class SqLiteDBConnection4 : public IDBConnection4 {
public:
    SqLiteDBConnection4() : m_protocol_version(0) {};
    explicit SqLiteDBConnection4(int protocolVersion) : m_protocol_version(protocolVersion) {};

    ConnectionType connectionType() const override;

    int query() const override;

private:
    int m_protocol_version;
};