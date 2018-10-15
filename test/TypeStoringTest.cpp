/* Copyright (c) 2018 Yaroslav Stanislavyk <stl.ros@outlook.com> */

#include <gtest/gtest.h>

#include "TypeStoring/TypeStoring.hpp"

namespace {

void CheckMySqlConnectionInfo(TypeStoring::IDBConnection& db_connection,
                              const int expected_value) {
  if (db_connection.GetConnectionType() != TypeStoring::ConnectionType::MYSQL) {
    throw std::bad_cast();
  }
  ASSERT_EQ(
      expected_value,
      static_cast<TypeStoring::MySqlDBConnection&>(db_connection).Query());
}

void CheckMySqlConnectionAdvancedInfo(TypeStoring::IDBConnection& db_connection,
                                      const std::string& expected_value) {
  if (db_connection.GetConnectionType() != TypeStoring::ConnectionType::MYSQL) {
    throw std::bad_cast();
  }
  ASSERT_EQ(expected_value,
            static_cast<TypeStoring::MySqlDBConnection&>(db_connection)
                .AdvancedQuery()
                .server_version);
}

void CheckSqLiteConnectionInfo(TypeStoring::IDBConnection& db_connection,
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
  CheckMySqlConnectionInfo(mysql_connection, 7);
  ASSERT_THROW(CheckSqLiteConnectionInfo(mysql_connection, 3), std::bad_cast);
}

TEST(MySqlConnection3InfoTest, GetAdvancedInfoStaticCast) {
  TypeStoring::MySqlDBConnection mysql_connection("One more server", 7);
  CheckMySqlConnectionAdvancedInfo(mysql_connection, "One more server");
}

TEST(SqLiteConnection3InfoTest, GetInfoStaticCast) {
  TypeStoring::SqLiteDBConnection sqlite_connection(3);
  ASSERT_THROW(CheckMySqlConnectionInfo(sqlite_connection, 3), std::bad_cast);
  CheckSqLiteConnectionInfo(sqlite_connection, 3);
}

TEST(SqLiteConnection3InfoTest, GetAdvancedInfoStaticCast) {
  TypeStoring::SqLiteDBConnection sqlite_connection(3);
  ASSERT_THROW(CheckMySqlConnectionAdvancedInfo(sqlite_connection, ""),
               std::bad_cast);
}

}  // namespace
