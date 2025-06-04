/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-fons <dda-fons@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 19:10:17 by dda-fons          #+#    #+#             */
/*   Updated: 2025/06/03 12:37:06 by dda-fons         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_small(t_stack **stack_a, t_stack **stack_b, int size)
{
	if (size == 2)
		ft_sortlist_size2(stack_a, stack_b);
	if (size == 3)
		ft_sortlist_size3(stack_a, stack_b);
	if (size == 4)
		ft_sortlist_size4(stack_a, stack_b);
	if (size == 5)
		ft_sortlist_size5(stack_a, stack_b);
}

void	ft_sortlist_size2(t_stack **stack_a, t_stack **stack_b)
{
	ft_swap('a', stack_a, stack_b);
}

void	ft_sortlist_size3(t_stack **stack_a, t_stack **stack_b)
{
	int	first;
	int	middle;
	int	last;

	first = (*stack_a)->value;
	middle = (*stack_a)->next->value;
	last = (*stack_a)->next->next->value;
	if (first > middle && first > last)
		ft_rotate('a', stack_a, stack_b);
	else if (middle > last && middle > first)
		ft_reverse_rotate('a', stack_a, stack_b);
	if ((*stack_a)->value > (*stack_a)->next->value)
		ft_swap('a', stack_a, stack_b);
}

void	ft_sortlist_size4(t_stack **stack_a, t_stack **stack_b)
{
	int	min;

	min = ft_get_min(stack_a);
	if ((*stack_a)->next->next->next->value == min)
		ft_reverse_rotate('a', stack_a, stack_b);
	while ((*stack_a)->value != min)
		ft_rotate('a', stack_a, stack_b);
	ft_push('b', stack_b, stack_a);
	ft_sortlist_size3(stack_a, stack_b);
	ft_push('a', stack_a, stack_b);
}

void	ft_sortlist_size5(t_stack **stack_a, t_stack **stack_b)
{
	int	min;

	min = ft_get_min(stack_a);
	if ((*stack_a)->next->next->next->value == min)
		ft_reverse_rotate('a', stack_a, stack_b);
	while ((*stack_a)->value != min)
		ft_rotate('a', stack_a, stack_b);
	ft_push('b', stack_b, stack_a);
	ft_sortlist_size4(stack_a, stack_b);
	ft_push('a', stack_a, stack_b);
}
