/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptheo <ptheo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 15:09:15 by ptheo             #+#    #+#             */
/*   Updated: 2024/09/02 18:03:55 by ptheo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_lswap(t_cell **t1, t_cell **t2)
{
	t_cell	*temp;
	int		index;

	temp = *t1;
	*t1 = *t2;
	*t2 = temp;
}

int	partition(t_cell ***tab, int low, int high)
{
	t_cell	**t;
	int		pivot;
	int		i;
	int		j;

	t = *tab;
	pivot = t[high]->n;
	i = low - 1;
	j = low;
	while (j <= high - 1)
	{
		if (t[j]->n < pivot)
		{
			i++;
			ft_lswap(&t[i], &t[j]);
		}
		j++;
	}
	ft_lswap(&t[i + 1], &t[high]);
	return (i + 1);
}

void	give_index(t_cell ***tab, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		(*tab)[i]->index = i + 1;
		i++;
	}
}

int	algo_index(t_cell ***tab, int low, int high)
{
	int	pivot;

	if (low < high)
	{
		pivot = partition(tab, low, high);
		algo_index(tab, low, pivot - 1);
		algo_index(tab, pivot + 1, high);
	}
	give_index(tab, high + 1);
	return (1);
}
