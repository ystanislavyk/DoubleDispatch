#ifndef PLAYGROUND_QUERYTYPE_HPP
#define PLAYGROUND_QUERYTYPE_HPP

class IDBConnection;

enum class QueryType
{
    SELECT,
    UPDATE
};

enum class QueryResult
{
    SUCCESS,
    FAIL
};

class IQuery
{
public:
    virtual QueryResult execute(IDBConnection*) = 0;
};

class SelectQuery : public IQuery
{
public:
    QueryResult execute(IDBConnection*) override;
};

class UpdateQuery : public IQuery
{
public:
    QueryResult execute(IDBConnection*) override;
};

#endif //PLAYGROUND_QUERYTYPE_HPP