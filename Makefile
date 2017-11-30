# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cfarnswo <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/07 14:16:37 by cfarnswo          #+#    #+#              #
#    Updated: 2017/11/29 17:06:13 by cfarnswo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

CC = gcc

CFLAGS = -Wall -Werror -Wextra

FILES =	tetlist			\
		map				\
		fillit			\
		placement		\
		readtetfile 	\
		validate1		\
		validate2		\
		trim			\
		trim1			\
		odd_fts			\

SRC = $(addsuffix .c, $(FILES))
OBJ = $(addsuffix .o, $(FILES))

all: $(NAME)

$(NAME):
	@make -C libft/ re
	@$(CC) $(CFLAGS) -c $(SRC) -I libft/
	@$(CC) $(CFLAGS) -o $(NAME) -I libft/ main.c $(OBJ) -L libft/ -lft

clean:
	@make -C libft/ fclean
	@/bin/rm -f $(OBJ)

fclean: clean
	@make -C libft/ fclean
	@/bin/rm -f $(NAME)

re: fclean all
