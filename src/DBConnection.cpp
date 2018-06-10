#include <utility>

#include "DBConnection.hpp"

MySqlDBConnection::MySqlDBConnection(std::string serverVersion, int protocolVersion)
{
	info.serverVersion = std::move(serverVersion);
	info.protocolVersion = protocolVersion;
}

int MySqlDBConnection::query() const
{
	return info.protocolVersion;
}

const Info& MySqlDBConnection::advancedQuery() const
{
	return info;
}