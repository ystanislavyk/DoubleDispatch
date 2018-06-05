#include <iostream>

#include "Queries.hpp"

QueryResult SelectQuery::execute(IDBConnection*)
{
    std::cout << "Executing select query" << std::endl;
    return QueryResult::SUCCESS;
}

QueryResult UpdateQuery::execute(IDBConnection*)
{
    std::cout << "Executing update query" << std::endl;
    return QueryResult::SUCCESS;
}