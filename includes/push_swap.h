/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juanhern <juanhern@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 17:35:19 by juanhern          #+#    #+#             */
/*   Updated: 2024/10/26 19:25:16 by juanhern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "../libft/libft.h"
# include <fcntl.h>
# include <limits.h>
# include <stdlib.h>

# ifndef VALID_CHAR
#  define VALID_CHAR "0123456789"
# endif

# ifndef VALID_START_CHAR
#  define VALID_START_CHAR "0123456789+-"
# endif

int		get_digits(t_list **stack);
int		get_max_stack(t_list **stack);
t_list	*ft_pre_lstlast(t_list *lst);
void	sw_push(t_list **src, t_list **dest, char stack);
void	sw_swap(t_list **header, char stack);
void	sw_double_swap(t_list **header_a, t_list **header_b);
void	sw_rotate(t_list **src, char stack);
void	sw_double_rotate(t_list **src_a, t_list **src_b);
void	sw_reverse_rotate(t_list **src, char stack);
void	sw_double_reverse_rotate(t_list **src_a, t_list **src_b);
int		sw_validate_inputs(int argc, char *argv[], t_list **stack_a);
void	del_content(void *content);
void	sw_clear_stack(t_list **stack_a);
void	index_stack(t_list **header);
void	sw_sort_3(t_list **stack_a);
int		is_sorted(t_list **stack_header);
int		is_int(char *argv);
void	sw_sort_4_5(t_list **stack_a, t_list **stack_b);
void	sw_sort(t_list **stack_a, t_list **stack_b);
long	ft_atol(const char *str);
#endif