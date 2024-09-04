/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juanhern <juanhern@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 17:35:10 by juanhern          #+#    #+#             */
/*   Updated: 2024/09/01 16:58:08 by juanhern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int main(int argc, char *argv[]){  
    int counter = 0;
    int digits = 0;
    t_list *stack_a = NULL;
    t_list *stack_b = NULL;

    pw_validate_input(argc, argv, &stack_a);

    int size = ft_lstsize(stack_a);
    int min = get_min_stack(stack_a);
    add_min(stack_a, min);
    int max = get_max_stack(stack_a); 
    while(digits < max)
    {
      counter = 0;
      while(counter < size)
      {
        if ((((*(int *)stack_a->content) >> digits) & 1) == 0)
          push(&stack_a, &stack_b,'a');
        else
          rotate(&stack_a,'a');
        counter++;
      }
      while(stack_b)
      {
        push(&stack_b, &stack_a,'b');
      }
      digits++;
    }
    substract_min(stack_a, min);
    print_stack(&stack_a);
  return(0);
}