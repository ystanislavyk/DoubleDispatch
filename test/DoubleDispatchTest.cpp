/* Copyright (c) 2018 Yaroslav Stanislavyk <stl.ros@outlook.com> */

#include <gtest/gtest.h>

#include "DoubleDispatch/ConnectionDispatcher.hpp"
#include "DoubleDispatch/DoubleDispatch.hpp"

namespace {

int GetMySqlConnectionInfo(DoubleDispatch::IDBConnection& db_connection) {
  DoubleDispatch::MySqlConnectionDispatcher mysql_connection_dispatcher;
  db_connection.Dispatch(mysql_connection_dispatcher);

  if (nullptr == mysql_connection_dispatcher.connection()) {
    return 0;
  }

  return mysql_connection_dispatcher.connection()->Query();
}

std::string GetMySqlConnectionAdvancedInfo(
    DoubleDispatch::IDBConnection& db_connection) {
  DoubleDispatch::MySqlConnectionDispatcher mysql_connection_dispatcher;
  db_connection.Dispatch(mysql_connection_dispatcher);

  if (nullptr == mysql_connection_dispatcher.connection()) {
    return std::string();
  }

  return mysql_connection_dispatcher.connection()
      ->AdvancedQuery()
      .server_version;
}

int GetSqLiteConnectionInfo(DoubleDispatch::IDBConnection& db_connection) {
  DoubleDispatch::SqLiteConnectionDispatcher sqlite_connection_dispatcher;
  db_connection.Dispatch(sqlite_connection_dispatcher);

  if (nullptr == sqlite_connection_dispatcher.connection()) {
    return 0;
  }

  return sqlite_connection_dispatcher.connection()->Query();
}

TEST(MySqlDBConnectionTest, GetInfoTest) {
  DoubleDispatch::MySqlDBConnection mysql_connection("4.2.2 MySQL Server", 10);
  DoubleDispatch::SqLiteDBConnection sqlite_connection(2);

  ASSERT_EQ(10, GetMySqlConnectionInfo(mysql_connection));
  ASSERT_EQ(0, GetMySqlConnectionInfo(sqlite_connection));
}

TEST(MySqlDBConnectionTest, GetAdvancedInfo) {
  DoubleDispatch::MySqlDBConnection mysql_connection("4.2.2 MySQL Server", 10);
  DoubleDispatch::SqLiteDBConnection sqlite_connection(2);

  ASSERT_EQ("4.2.2 MySQL Server",
            GetMySqlConnectionAdvancedInfo(mysql_connection));
  ASSERT_EQ("", GetMySqlConnectionAdvancedInfo(sqlite_connection));
}

TEST(PassWrongChildrensTest, SqLiteAndMySql) {
  DoubleDispatch::SqLiteDBConnection sqlite_connection(7);
  DoubleDispatch::MySqlDBConnection mysql_connection("Some SQL server", 8);

  ASSERT_EQ(0, GetSqLiteConnectionInfo(mysql_connection));
  ASSERT_EQ(0, GetMySqlConnectionInfo(sqlite_connection));
}

}  // namespace
