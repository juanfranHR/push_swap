/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sw_checker_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juanhern <juanhern@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 17:35:00 by juanhern          #+#    #+#             */
/*   Updated: 2024/10/27 18:10:51 by juanhern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap_bonus.h"

static int	is_valid_instruction(char *instruction)
{
	if (ft_strnstr(VALID_MOVES, instruction, ft_strlen(VALID_MOVES)))
		return (1);
	return (0);
}
static void	apply_movement(char *move, t_list **stack)
{
	if (ft_strnstr(MOVES_SW, move, ft_strlen(MOVES_SW)))
		sw_swap_bonus(stack);
	else if (ft_strnstr(MOVES_ROT, move, ft_strlen(MOVES_ROT)))
		sw_rotate_bonus(stack);
	else if (ft_strnstr(MOVES_RROT, move, ft_strlen(MOVES_RROT)))
		sw_reverse_rotate_bonus(stack);
}

static void	process_moves(t_list **stack_a, t_list **stack_b,
		t_list **instructions)
{
	char	*move;
	t_list	*instruction;

	instruction = *instructions;
	while (instruction)
	{
		move = (char *)instruction->content;
		if (ft_strnstr(MOVES_D, move, ft_strlen(MOVES_D)))
			sw_double_moves_bonus(move, stack_a, stack_b);
		else if (ft_strnstr("pa", move, 2))
			sw_push_bonus(stack_b, stack_a);
		else if (ft_strnstr("pb", move, 2))
			sw_push_bonus(stack_a, stack_b);
		else if (ft_strnstr(MOVES_A, move, ft_strlen(MOVES_A)))
			apply_movement(move, stack_a);
		else if (ft_strnstr(MOVES_B, move, ft_strlen(MOVES_B)))
			apply_movement(move, stack_b);
		instruction = instruction->next;
	}
}

static int	get_instructions(t_list **instructions)
{
	char	*instruction;
	t_list	*instruction_node;
	char	*line;

	instruction_node = NULL;
	while (1)
	{
		line = get_next_line(STDIN_FILENO);
		instruction = ft_strtrim(line, "\n");
		free(line);
		if (!instruction)
			return (1);
		if (!is_valid_instruction(instruction))
		{
			ft_putendl_fd("Error", STDOUT_FILENO);
			free(instruction);
			ft_lstclear(instructions, del_content);
			return (0);
		}
		instruction_node = ft_lstnew(ft_strdup(instruction));
		free(instruction);
		ft_lstadd_back(instructions, instruction_node);
	}
	return (1);
}

int	main(int argc, char *argv[])
{
	t_list	*stack_a;
	t_list	*stack_b;
	t_list	*instructions;

	if (argc < 2)
		return (0);
	stack_a = NULL;
	stack_b = NULL;
	instructions = NULL;
	if (sw_validate_inputs(argc, argv, &stack_a) && get_instructions(&instructions))
	{
		process_moves(&stack_a, &stack_b, &instructions);
		if (is_sorted(&stack_a) && !stack_b)
			ft_putendl_fd("OK", STDOUT_FILENO);
		else
			ft_putendl_fd("KO", STDOUT_FILENO);
	}
	ft_lstclear(&stack_a, del_content);
	ft_lstclear(&instructions, del_content);
	if (stack_b)
		ft_lstclear(&stack_b, del_content);
	return (0);
}
