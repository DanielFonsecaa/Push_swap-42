/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-fons <dda-fons@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 12:40:09 by dda-fons          #+#    #+#             */
/*   Updated: 2025/05/29 19:24:16 by dda-fons         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap(char c, t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*temp;
	int		temp_index;

	ft_printf("s%c\n", c);
	if ((c == 'a' || c == 's') && ft_get_last(stack_a) >= 2)
	{
		temp = (*stack_a)->value;
		temp_index = (*stack_a)->index;
		*stack_a->value = (*stack_a)->next->value;
		*stack_a->index = (*stack_a)->next->index;
		*stack_a->next->value = temp;
		*stack_a->next->index = temp_index;
	}
	if ((c == 'b' || c == 's') && ft_get_last(stack_b) >= 2)
	{
		temp = (*stack_b)->value;
		temp_index = (*stack_b)->index;
		*stack_b->value = (*stack_b)->next->value;
		*stack_b->index = (*stack_b)->next->index;
		*stack_b->next->value = temp;
		*stack_b->next->index = temp_index;
	}
}

void	ft_push(char c, t_stack **stack_to, t_stack **stack_from)
{
	t_stack	*temp;
	t_stack	*receive;
	t_stack	*push;

	if (!stack_from || !*stack_from)
		return ;
	ft_printf("p%c\n", c);
	push = *stack_from;
	receive = *stack_to;
	temp = push->next;
	if (!receive)
	{
		push->next = NULL;
		*stack_to = push;
		*stack_from = temp;
	}
	else
	{
		push->next = receive;
		*stack_to = push;
		*stack_from = temp;
	}
}

void	ft_rotate(char c, t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*temp;
	t_stack	*first;
	t_stack	*last;

	ft_printf("r%c\n", c);
	if ((c == 'a' || c == 'r') && (*stack_a) && (*stack_a)->next)
	{
		temp = *stack_a;
		first = (*stack_a)->next;
		last = ft_get_last(*stack_a);
		last->next = temp;
		temp->next = NULL;
		*stack_a = first;
	}
	if ((c == 'b' || c == 'r') && (*stack_b) && (*stack_b)->next)
	{
		temp = *stack_b;
		first = (*stack_b)->next;
		last = ft_get_last(*stack_b);
		last->next = temp;
		temp->next = NULL;
		*stack_b = first;
	}
}

void	ft_reverse_rotate(char c, t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*temp;
	t_stack	*second_last;
	t_stack	*last;

	ft_printf("rr%c\n", c);
	if ((c == 'a' || c == 'r') && (*stack_a) && (*stack_a)->next)
	{
		last = ft_get_last(*stack_a);
		second_last = ft_get_second_last(*stack_a);
		second_last->next = NULL;
		last->next = *stack_a;
		*stack_a = last;
	}
	if ((c == 'b' || c == 'r') && (*stack_b) && (*stack_b)->next)
	{
		last = ft_get_last(*stack_b);
		second_last = ft_get_second_last(*stack_b);
		second_last->next = NULL;
		last->next = *stack_b;
		*stack_b = last;
	}
}
