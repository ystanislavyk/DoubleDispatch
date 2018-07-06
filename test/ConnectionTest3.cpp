#include <gtest/gtest.h>

#include "DBConnection3.hpp"
#include "DBConnection3Caster.hpp"

namespace {

    int getMySqlConnection3Info(IDBConnection3& dbConnection) {
        auto& mysql_connection = DBConnection3Caster<MySqlDBConnection3, IDBConnection3>::cast(dbConnection);
        return mysql_connection.query();
    }

    std::string getMySqlConnection3AdvancedInfo(IDBConnection3& dbConnection) {
        auto& mysql_connection = DBConnection3Caster<MySqlDBConnection3, IDBConnection3>::cast(dbConnection);
        return mysql_connection.advancedQuery().server_version;
    }

    int getSqLiteConnection3Info(IDBConnection3& dbConnection) {
        auto& sqlite_connection = DBConnection3Caster<SqLiteDBConnection3, IDBConnection3>::cast(dbConnection);
        return sqlite_connection.query();
    }

    TEST(MySqlConnection3InfoTest, GetInfoStaticCast) {
        MySqlDBConnection3 mysql_connection("Some server", 7);
        ASSERT_EQ(7, getMySqlConnection3Info(mysql_connection));
    }

    TEST(MySqlConnection3InfoTest, GetAdvancedInfoStaticCast) {
        MySqlDBConnection3 mysql_connection("One more server", 7);
        ASSERT_EQ("One more server", getMySqlConnection3AdvancedInfo(mysql_connection));
    }

    TEST(SqLiteConnection3InfoTest, GetInfoStaticCast) {
        SqLiteDBConnection3 sqlite_connection(3);
        ASSERT_THROW(getMySqlConnection3Info(sqlite_connection), std::bad_cast);
    }

    TEST(SqLiteConnection3InfoTest, GetAdvancedInfoStaticCast) {
        SqLiteDBConnection3 sqlite_connection(3);
        ASSERT_THROW(getMySqlConnection3AdvancedInfo(sqlite_connection), std::bad_cast);
    }

    TEST(SqLiteConnection3InfoTest, GetInfoDynamicCast) {
        SqLiteDBConnection3 sqlite_connection(3);
        ASSERT_EQ(3, getSqLiteConnection3Info(sqlite_connection));
    }

    TEST(SqLiteConnection3InfoTest, GetInfoBadCast) {
        MySqlDBConnection3 mysql_connection("Some SQLite server", 3);
        ASSERT_THROW(getSqLiteConnection3Info(mysql_connection), std::bad_cast);
    }

}