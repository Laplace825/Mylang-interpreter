/**
 * Created by laplace on 24-6-10.
 * Project: interpreter
 * Last Edit: 24-6-10-下午6:26
 * Copyright (c) 2024 laplace . All rights reserved.
 **/

#ifndef INTERPRETER_PROGRAM_HPP
#define INTERPRETER_PROGRAM_HPP

#include <AST_Tree/AST_Node.hpp>
#include <list>
#include <memory>

namespace mylang {
namespace ast {
class Program : public Statement
{
public:
    Program();
    ~Program() override = default;
    std::list<std::shared_ptr<Statement>> &statements();

protected:
    std::list<std::shared_ptr<Statement>> m_statements;
};
} // namespace ast
} // namespace mylang
#endif // INTERPRETER_PROGRAM_HPP
