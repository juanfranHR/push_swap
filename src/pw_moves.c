/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pw_moves.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juanhern <juanhern@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 20:37:32 by juanhern          #+#    #+#             */
/*   Updated: 2024/09/05 14:04:34 by juanhern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	push(t_list **src, t_list **dest, char stack)
{
	t_list	*tmp_node;

	tmp_node = *src;
	*src = (*src)->next;
	ft_lstadd_front(dest, tmp_node);
	if (stack == 'a')
		ft_putstr_fd("pa\n", 1);
	else
		ft_putstr_fd("pb\n", 1);
}

void	swap(t_list **header, char stack)
{
	t_list	*tmp;
	t_list	*second_node;

	tmp = *header;
	second_node = (*header)->next;
	tmp->next = second_node->next;
	*header = second_node;
	(*header)->next = tmp;
	if (stack == 'a')
		ft_putstr_fd("sa\n", 1);
	else if (stack == 'b')
		ft_putstr_fd("sb\n", 1);
	else
		ft_putstr_fd("ss\n", 1);
}

void	rotate(t_list **src, char stack)
{
	t_list	*tmp_node;
	t_list	*last_node;

	tmp_node = *src;
	*src = (*src)->next;
	last_node = ft_lstlast(*src);
	tmp_node->next = NULL;
	last_node->next = tmp_node;
	if (stack == 'a')
		ft_putstr_fd("ra\n", 1);
	else if (stack == 'b')
		ft_putstr_fd("rb\n", 1);
	else
		ft_putstr_fd("rr\n", 1);
}

void	reverse_rotate(t_list **src, char stack)
{
	t_list	*tmp_node;
	t_list	*last_node;

	tmp_node = ft_pre_lstlast(*src);
	last_node = ft_lstlast(*src);
	last_node->next = *src;
	*src = last_node;
	tmp_node->next = NULL;
	if (stack == 'a')
		ft_putstr_fd("rra\n", 1);
	else if (stack == 'b')
		ft_putstr_fd("rrb\n", 1);
	else
		ft_putstr_fd("rrr\n", 1);
}
