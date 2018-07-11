/* Copyright (c) 2018 Yaroslav Stanislavyk <stl.ros@outlook.com> */

#pragma once

#include "DBConnection.hpp"

class IConnectionDispatcher;

class IDBConnection2 {
public:
    virtual ~IDBConnection2() = default;

    virtual void dispatch(IConnectionDispatcher& connectionDispatcher) = 0;
    virtual int query() const = 0;
};

class MySqlDBConnection2 : public IDBConnection2 {
public:
    MySqlDBConnection2() = default;
    explicit MySqlDBConnection2(std::string serverVersion, int protocolVersion) :
            m_info{std::move(serverVersion), protocolVersion} {};

    void dispatch(IConnectionDispatcher& connectionDispatcher) override;
    int query() const override;

    Info advancedQuery() const;

private:
    Info m_info;
};

class SqLiteDBConnection2 : public IDBConnection2 {
public:
    SqLiteDBConnection2() = default;
    explicit SqLiteDBConnection2(int protocolVersion) : m_protocol_version(protocolVersion) {};

    void dispatch(IConnectionDispatcher& connectionDispatcher) override;
    int query() const override;

private:
    int m_protocol_version;
};