#include "DBConnection4.hpp"

ConnectionType MySqlDBConnection4::connectionType() const {
    return ConnectionType::MYSQL;
}

int MySqlDBConnection4::query() const {
    return m_info.protocol_version;
}

Info MySqlDBConnection4::advancedQuery() const {
    return m_info;
}

int SqLiteDBConnection4::query() const {
    return m_protocol_version;
}

ConnectionType SqLiteDBConnection4::connectionType() const {
    return ConnectionType::SQLITE;
}