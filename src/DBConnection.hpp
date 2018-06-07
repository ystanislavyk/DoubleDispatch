#pragma once

class IDBConnection
{
public:
	virtual int query() const = 0;
};

class MySqlDBConnection : public IDBConnection
{
public:
	int query() const override;
	int advancedQuery() const;
};