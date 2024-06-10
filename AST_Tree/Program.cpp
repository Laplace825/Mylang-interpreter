/**
 * Created by laplace on 24-6-10.
 * Project: interpreter
 * Last Edit: 24-6-10-下午6:26
 * Copyright (c) 2024 laplace . All rights reserved.
 **/

#include <AST_Tree/Program.hpp>
using namespace mylang::ast;

Program::Program() : Statement(AST_Node::Type::NODE_PROGRAM), m_statements() {}

std::list<std::shared_ptr<Statement>> &Program::statements() {
    return m_statements;
}
