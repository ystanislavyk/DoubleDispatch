#include <cassert>

#include "DBConnection.hpp"

QueryResult MySqlDBConnection::query(IQuery* query, QueryType type)
{
    if (type == QueryType::SELECT)
    {
        assert(query = dynamic_cast<SelectQuery*>(query));
        query = static_cast<SelectQuery*>(query);

        return query->execute(this);
    }
    else if (type == QueryType::UPDATE)
    {
        assert(query = dynamic_cast<UpdateQuery*>(query));
        query = static_cast<UpdateQuery*>(query);

        return query->execute(this);
    }
    else
    {
        return QueryResult::FAIL;
    }
}

QueryResult MySqlDBConnection::query(SelectQuery* query)
{
    return query->execute(this);
}

QueryResult MySqlDBConnection::query(UpdateQuery* query)
{
    return query->execute(this);
}