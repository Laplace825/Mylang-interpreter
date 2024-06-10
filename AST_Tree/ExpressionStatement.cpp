/**
 * Created by laplace on 24-6-10.
 * Project: interpreter
 * Last Edit: 24-6-10-下午6:33
 * Copyright (c) 2024 laplace . All rights reserved.
 **/

#include <AST_Tree/ExpressionStatement.hpp>
using namespace mylang::ast;

ExpressionStatement::ExpressionStatement()
    : Statement(AST_Node::Type::NODE_EXPRESSION_STATEMENT), m_expr(nullptr)
{
}
