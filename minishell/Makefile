# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lobertho <lobertho@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/11 16:59:33 by lobertho          #+#    #+#              #
#    Updated: 2023/09/12 13:49:06 by cgross           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = $(wildcard *.c)	\
	   $(wildcard */*.c)

OBJS = $(SRCS:.c=.o)

RD_REPLACE = -L $(HOME)/.brew/Cellar/readline/8.2.1/lib -I $(HOME)/.brew/Cellar/readline/8.2.1/include

NAME = minishell

CC = gcc

FLAGS = -Wall -Wextra -Werror -g -lreadline $(RD_REPLACE)
all: $(NAME)

$(NAME): $(OBJS)
					$(CC) $(FLAGS) $(SRCS) -g -o $(NAME)

clean:
					rm -f $(OBJS)

fclean: clean
					rm -f $(NAME)

re:	fclean all

.PHONY: all clean fclean re
