# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aderouba <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/26 12:24:51 by aderouba          #+#    #+#              #
#    Updated: 2022/11/03 11:33:03 by aderouba         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

MAKEFLAGS = --no-print-directory

NAME = fdf

SRC =	fdf.c

OBJ = ${SRC:.c=.o}

CC = cc
CFLAGS = -g -Wall -Wextra -Werror
LIBFLAGS = -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz
LIBFTFLAGS = -Llibft -lft
INCLUDES = -I. -I/usr/include -Imlx_linux -Ilibft

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -O3 -c $< -o $@

$(NAME): $(OBJ)
	@cd libft && make
	$(CC) $^ $(LIBFLAGS) $(LIBFTFLAGS) -o $@

all : $(NAME)

clean :
	@cd libft && make clean
	rm -f $(OBJ)

fclean : clean
	@cd libft && make fclean
	rm -f $(NAME)

re : fclean $(NAME)
	@cd libft && make re

.PHONY: all clean fclean re
