# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cdavila <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/08/01 11:34:55 by cdavila           #+#    #+#              #
#    Updated: 2016/08/01 11:35:03 by cdavila          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = bsq

SRC = bsq.c \
		basics.c \
		readargv.c \
		maputils.c \
		error_check.c \
		ft_list.c \
		readstdin.c \
		dpsolve.c \
		final_map.c

CC = gcc

FLAGS = -Wall -Werror -Wextra

INCLUD = ft_head.h

all: $(NAME)

$(NAME):
	$(CC) $(FLAGS) $(SRC) -I$(INCLUD) -o $(NAME)

clean:
	/bin/rm $(NAME)

fclean: clean

re: fclean all

