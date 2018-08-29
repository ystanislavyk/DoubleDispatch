/* Copyright (c) 2018 Yaroslav Stanislavyk <stl.ros@outlook.com> */

#pragma once

#include "DBConnection.hpp"

namespace DoubleDispatch {

class IConnectionDispatcher;

class IDBConnection {
 public:
  virtual ~IDBConnection();

  virtual void Dispatch(IConnectionDispatcher& connection_dispatcher) = 0;
  virtual int Query() const = 0;
};

class MySqlDBConnection : public IDBConnection {
 public:
  MySqlDBConnection();
  explicit MySqlDBConnection(std::string server_version, int protocol_version);

  void Dispatch(IConnectionDispatcher& connection_dispatcher) override;
  int Query() const override;

  Origin::Info AdvancedQuery() const;

 private:
  Origin::Info m_info;
};

class SqLiteDBConnection : public IDBConnection {
 public:
  SqLiteDBConnection();
  explicit SqLiteDBConnection(int protocol_version);

  void Dispatch(IConnectionDispatcher& connection_dispatcher) override;
  int Query() const override;

 private:
  int m_protocol_version;
};

}  // namespace DoubleDispatch
