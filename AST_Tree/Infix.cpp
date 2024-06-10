/**
 * Created by laplace on 24-6-10.
 * Project: interpreter
 * Last Edit: 24-6-10-下午6:08
 * Copyright (c) 2024 laplace . All rights reserved.
 **/

#include <AST_Tree/Infix.hpp>
using namespace mylang::ast;

Infix::Infix()
    : Expression(AST_Node::Type::NODE_INFIX), m_left(nullptr), m_right(nullptr)
{
}

std::string& Infix::getOperator() { return m_operator; }

std::shared_ptr<Expression>& Infix::getLeft() { return m_left; }

std::shared_ptr<Expression>& Infix::getRight() { return m_right; }
