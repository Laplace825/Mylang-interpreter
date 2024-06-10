/**
 * Created by laplace on 24-6-10.
 * Project: interpreter
 * Last Edit: 24-6-10-下午5:31
 * Copyright (c) 2024 laplace . All rights reserved.
 **/

#ifndef INTERPRETER_AST_NODE_HPP
#define INTERPRETER_AST_NODE_HPP

#include <map>
#include <string>
#include <token/Token.hpp>

namespace mylang {
namespace ast {
class AST_Node
{
public:
    enum Type
    {
        NODE_INTEGER = 0,
        NODE_INFIX,                // 中缀表达式
        NODE_EXPRESSION_STATEMENT, // 表达式语句
        NODE_PROGRAM,              // 程序根节点
    };

    AST_Node();
    explicit AST_Node(Type type);
    virtual ~AST_Node() = default;

    Type type() const;
    std::string name() const;

protected:
    Type m_type;
    mylang::token::Token m_token;
    static std::map<Type, std::string> m_type_names;
};

class Expression : public AST_Node
{
public:
    Expression() = default;
    explicit Expression(Type type);
    virtual ~Expression() = default;
};

class Statement : public AST_Node
{
public:
    Statement() = default;
    explicit Statement(Type type);
    virtual ~Statement() = default;
};

} // namespace ast
} // namespace mylang
#endif // INTERPRETER_AST_NODE_HPP
