#pragma once

#include <string>

struct Info
{
    Info() : serverVersion(""), protocolVersion(0) {};
    ~Info() = default;

    std::string serverVersion;
    int protocolVersion;
};

class IDBConnection
{
public:
    virtual ~IDBConnection() = default;

    virtual int query() const = 0;
};

class MySqlDBConnection : public IDBConnection
{
public:
    explicit MySqlDBConnection(std::string serverVersion, int protocolVersion);

    int query() const override;
    Info advancedQuery() const;

private:
    Info info;
};