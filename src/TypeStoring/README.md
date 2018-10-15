# Double Dispatch example #

In this example considered a pretty easy way to avoid RTTI use. Using the class type storing.

There is an **interface** `IDBConnection`, it's **implementations**: `MySqlDBConnection`, `SqLiteDBConnection` with some
business logic and the **enum** `ConnectionType`

In addition to business logic adds the function which returning the enumerator based on class.

[Using](/test/TypeStoringTest.cpp)

## Pluses ##

- No RTTI mechanism use

## Minuses ##

- Extra class functionality which not related to business logic