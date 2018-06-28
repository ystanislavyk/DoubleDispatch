#include "DBConnection2.hpp"
#include "ConnectionDispatcher.hpp"

MySqlDBConnection2::MySqlDBConnection2(std::string serverVersion, int protocolVersion) {
    m_info.serverVersion = std::move(serverVersion);
    m_info.protocolVersion = protocolVersion;
}

void MySqlDBConnection2::connect(ConnectionDispatcher& connectionDispatcher) {
    connectionDispatcher.dispatch(*this);
}

int MySqlDBConnection2::query() const {
    return m_info.protocolVersion;
}

Info MySqlDBConnection2::advancedQuery() const {
    return m_info;
}

SqLiteDBConnection2::SqLiteDBConnection2(std::string serverVersion, int protocolVersion) {
    m_info.serverVersion = std::move(serverVersion);
    m_info.protocolVersion = protocolVersion;
}

void SqLiteDBConnection2::connect(ConnectionDispatcher& connectionDispatcher) {
    connectionDispatcher.dispatch(*this);
}

int SqLiteDBConnection2::query() const {
    return m_info.protocolVersion;
}