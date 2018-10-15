# Assertion example #

Here we have an **interface** `IDBConnection` and it's **implementation** `MySqlDBConnection` with some business logic.

Suppose that we have a function which using one of the current implementations through the interface:

`std::string GetConnectionAdvancedInfo(const Assertion::IDBConnection& db_connection)`

In [this](/test/AssertionTest.cpp) example used `assert()` and `dynamic_cast` to check the type of the object.
A bit of RTTI in the "debug" and no any RTTI in the "release".

## Pluses ##

- No RTTI mechanism use in the "release"
- Just the one line of the code

## Minuses ##

- Undefined behaviour in the "release"