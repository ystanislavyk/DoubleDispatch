#ifndef PLAYGROUND_IDBCONNECTION_HPP
#define PLAYGROUND_IDBCONNECTION_HPP

#include "Queries.hpp"

class IDBConnection
{
public:
    virtual QueryResult query(IQuery*, QueryType) = 0;
    virtual QueryResult query(SelectQuery*) = 0;
    virtual QueryResult query(UpdateQuery*) = 0;
};

class MySqlDBConnection : public IDBConnection
{
public:
    QueryResult query(IQuery* query, QueryType) override;
    QueryResult query(SelectQuery* query) override;
    QueryResult query(UpdateQuery* query) override;
};

#endif //PLAYGROUND_IDBCONNECTION_HPP