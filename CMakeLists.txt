cmake_minimum_required(VERSION 3.6)
project(fillit)

#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
#set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -g -fsanitize=address -Wall -Werror -Wextra")
#set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -g -fsanitize=address")
#set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Werror -Wextra")
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -D_DEBUG")

set(SOURCE_FILES
    ft_bzero.c
    ft_console.c
    ft_exit_error.c
    ft_ptest.c
    ft_putchar.c
    ft_putnstr.c
    ft_putstr.c
    ft_readfile.c
    ft_smart_validator.c
    ft_strcpy.c
    ft_strncpy.c
    ft_strnew.c
    ft_tetro_splitter.c
    ft_validator.c
	ft_tetriminos.c
	ft_grid.c
	ft_putgrid.c
	ft_tetro_move.c
	ft_border.c
	ft_fillit.c
    libft.h
    main.c)

add_executable(fillit ${SOURCE_FILES})