#pragma once

#include <string>
#include <utility>

struct Info {
    Info() = default;
    explicit Info(std::string serverVersion, int protocolVersion) :
            server_version(std::move(serverVersion)), protocol_version(protocolVersion) {};

    std::string server_version{""};
    int protocol_version{0};
};

class IDBConnection {
public:
    virtual ~IDBConnection() = default;

    virtual int query() const = 0;
};

class MySqlDBConnection : public IDBConnection {
public:
    explicit MySqlDBConnection(std::string serverVersion, int protocolVersion) :
            m_info{std::move(serverVersion), protocolVersion} {};

    int query() const override;
    Info advancedQuery() const;

private:
    Info m_info;
};