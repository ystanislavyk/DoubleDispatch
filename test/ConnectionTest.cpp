/* Copyright (c) 2018 Yaroslav Stanislavyk <stl.ros@outlook.com> */

#include <gtest/gtest.h>
#include <cassert>

#include "DBConnection.hpp"

namespace {

int GetConnectionInfo(const IDBConnection& db_connection) {
  return db_connection.Query();
}

std::string GetConnectionAdvancedInfo(const IDBConnection& db_connection) {
  assert(dynamic_cast<const MySqlDBConnection*>(&db_connection));
  auto& mysql_connection = static_cast<const MySqlDBConnection&>(db_connection);
  return mysql_connection.AdvancedQuery().server_version;
}

TEST(ConnectionInfoTest, GetInfo) {
  MySqlDBConnection mysql_connection("5.5.8 MySQL Community Server (GPL)", 10);
  ASSERT_EQ(10, GetConnectionInfo(mysql_connection));
}

TEST(ConnectionInfoTest, GetAdvancedInfo) {
  MySqlDBConnection mysql_connection("5.5.8 MySQL Community Server (GPL)", 10);
  ASSERT_EQ("5.5.8 MySQL Community Server (GPL)",
            GetConnectionAdvancedInfo(mysql_connection));
}

}  // namespace
