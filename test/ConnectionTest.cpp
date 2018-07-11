/* Copyright (c) 2018 Yaroslav Stanislavyk <stl.ros@outlook.com> */

#include <cassert>
#include <gtest/gtest.h>

#include "DBConnection.hpp"

namespace {

    int getConnectionInfo(const IDBConnection& dbConnection) {
        return dbConnection.query();
    }

    std::string getConnectionAdvancedInfo(const IDBConnection& dbConnection) {
        assert(dynamic_cast<const MySqlDBConnection*>(&dbConnection));
        auto& mysql_connection = static_cast<const MySqlDBConnection&>(dbConnection);
        return mysql_connection.advancedQuery().server_version;
    }

    TEST(ConnectionInfoTest, GetInfo) {
        MySqlDBConnection mysql_connection("5.5.8 MySQL Community Server (GPL)", 10);
        ASSERT_EQ(10, getConnectionInfo(mysql_connection));
    }

    TEST(ConnectionInfoTest, GetAdvancedInfo) {
        MySqlDBConnection mysql_connection("5.5.8 MySQL Community Server (GPL)", 10);
        ASSERT_EQ("5.5.8 MySQL Community Server (GPL)", getConnectionAdvancedInfo(mysql_connection));
    }

}