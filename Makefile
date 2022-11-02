# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aderouba <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/26 12:24:51 by aderouba          #+#    #+#              #
#    Updated: 2022/11/02 17:21:03 by aderouba         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

SRC =	fdf.c

OBJ = ${SRC:.c=.o}

CC = cc
CFLAGS = -g -Wall -Wextra -Werror
INCLUDE = -I .

%.o : %.c
	$(CC) $(CFLAGS) -o $@ -c $< $(INCLUDE)

$(NAME) : $(OBJ)
	$(CC) $(CFLAGS) $@ $^

all : $(NAME)

clean :
	rm -f $(OBJ)

fclean : clean
	rm -f $(NAME)

re : fclean $(NAME)

.PHONY: all clean fclean re
