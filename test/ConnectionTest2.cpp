/* Copyright (c) 2018 Yaroslav Stanislavyk <stl.ros@outlook.com> */

#include <gtest/gtest.h>

#include "DBConnection2.hpp"
#include "ConnectionDispatcher.hpp"

namespace {

    int getMySqlConnection2Info(IDBConnection2& dbConnection) {
        MySqlConnectionDispatcher mysql_connection_dispatcher;
        dbConnection.dispatch(mysql_connection_dispatcher);

        if (nullptr == mysql_connection_dispatcher.connection()) {
            return 0;
        }

        return mysql_connection_dispatcher.connection()->query();
    }

    std::string getMySqlConnection2AdvancedInfo(IDBConnection2& dbConnection) {
        MySqlConnectionDispatcher mysql_connection_dispatcher;
        dbConnection.dispatch(mysql_connection_dispatcher);

        if (nullptr == mysql_connection_dispatcher.connection()) {
            return std::string();
        }

        return mysql_connection_dispatcher.connection()->advancedQuery().server_version;
    }

    int getSqLiteConnection2Info(IDBConnection2& dbConnection) {
        SqLiteConnectionDispatcher sqlite_connection_dispatcher;
        dbConnection.dispatch(sqlite_connection_dispatcher);

        if (nullptr == sqlite_connection_dispatcher.connection()) {
            return 0;
        }

        return sqlite_connection_dispatcher.connection()->query();
    }

    TEST(MySqlDBConnection2Test, GetInfoTest) {
        MySqlDBConnection2 mysql_connection("4.2.2 MySQL Server", 10);
        SqLiteDBConnection2 sqlite_connection(2);

        ASSERT_EQ(10, getMySqlConnection2Info(mysql_connection));
        ASSERT_EQ(0, getMySqlConnection2Info(sqlite_connection));
    }

    TEST(MySqlDBConnection2Test, GetAdvancedInfo) {
        MySqlDBConnection2 mysql_connection("4.2.2 MySQL Server", 10);
        SqLiteDBConnection2 sqlite_connection(2);

        ASSERT_EQ("4.2.2 MySQL Server", getMySqlConnection2AdvancedInfo(mysql_connection));
        ASSERT_EQ("", getMySqlConnection2AdvancedInfo(sqlite_connection));
    }

    TEST(PassWrongChildrensTest, SqLiteAndMySql) {
        SqLiteDBConnection2 sqlite_connection(7);
        MySqlDBConnection2 mysql_connection("Some SQL server", 8);

        ASSERT_EQ(0, getSqLiteConnection2Info(mysql_connection));
        ASSERT_EQ(0, getMySqlConnection2Info(sqlite_connection));
    }

}