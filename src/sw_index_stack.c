/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sw_index_stack.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juanhern <juanhern@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 09:01:19 by juanhern          #+#    #+#             */
/*   Updated: 2024/09/06 09:04:54 by juanhern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	add_index_stack(t_list **indexed_stack, int index)
{
	int	*num;

	num = malloc(sizeof(int));
	if (!num)
		ft_lstclear(indexed_stack, del_content);
	*num = index;
	ft_lstadd_back(indexed_stack, ft_lstnew(num));
}

void	index_stack(t_list **header)
{
	t_list	*indexed_stack;
	t_list	*primer_nodo;
	t_list	*node_a;
	int		index;

	indexed_stack = NULL;
	primer_nodo = *header;
	while (*header)
	{
		index = 0;
		node_a = primer_nodo;
		while (node_a)
		{
			if (*(int *)(*header)->content > *(int *)node_a->content)
				index++;
			node_a = node_a->next;
		}
		add_index_stack(&indexed_stack, index);
		*header = (*header)->next;
	}
	ft_lstclear(&primer_nodo, del_content);
	*header = indexed_stack;
}
