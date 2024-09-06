/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pw_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juanhern <juanhern@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 09:04:28 by juanhern          #+#    #+#             */
/*   Updated: 2024/09/05 14:02:57 by juanhern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	pw_sort_3(t_list **stack_a)
{
	int	max;

	max = get_max_stack(stack_a);
	if (*(int *)(*stack_a)->content == max)
		rotate(stack_a, 'a');
	else if (*(int *)((*stack_a)->next)->content == max)
		reverse_rotate(stack_a, 'a');
	if (*(int *)(*stack_a)->content != max - 2)
		swap(stack_a, 'a');
}

void	pw_sort_4_5(t_list **stack_a, t_list **stack_b)
{
	while (ft_lstsize(*stack_b) != 2)
	{
		if (*(int *)(*stack_a)->content == 0
			|| *(int *)(*stack_a)->content == 1)
			push(stack_a, stack_b, 'b');
		else
			rotate(stack_a, 'a');
	}
	if (*(int *)(*stack_b)->content < *(int *)((*stack_b)->next)->content)
		swap(stack_b, 'b');
	if (ft_lstsize(*stack_a) == 3)
		pw_sort_3(stack_a);
	else if (*(int *)(*stack_a)->content > *(int *)((*stack_a)->next)->content)
		swap(stack_a, 'a');
	while (*stack_b)
		push(stack_b, stack_a, 'a');
}

void	pw_sort_stack_a(t_list **stack_a, t_list **stack_b, int digits)
{
	int	counter;
	int	size_a;

	counter = 0;
	size_a = ft_lstsize(*stack_a);
	while (counter < size_a && !is_sorted(stack_a))
	{
		if ((((*(int *)(*stack_a)->content) >> digits) & 1) == 0)
			push(stack_a, stack_b, 'b');
		else
			rotate(stack_a, 'a');
		counter++;
	}
}

void	pw_sort_stack_b(t_list **stack_a, t_list **stack_b, int digits)
{
	int	counter;
	int	size_b;

	counter = 0;
	size_b = ft_lstsize(*stack_b);
	while (counter < size_b && !is_sorted(stack_a))
	{
		if ((((*(int *)(*stack_b)->content) >> digits) & 1) == 0)
			rotate(stack_b, 'b');
		else
			push(stack_b, stack_a, 'a');
		counter++;
	}
}

void	pw_sort(t_list **stack_a, t_list **stack_b)
{
	int	max;
	int	digits;

	digits = 0;
	max = get_digits(stack_a);
	while (digits < max)
	{
		pw_sort_stack_a(stack_a, stack_b, digits);
		pw_sort_stack_b(stack_a, stack_b, digits + 1);
		if (is_sorted(stack_a))
		{
			while (*stack_b)
				push(stack_b, stack_a, 'a');
		}
		digits++;
	}
	while (*stack_b)
		push(stack_b, stack_a, 'a');
}
