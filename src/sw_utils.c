/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sw_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juanhern <juanhern@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 20:06:54 by juanhern          #+#    #+#             */
/*   Updated: 2024/09/06 09:07:14 by juanhern         ###   ########.fr       */
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

int	is_int(char *argv)
{
	long	num;

	num = ft_atol(argv);
	if (num >= INT_MIN && num <= INT_MAX)
		return (1);
	else
		return (0);
}
