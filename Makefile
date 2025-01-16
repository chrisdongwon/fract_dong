# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cwon <cwon@student.42bangkok.com>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/08 10:53:51 by cwon              #+#    #+#              #
#    Updated: 2025/01/16 18:31:29 by cwon             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol
MANDATORY_EXEC = fractol_mandatory
BONUS_EXEC = fractol_bonus

CC = cc
CFLAGS = -Wall -Werror -Wextra -O3

LIBFT = libft/libft.a

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

all: $(MANDATORY_EXEC)
	@ln -sf $(MANDATORY_EXEC) $(NAME)

$(MANDATORY_EXEC): $(OBJ) $(LIBFT)
	$(CC) $(OBJ) -Lminilibx-linux -lmlx_Linux -L/usr/lib -Iminilibx-linux \
	-lXext -lX11 -lm -lz $(LIBFT) -o $(MANDATORY_EXEC) 

bonus: $(BONUS_EXEC)
	@ln -sf $(BONUS_EXEC) $(NAME)

$(BONUS_EXEC): $(BONUS_OBJ) $(LIBFT)
	$(CC) $(BONUS_OBJ) -Lminilibx-linux -lmlx_Linux -L/usr/lib -Iminilibx-linux \
	-lXext -lX11 -lm -lz $(LIBFT) -o $(BONUS_EXEC)

%.o: %.c
	$(CC) $(CFLAGS) -I/usr/include -Iminilibx-linux -c $< -o $@

$(LIBFT):
	make -C libft

clean:
	make clean -C libft
	rm -f $(OBJ) $(BONUS_OBJ)

fclean: clean
	make fclean -C libft
	rm -f $(MANDATORY_EXEC) $(BONUS_EXEC) $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus