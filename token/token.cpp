/**
 * Created by laplace on 24-6-9.
 * Project: interpreter
 * Last Edit: 24-6-9-下午2:52
 * Copyright (c) 2024 laplace . All rights reserved.
 **/

#include "token/token.hpp"

#include <format>

using namespace mylang::token;
using namespace yazi::json;

std::map<Token::Type, std::string> Token::m_names = {
    {TOKEN_ILLEGAL, "illegal"}, // 非法符号
    {TOKEN_EOF, "eof"},         // 文件结束
    {TOKEN_INTEGER, "integer"}, // integer
    {TOKEN_PLUS, "+"},          // +
    {TOKEN_MINUS, "-"},         // -
    {TOKEN_MUL, "*"},           // *
    {TOKEN_ASSIGN, "="},        // =
    {TOKEN_DIV, "/"},           // /
    {TOKEN_LPAREN, "("},        // (
    {TOKEN_RPAREN, ")"},        // )
    {TOKEN_SEMICOLON, ";"}      // ;
};

Token::Token() : m_type(TOKEN_ILLEGAL) {}

Token::Token(Token::Type type, const std::string &literal)
    : m_type(type), m_literal(literal)
{
}

Token::Type Token::type() const { return m_type; }

std::string Token::name() const
{
    auto findName = m_names.find(m_type);
    return findName != m_names.end() ? findName->second : "";
}

std::string Token::literal() const { return m_literal; }

Token &Token::operator=(Token other)
{
    std::swap(*this, other);
    return *this;
}

std::basic_string<char> Token::to_string() const
{
    return std::format("Token(type: {}, literal: \"{}\")", name(), literal());
}

Json Token::to_json() const
{
    Json json;
    json["type"] = name();
    json["literal"] = literal();
    return json;
}