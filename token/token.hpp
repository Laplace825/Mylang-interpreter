/**
 * Created by laplace on 24-6-9.
 * Project: interpreter
 * Last Edit: 24-6-9-下午2:54
 * Copyright (c) 2024 laplace . All rights reserved.
 **/

#ifndef INTERPRETER_TOKEN_HPP
#define INTERPRETER_TOKEN_HPP

#include <json/Json.hpp>
#include <map>
#include <string>

namespace mylang {

namespace token {
class Token
{
public:
    enum Type
    {
        TOKEN_EOF = -1,    // 文件结束
        TOKEN_ILLEGAL = 0, // 非法符号
        TOKEN_INTEGER,     // integer
        TOKEN_PLUS,        // +
        TOKEN_MINUS,       // -
        TOKEN_MUL,         // *
        TOKEN_ASSIGN,      // =
        TOKEN_DIV,         // /
        TOKEN_LPAREN,      // (
        TOKEN_RPAREN,      // )
        TOKEN_SEMICOLON,   // ;
    };

    Token();

    explicit Token(Type type, const std::string &literal);

    ~Token() = default;

    Type type() const;

    std::string name() const;

    std::string literal() const;

    Token &operator=(Token other);

    std::basic_string<char> to_string() const;
    yazi::json::Json to_json() const;

protected:
    Type m_type;
    std::string m_literal;
    static std::map<Type, std::string> m_names;
};
}; // namespace token

} // namespace mylang

#endif // INTERPRETER_TOKEN_HPP
