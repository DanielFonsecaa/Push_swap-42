/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getters.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-fons <dda-fons@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 18:02:07 by dda-fons          #+#    #+#             */
/*   Updated: 2025/06/05 11:33:57 by dda-fons         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ft_get_last(t_stack **stack)
{
	t_stack	*temp;

	if (!stack || !*stack)
		return (NULL);
	temp = *stack;
	while (temp->next)
		temp = temp->next;
	return (temp);
}

t_stack	*ft_get_second_last(t_stack **stack)
{
	t_stack	*temp;

	if (!stack || !*stack)
		return (NULL);
	temp = *stack;
	while (temp->next->next)
		temp = temp->next;
	return (temp);
}

int	ft_get_stack_size(t_stack **stack)
{
	t_stack	*temp;
	int		i;

	i = 0;
	temp = *stack;
	while (temp)
	{
		i++;
		temp = temp->next;
	}
	return (i);
}

int	ft_get_bits(t_stack **stack)
{
	t_stack	*temp;
	int		max;
	int		bits;

	temp = *stack;
	max = temp->index;
	bits = 0;
	while (temp)
	{
		if (temp->index > max)
			max = temp->index;
		temp = temp->next;
	}
	while ((max >> bits) != 0)
		bits++;
	return (bits);
}

int	ft_get_min(t_stack **stack)
{
	t_stack	*temp;
	int		min;

	temp = *stack;
	min = temp->value;
	while (temp)
	{
		if (temp->value < min)
			min = temp->value;
		temp = temp->next;
	}
	return (min);
}
