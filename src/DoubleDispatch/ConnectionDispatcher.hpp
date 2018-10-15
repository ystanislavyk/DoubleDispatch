/* Copyright (c) 2018 Yaroslav Stanislavyk <stl.ros@outlook.com> */

#pragma once

#include "DoubleDispatch.hpp"

namespace DoubleDispatch {

class IConnectionDispatcher {
 public:
  virtual ~IConnectionDispatcher();
  virtual void Dispatch(MySqlDBConnection& connection) = 0;
  virtual void Dispatch(SqLiteDBConnection& connection) = 0;
};

class MySqlConnectionDispatcher : public IConnectionDispatcher {
 public:
  MySqlConnectionDispatcher();

  void Dispatch(MySqlDBConnection& connection) override;
  void Dispatch(SqLiteDBConnection& connection) override;

  MySqlDBConnection* connection() const;

 private:
  MySqlDBConnection* m_mysql_connection;
};

class SqLiteConnectionDispatcher : public IConnectionDispatcher {
 public:
  SqLiteConnectionDispatcher();

  void Dispatch(MySqlDBConnection& connection) override;
  void Dispatch(SqLiteDBConnection& connection) override;

  SqLiteDBConnection* connection() const;

 private:
  SqLiteDBConnection* m_sqlite_connection;
};

}  // namespace DoubleDispatch
