#include <utility>

#include "DBConnection.hpp"

MySqlDBConnection::MySqlDBConnection(std::string serverVersion, int protocolVersion) {
	info.serverVersion = std::move(serverVersion);
	info.protocolVersion = protocolVersion;
}

int MySqlDBConnection::query() const {
	return info.protocolVersion;
}

Info MySqlDBConnection::advancedQuery() const {
	return info;
}

MySqlDBConnection2::MySqlDBConnection2(std::string serverVersion, int protocolVersion) {
	info.serverVersion = std::move(serverVersion);
	info.protocolVersion = protocolVersion;
}

int MySqlDBConnection2::query() const {
	return info.protocolVersion;
}

Info MySqlDBConnection2::advancedQuery() const {
	return info;
}

int MySqlDBConnection2::sendQuery(const QueryReceiver& queryReceiver) const {
	return queryReceiver.receiveQuery(*this);
}

Info MySqlDBConnection2::sendAdvancedQuery(const QueryReceiver& queryReceiver) const {
	return queryReceiver.receiveAdvancedQuery(*this);
}

int QueryReceiver::receiveQuery(const MySqlDBConnection2& connection) const {
	return connection.query();
}

Info QueryReceiver::receiveAdvancedQuery(const MySqlDBConnection2& connection) const {
	return connection.advancedQuery();
}