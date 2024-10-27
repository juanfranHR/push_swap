/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juanhern <juanhern@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 20:13:34 by juanhern          #+#    #+#             */
/*   Updated: 2024/10/27 17:26:54 by juanhern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H
# include "../libft/libft.h"
# include <fcntl.h>
# include <limits.h>
# include <stdlib.h>

//PROCESS INPUT
# ifndef VALID_CHAR
#  define VALID_CHAR "0123456789"
# endif

# ifndef VALID_START_CHAR
#  define VALID_START_CHAR "0123456789+-"
# endif

# ifndef VALID_MOVES
#  define VALID_MOVES "papbsasbssrarbrrrrarrbrrr"
# endif

//MOVES
# ifndef MOVES_A
#  define MOVES_A "pasararra"
# endif

# ifndef MOVES_B
#  define MOVES_B "pbsbrbrrb"
# endif

# ifndef MOVES_D
#  define MOVES_D "rrssrrr"
# endif

# ifndef MOVES_SW
#  define MOVES_SW "sasbss"
# endif

# ifndef MOVES_ROT
#  define MOVES_ROT "rarbrr"
# endif

# ifndef MOVES_RROT
#  define MOVES_RROT "rrarrbrrr"
# endif

# ifndef MOVES_PS
#  define MOVES_PS "papb"
# endif

//INPUT VALIDATION AND CLEANING
long	ft_atol(const char *str);
int		get_digits(t_list **stack);
int		get_max_stack(t_list **stack);
t_list	*ft_pre_lstlast(t_list *lst);
void	index_stack(t_list **header);
int		sw_validate_inputs(int argc, char *argv[], t_list **stack_a);
void	del_content(void *content);
void	sw_clear_stack(t_list **stack_a);

//MOVES
void	sw_swap_bonus(t_list **stack);
void	sw_rotate_bonus(t_list **stack);
void	sw_reverse_rotate_bonus(t_list **stack);
void	sw_push_bonus(t_list **src, t_list **dest);
void	sw_double_moves_bonus(char *move, t_list **stack_a, t_list **stack_b);

//SORTING
void	sw_sort_3(t_list **stack_a);
int		is_sorted(t_list **stack_header);
int		is_int(char *argv);
void	sw_sort_4_5(t_list **stack_a, t_list **stack_b);
void	sw_sort(t_list **stack_a, t_list **stack_b);

#endif