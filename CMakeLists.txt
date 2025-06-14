cmake_minimum_required(VERSION 3.16)
project(cpp_cmake_clang_ninja_template LANGUAGES CXX)

set(CMAKE_CXX_COMPILER clang++)
set(CMAKE_CXX_STANDARD 17)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

include_directories(src)

add_executable(CppCmakeClangNinjaTemplate src/main.cpp src/Logger.cpp)

