#include <gtest/gtest.h>

#include "DBConnection2.hpp"
#include "ConnectionDispatcher.hpp"

namespace {

    int getMySqlConnection2Info(IDBConnection2& dbConnection) {
        ConnectionDispatcher connectionDispatcher;
        dbConnection.connect(connectionDispatcher);

        if (nullptr == connectionDispatcher.getMySqlConnection()) {
            return 0;
        }

        return connectionDispatcher.getMySqlConnection()->query();
    }

    std::string getMySqlConnection2AdvancedInfo(IDBConnection2& dbConnection) {
        ConnectionDispatcher connectionDispatcher;
        dbConnection.connect(connectionDispatcher);

        if (nullptr == connectionDispatcher.getMySqlConnection()) {
            return std::string();
        }

        return connectionDispatcher.getMySqlConnection()->advancedQuery().serverVersion;
    }

    int getSqLiteConnection2Info(IDBConnection2& dbconnection) {
        ConnectionDispatcher connectionDispatcher;
        dbconnection.connect(connectionDispatcher);

        if (nullptr == connectionDispatcher.getSqLiteConnection()) {
            return 0;
        }

        return connectionDispatcher.getSqLiteConnection()->query();
    }

    TEST(MySqlDBConnection2Test, GetInfoTest) {
        MySqlDBConnection2 connection("4.2.2 MySQL Server", 10);
        SqLiteDBConnection2 connection2("SQLite server", 2);

        ASSERT_EQ(10, getMySqlConnection2Info(connection));
        ASSERT_EQ(0, getMySqlConnection2Info(connection2));
    }

    TEST(MySqlDBConnection2Test, GetAdvancedInfo) {
        MySqlDBConnection2 connection("4.2.2 MySQL Server", 10);
        SqLiteDBConnection2 connection2("SQLite server", 2);

        ASSERT_EQ("4.2.2 MySQL Server", getMySqlConnection2AdvancedInfo(connection));
        ASSERT_EQ("", getMySqlConnection2AdvancedInfo(connection2));
    }

    TEST(SqLiteDBConnection2Test, GetInfoTest) {
        SqLiteDBConnection2 connection("Some SQLite server", 7);
        MySqlDBConnection2 connection2("Some SQL server", 8);

        ASSERT_EQ(7, getSqLiteConnection2Info(connection));
        ASSERT_EQ(0, getSqLiteConnection2Info(connection2));
    }

}