/* Copyright (c) 2018 Yaroslav Stanislavyk <stl.ros@outlook.com> */

#include <gtest/gtest.h>

#include "DBConnection4.hpp"

namespace {

void CheckMySqlConnection4Info(IDBConnection4& db_connection,
                               const int expected_value) {
  if (db_connection.GetConnectionType() != ConnectionType::MYSQL) {
    throw std::bad_cast();
  }
  ASSERT_EQ(expected_value,
            static_cast<MySqlDBConnection4&>(db_connection).Query());
}

void CheckMySqlConnection4AdvancedInfo(IDBConnection4& db_connection,
                                       const std::string& expected_value) {
  if (db_connection.GetConnectionType() != ConnectionType::MYSQL) {
    throw std::bad_cast();
  }
  ASSERT_EQ(expected_value, static_cast<MySqlDBConnection4&>(db_connection)
                                .AdvancedQuery()
                                .server_version);
}

void CheckSqLiteConnection4Info(IDBConnection4& db_connection,
                                const int expected_value) {
  if (db_connection.GetConnectionType() != ConnectionType::SQLITE) {
    throw std::bad_cast();
  }
  ASSERT_EQ(expected_value,
            static_cast<MySqlDBConnection4&>(db_connection).Query());
}

TEST(MySqlConnection4InfoTest, GetInfoStaticCast) {
  MySqlDBConnection4 mysql_connection("Some server", 7);
  CheckMySqlConnection4Info(mysql_connection, 7);
  ASSERT_THROW(CheckSqLiteConnection4Info(mysql_connection, 3), std::bad_cast);
}

TEST(MySqlConnection4InfoTest, GetAdvancedInfoStaticCast) {
  MySqlDBConnection4 mysql_connection("One more server", 7);
  CheckMySqlConnection4AdvancedInfo(mysql_connection, "One more server");
}

TEST(SqLiteConnection4InfoTest, GetInfoStaticCast) {
  SqLiteDBConnection4 sqlite_connection(3);
  ASSERT_THROW(CheckMySqlConnection4Info(sqlite_connection, 3), std::bad_cast);
  CheckSqLiteConnection4Info(sqlite_connection, 3);
}

TEST(SqLiteConnection4InfoTest, GetAdvancedInfoStaticCast) {
  SqLiteDBConnection4 sqlite_connection(3);
  ASSERT_THROW(CheckMySqlConnection4AdvancedInfo(sqlite_connection, ""),
               std::bad_cast);
}

}  // namespace