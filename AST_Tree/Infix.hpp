/**
 * Created by laplace on 24-6-10.
 * Project: interpreter
 * Last Edit: 24-6-10-下午6:08
 * Copyright (c) 2024 laplace . All rights reserved.
 **/

#ifndef INTERPRETER_INFIX_HPP
#define INTERPRETER_INFIX_HPP
#include <AST_Tree/AST_Node.hpp>
#include <memory>
#include <string>

namespace mylang {
namespace ast {
class Infix : public Expression
{
public:
    Infix();
    ~Infix() override = default;
    std::string &getOperator();
    std::shared_ptr<Expression> &getLeft();
    std::shared_ptr<Expression> &getRight();

protected:
    std::string m_operator;
    std::shared_ptr<Expression> m_left;
    std::shared_ptr<Expression> m_right;
};
} // namespace ast
} // namespace mylang
#endif // INTERPRETER_INFIX_HPP
