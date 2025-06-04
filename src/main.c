/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-fons <dda-fons@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 18:11:59 by dda-fons          #+#    #+#             */
/*   Updated: 2025/06/04 11:41:07 by dda-fons         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_end(t_stack **stack_a, t_stack **stack_b)
{
	if (ft_get_stack_size(stack_a) <= 5)
	{
		ft_small(stack_a, stack_b, ft_get_stack_size(stack_a));
		ft_free(stack_a);
		ft_free(stack_b);
		return ;
	}
	ft_big(stack_a, stack_b);
	ft_free(stack_a);
	ft_free(stack_b);
}

void	ft_wrong_free(t_stack **stack_a, t_stack **stack_b)
{
	ft_free(stack_a);
	ft_free(stack_b);
}

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
	else
		arguments = argv + 1;
	if (!ft_is_digit(arguments))
		return (ft_free_arguments(arguments), 1);
	stack_a = (t_stack **)malloc(sizeof(t_stack));
	stack_b = (t_stack **)malloc(sizeof(t_stack));
	*stack_b = NULL;
	ft_create_stack(arguments, stack_a);
	if (ft_check_all(argc, arguments, stack_a))
		return (ft_wrong_free(stack_a, stack_b), 1);
	return (ft_end(stack_a, stack_b), 0);
}
