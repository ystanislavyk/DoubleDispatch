/* Copyright (c) 2018 Yaroslav Stanislavyk <stl.ros@outlook.com> */

#include <gtest/gtest.h>

#include "DBConnection3.hpp"
#include "DBConnection3Caster.hpp"

namespace {

    void checkMySqlConnection3Info(IDBConnection3& db_connection, const CastType expected_cast_type, const int expected_value) {
        ASSERT_EQ((DBConnection3Caster<MySqlDBConnection3, IDBConnection3>::castType()), expected_cast_type);
        auto& mysql_connection = DBConnection3Caster<MySqlDBConnection3, IDBConnection3>::cast(db_connection);
        ASSERT_EQ(expected_value, mysql_connection.query());
    }

    void checkMySqlConnection3AdvancedInfo(IDBConnection3& db_connection, const CastType expected_cast_type, const std::string& expected_value) {
        ASSERT_EQ((DBConnection3Caster<MySqlDBConnection3, IDBConnection3>::castType()), expected_cast_type);
        auto& mysql_connection = DBConnection3Caster<MySqlDBConnection3, IDBConnection3>::cast(db_connection);
        ASSERT_EQ(expected_value, mysql_connection.advancedQuery().server_version);
    }

    void checkSqLiteConnection3Info(IDBConnection3& db_connection, const CastType expected_cast_type, const int expected_value) {
        ASSERT_EQ((DBConnection3Caster<SqLiteDBConnection3, IDBConnection3>::castType()), expected_cast_type);
        auto& sqlite_connection = DBConnection3Caster<SqLiteDBConnection3, IDBConnection3>::cast(db_connection);
        ASSERT_EQ(expected_value, sqlite_connection.query());
    }

    TEST(MySqlConnection3InfoTest, GetInfoStaticCast) {
        MySqlDBConnection3 mysql_connection("Some server", 7);
        checkMySqlConnection3Info(mysql_connection, CastType::STATIC_CAST, 7);
    }

    TEST(MySqlConnection3InfoTest, GetAdvancedInfoStaticCast) {
        MySqlDBConnection3 mysql_connection("One more server", 7);
        checkMySqlConnection3AdvancedInfo(mysql_connection, CastType::STATIC_CAST, "One more server");
    }

    TEST(SqLiteConnection3InfoTest, GetInfoStaticCast) {
        SqLiteDBConnection3 sqlite_connection(3);
        checkSqLiteConnection3Info(sqlite_connection, CastType::DYNAMIC_CAST, 3);
    }

    TEST(SqLiteConnection3InfoTest, DISABLED_GetAdvancedInfoStaticCast) {
        SqLiteDBConnection3 sqlite_connection(3);
        checkMySqlConnection3AdvancedInfo(sqlite_connection, CastType::DYNAMIC_CAST, "");
    }

    TEST(SqLiteConnection3InfoTest, GetInfoBadCast) {
        MySqlDBConnection3 mysql_connection("Some SQLite server", 3);
        ASSERT_THROW(checkSqLiteConnection3Info(mysql_connection, CastType::DYNAMIC_CAST, 3), std::bad_cast);
    }

}