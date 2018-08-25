/* Copyright (c) 2018 Yaroslav Stanislavyk <stl.ros@outlook.com> */

#pragma once

#include "DBConnection.hpp"

class IConnectionDispatcher;

class IDBConnection2 {
 public:
  virtual ~IDBConnection2();

  virtual void Dispatch(IConnectionDispatcher& connection_dispatcher) = 0;
  virtual int Query() const = 0;
};

class MySqlDBConnection2 : public IDBConnection2 {
 public:
  MySqlDBConnection2() = default;
  explicit MySqlDBConnection2(std::string server_version, int protocol_version)
      : m_info{std::move(server_version), protocol_version} {}

  void Dispatch(IConnectionDispatcher& connection_dispatcher) override;
  int Query() const override;

  Info AdvancedQuery() const;

 private:
  Info m_info;
};

class SqLiteDBConnection2 : public IDBConnection2 {
 public:
  SqLiteDBConnection2() : m_protocol_version(0) {}
  explicit SqLiteDBConnection2(int protocol_version)
      : m_protocol_version(protocol_version) {}

  void Dispatch(IConnectionDispatcher& connection_dispatcher) override;
  int Query() const override;

 private:
  int m_protocol_version;
};
