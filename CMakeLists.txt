cmake_minimum_required(VERSION 3.8)
project(ft_select)

set(CMAKE_C_STANDARD 99)

set(SOURCE_FILES srcs/main.c includes/ft_select.h)
add_executable(ft_select ${SOURCE_FILES})