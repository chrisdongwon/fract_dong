# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cwon <cwon@student.42bangkok.com>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/08 10:53:51 by cwon              #+#    #+#              #
#    Updated: 2025/01/14 14:07:24 by cwon             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror -Iminilibx-linux -O3

src = \
	main.c \
	fractol.c \
	hook.c \
	mandelbrot.c \
	julia.c
obj = $(src:.c=.o)

bonus_src = \
	main_bonus.c \
	fractol_bonus.c \
	hook_bonus.c \
	mandelbrot_bonus.c \
	julia_bonus.c \
	burning_ship_bonus.c
bonus_obj = $(bonus_src:.c=.o)

lib_dir = libft
lib_name = libft.a
lib_path = $(lib_dir)/$(lib_name)

NAME = fractol
header = fractol.h
bonus_header = fractol_bonus.h

all: $(lib_path) $(NAME)

bonus: $(lib_path) $(bonus_name)

$(lib_path):
	make -C $(lib_dir)

%.o: %.c
	$(CC) $(CFLAGS) -I/usr/include -c $< -o $@

$(NAME): $(src) $(obj) $(header) $(lib_path)
	$(CC) $(CFLAGS) $(obj) -Lminilibx-linux -lmlx_Linux -L/usr/lib \
	-lXext -lX11 -lm -lz -o $(NAME) $(lib_path)

$(bonus_name): $(bonus_src) $(bonus_obj) $(bonus_header) $(lib_path)
	$(CC) $(CFLAGS) $(bonus_obj) -Lminilibx-linux -lmlx_Linux -L/usr/lib \
	-lXext -lX11 -lm -lz -o $(NAME) $(lib_path)

clean:
	make clean -C $(lib_dir)
	rm -f $(obj) $(bonus_obj)

fclean: clean
	make fclean -C $(lib_dir)
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re libft bonus