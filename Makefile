# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: juanhern <juanhern@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/30 17:35:32 by juanhern          #+#    #+#              #
#    Updated: 2024/10/27 14:04:13 by juanhern         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror -g
NAME = push_swap
NAME_BONUS = checker
LIBFT = ./libft/libft.a
SRC_FILES = src/main.c src/sw_moves.c src/sw_sort.c src/sw_utils.c src/sw_input_checker.c src/ft_atol.c src/sw_clear_stack.c src/sw_index_stack.c

BONUS_FILES = bonus/sw_checker_bonus.c bonus/sw_moves_bonus.c src/sw_utils.c src/sw_input_checker.c\
src/ft_atol.c src/sw_clear_stack.c src/sw_index_stack.c

OBJS = $(SRC_FILES:.c=.o)
OBJS_BONUS = $(BONUS_FILES:.c=.o)

all: $(NAME) $(LIBFT)

$(LIBFT):
	make -C libft
	make clean -C libft

$(NAME): $(LIBFT) $(OBJS)
	$(CC) $(CFLAGS) $(SRC_FILES) -L ./libft -lft -o $(NAME)

bonus: $(OBJS_BONUS)
	$(CC) $(CFLAGS) $(BONUS_FILES) -L ./libft -lft -o $(NAME_BONUS)

clean:
	rm -f $(OBJS) 
	rm -f $(OBJS_BONUS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re