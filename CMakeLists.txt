cmake_minimum_required(VERSION 3.8)
project(ft_select)

set(CMAKE_C_STANDARD 99)

set(SOURCE_FILES
        includes/ft_select.h
        srcs/main.c
        srcs/util_mode_terminal.c
        )

add_executable(ft_select ${SOURCE_FILES})