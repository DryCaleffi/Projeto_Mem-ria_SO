cmake_minimum_required(VERSION 3.29)
project(S_O C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(S_O
        funcao.c
    main.c
        funcao.h)
