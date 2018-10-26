cmake_minimum_required(VERSION 3.12)
project(cpplisp)

set(CMAKE_CXX_STANDARD 14)

include_directories(lib/)

add_executable(lisp tests/unit-test.cpp lib/cpplisp.cpp lib/cpplisp.hpp)