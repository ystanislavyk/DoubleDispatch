/* Copyright (c) 2018 Yaroslav Stanislavyk <stl.ros@outlook.com> */

#include <gtest/gtest.h>

#include "DBConnection3.hpp"
#include "DBConnection3Caster.hpp"

namespace {

void CheckMySqlConnection3Info(IDBConnection3& db_connection,
                               const CastType expected_cast_type,
                               const int expected_value) {
  ASSERT_EQ(
      (DBConnection3Caster<MySqlDBConnection3, IDBConnection3>::GetCastType()),
      expected_cast_type);
  auto& mysql_connection =
      DBConnection3Caster<MySqlDBConnection3, IDBConnection3>::Cast(
          db_connection);
  ASSERT_EQ(expected_value, mysql_connection.Query());
}

void CheckMySqlConnection3AdvancedInfo(IDBConnection3& db_connection,
                                       const CastType expected_cast_type,
                                       const std::string& expected_value) {
  ASSERT_EQ(
      (DBConnection3Caster<MySqlDBConnection3, IDBConnection3>::GetCastType()),
      expected_cast_type);
  auto& mysql_connection =
      DBConnection3Caster<MySqlDBConnection3, IDBConnection3>::Cast(
          db_connection);
  ASSERT_EQ(expected_value, mysql_connection.AdvancedQuery().server_version);
}

void CheckSqLiteConnection3Info(IDBConnection3& db_connection,
                                const CastType expected_cast_type,
                                const int expected_value) {
  ASSERT_EQ(
      (DBConnection3Caster<SqLiteDBConnection3, IDBConnection3>::GetCastType()),
      expected_cast_type);
  auto& sqlite_connection =
      DBConnection3Caster<SqLiteDBConnection3, IDBConnection3>::Cast(
          db_connection);
  ASSERT_EQ(expected_value, sqlite_connection.Query());
}

TEST(MySqlConnection3InfoTest, GetInfoStaticCast) {
  MySqlDBConnection3 mysql_connection("Some server", 7);
  CheckMySqlConnection3Info(mysql_connection, CastType::STATIC_CAST, 7);
}

TEST(MySqlConnection3InfoTest, GetAdvancedInfoStaticCast) {
  MySqlDBConnection3 mysql_connection("One more server", 7);
  CheckMySqlConnection3AdvancedInfo(mysql_connection, CastType::STATIC_CAST,
                                    "One more server");
}

TEST(SqLiteConnection3InfoTest, GetInfoStaticCast) {
  SqLiteDBConnection3 sqlite_connection(3);
  CheckSqLiteConnection3Info(sqlite_connection, CastType::DYNAMIC_CAST, 3);
}

TEST(SqLiteConnection3InfoTest, DISABLED_GetAdvancedInfoStaticCast) {
  SqLiteDBConnection3 sqlite_connection(3);
  CheckMySqlConnection3AdvancedInfo(sqlite_connection, CastType::DYNAMIC_CAST,
                                    "");
}

TEST(SqLiteConnection3InfoTest, GetInfoBadCast) {
  MySqlDBConnection3 mysql_connection("Some SQLite server", 3);
  ASSERT_THROW(
      CheckSqLiteConnection3Info(mysql_connection, CastType::DYNAMIC_CAST, 3),
      std::bad_cast);
}

}  // namespace
