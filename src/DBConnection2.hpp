#pragma once

#include "DBConnection.hpp"

class ConnectionDispatcher;

class IDBConnection2 {
public:
    virtual ~IDBConnection2() = default;

    virtual void dispatch(ConnectionDispatcher& connectionDispatcher) = 0;
    virtual int query() const = 0;
};

class MySqlDBConnection2 : public IDBConnection2 {
public:
    MySqlDBConnection2() = default;
    explicit MySqlDBConnection2(std::string serverVersion, int protocolVersion);

    void dispatch(ConnectionDispatcher& connectionDispatcher) override;
    int query() const override;

    Info advancedQuery() const;

private:
    Info m_info;
};