/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_checker.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juanhern <juanhern@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 10:38:18 by juanhern          #+#    #+#             */
/*   Updated: 2024/09/01 16:55:12 by juanhern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void del_content(void *content)
{
  free(content);
}
int check_duplicate(t_list **stack, int *num)
{
  t_list *current_node;
  if (stack == NULL)
    return 0;
  current_node = *stack;
  while (current_node)
  {
    *num+=0;
    if (*(int *)(current_node -> content) == *num)
      return (1);
    current_node = current_node -> next;
  }
  return (0);
}

void pw_validate_input(int argc, char* argv[], t_list **stack_a)
{
  int i = 1;
  int j;
  int *num;
  int valid;

  valid = 1;
  while(i < argc)
  {
    j = 0;
    while(argv[i][j] && valid)
    {
      if (ft_strchr(VALID_CHAR, argv[i][j]) == NULL)
        valid = 0;
      j++;
    }
    if (valid)
    {
      num = malloc(sizeof(int));
      if (!num)
        ft_lstclear(stack_a, del_content);
      *num = ft_atoi(argv[i]);
      if (check_duplicate(stack_a, num) == 0)
        ft_lstadd_back(stack_a, ft_lstnew(num));
      else
      {
          ft_lstclear(stack_a, del_content);
          ft_putstr_fd("Error\n", 1);
          break;
      }
    }
    else
    {
      ft_lstclear(stack_a, del_content);
      ft_putstr_fd("Error\n", 1);
      break;
    }
    i++;
  }
}
  