/**
 * Created by laplace on 24-6-10.
 * Project: interpreter
 * Last Edit: 24-6-10-下午6:33
 * Copyright (c) 2024 laplace . All rights reserved.
 **/

#ifndef INTERPRETER_EXPRESSIONSTATEMENT_HPP
#define INTERPRETER_EXPRESSIONSTATEMENT_HPP
#include <AST_Tree/AST_Node.hpp>
#include <memory>

namespace mylang::ast {
class ExpressionStatement : public Statement
{
public:
    ExpressionStatement();
    ~ExpressionStatement() override = default;
    std::shared_ptr<Expression>& expr();

protected:
    std::shared_ptr<Expression> m_expr;
};
}; // namespace mylang::ast
#endif // INTERPRETER_EXPRESSIONSTATEMENT_HPP
