#include <iostream>
#include "DBConnection2.hpp"
#include "ConnectionDispatcher.hpp"

MySqlDBConnection2::MySqlDBConnection2(std::string serverVersion, int protocolVersion) {
    info.serverVersion = std::move(serverVersion);
    info.protocolVersion = protocolVersion;
}

void MySqlDBConnection2::dispatch(const ConnectionDispatcher& connectionDispatcher) const {
    connectionDispatcher.dispatchConnection(*this);
}

int MySqlDBConnection2::query() const {
    return info.protocolVersion;
}

Info MySqlDBConnection2::advancedQuery() const {
    return info;
}