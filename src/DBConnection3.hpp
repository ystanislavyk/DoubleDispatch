#pragma once

#include "DBConnection.hpp"

enum class ConnectionType {
    MYSQL,
    SQLITE
};

class IDBConnection3 {
public:
    virtual ~IDBConnection3() = default;

    virtual ConnectionType connectionType() const = 0;

    virtual int query() const = 0;
};

class MySqlDBConnection3 : public IDBConnection3 {
public:
    explicit MySqlDBConnection3(std::string serverVersion, int protocolVersion) :
            m_info{std::move(serverVersion), protocolVersion} {};

    ConnectionType connectionType() const override;

    int query() const override;
    Info advancedQuery() const;

private:
    Info m_info;
};

class SqLiteDBConnection3 : public IDBConnection3 {
public:
    SqLiteDBConnection3() : m_protocol_version(0) {};
    explicit SqLiteDBConnection3(int protocolVersion) : m_protocol_version(protocolVersion) {};

    ConnectionType connectionType() const override;

    int query() const override;

private:
    int m_protocol_version;
};