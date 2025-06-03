/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-fons <dda-fons@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 18:11:59 by dda-fons          #+#    #+#             */
/*   Updated: 2025/06/03 14:28:26 by dda-fons         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	**stack_a;
	t_stack	**stack_b;
	char	**arguments;

	arguments = NULL;
	if (argc == 1 || (argc == 2 && argv[1][0] == '\0'))
	{
		ft_printf("Error\nUsage : ./push_swap 10 20 30 or\n \
       ./push_swap \"10 20 30\"\n");
		return (1);
	}
	else if (argc == 2)
		arguments = ft_split(argv[1], ' ');
	if (!ft_is_digit(arguments))
	{
		ft_free_arguments(arguments);
		return (1);
	}
	stack_a = (t_stack **)malloc(sizeof(t_stack));
	stack_b = (t_stack **)malloc(sizeof(t_stack));
	*stack_b = NULL;
	ft_create_stack(arguments, stack_a);
	if (ft_check_all(argc, arguments, stack_a))
	{
		ft_free(stack_a);
		ft_free(stack_b);
		return (1);
	}
	if (ft_get_stack_size(stack_a) <= 5)
	{
		ft_small(stack_a, stack_b, ft_get_stack_size(stack_a));
		ft_free(stack_a);
		ft_free(stack_b);
		return (0);
	}
	ft_big(stack_a, stack_b);
	ft_free(stack_a);
	ft_free(stack_b);
	return (0);
}
