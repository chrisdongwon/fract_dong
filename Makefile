# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cwon <cwon@student.42bangkok.com>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/08 10:53:51 by cwon              #+#    #+#              #
#    Updated: 2024/12/08 23:32:06 by cwon             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror -Iminilibx-linux -O3
src = $(wildcard *.c)

obj = $(src:.c=.o)

lib_dir = libft
lib_name = libft.a
lib_path = $(lib_dir)/$(lib_name)

NAME = fractol
header = fractol.h

all: $(lib_path) $(NAME)

bonus: all

$(lib_path):
	make -C $(lib_dir)

%.o: %.c $(header)
	$(CC) $(CFLAGS) -I/usr/include -c $< -o $@

$(NAME): $(src) $(obj) $(header) $(lib_path)
	$(CC) $(CFLAGS) $(obj) -Lminilibx-linux -lmlx_Linux -L/usr/lib -lXext -lX11 -lm -lz -o $(NAME) $(lib_path)

clean:
	make clean -C $(lib_dir)
	rm -f $(obj)

fclean: clean
	make fclean -C $(lib_dir)
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re libft bonus