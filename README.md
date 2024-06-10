# Mylang-interpreter

**The English version is [here](./docs/README_en.md).**

基于C++的语言解释器学习,目的是创造一个解释器用于解释Mylang语言。

## 要求

很抱歉我并未测试其他版本，使用的话尽可能保持最新。
使用到了一些特性,例如`std::format` `std::println`,希望这样能帮助你决定`C++`标准。
这里我列出了一些开发环境的要求：

- `C++23` or higher
- `CMake` 3.28 or higher
- `clang-cl` 18.1.x or higher (Windows)
- `clang-format` 18.x.x or higher (optional)

## TODO

- [ ] 实现一些基本数据类型及运算
- [ ] 实现一些基本控制结构
- [ ] 实现一些基本函数
- [ ] 实现一些内建函数

## 参考 & 使用的开源工具

- [A tiny c++ json parser](https://github.com/sukai33/yazi-json)
- [Very fast, header-only/compiled, C++ logging library](https://github.com/gabime/spdlog/tree/v1.x)
