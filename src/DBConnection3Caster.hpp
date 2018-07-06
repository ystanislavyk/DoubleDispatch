#pragma once

#include "DBConnection3.hpp"

template <typename To, typename From>
struct DBConnection3Caster {
    static To& cast(IDBConnection3& object) {
        return dynamic_cast<To&>(object);
    }
};

template <>
class DBConnection3Caster<MySqlDBConnection3, IDBConnection3> {
public:
    static MySqlDBConnection3& cast(IDBConnection3& object) {
        if (ConnectionType::MYSQL != object.connectionType()) {
            throw std::bad_cast();
        }
        return static_cast<MySqlDBConnection3&>(object);
    }
};

template <>
class DBConnection3Caster<SqLiteDBConnection3, IDBConnection3> {
public:
    static MySqlDBConnection3& cast(IDBConnection3& object) {
        if (ConnectionType::SQLITE != object.connectionType()) {
            throw std::bad_cast();
        }
        return static_cast<MySqlDBConnection3&>(object);
    }
};