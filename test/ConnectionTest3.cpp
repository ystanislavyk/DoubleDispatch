/* Copyright (c) 2018 Yaroslav Stanislavyk <stl.ros@outlook.com> */

#include <gtest/gtest.h>

#include "DBConnection3.hpp"

namespace {

void CheckMySqlConnection3Info(TypeStoring::IDBConnection& db_connection,
                               const int expected_value) {
  if (db_connection.GetConnectionType() != TypeStoring::ConnectionType::MYSQL) {
    throw std::bad_cast();
  }
  ASSERT_EQ(
      expected_value,
      static_cast<TypeStoring::MySqlDBConnection&>(db_connection).Query());
}

void CheckMySqlConnection3AdvancedInfo(
    TypeStoring::IDBConnection& db_connection,
    const std::string& expected_value) {
  if (db_connection.GetConnectionType() != TypeStoring::ConnectionType::MYSQL) {
    throw std::bad_cast();
  }
  ASSERT_EQ(expected_value,
            static_cast<TypeStoring::MySqlDBConnection&>(db_connection)
                .AdvancedQuery()
                .server_version);
}

void CheckSqLiteConnection3Info(TypeStoring::IDBConnection& db_connection,
                                const int expected_value) {
  if (db_connection.GetConnectionType() !=
      TypeStoring::ConnectionType::SQLITE) {
    throw std::bad_cast();
  }
  ASSERT_EQ(
      expected_value,
      static_cast<TypeStoring::MySqlDBConnection&>(db_connection).Query());
}

TEST(MySqlConnection3InfoTest, GetInfoStaticCast) {
  TypeStoring::MySqlDBConnection mysql_connection("Some server", 7);
  CheckMySqlConnection3Info(mysql_connection, 7);
  ASSERT_THROW(CheckSqLiteConnection3Info(mysql_connection, 3), std::bad_cast);
}

TEST(MySqlConnection3InfoTest, GetAdvancedInfoStaticCast) {
  TypeStoring::MySqlDBConnection mysql_connection("One more server", 7);
  CheckMySqlConnection3AdvancedInfo(mysql_connection, "One more server");
}

TEST(SqLiteConnection3InfoTest, GetInfoStaticCast) {
  TypeStoring::SqLiteDBConnection sqlite_connection(3);
  ASSERT_THROW(CheckMySqlConnection3Info(sqlite_connection, 3), std::bad_cast);
  CheckSqLiteConnection3Info(sqlite_connection, 3);
}

TEST(SqLiteConnection3InfoTest, GetAdvancedInfoStaticCast) {
  TypeStoring::SqLiteDBConnection sqlite_connection(3);
  ASSERT_THROW(CheckMySqlConnection3AdvancedInfo(sqlite_connection, ""),
               std::bad_cast);
}

}  // namespace
