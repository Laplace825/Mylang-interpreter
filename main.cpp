/**
 * Created by laplace on 24-6-8.
 * Project: interpreter
 * Last Edit: 24-6-9-下午2:52
 * Copyright (c) 2024 laplace . All rights reserved.
 **/

#include <filesystem>
#include <fstream>
#include <json/Json.hpp>
#include <lexer/lexer.hpp>
#include <print>

using namespace mylang::lexer;
using namespace mylang::token;
using namespace yazi::json;

auto main() -> int
{
    using std::println;
    // 获取当前可执行文件的路径
    Lexer lexer("../plus.helang");
    Json json;
    while (true)
    {
        auto token = lexer.next_token();
        if (token.type() == Token::Type::TOKEN_EOF)
        {
            break;
        }
        json.append(token.to_json());
        println("{}", token.to_string());
    }

    std::ofstream ofs("../output.json");
    ofs << json.str();
    ofs.close();

    return 0;
}
