/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-fons <dda-fons@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 13:57:49 by dda-fons          #+#    #+#             */
/*   Updated: 2025/06/05 11:45:30 by dda-fons         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../lib/libft/libft/libft.h"
# include <stdlib.h>
# include <limits.h>

typedef struct s_stack
{
	long			value;
	int				index;
	struct s_stack	*next;
}		t_stack;

//Sorting and Convertions functions
void	ft_big(t_stack **stack_a, t_stack **stack_b);
void	ft_small(t_stack **stack_a, t_stack **stack_b, int size);
void	ft_sortlist_size2(t_stack **stack_a, t_stack **stack_b);
void	ft_sortlist_size3(t_stack **stack_a, t_stack **stack_b);
void	ft_sortlist_size4(t_stack **stack_a, t_stack **stack_b);
void	ft_sortlist_size5(t_stack **stack_a, t_stack **stack_b);

//stack functions
void	ft_create_stack(char **argv, t_stack **stack);
void	ft_put_first_index(t_stack **stack);
void	ft_put_all_index(t_stack **stack, int index);

//moves
void	ft_swap(char c, t_stack **stack_a, t_stack **stack_b);
void	ft_push(char c, t_stack **stack_to, t_stack **stack_from);
void	ft_rotate(char c, t_stack **stack_a, t_stack **stack_b);
void	ft_reverse_rotate(char c, t_stack **stack_a, t_stack **stack_b);

//getters
t_stack	*ft_get_last(t_stack **stack);
t_stack	*ft_get_second_last(t_stack **stack);
int		ft_get_stack_size(t_stack **stack);
int		ft_get_bits(t_stack **stack);
int		ft_get_min(t_stack **stack);

//free
void	ft_free(t_stack **stack);
void	ft_free_arguments(char **argv);

//checks
int		ft_is_sorted(t_stack **stack);
int		ft_is_digit(char **argv);
int		ft_is_integer(char **argv);
int		ft_is_duplicate(t_stack **stack);
int		ft_check_all(int argc, char **argv, t_stack **stack);
int		ft_check_errors(char **argv, int argc);

#endif
