/* Copyright (c) 2018 Yaroslav Stanislavyk <stl.ros@outlook.com> */

#include "DBConnection2.hpp"
#include "ConnectionDispatcher.hpp"

void MySqlDBConnection2::dispatch(IConnectionDispatcher& connectionDispatcher) {
    connectionDispatcher.dispatch(*this);
}

int MySqlDBConnection2::query() const {
    return m_info.protocol_version;
}

Info MySqlDBConnection2::advancedQuery() const {
    return m_info;
}

void SqLiteDBConnection2::dispatch(IConnectionDispatcher& connectionDispatcher) {
    connectionDispatcher.dispatch(*this);
}

int SqLiteDBConnection2::query() const {
    return m_protocol_version;
}