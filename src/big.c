/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-fons <dda-fons@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 19:10:35 by dda-fons          #+#    #+#             */
/*   Updated: 2025/06/04 11:09:25 by dda-fons         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_big(t_stack **stack_a, t_stack **stack_b)
{
	int		max_bits;
	int		bits;
	int		i;
	int		stack_size;
	t_stack	*temp;

	bits = -1;
	stack_size = ft_get_stack_size(stack_a);
	ft_put_first_index(stack_a);
	max_bits = ft_get_bits(stack_a);
	while (!ft_is_sorted(stack_a) && ++bits < max_bits)
	{
		i = 0;
		while (i++ < stack_size)
		{
			temp = *stack_a;
			if (((temp->index >> bits) & 1) == 1)
				ft_rotate('a', stack_a, stack_b);
			else
				ft_push('b', stack_b, stack_a);
		}
		while (*stack_b)
			ft_push('a', stack_a, stack_b);
	}
}
