/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_length.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-fons <dda-fons@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 18:02:07 by dda-fons          #+#    #+#             */
/*   Updated: 2025/05/24 18:14:16 by dda-fons         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_int_arraylen(int *array)
{
	int	i;

	if (!array)
		return (0);
	i = 0;
	while (*array)
	{
		array++;
		i++;
	}
	array -= i;
	return (i);
}

int	ft_count_numbers(char **array)
{
	int	i;

	if (!array)
		return (0);
	i = 0;
	while (array[i])
		i++;
	return (i);
}
