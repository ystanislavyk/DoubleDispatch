#ifndef PLAYGROUND_IDBCONNECTION_HPP
#define PLAYGROUND_IDBCONNECTION_HPP

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

#endif //PLAYGROUND_IDBCONNECTION_HPP