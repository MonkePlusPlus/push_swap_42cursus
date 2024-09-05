/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hope.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptheo <ptheo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 17:42:21 by ptheo             #+#    #+#             */
/*   Updated: 2024/09/05 15:16:27 by ptheo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_split	*new_split(int size, int pos)
{
	t_split	*split;

	split = (t_split *)malloc(sizeof(t_split) * 1);
	if (split == NULL)
		return (NULL);
	split->size = size;
	split->pos = pos;
	split->size_max = 0;
	split->size_mid = 0;
	split->size_min = 0;
	return (split);
}

void	new_ssplit_utils(t_ssplit *ssplit, t_split *split)
{
	if (split->pos == BOTA)
	{
		ssplit->smax = new_split(split->size_max, TOPA);
		ssplit->smid = new_split(split->size_mid, TOPB);
		ssplit->smin = new_split(split->size_min, BOTB);
	}
	else if (split->pos == BOTB)
	{
		ssplit->smax = new_split(split->size_max, TOPA);
		ssplit->smid = new_split(split->size_mid, TOPB);
		ssplit->smin = new_split(split->size_min, BOTA);
	}
	else
	{
		ssplit->smax = NULL;
		ssplit->smid = NULL;
		ssplit->smin = NULL;
	}
}

t_ssplit	*new_ssplit(t_split *split)
{
	t_ssplit	*ssplit;

	ssplit = (t_ssplit *)malloc(sizeof(t_ssplit) * 1);
	if (ssplit == NULL)
		return (NULL);
	if (split->pos == TOPA)
	{
		ssplit->smax = new_split(split->size_max, BOTA);
		ssplit->smid = new_split(split->size_mid, TOPB);
		ssplit->smin = new_split(split->size_min, BOTB);
	}
	else if (split->pos == TOPB)
	{
		ssplit->smax = new_split(split->size_max, TOPA);
		ssplit->smid = new_split(split->size_mid, BOTA);
		ssplit->smin = new_split(split->size_min, BOTB);
	}
	else
		new_ssplit_utils(ssplit, split);
	if (ssplit->smax == NULL || ssplit->smid == NULL || ssplit->smin == NULL)
		return (free_ssplit(ssplit), NULL);
	return (ssplit);
}

int	algo_hope(t_data *data, t_split *split)
{
	t_ssplit	*ssplit;

	if (is_sorted(data->stack_a, data->stack_b))
		return (0);
	if (split->size <= 3 || (data->stack_a->size == 5
			&& data->stack_b->size == 0))
	{
		simple_sort(data, split);
		return (0);
	}
	get_limit(data, split);
	get_number(split);
	split_pos(data, split);
	ssplit = new_ssplit(split);
	if (ssplit == NULL)
		return (-1);
	algo_hope(data, ssplit->smax);
	algo_hope(data, ssplit->smid);
	algo_hope(data, ssplit->smin);
	free_ssplit(ssplit);
	return (0);
}

void	split_pos(t_data *data, t_split *split)
{
	if (split->pos == TOPA)
		split_topa(data, split);
	else if (split->pos == TOPB)
		split_topb(data, split);
	else if (split->pos == BOTA)
		split_bota(data, split);
	else
		split_botb(data, split);
}
