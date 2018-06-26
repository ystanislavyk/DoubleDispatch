#include <utility>

#include "DBConnection.hpp"

MySqlDBConnection::MySqlDBConnection(std::string serverVersion, int protocolVersion) {
	m_info.serverVersion = std::move(serverVersion);
	m_info.protocolVersion = protocolVersion;
}

int MySqlDBConnection::query() const {
	return m_info.protocolVersion;
}

Info MySqlDBConnection::advancedQuery() const {
	return m_info;
}