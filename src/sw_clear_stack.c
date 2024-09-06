/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sw_clear_stack.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juanhern <juanhern@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 08:49:01 by juanhern          #+#    #+#             */
/*   Updated: 2024/09/06 09:04:03 by juanhern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	del_content(void *content)
{
	free(content);
}

void	sw_clear_stack(t_list **stack_a)
{
	ft_lstclear(stack_a, del_content);
	ft_putstr_fd("Error\n", 2);
}
