/* Copyright (c) 2018 Yaroslav Stanislavyk <stl.ros@outlook.com> */

#pragma once

#include "DBConnection3.hpp"

enum class CastType {
    DYNAMIC_CAST,
    STATIC_CAST
};

template <typename To, typename From>
struct DBConnection3Caster {
    static To& Cast(From& object) {
        return dynamic_cast<To&>(object);
    }

    static CastType GetCastType() {
        return CastType::DYNAMIC_CAST;
    }
};

template <>
class DBConnection3Caster<MySqlDBConnection3, IDBConnection3> {
public:
    static MySqlDBConnection3& Cast(IDBConnection3& object) {
        return static_cast<MySqlDBConnection3&>(object);
    }

    static CastType GetCastType() {
        return CastType::STATIC_CAST;
    }
};