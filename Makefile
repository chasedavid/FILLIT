# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cfarnswo <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/07 14:16:37 by cfarnswo          #+#    #+#              #
#    Updated: 2017/11/14 20:23:24 by aho              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

CC = gcc

CFLAGS = -Wall -Werror -Wextra

FILES =	placement	\
		fillit		\
		tetlist		\
		move		\
		map			\
		readtetfile \
		odd_fts		\
		isvalidpiece\
		trimtets	\

SRC = $(addsuffix .c, $(FILES))
OBJ = $(addsuffix .o, $(FILES))

all: $(NAME)

$(NAME):
	make -C libft/ re
	$(CC) $(CFLAGS) -c $(SRC) -I libft/ fillit.h
	$(CC) $(CFLAGS) -o $(NAME) main.c $(OBJ) -L libft/ -lft

clean:
	make -C libft/ fclean
	/bin/rm -f $(OBJ)

fclean: clean
	make -C libft/ fclean
	/bin/rm -f $(NAME)
	/bin/rm -f *.c~ *.h~

re: fclean all
