/* Copyright (c) 2018 Yaroslav Stanislavyk <stl.ros@outlook.com> */

#include <gtest/gtest.h>

#include "DBConnection2.hpp"
#include "ConnectionDispatcher.hpp"

namespace {

    int GetMySqlConnection2Info(IDBConnection2& db_connection) {
        MySqlConnectionDispatcher mysql_connection_dispatcher;
        db_connection.Dispatch(mysql_connection_dispatcher);

        if (nullptr == mysql_connection_dispatcher.connection()) {
            return 0;
        }

        return mysql_connection_dispatcher.connection()->Query();
    }

    std::string GetMySqlConnection2AdvancedInfo(IDBConnection2& db_connection) {
        MySqlConnectionDispatcher mysql_connection_dispatcher;
        db_connection.Dispatch(mysql_connection_dispatcher);

        if (nullptr == mysql_connection_dispatcher.connection()) {
            return std::string();
        }

        return mysql_connection_dispatcher.connection()->AdvancedQuery().server_version;
    }

    int GetSqLiteConnection2Info(IDBConnection2& db_connection) {
        SqLiteConnectionDispatcher sqlite_connection_dispatcher;
        db_connection.Dispatch(sqlite_connection_dispatcher);

        if (nullptr == sqlite_connection_dispatcher.connection()) {
            return 0;
        }

        return sqlite_connection_dispatcher.connection()->Query();
    }

    TEST(MySqlDBConnection2Test, GetInfoTest) {
        MySqlDBConnection2 mysql_connection("4.2.2 MySQL Server", 10);
        SqLiteDBConnection2 sqlite_connection(2);

        ASSERT_EQ(10, GetMySqlConnection2Info(mysql_connection));
        ASSERT_EQ(0, GetMySqlConnection2Info(sqlite_connection));
    }

    TEST(MySqlDBConnection2Test, GetAdvancedInfo) {
        MySqlDBConnection2 mysql_connection("4.2.2 MySQL Server", 10);
        SqLiteDBConnection2 sqlite_connection(2);

        ASSERT_EQ("4.2.2 MySQL Server", GetMySqlConnection2AdvancedInfo(mysql_connection));
        ASSERT_EQ("", GetMySqlConnection2AdvancedInfo(sqlite_connection));
    }

    TEST(PassWrongChildrensTest, SqLiteAndMySql) {
        SqLiteDBConnection2 sqlite_connection(7);
        MySqlDBConnection2 mysql_connection("Some SQL server", 8);

        ASSERT_EQ(0, GetSqLiteConnection2Info(mysql_connection));
        ASSERT_EQ(0, GetMySqlConnection2Info(sqlite_connection));
    }

}