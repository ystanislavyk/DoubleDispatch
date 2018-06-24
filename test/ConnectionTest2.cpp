#include <gtest/gtest.h>

#include "DBConnection2.hpp"
#include "ConnectionDispatcher.hpp"

namespace {

    int getConnection2Info(const IDBConnection2& dbConnection) {
        ConnectionDispatcher connectionDispatcher;
        dbConnection.dispatch(connectionDispatcher);
        return connectionDispatcher.getMySqlConnection().query();
    }

    std::string getConnection2AdvancedInfo(const IDBConnection2& dbConnection) {
        ConnectionDispatcher connectionDispatcher;
        dbConnection.dispatch(connectionDispatcher);
        return connectionDispatcher.getMySqlConnection().advancedQuery().serverVersion;
    }

    TEST(Connection2InfoTest, GetInfo) {
        MySqlDBConnection2 connection("4.2.2 MySQL Server", 10);
        ASSERT_EQ(10, getConnection2Info(connection));
    }

    TEST(Connection2InfoTest, GetAdvancedInfo) {
        MySqlDBConnection2 connection("4.2.2 MySQL Server", 10);
        ASSERT_EQ("4.2.2 MySQL Server", getConnection2AdvancedInfo(connection));
    }

}