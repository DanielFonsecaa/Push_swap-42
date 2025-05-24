/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   element.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-fons <dda-fons@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 18:05:33 by dda-fons          #+#    #+#             */
/*   Updated: 2025/05/24 18:06:21 by dda-fons         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_elem	*ft_create_elem(int value, int index)
{
	t_elem	*new;

	new = malloc(sizeof(t_elem));
	if (!new)
		return (NULL);
	new->value = value;
	new->index = index;
	new->binary = ft_decimal_to_binary(index);
	return (new);
}

void	ft_delete_elem(t_elem *elem)
{
	if (elem)
	{
		free(elem);
	}
}
