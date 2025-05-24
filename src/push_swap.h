/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-fons <dda-fons@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 13:57:49 by dda-fons          #+#    #+#             */
/*   Updated: 2025/05/24 18:15:41 by dda-fons         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../lib/libft/libft/libft.h"
# include <stdlib.h>
# include <limits.h>

typedef struct s_elem
{
	int	value;
	int	index;
	int	binary;
}		t_elem;

typedef struct s_stack
{
	t_elem	*a;
	t_elem	*b;
	int		size_a;
	int		size_b;
}		t_stack;

void	ft_init(char **argv);

//Sorting and Convertions functions
char	**ft_back_in_original_order(char **str, char **original);
char	**ft_sort_normal(char **str);
int		ft_decimal_to_binary(int num);

//Elements functions
t_elem	*ft_create_elem(int value, int index);
void	ft_delete_elem(t_elem *elem);

//Array functions
int		ft_count_numbers(char **array);
int		ft_int_arraylen(int *array);

#endif
