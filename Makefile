# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: juanhern <juanhern@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/30 17:35:32 by juanhern          #+#    #+#              #
#    Updated: 2024/09/08 21:22:19 by juanhern         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = push_swap
LIBFT = ./libft/libft.a
SRC_FILES = src/main.c src/sw_moves.c src/sw_sort.c src/sw_utils.c src/sw_input_checker.c src/ft_atol.c src/sw_clear_stack.c src/sw_index_stack.c

OBJS = $(SRC_FILES:.c=.o)

all: $(NAME) $(LIBFT)

$(LIBFT):
	make -C libft
	make clean -C libft

$(NAME): $(LIBFT) $(OBJS)
	$(CC) $(CFLAGS) $(SRC_FILES) -L ./libft -lft -o $(NAME)

clean:
	rm -f $(OBJS) 

fclean: clean
	rm -f $(NAME)

.PHONY: all clean fclean re