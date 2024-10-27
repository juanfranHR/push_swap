/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sw_moves_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juanhern <juanhern@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 20:37:32 by juanhern          #+#    #+#             */
/*   Updated: 2024/10/27 17:50:38 by juanhern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap_bonus.h"

void	sw_push_bonus(t_list **src, t_list **dest)
{
	t_list	*tmp_node;

	tmp_node = *src;
	*src = (*src)->next;
	ft_lstadd_front(dest, tmp_node);
}

void	sw_swap_bonus(t_list **src)
{
	t_list	*tmp;
	t_list	*second_node;

	tmp = *src;
	second_node = (*src)->next;
	tmp->next = second_node->next;
	*src = second_node;
	(*src)->next = tmp;
}

void	sw_rotate_bonus(t_list **src)
{
	t_list	*tmp_node;
	t_list	*last_node;

	tmp_node = *src;
	*src = (*src)->next;
	last_node = ft_lstlast(*src);
	tmp_node->next = NULL;
	last_node->next = tmp_node;
}

void	sw_reverse_rotate_bonus(t_list **src)
{
	t_list	*tmp_node;
	t_list	*last_node;

	tmp_node = ft_pre_lstlast(*src);
	last_node = ft_lstlast(*src);
	last_node->next = *src;
	*src = last_node;
	tmp_node->next = NULL;
}

void	sw_double_moves_bonus(char *move, t_list **stack_a, t_list **stack_b)
{
	if (ft_strnstr(MOVES_SW, move, ft_strlen(MOVES_SW)) == 0)
	{
		sw_swap_bonus(stack_a);
		sw_swap_bonus(stack_b);
	}
	else if (ft_strnstr(MOVES_ROT, move, ft_strlen(MOVES_ROT)) == 0)
	{
		sw_rotate_bonus(stack_a);
		sw_rotate_bonus(stack_b);
	}
	else if (ft_strnstr(MOVES_RROT, move, ft_strlen(MOVES_RROT)) == 0)
	{
		sw_reverse_rotate_bonus(stack_a);
		sw_reverse_rotate_bonus(stack_b);
	}
}
