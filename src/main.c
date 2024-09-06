/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juanhern <juanhern@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 17:35:10 by juanhern          #+#    #+#             */
/*   Updated: 2024/09/06 08:59:25 by juanhern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	main(int argc, char *argv[])
{
	t_list	*stack_a;
	t_list	*stack_b;
	int		valid;

	stack_a = NULL;
	stack_b = NULL;
	valid = sw_validate_inputs(argc, argv, &stack_a);
	if (valid && !is_sorted(&stack_a))
	{
		index_stack(&stack_a);
		if (argc > 1 && argc < 4
			&& (*(int *)stack_a->content > *(int *)(stack_a->next)->content))
			sw_swap(&stack_a, 'a');
		else if (argc == 4)
			sw_sort_3(&stack_a);
		else if (argc > 4 && argc < 7)
			sw_sort_4_5(&stack_a, &stack_b);
		else if (argc >= 7)
			sw_sort(&stack_a, &stack_b);
	}
	ft_lstclear(&stack_a, del_content);
	return (0);
}
