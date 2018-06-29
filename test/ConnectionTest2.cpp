#include <gtest/gtest.h>

#include "DBConnection2.hpp"
#include "ConnectionDispatcher.hpp"

namespace {

    int getMySqlConnection2Info(IDBConnection2& dbConnection) {
        MySqlConnectionDispatcher mySqlConnectionDispatcher;
        dbConnection.connect(mySqlConnectionDispatcher);

        if (nullptr == mySqlConnectionDispatcher.connection()) {
            return 0;
        }

        return mySqlConnectionDispatcher.connection()->query();
    }

    std::string getMySqlConnection2AdvancedInfo(IDBConnection2& dbConnection) {
        MySqlConnectionDispatcher mySqlConnectionDispatcher;
        dbConnection.connect(mySqlConnectionDispatcher);

        if (nullptr == mySqlConnectionDispatcher.connection()) {
            return std::string();
        }

        return mySqlConnectionDispatcher.connection()->advancedQuery().serverVersion;
    }

    int getSqLiteConnection2Info(IDBConnection2& dbconnection) {
        SqLiteConnectionDispatcher sqLiteConnectionDispatcher;
        dbconnection.connect(sqLiteConnectionDispatcher);

        if (nullptr == sqLiteConnectionDispatcher.connection()) {
            return 0;
        }

        return sqLiteConnectionDispatcher.connection()->query();
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