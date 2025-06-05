/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-fons <dda-fons@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 18:11:59 by dda-fons          #+#    #+#             */
/*   Updated: 2025/06/05 11:05:35 by dda-fons         ###   ########.fr       */
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

void	ft_wrong_free(t_stack **stack_a, t_stack **stack_b, char **av, int argc)
{
	if (argc == 2)
		ft_free_arguments(av);
	if (stack_a)
		ft_free(stack_a);
	if (stack_b)
		ft_free(stack_b);
}

int	ft_check_errors(char **av, int argc)
{
	if (argc == 2 && av[1][0] == ' ' && av[1][1] == '\0')
		return (ft_putstr_fd("Error\n", 2), 0);
	if (argc == 2 && ft_isdigit(av[1][0]) && av[1][1] == '\0')
		return (0);
	return (1);
}

int	main(int argc, char **argv)
{
	t_stack	**stack_a;
	t_stack	**stack_b;
	char	**arguments;

	arguments = NULL;
	if (!ft_check_errors(argv, argc))
		return (0);
	if (argc == 1)
		return (0);
	if (argc == 2 && argv[1][0] == '\0')
		return (ft_putstr_fd("Error\n", 2), 1);
	else if (argc == 2)
		arguments = ft_split(argv[1], ' ');
	else
		arguments = ++argv;
	if (!ft_is_digit(arguments))
		return (ft_free_arguments(arguments), 1);
	stack_a = (t_stack **)malloc(sizeof(t_stack *));
	stack_b = (t_stack **)malloc(sizeof(t_stack *));
	*stack_a = NULL;
	*stack_b = NULL;
	ft_create_stack(arguments, stack_a);
	if (ft_check_all(argc, arguments, stack_a))
		return (ft_wrong_free(stack_a, stack_b, arguments, argc), 1);
	return (ft_end(stack_a, stack_b), 0);
}
