/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pw_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juanhern <juanhern@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 20:06:54 by juanhern          #+#    #+#             */
/*   Updated: 2024/09/05 22:05:43 by juanhern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	get_digits(t_list **stack)
{
	int	digits;
	int	max;

	max = get_max_stack(stack);
	digits = 0;
	while (max > 1)
	{
		max /= 2;
		digits++;
	}
	return (digits + 1);
}

int	get_max_stack(t_list **stack)
{
	int		max;
	int		number;
	t_list	*current_node;

	current_node = *stack;
	max = INT_MIN;
	while (current_node)
	{
		number = *(int *)current_node->content;
		if (number > max)
			max = number;
		current_node = current_node->next;
	}
	return (max);
}

t_list	*ft_pre_lstlast(t_list *lst)
{
	if (lst == NULL)
		return (NULL);
	while ((lst->next)->next != NULL)
	{
		lst = lst->next;
	}
	return (lst);
}

void	index_stack(t_list **header)
{
	t_list	*indexed_stack;
	t_list	*primer_nodo;
	t_list	*node_a;
	int		index;
	int		*num;

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
		num = malloc(sizeof(int));
		if (!num)
			ft_lstclear(&indexed_stack, del_content);
		*num = index;
		ft_lstadd_back(&indexed_stack, ft_lstnew(num));
		*header = (*header)->next;
	}
	ft_lstclear(&primer_nodo, del_content);
	*header = indexed_stack;
}

int	is_sorted(t_list **stack_header)
{
	t_list	*previous_node;
	t_list	*current_node;

	previous_node = *stack_header;
	current_node = previous_node->next;
	while (current_node)
	{
		if (*(int *)previous_node->content > *(int *)current_node->content)
			return (0);
		previous_node = current_node;
		current_node = current_node->next;
	}
	return (1);
}

void	print_stack(t_list **stack_a, t_list **stack_b)
{
	t_list	*node_a;
	t_list	*node_b;

	node_a = *stack_a;
	node_b = *stack_b;
	printf("***************************************\n");
	printf("\tSTACK A\t\tSTACK B\n");
	while (node_a || node_b)
	{
		printf("\t");
		if (node_a)
		{
			printf("   %d", *(int *)node_a->content);
			node_a = node_a->next;
		}
		printf("\t\t");
		if (node_b)
		{
			printf("   %d", *(int *)node_b->content);
			node_b = node_b->next;
		}
		printf("\n");
	}
	printf("***************************************\n\n");
}
