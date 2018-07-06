#include "DBConnection3.hpp"

ConnectionType MySqlDBConnection3::connectionType() const {
    return ConnectionType::MYSQL;
}

int MySqlDBConnection3::query() const {
    return m_info.protocol_version;
}

Info MySqlDBConnection3::advancedQuery() const {
    return m_info;
}

int SqLiteDBConnection3::query() const {
    return m_protocol_version;
}

ConnectionType SqLiteDBConnection3::connectionType() const {
    return ConnectionType::SQLITE;
}