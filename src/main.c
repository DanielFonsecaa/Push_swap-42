/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-fons <dda-fons@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 18:11:59 by dda-fons          #+#    #+#             */
/*   Updated: 2025/05/24 18:25:09 by dda-fons         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_init(char **argv)
{
	int		i;
	int		len;
	char	**int_array;
	char	**int_array2;
	int		*array_int;

	i = 0;
	int_array = ft_sort_normal(argv);
	while (int_array[i])
	{
		ft_printf("sorted - %s orignal - %s\n", int_array[i], argv[i]);
		i++;
	}
	ft_printf("over sorting\n");
	i = 0;
	int_array2 = ft_back_in_original_order(int_array, argv);
	while (int_array2[i])
	{
		ft_printf("%s\n", int_array2[i]);
		i++;
	}
	array_int = ft_foreach(int_array2, (int (*)(char *))ft_atoi);
	len = i;
	ft_printf("over putting back on oder\n");
	i = 0;
	while (i < len)
	{
		ft_printf("%d\n", ft_decimal_to_binary(array_int[i++]));
	}
	free(int_array2);
	free(int_array);
}

int	main(int argc, char **argv)
{
/*
    t_stack *a;
    t_stack *b;
*/
	if (argc == 1 || (argc == 2 && argv[1][0] == '\0'))
	{
		ft_printf("Error\nUsage : ./push_swap 10 20 30 or\n \
       ./push_swap \"10 20 30\"\n");
		return (1);
	}
	else if (argc == 2)
		argv = ft_split(argv[1], ' ');
	ft_init(argv);
	return (0);
}
