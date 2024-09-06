/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pw_input_checker.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juanhern <juanhern@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 10:38:18 by juanhern          #+#    #+#             */
/*   Updated: 2024/09/05 21:55:09 by juanhern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	del_content(void *content)
{
	free(content);
}

int	is_duplicated(t_list **stack_a, int num)
{
	t_list	*current_node;

	current_node = *stack_a;
	while (current_node)
	{
		if (*(int *)current_node->content == num)
			return (1);
		current_node = current_node->next;
	}
	return (0);
}

int	pw_validate_input(char *argv)
{
	int	i;

	if (ft_strlen(argv) == 1 && !ft_isdigit(argv[0]))
		return (0);
	i = 1;
	while (argv[i])
	{
		if (ft_strchr(VALID_CHAR, argv[i]) == NULL
			|| ft_strchr(VALID_START_CHAR, argv[0]) == NULL)
			return (0);
		i++;
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

int	add_number_stack(t_list **stack_a, char *argv)
{
	int	*num;

	num = malloc(sizeof(int));
	if (!num)
		ft_lstclear(stack_a, del_content);
	*num = ft_atoi(argv);
	if (!is_duplicated(stack_a, *num))
		ft_lstadd_back(stack_a, ft_lstnew((int *)num));
	else
	{
		free(num);
		return(0);
	}
	return (1);
}

int	pw_validate_inputs(int argc, char *argv[], t_list **stack_a)
{
	int	i;
	int	valid;

	i = 1;
	valid = 1;
	if (!argv[1])
		return (0);
	while (i < argc && valid)
	{
		if (pw_validate_input(argv[i]) && is_int(argv[i]))
			valid = add_number_stack(stack_a, argv[i]);
		else
			valid = 0;
		i++;
	}
	if (!valid)
	{
		ft_lstclear(stack_a, del_content);
		ft_putstr_fd("Error\n", 2);
		return (0);
	}
	return (1);
}
