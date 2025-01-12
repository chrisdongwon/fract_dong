# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cwon <cwon@student.42bangkok.com>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/03 16:52:39 by cwon              #+#    #+#              #
#    Updated: 2025/01/12 12:50:18 by cwon             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror

src = \
	ft_abs.c \
	ft_isascii.c \
	ft_lstadd_back.c \
	ft_lstsize.c \
	ft_putendl_fd.c \
	ft_strlcat.c \
	ft_substr.c \
	ft_atof.c \
	ft_isdigit.c \
	ft_lstadd_front.c \
	ft_memchr.c \
	ft_putnbr_fd.c \
	ft_strlcpy.c \
	ft_tolower.c \
	ft_atoi.c \
	ft_isinteger.c \
	ft_lstclear.c \
	ft_memcmp.c \
	ft_putstr_fd.c \
	ft_strlen.c \
	ft_toupper.c \
	ft_bzero.c \
	ft_ismember.c \
	ft_lstdelone.c \
	ft_memcpy.c \
	ft_split.c \
	ft_strmapi.c \
	ft_utoa.c \
	ft_calloc.c \
	ft_isprint.c \
	ft_lstiter.c \
	ft_memmove.c \
	ft_strchr.c \
	ft_strncmp.c \
	ft_greater_than.c \
	ft_isspace.c \
	ft_lstlast.c \
	ft_memset.c \
	ft_strdup.c \
	ft_strnstr.c \
	ft_isalnum.c \
	ft_itoa.c \
	ft_lstmap.c \
	ft_striteri.c \
	ft_strrchr.c \
	ft_isalpha.c \
	ft_less_than.c \
	ft_lstnew.c \
	ft_putchar_fd.c \
	ft_strjoin.c \
	ft_strtrim.c \
	ft_printf/convert.c \
	ft_printf/convert_literal.c \
	ft_printf/convert_pointer.c \
	ft_printf/ft_printf.c \
	ft_printf/pad.c \
	ft_printf/convert_hex.c \
	ft_printf/convert_numeric.c \
	ft_printf/extract.c
obj = $(src:.c=.o)

NAME = libft.a

all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(obj)
	ar -rcs $(NAME) $(obj)

clean:
	rm -f $(obj)

fclean: clean 
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re