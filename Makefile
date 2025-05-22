# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sabouelk <sabouelk@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/06 11:01:49 by sabouelk          #+#    #+#              #
#    Updated: 2025/05/06 11:10:39 by sabouelk         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CC = CC
CFLAGS = -Wall -Wextar -Werror

SRCS = main.c \ operations.c \ parsing.c \ algorithm.c \ maintenace.c 
OBJS = $(SRCS:.c=.o)

all:$(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.phony: all clean fclean re