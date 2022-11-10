# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aderouba <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/26 12:24:51 by aderouba          #+#    #+#              #
#    Updated: 2022/11/10 09:09:05 by aderouba         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

MAKEFLAGS = --no-print-directory

NAME = fdf

SRC =	mandatory/fdf.c \
		mandatory/draw_utils.c \
		mandatory/parsing.c \
		mandatory/parsing2.c \
		mandatory/color.c \
		mandatory/projection.c \
		mandatory/utils.c

SRC_BONUS =	bonus/fdf_bonus.c \
			bonus/draw_utils_bonus.c \
			bonus/parsing_bonus.c \
			bonus/parsing2_bonus.c \
			bonus/color_bonus.c \
			bonus/projection_bonus.c \
			bonus/utils_bonus.c \
			bonus/space_operation_iso_bonus.c \
			bonus/space_rotation_iso_bonus.c \
			bonus/utils_iso_bonus.c \
			bonus/menu_bonus.c

OBJ = ${SRC:.c=.o}
ifdef BONUS
	OBJ = ${SRC_BONUS:.c=.o}
endif
OBJ_BONUS = ${SRC_BONUS:.c=.o}

CC = clang
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
	rm -f $(OBJ) $(OBJ_BONUS)

fclean : clean
	@cd libft && make fclean
	rm -f $(NAME)

re : fclean $(NAME)
	@cd libft && make re

bonus :
	@make BONUS=42

.PHONY: all clean fclean re bonus
