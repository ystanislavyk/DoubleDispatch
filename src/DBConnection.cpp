#include "DBConnection.hpp"

int MySqlDBConnection::query() const {
	return m_info.protocol_version;
}

Info MySqlDBConnection::advancedQuery() const {
	return m_info;
}