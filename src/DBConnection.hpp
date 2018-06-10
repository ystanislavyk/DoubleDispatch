#pragma once

#include <string>

struct Info
{
	Info() : serverVersion(""), protocolVersion(0) {};
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
	const Info& advancedQuery() const;

private:
	Info info;
};

class QueryReceiver;

class IDBConnection2
{
public:
    virtual ~IDBConnection2() = default;

	virtual int sendQuery(const QueryReceiver& connectionVisitor) const = 0;
    virtual const Info& sendAdvancedQuery(const QueryReceiver& connectionVisitor) const = 0;
};

class MySqlDBConnection2 : public IDBConnection2
{
public:
    explicit MySqlDBConnection2(std::string serverVersion, int protocolVersion);

    int query() const;
    const Info& advancedQuery() const;

private:
    Info info;

private:
	int sendQuery(const QueryReceiver& queryReceiver) const override;
    const Info& sendAdvancedQuery(const QueryReceiver& queryReceiver) const override;
};

class QueryReceiver
{
public:
	int receiveQuery(const MySqlDBConnection2& connection) const;
    const Info& receiveAdvancedQuery(const MySqlDBConnection2& connection) const;
};