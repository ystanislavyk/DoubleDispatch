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