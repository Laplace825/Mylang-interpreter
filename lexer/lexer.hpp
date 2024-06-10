/**
 * Created by laplace on 24-6-9.
 * Project: interpreter
 * Last Edit: 24-6-9-下午3:01
 * Copyright (c) 2024 laplace . All rights reserved.
 **/

#ifndef INTERPRETER_LEXER_HPP
#define INTERPRETER_LEXER_HPP

#include <token/Token.hpp>

namespace mylang {

namespace lexer {

class Lexer // 词法分析器
{
public:
    Lexer();
    explicit Lexer(const std::string &file);
    ~Lexer() = default;

    mylang::token::Token next_token();
    std::basic_string<char> to_string() const;

protected:
    std::string m_input; // 输入的代码内容
    char m_ch;           // 当前遍历的字符
    size_t m_pos;        // 当前遍历的位置
    size_t m_next_pos;   // 下一个位置

    void skip_white_space(); // 忽略空白符
    void read_char();        // 读取下一个字符
    void unread_char();
    static bool is_digital(char ch); // ch 是不是数字
    std::string read_number();
    static mylang::token::Token new_token(mylang::token::Token::Type type,
                                          const std::string &literal);

}; // class Lexer
} // namespace lexer
} // namespace mylang
#endif // INTERPRETER_LEXER_HPP
