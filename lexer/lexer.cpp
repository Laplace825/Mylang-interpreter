/**
 * Created by laplace on 24-6-9.
 * Project: interpreter
 * Last Edit: 24-6-9-下午3:01
 * Copyright (c) 2024 laplace . All rights reserved.
 **/

#include <format>
#include <fstream>
#include <lexer/lexer.hpp>
#include <print>
#include <sstream>
#include <token/Token.hpp>

using namespace mylang::lexer;
using namespace mylang::token;

Lexer::Lexer() = default;
Lexer::Lexer(const std::string &file) : m_ch(0), m_pos(0), m_next_pos(0)
{
    std::ifstream ifs(file);
    if (!ifs.good())
    {
        throw std::runtime_error("\033[1;31mfile not Found\033[0m");
    }

    std::ostringstream oss;
    oss << ifs.rdbuf();
    m_input = oss.str();
    ifs.close();
}

Token Lexer::next_token()
{
    read_char();
    skip_white_space();
    auto NewToken = [this](Token::Type type) -> Token {
        return new_token(type, std::format("{}", m_ch));
    };
    switch (m_ch)
    {
        case '+': return NewToken(Token::Type::TOKEN_PLUS);
        case '-': return NewToken(Token::Type::TOKEN_MINUS);
        case '*': return NewToken(Token::Type::TOKEN_MUL);
        case '/': return NewToken(Token::Type::TOKEN_DIV);
        case '(': return NewToken(Token::Type::TOKEN_LPAREN);
        case ')': return NewToken(Token::Type::TOKEN_RPAREN);
        case '=': return NewToken(Token::Type::TOKEN_ASSIGN);
        case ';': return NewToken(Token::Type::TOKEN_SEMICOLON);
        case -1: return NewToken(Token::Type::TOKEN_EOF);
        default: {
            if (is_digital(m_ch))
            {
                std::string num = read_number();
                unread_char(); // 回退一个字符,因为数字可能是标识符的开头
                return new_token(Token::Type::TOKEN_INTEGER, num);
            }
            else
            {
                return NewToken(Token::Type::TOKEN_ILLEGAL);
            }
        }
    }
}

void Lexer::skip_white_space()
{
    /**
     * @description: 跳过空白字符,拿到第一个非空白字符
     */
    auto is_space = [](char ch) -> bool {
        return ch == ' ' || ch == '\t' || ch == '\n' || ch == '\r';
    };
    while (is_space(m_ch))
    {
        read_char();
    }
}

void Lexer::read_char()
{
    /**
     * @description: 读取下一个字符
     */
    if (m_input.empty()) throw std::runtime_error("input is empty");
    if (m_next_pos >= m_input.size())
    {
        m_ch = Token::Type::TOKEN_EOF;
    }
    else
    {
        m_ch = m_input[m_next_pos];
    }
    m_pos = m_next_pos;
    m_next_pos++;
}

void Lexer::unread_char()
{
    /**
     * @description: 回退一个字符
     */
    if (m_pos == 0) throw std::runtime_error("already at the beginning");
    m_next_pos = m_pos;
    m_pos--;
}

bool Lexer::is_digital(char ch) { return ch >= '0' && ch <= '9'; }

std::string Lexer::read_number()
{
    /**
     * @description: 读取单个数字
     */
    size_t pos = m_pos;
    while (is_digital(m_ch))
    {
        read_char();
    }
    return m_input.substr(pos, m_pos - pos);
}

Token Lexer::new_token(Token::Type type, const std::string &literal)
{
    return Token{type, literal};
}

std::basic_string<char> Lexer::to_string() const
{
    return std::format("Lexer(pos:{}, ch:{}, next_pos:{})", m_pos, m_ch,
                       m_next_pos);
}
