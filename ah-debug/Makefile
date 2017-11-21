# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cfarnswo <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/07 14:16:37 by cfarnswo          #+#    #+#              #
#    Updated: 2017/11/20 17:33:15 by aho              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

CC = gcc

CFLAGS = -Wall -Werror -Wextra -g

FILES =	placement	\
		placement2	\
		fillit		\
		tetlist		\
		move		\
		map			\
		readtetfile \
		validate	\
		trim		\
		odd_fts		\

SRC = $(addsuffix .c, $(FILES))
OBJ = $(addsuffix .o, $(FILES))

all: $(NAME)

$(NAME):
	@make -C libft/ re
	@$(CC) $(CFLAGS) -c $(SRC) -I libft/
	@$(CC) $(CFLAGS) -o $(NAME) main.c $(OBJ) -L libft/ -lft

clean:
	@make -C libft/ fclean
	@/bin/rm -f $(OBJ)

fclean: clean
	@make -C libft/ fclean
	@/bin/rm -f $(NAME)
	@/bin/rm -f *.c~ *.h~ *.txt~ Makefile~
	@/bin/rm -rf *.dSYM

re: fclean all
