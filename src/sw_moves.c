/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sw_moves.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juanhern <juanhern@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 20:37:32 by juanhern          #+#    #+#             */
/*   Updated: 2024/10/26 19:24:40 by juanhern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sw_push(t_list **src, t_list **dest, char stack)
{
	t_list	*tmp_node;

	tmp_node = *src;
	*src = (*src)->next;
	ft_lstadd_front(dest, tmp_node);
	if (stack == 'a')
		ft_putendl_fd("pa", STDOUT_FILENO);
	else
		ft_putendl_fd("pb", STDOUT_FILENO);
}

void	sw_swap(t_list **header, char stack)
{
	t_list	*tmp;
	t_list	*second_node;

	tmp = *header;
	second_node = (*header)->next;
	tmp->next = second_node->next;
	*header = second_node;
	(*header)->next = tmp;
	if (stack == 'a')
		ft_putendl_fd("sa", STDOUT_FILENO);
	else if (stack == 'b')
		ft_putendl_fd("sb", STDOUT_FILENO);
}

void	sw_rotate(t_list **src, char stack)
{
	t_list	*tmp_node;
	t_list	*last_node;

	tmp_node = *src;
	*src = (*src)->next;
	last_node = ft_lstlast(*src);
	tmp_node->next = NULL;
	last_node->next = tmp_node;
	if (stack == 'a')
		ft_putendl_fd("ra", STDOUT_FILENO);
	else if (stack == 'b')
		ft_putendl_fd("rb", STDOUT_FILENO);
}

void	sw_reverse_rotate(t_list **src, char stack)
{
	t_list	*tmp_node;
	t_list	*last_node;

	tmp_node = ft_pre_lstlast(*src);
	last_node = ft_lstlast(*src);
	last_node->next = *src;
	*src = last_node;
	tmp_node->next = NULL;
	if (stack == 'a')
		ft_putendl_fd("rra", STDOUT_FILENO);
	else if (stack == 'b')
		ft_putendl_fd("rrb", STDOUT_FILENO);
}
