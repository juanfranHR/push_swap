/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juanhern <juanhern@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 17:35:19 by juanhern          #+#    #+#             */
/*   Updated: 2024/09/01 16:57:52 by juanhern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>
# include "../libft/libft.h"

# ifndef VALID_CHAR
#  define VALID_CHAR "0123456789+-"
# endif

int get_max_stack(t_list *stack);
int get_min_stack(t_list *stack);
t_list	*ft_pre_lstlast(t_list *lst);
void add_min(t_list *stack, int min);
void substract_min(t_list *stack, int min);
void push(t_list **src, t_list **dest, char stack);
void swap(t_list **header, char stack);
void rotate(t_list **src, char stack);
void reverse_rotate(t_list **src, char stack);
void pw_validate_input(int argc, char* argv[], t_list **stack_a);
void print_stack(t_list **header);
#endif