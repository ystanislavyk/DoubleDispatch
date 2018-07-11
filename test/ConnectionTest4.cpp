/* Copyright (c) 2018 Yaroslav Stanislavyk <stl.ros@outlook.com> */

#include <gtest/gtest.h>

#include "DBConnection4.hpp"

namespace {

    void checkMySqlConnection4Info(IDBConnection4& db_connection, const int expected_value) {
        if (db_connection.connectionType() != ConnectionType::MYSQL) {
            throw std::bad_cast();
        }
        ASSERT_EQ(expected_value, static_cast<MySqlDBConnection4&>(db_connection).query());
    }

    void checkMySqlConnection4AdvancedInfo(IDBConnection4& db_connection, const std::string& expected_value) {
        if (db_connection.connectionType() != ConnectionType::MYSQL) {
            throw std::bad_cast();
        }
        ASSERT_EQ(expected_value, static_cast<MySqlDBConnection4&>(db_connection).advancedQuery().server_version);
    }

    void checkSqLiteConnection4Info(IDBConnection4& db_connection, const int expected_value) {
        if (db_connection.connectionType() != ConnectionType::SQLITE) {
            throw std::bad_cast();
        }
        ASSERT_EQ(expected_value, static_cast<MySqlDBConnection4&>(db_connection).query());
    }

    TEST(MySqlConnection4InfoTest, GetInfoStaticCast) {
        MySqlDBConnection4 mysql_connection("Some server", 7);
        checkMySqlConnection4Info(mysql_connection, 7);
        ASSERT_THROW(checkSqLiteConnection4Info(mysql_connection, 3), std::bad_cast);
    }

    TEST(MySqlConnection4InfoTest, GetAdvancedInfoStaticCast) {
        MySqlDBConnection4 mysql_connection("One more server", 7);
        checkMySqlConnection4AdvancedInfo(mysql_connection, "One more server");
    }

    TEST(SqLiteConnection4InfoTest, GetInfoStaticCast) {
        SqLiteDBConnection4 sqlite_connection(3);
        ASSERT_THROW(checkMySqlConnection4Info(sqlite_connection, 3), std::bad_cast);
        checkSqLiteConnection4Info(sqlite_connection, 3);
    }

    TEST(SqLiteConnection4InfoTest, GetAdvancedInfoStaticCast) {
        SqLiteDBConnection4 sqlite_connection(3);
        ASSERT_THROW(checkMySqlConnection4AdvancedInfo(sqlite_connection, ""), std::bad_cast);
    }

}