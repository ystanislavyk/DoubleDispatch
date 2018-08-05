/* Copyright (c) 2018 Yaroslav Stanislavyk <stl.ros@outlook.com> */

#include <gtest/gtest.h>

#include "DBConnection5.hpp"
#include "DBConnectionChecker.hpp"

namespace {

TEST(MySqlConnection5InfoTest, GetInfo) {
  MySqlConnection::MySqlDBConnection5 mysql_connection("Some server", 7);
  ConnectionChecker connection_checker;
  connection_checker.CheckForMySqlConnection(mysql_connection);
  ASSERT_EQ(mysql_connection.Query(), 7);
}

TEST(MySqlConnection5InfoTest, GetAdvancedInfo) {
  MySqlConnection::MySqlDBConnection5 mysql_connection("One more server", 7);
  ConnectionChecker connection_checker;
  connection_checker.CheckForMySqlConnection(mysql_connection);
  ASSERT_EQ(mysql_connection.AdvancedQuery().server_version, "One more server");
}

TEST(SqLiteConnection5InfoTest, GetInfo) {
  SqLiteConnection::SqLiteDBConnection5 sqlite_connection(3);
  ConnectionChecker connection_checker;
  connection_checker.CheckForSqLiteConnection(sqlite_connection);
  ASSERT_EQ(sqlite_connection.Query(), 3);
}

TEST(SqLiteConnection5InfoTest, FailedStaticAssert) {
  SqLiteConnection::SqLiteDBConnection5 sqlite_connection(3);
  ConnectionChecker connection_checker;

  /* static_assert failed */
  // connection_checker.CheckForMySqlConnection(sqlite_connection);
}

}  // namespace