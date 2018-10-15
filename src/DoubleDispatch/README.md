# Double Dispatch example #

In this example considered using of the [Double Dispatch](https://en.wikipedia.org/wiki/Double_dispatch)
and [Visitor](https://en.wikipedia.org/wiki/Visitor_pattern) patterns.

There is an **interface** `IDBConnection` and it's **implementations**: `MySqlDBConnection`, `SqLiteDBConnection` with some
business logic.

Also there is `ConnectionDispatcher`, a **Visitor** of the classes specified above.

[Using](/test/DoubleDispatchTest.cpp)

## Pluses ##

- No RTTI mechanism use

## Minuses ##

- Cyclic dependency between the class hierarchy and **Visitor**
- Changing of the class hierarchy requires the changing of the **Visitor**