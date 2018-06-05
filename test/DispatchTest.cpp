#include "gtest/gtest.h"
#include "../src/DBConnection.hpp"
#include "../src/Queries.hpp"

namespace
{
    TEST(TypesConversionQueriesTesting, SelectQuery)
    {
        auto* connection = new MySqlDBConnection();
        auto* selectQuery = new SelectQuery();

        ASSERT_EQ(connection->query(selectQuery, QueryType::SELECT), QueryResult::SUCCESS);
    }

    TEST(TypesConversionQueriesTesting, UpdateQuery)
    {
        auto* connection = new MySqlDBConnection();
        auto* updateQuery = new UpdateQuery();

        ASSERT_EQ(connection->query(updateQuery, QueryType::UPDATE), QueryResult::SUCCESS);
    }

    TEST(DoubleDispatchQueriesTesting, SelectQuery)
    {
        auto* connection = new MySqlDBConnection();
        auto* selectQuery = new SelectQuery();

        ASSERT_EQ(connection->query(selectQuery), QueryResult::SUCCESS);
    }

    TEST(DoubleDispatchQueriesTesting, UpdateQuery)
    {
        auto* connection = new MySqlDBConnection();
        auto* updateQuery = new UpdateQuery();

        ASSERT_EQ(connection->query(updateQuery), QueryResult::SUCCESS);
    }
}