/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sw_checker_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juanhern <juanhern@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 17:35:00 by juanhern          #+#    #+#             */
/*   Updated: 2024/09/19 17:58:21 by juanhern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap_bonus.h"

void	apply_movements(t_list **stack_a, t_list **stack_b,
		t_list **instructions)
{
	char	*move;

	while (*instructions)
	{
		move = (char *)(*instructions)->content;
		if (ft_strncmp(move, "pa", 2) == 0)
			sw_push(stack_b, stack_a, 'a', 0);
		else if (ft_strncmp(move, "pb", 2) == 0)
			sw_push(stack_a, stack_b, 'b', 0);
		else if (ft_strncmp(move, "sa", 2) == 0)
			sw_swap(stack_a, 'a', 0);
		else if (ft_strncmp(move, "sb", 2) == 0)
			sw_swap(stack_b, 'b', 0);
		else if (ft_strncmp(move, "ra", 2) == 0)
			sw_rotate(stack_a, 'a', 0);
		else if (ft_strncmp(move, "rb", 2) == 0)
			sw_rotate(stack_b, 'b', 0);
		else if (ft_strncmp(move, "rra", 3) == 0)
			sw_reverse_rotate(stack_a, 'a', 0);
		else if (ft_strncmp(move, "rb", 3) == 0)
			sw_rotate(stack_b, 'b', 0);
		*instructions = (*instructions)->next;
	}
}

void	get_instructions(t_list **instructions)
{
	char	*instruction;
	t_list	*instruction_node;

	instruction_node = NULL;
	while (1)
	{
		instruction = get_next_line(STDIN_FILENO);
		if (!instruction)
			break ;
		instruction_node = ft_lstnew((char *)ft_strdup(instruction));
		ft_lstadd_back(instructions, instruction_node);
	}
}

int	main(int argc, char *argv[])
{
	t_list	*stack_a;
	t_list	*stack_b;
	t_list	*instructions;
	int		valid;

	if (argc < 2)
		return (0);
	stack_a = NULL;
	stack_b = NULL;
	instructions = NULL;
	valid = sw_validate_inputs(argc, argv, &stack_a);
	if (valid)
	{
		get_instructions(&instructions);
		apply_movements(&stack_a, &stack_b, &instructions);
		if (is_sorted(&stack_a) && !stack_b)
			ft_putendl_fd("OK", STDOUT_FILENO);
		else
			ft_putendl_fd("KO", STDOUT_FILENO);
		ft_lstclear(&stack_a, del_content);
		if (stack_b)
			ft_lstclear(&stack_b, del_content);
	}
	return (0);
}
