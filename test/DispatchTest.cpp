#include "gtest/gtest.h"
#include "../src/DBConnection.hpp"

namespace
{
    int getConnectionInfo(const IDBConnection& connection)
    {
        assert(dynamic_cast<const MySqlDBConnection*>(&connection));
        auto& con = static_cast<const MySqlDBConnection&>(connection);
        return con.advancedQuery();
    }

    TEST(ConversionTest, StaticCast)
    {
        MySqlDBConnection connection;
        ASSERT_EQ(4, getConnectionInfo(connection));
    }
}