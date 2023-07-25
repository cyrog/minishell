# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cgross <cgross@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/11 16:59:33 by lobertho          #+#    #+#              #
#    Updated: 2023/07/25 15:50:15 by cgross           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = main.c ft_split.c utils.c free.c cmd_path.c parsing.c parsing_utils.c \
tokenizer.c tokenizer_utils.c lists.c get_quote.c get.c redirection.c

OBJS = $(SRCS:.c=.o)

NAME = minishell

CC = gcc

FLAGS = -Wall -Wextra -Werror -lreadline
all: $(NAME)

$(NAME): $(OBJS)
					$(CC) $(FLAGS) $(SRCS) -g -o $(NAME)

clean:
					rm -f $(OBJS)

fclean: clean
					rm -f $(NAME)

re:	fclean all

.PHONY: all clean fclean re
