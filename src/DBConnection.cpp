/* Copyright (c) 2018 Yaroslav Stanislavyk <stl.ros@outlook.com> */

#include "DBConnection.hpp"

namespace Origin {

Info::Info() : server_version{""}, protocol_version(0) {}

Info::Info(std::string server_ver, int protocol_ver)
    : server_version(std::move(server_ver)), protocol_version(protocol_ver) {}

IDBConnection::~IDBConnection() = default;

MySqlDBConnection::MySqlDBConnection(std::string server_version,
                                     int protocol_version)
    : m_info{std::move(server_version), protocol_version} {}

int MySqlDBConnection::Query() const { return m_info.protocol_version; }

Info MySqlDBConnection::AdvancedQuery() const { return m_info; }

}  // namespace Origin
