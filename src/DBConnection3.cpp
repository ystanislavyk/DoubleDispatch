/* Copyright (c) 2018 Yaroslav Stanislavyk <stl.ros@outlook.com> */

#include "DBConnection3.hpp"

int MySqlDBConnection3::Query() const { return m_info.protocol_version; }

Info MySqlDBConnection3::AdvancedQuery() const { return m_info; }

int SqLiteDBConnection3::Query() const { return m_protocol_version; }