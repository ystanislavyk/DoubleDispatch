/* Copyright (c) 2018 Yaroslav Stanislavyk <stl.ros@outlook.com> */

#pragma once

#include <boost/type_index/ctti_type_index.hpp>

/* Helper function that returns true if `name` starts with `substr` */
template <std::size_t N>
constexpr bool StartsWith(const char* name, const char (&substr)[N]) noexcept {
  for (std::size_t i = 0; i < N - 1; ++i) {
    if (name[i] != substr[i]) {
      return false;
    }
  }

  return true;
}

/* Function that returns true if `T` declared in namespace `ns` */
template <class T, std::size_t N>
constexpr bool InNamespace(const char (&ns)[N]) noexcept {
  const char* name = boost::typeindex::ctti_type_index::type_id<T>().raw_name();

  /* Some compilers add `class ` or `struct ` before the namespace, so we need
   * to skip those words first */
  if (StartsWith(name, "class ")) {
    name += sizeof("class ") - 1;
  } else if (StartsWith(name, "struct ")) {
    name += sizeof("struct ") - 1;
  }

  return StartsWith(name, ns) && StartsWith(name + N - 1, "::");
}

struct ConnectionChecker {
  template <typename T>
  void CheckForMySqlConnection(const T&) {
    static_assert(InNamespace<T>("MySqlConnection"),
                  "Error. It's not a MySqlConnection");
  }

  template <typename T>
  void CheckForSqLiteConnection(const T&) {
    static_assert(InNamespace<T>("SqLiteConnection"),
                  "Error. It's not a SqLiteConnection");
  }
};