#include <cassert>
#include <gtest/gtest.h>

#include "DBConnection.hpp"

int getConnectionInfo(const IDBConnection& idbConnection)
{
    return idbConnection.query();
}

std::string getConnectionAdvancedInfo(const IDBConnection& dbConnection)
{
    assert(dynamic_cast<const MySqlDBConnection*>(&dbConnection));
    auto& connection = static_cast<const MySqlDBConnection&>(dbConnection);
    return connection.advancedQuery().serverVersion;
}

TEST(ConnectionInfoTest, GetInfo)
{
    MySqlDBConnection connection("5.5.8 MySQL Community Server (GPL)", 10);
    ASSERT_EQ(10, getConnectionInfo(connection));
}

TEST(ConnectionInfoTest, GetAdvancedInfo)
{
    MySqlDBConnection connection("5.5.8 MySQL Community Server (GPL)", 10);
    ASSERT_EQ("5.5.8 MySQL Community Server (GPL)", getConnectionAdvancedInfo(connection));
}