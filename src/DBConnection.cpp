/* Copyright (c) 2018 Yaroslav Stanislavyk <stl.ros@outlook.com> */

#include "DBConnection.hpp"

int MySqlDBConnection::query() const {
	return m_info.protocol_version;
}

Info MySqlDBConnection::advancedQuery() const {
	return m_info;
}