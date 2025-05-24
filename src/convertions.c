/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convertions.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-fons <dda-fons@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 18:06:45 by dda-fons          #+#    #+#             */
/*   Updated: 2025/05/24 18:11:23 by dda-fons         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_decimal_to_binary(int num)
{
	int	binary;
	int	place;

	binary = 0;
	place = 1;
	while (num > 0)
	{
		binary += (num % 2) * place;
		num /= 2;
		place *= 10;
	}
	return (binary);
}

char	**ft_sort_normal(char **str)
{
	int		i;
	int		j;
	char	*temp;
	char	**result_str;
	int		len;

	len = 0;
	while (str[len])
		len++;
	result_str = malloc((len + 1) * sizeof(char *));
	if (!result_str)
		return (NULL);
	for (i = 0; i < len; i++)
		result_str[i] = ft_strdup(str[i]);
	result_str[len] = NULL;
	for (i = 0; i < len - 1; i++)
		for (j = i + 1; j < len; j++)
			if (ft_strcmp(result_str[i], result_str[j]) > 0)
			{
				temp = result_str[i];
				result_str[i] = result_str[j];
				result_str[j] = temp;
			}
	return (result_str);
}

char	**ft_back_in_original_order(char **str, char **original)
{
	int		i;
	int		j;
	char	**temp;
	int		len;

	i = 0;
	len = 0;
	while (original[len])
		len++;
	temp = malloc((len + 1) * sizeof(char *));
	if (!temp)
		return (NULL);
	while (original[i])
	{
		j = 0;
		while (str[j])
		{
			if (ft_strcmp(original[i], str[j]) == 0)
			{
				temp[i] = ft_strdup(str[j]);
				break ;
			}
			j++;
		}
		i++;
	}
	temp[i] = NULL;
	return (temp);
}
