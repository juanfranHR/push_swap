/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juanhern <juanhern@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 20:06:54 by juanhern          #+#    #+#             */
/*   Updated: 2024/09/01 16:57:21 by juanhern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int get_max_stack(t_list *stack)
{
  int max;
  int number;
  int digits;

  max = INT8_MIN;
  while(stack)
  {
    number = *(int *)stack -> content;
    if (number > max)
      max = number;
    stack = stack -> next;
  }
  digits = 0;
  while(max > 1)
  {
    max /= 2;
    digits++;
  }
  return(digits + 1);
}

int get_min_stack(t_list *stack)
{
  int min;
  int number;
  
  min = INT8_MAX;
  while(stack)
  {
    number = *(int *)stack -> content;
    if (number < min)
      min = number;
    stack = stack -> next;
  }
  return(min);
}

t_list	*ft_pre_lstlast(t_list *lst)
{
	if (lst == NULL)
		return (NULL);
	while ((lst->next)->next != NULL){
		lst = lst->next;
	}
	return (lst);
}

void add_min(t_list *stack, int min)
{
  while (stack)
  {
    *(int *)stack -> content += -1* min;
    stack = stack -> next;
  }
}

void substract_min(t_list *stack, int min)
{
  while (stack)
  {
    *(int *)stack -> content -= -1* min;
    stack = stack -> next;
  }
}
void print_stack(t_list **header)
{
  t_list  *current_node;

  current_node = *header;
  while(current_node)
  {
    printf("%d\n", *(int *)current_node->content);
    current_node = current_node -> next;
  }
}