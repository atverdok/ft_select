cmake_minimum_required(VERSION 3.8)
project(ft_select)

set(CMAKE_C_STANDARD 99)

set(SOURCE_FILES
        includes/ft_select.h
        srcs/main.c
        srcs/util_mode_terminal.c
        )

add_executable(ft_select ${SOURCE_FILES})
#target_link_libraries(ft_select ${CMAKE_SOURCE_DIR}/libft/libft.a)
target_link_libraries(ft_select ${CMAKE_SOURCE_DIR}/libft/libft.a -lncurses -ltermcap)