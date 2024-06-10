/**
 * Created by laplace on 24-6-10.
 * Project: interpreter
 * Last Edit: 24-6-10-下午6:04
 * Copyright (c) 2024 laplace . All rights reserved.
 **/

#ifndef INTERPRETER_INTEGER_HPP
#define INTERPRETER_INTEGER_HPP
#include <AST_Tree/AST_Node.hpp>

namespace mylang {
namespace ast {
class Integer : public Statement
{
public:
    Integer(int64_t value = 0);
    ~Integer() override = default;
    int64_t& value(); // access the value of the integer

protected:
    int64_t m_value; // 64-bit integer
};

} // namespace ast

} // namespace mylang

#endif // INTERPRETER_INTEGER_HPP
