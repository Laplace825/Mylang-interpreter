/**
 * Created by laplace on 24-6-10.
 * Project: interpreter
 * Last Edit: 24-6-10-下午5:42
 * Copyright (c) 2024 laplace . All rights reserved.
 **/

#include <AST_Tree/AST_Node.hpp>
#include <map>
#include <string>

using namespace mylang::ast;
using namespace mylang::token;

std::map<AST_Node::Type, std::string> AST_Node::m_type_names = {
    {AST_Node::NODE_INTEGER, "integer"},
    {AST_Node::NODE_INFIX, "infix"},
    {AST_Node::NODE_EXPRESSION_STATEMENT, "expression statement"},
    {AST_Node::NODE_PROGRAM, "program"},
};

AST_Node::AST_Node() = default;

AST_Node::AST_Node(AST_Node::Type type) : m_type(type) {}

AST_Node::Type AST_Node::type() const { return m_type; }

std::string AST_Node::name() const
{
    auto find_name = m_type_names.find(m_type);
    if (find_name == m_type_names.end())
    {
        return "";
    }
    return find_name->second;
}

Expression::Expression(AST_Node::Type type) : AST_Node(type) {}

Statement::Statement(AST_Node::Type type) : AST_Node(type) {}
