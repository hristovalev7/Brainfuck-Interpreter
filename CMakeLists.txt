cmake_minimum_required(VERSION 3.26)
project(BrainfuckInterpreter)

set(CMAKE_CXX_STANDARD 17)

add_executable(BrainfuckInterpreter main.cpp
        Interpreter.cpp
        Interpreter.hpp
        Cell.cpp
        Cell.hpp
        HelperFunctions.cpp
        HelperFunctions.hpp)
