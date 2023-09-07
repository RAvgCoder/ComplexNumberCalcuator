cmake_minimum_required(VERSION 3.26)
project(ComplexNumberCalcuator C)

set(CMAKE_C_STANDARD 11)

add_executable(ComplexNumberCalcuator main.c
        Complex.c
        Complex.h)
