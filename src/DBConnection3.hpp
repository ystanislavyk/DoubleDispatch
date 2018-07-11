#pragma once

#include "DBConnection.hpp"

class IDBConnection3 {
public:
    virtual ~IDBConnection3() = default;

    virtual int query() const = 0;
};

class MySqlDBConnection3 : public IDBConnection3 {
public:
    explicit MySqlDBConnection3(std::string serverVersion, int protocolVersion) :
            m_info{std::move(serverVersion), protocolVersion} {};

    int query() const override;
    Info advancedQuery() const;

private:
    Info m_info;
};

class SqLiteDBConnection3 : public IDBConnection3 {
public:
    SqLiteDBConnection3() : m_protocol_version(0) {};
    explicit SqLiteDBConnection3(int protocolVersion) : m_protocol_version(protocolVersion) {};

    int query() const override;

private:
    int m_protocol_version;
};