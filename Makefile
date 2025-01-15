# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cwon <cwon@student.42bangkok.com>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/08 10:53:51 by cwon              #+#    #+#              #
#    Updated: 2025/01/15 13:17:24 by cwon             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

CC = cc
CFLAGS = -Wall -Werror -Wextra -O3

SRC = \
	fractol.c \
	hook.c \
	julia.c \
	main.c \
	mandelbrot.c
OBJ = $(SRC:.c=.o)

BONUS_SRC = \
	burning_ship_bonus.c \
	fractol_bonus.c \
	hook_bonus.c \
	julia_bonus.c \
	main_bonus.c \
	mandelbrot_bonus.c
BONUS_OBJ = $(BONUS_SRC:.c=.o)

%.o: %.c
	$(CC) $(CFLAGS) -I/usr/include -Iminilibx-linux -c $< -o $@

all: $(NAME)

$(NAME): $(OBJ)
	make -C libft
	$(CC) $(OBJ) -Lminilibx-linux -lmlx_Linux -L/usr/lib -Iminilibx-linux \
	-lXext -lX11 -lm -lz -o $(NAME) libft/libft.a

bonus: $(NAME)_bonus

$(NAME)_bonus: $(BONUS_OBJ)
	make -C libft
	$(CC) $(BONUS_OBJ) -Lminilibx-linux -lmlx_Linux -L/usr/lib -Iminilibx-linux \
	-lXext -lX11 -lm -lz -o $(NAME)_bonus libft/libft.a

clean:
	make clean -C libft
	rm -f $(OBJ) $(BONUS_OBJ)

fclean: clean
	make fclean -C libft
	rm -f $(NAME) $(NAME)_bonus

re: fclean all

.PHONY: all clean fclean re