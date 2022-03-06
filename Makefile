# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rraffat <rraffat@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/18 11:36:30 by rraffat           #+#    #+#              #
#    Updated: 2022/03/01 06:17:26 by rraffat          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex

CC = clang

CFLAGS = -Wall -Wextra -Werror

HEADER = pipex.h

SRC = pipex.c helper.c

OBJ = $(SRC:c=o)

all: $(NAME)

$(NAME): $(OBJ)
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJ)

%.o: %.c
	@${CC} ${CFLAGS} -c $< -o $@

clean:
	@rm -f $(OBJ)

fclean:
	@rm -f $(OBJ)
	@rm -f $(NAME)

re: fclean all

.PHONY: clean fclean re bonus
