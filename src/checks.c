/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-fons <dda-fons@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 17:20:14 by dda-fons          #+#    #+#             */
/*   Updated: 2025/05/30 16:15:40 by dda-fons         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_is_sorted(t_stack **stack)
{
	t_stack	*temp;

	temp = *stack;
	while (temp->next)
	{
		if (temp->value > temp->next->value)
			return (1);
		temp = temp->next;
	}
	return (0);
}

int	ft_is_digit(char **argv)
{
	int	i;
	int	j;

	i = 0;
	while (argv[i])
	{
		j = 0;
		while (argv[i][j])
		{
			if ((j == 0) && (argv[i][j] == '-' || argv[i][j] == '+'))
				i++;
			if (!ft_isdigit(argv[i][j]))
				return (ft_printf("ERROR\n"), 0);
			j++;
		}
		i++;
	}
	return (1);
}

int	ft_is_integer(char **argv)
{
	int	i;
	int	number;

	i = 0;
	while (argv[i])
	{
		number = ft_atoi(argv[i]);
		if (number > INT_MAX || number < INT_MIN)
			return (ft_printf("ERROR\n"), 0);
		i++;
	}
	return (1);
}

int	ft_is_duplicate(t_stack **stack)
{
	int		i;
	t_stack	*temp;
	t_stack	*next_temp;

	i = 0;
	temp = *stack;
	while (temp->next)
	{
		next_temp = temp->next;
		while (next_temp)
		{
			if (temp->value == next_temp->value)
				return (ft_printf("ERROR\n"), 0);
			next_temp = next_temp->next;
		}
		temp = temp->next;
	}
	return (1);
}

int	ft_check_all(int argc, char **argv, t_stack **stack)
{
	if (!ft_is_digit(argv))
		return (1);
	if (!ft_is_sorted(stack))
		return (1);
	if (!ft_is_integer(argv))
		return (1);
	if (!ft_is_duplicate(stack))
		return (1);
	if (argc == 2)
		ft_free_arguments(argv);
	return (0);
}
