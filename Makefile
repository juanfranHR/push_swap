# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: juanhern <juanhern@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/30 17:35:32 by juanhern          #+#    #+#              #
#    Updated: 2024/09/01 11:42:44 by juanhern         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = push_swap
LIBFT = ./libft/libft.a
SRC_FILES = src/main.c src/moves.c src/radix_sort.c src/utils.c src/input_checker.c

OBJS = $(SRC_FILES:.c=.o)

all: $(NAME)

$(LIBFT):
	make -C libft
	make clean -C libft

$(NAME): $(LIBFT) $(OBJS)
	$(CC) $(CFLAGS) $(SRC_FILES) -L ./libft -lft -o $(NAME)

clean:
	rm -f $(OBJS) 

fclean: clean
	rm -f $(NAME)

.PHONY: all clean fclean re bonus