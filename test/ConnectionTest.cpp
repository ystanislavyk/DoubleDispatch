#include <cassert>
#include <gtest/gtest.h>

#include "DBConnection.hpp"

namespace {

    int getConnectionInfo(const IDBConnection& dbConnection) {
        return dbConnection.query();
    }

    std::string getConnectionAdvancedInfo(const IDBConnection& dbConnection) {
        assert(dynamic_cast<const MySqlDBConnection*>(&dbConnection));
        auto& connection = static_cast<const MySqlDBConnection&>(dbConnection);
        return connection.advancedQuery().serverVersion;
    }

    int getDispatchedConnectionInfo(const IDBConnection2& dbConnection) {
        QueryReceiver queryReceiver;
        return dbConnection.sendQuery(queryReceiver);
    }

    std::string getDispatchedConnectionAdvancedInfo(const IDBConnection2& dbConnection) {
        QueryReceiver queryReceiver;
        return dbConnection.sendAdvancedQuery(queryReceiver).serverVersion;
    }

    TEST(ConnectionInfoTest, GetInfo) {
        MySqlDBConnection connection("5.5.8 MySQL Community Server (GPL)", 10);
        ASSERT_EQ(10, getConnectionInfo(connection));
    }

    TEST(ConnectionInfoTest, GetAdvancedInfo) {
        MySqlDBConnection connection("5.5.8 MySQL Community Server (GPL)", 10);
        ASSERT_EQ("5.5.8 MySQL Community Server (GPL)", getConnectionAdvancedInfo(connection));
    }

    TEST(DispatchedConnectionInfoTest, GetInfo) {
        MySqlDBConnection2 connection("4.2.2 MySQL Server", 10);
        ASSERT_EQ(10, getDispatchedConnectionInfo(connection));
    }

    TEST(DispatchedConnectionInfoTest, GetAdvancedInfo) {
        MySqlDBConnection2 connection("4.2.2 MySQL Server", 10);
        ASSERT_EQ("4.2.2 MySQL Server", getDispatchedConnectionAdvancedInfo(connection));
    }

}