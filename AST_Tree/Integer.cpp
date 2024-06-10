/**
 * Created by laplace on 24-6-10.
 * Project: interpreter
 * Last Edit: 24-6-10-下午6:08
 * Copyright (c) 2024 laplace . All rights reserved.
 **/

#include <AST_Tree/Integer.hpp>

using namespace mylang::ast;

Integer::Integer(int64_t value) // 默认value为0
    : m_value(value), Statement(AST_Node::Type::NODE_INTEGER)
{
}

int64_t &Integer::value() { return m_value; }