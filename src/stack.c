/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-fons <dda-fons@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 18:05:33 by dda-fons          #+#    #+#             */
/*   Updated: 2025/05/30 16:08:09 by dda-fons         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_create_stack(char **argv, t_stack **stack)
{
	int		i;
	t_stack	*list;

	i = 0;
	*stack = malloc(sizeof(t_stack));
	if (!stack)
		return ;
	(*stack)->value = ft_atol(argv[i++]);
	(*stack)->index = -1;
	list = *stack;
	while (argv[i])
	{
		list->next = malloc(sizeof(t_stack));
		if (!list->next)
		{
			ft_free(stack);
			return ;
		}
		list = list->next;
		list->value = ft_atol(argv[i]);
		list->index = -1;
		list->next = NULL;
		i++;
	}
	return ;
}

void	ft_put_first_index(t_stack **stack)
{
	t_stack	*temp;
	long	min;

	temp = *stack;
	min = temp->value;
	while (temp)
	{
		if (min > temp->value)
			min = temp->value;
		temp = temp->next;
	}
	temp = *stack;
	while (min != temp->value)
		temp = temp->next;
	temp->index = 0;
	ft_put_all_index(stack, 1);
}

void	ft_put_all_index(t_stack **stack, int index)
{
	int		min;
	t_stack	*temp;

	temp = *stack;
	while (temp->next && temp->index != -1)
		temp = temp->next;
	if (temp->index != -1)
		return ;
	min = temp->value;
	while (temp)
	{
		if (min > temp->value && temp->index == -1)
			min = temp->value;
		temp = temp->next;
	}
	temp = *stack;
	while (temp->value != min)
		temp = temp->next;
	temp->index = index;
	ft_put_all_index(stack, ++index);
}

void	ft_free(t_stack **stack)
{
	t_stack	*temp;

	while (*stack)
	{
		temp = *stack;
		*stack = (*stack)->next;
		free(temp);
	}
	if (stack)
		free(stack);
}

void	ft_free_arguments(char **argv)
{
	int	i;

	if (!argv)
		return ;
	i = 0;
	while (argv[i])
		free(argv[i++]);
	free(argv);
}
