#include <gtest/gtest.h>

#include "../src/DBConnection.hpp"

int getConnectionInfo(const IDBConnection& dbConnection)
{
    if (dynamic_cast<const MySqlDBConnection*>(&dbConnection))
    {
        auto& connection = static_cast<const MySqlDBConnection&>(dbConnection);
        return connection.advancedQuery();
    }
}

TEST(ConversionTest, StaticCast)
{
    MySqlDBConnection connection;
    ASSERT_EQ(4, getConnectionInfo(connection));
}