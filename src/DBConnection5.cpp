/* Copyright (c) 2018 Yaroslav Stanislavyk <stl.ros@outlook.com> */

#include "DBConnection5.hpp"

int MySqlConnection::MySqlDBConnection5::Query() const {
  return m_info.protocol_version;
}

Info MySqlConnection::MySqlDBConnection5::AdvancedQuery() const {
  return m_info;
}

int SqLiteConnection::SqLiteDBConnection5::Query() const {
  return m_protocol_version;
}