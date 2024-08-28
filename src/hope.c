/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hope.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptheo <ptheo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 17:42:21 by ptheo             #+#    #+#             */
/*   Updated: 2024/08/29 01:01:26 by ptheo            ###   ########.fr       */
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
		ssplit->smax = new_split(split->size_max, BOTA);
		ssplit->smid = new_split(split->size_mid, TOPB);
		ssplit->smin = new_split(split->size_min, BOTB);
	}
	else if (split->pos == BOTA)
	{
		ssplit->smax = new_split(split->size_max, BOTA);
		ssplit->smid = new_split(split->size_mid, TOPB);
		ssplit->smin = new_split(split->size_min, BOTB);
	}
	else
	{
		ssplit->smax = new_split(split->size_max, BOTA);
		ssplit->smid = new_split(split->size_mid, TOPB);
		ssplit->smin = new_split(split->size_min, BOTB);
	}
	if (ssplit->smax == NULL || ssplit->smid == NULL || ssplit->smin == NULL)
		return (free_ssplit(ssplit), NULL);
	return (ssplit);
}

void	get_number(t_split *split)
{
	split->max = (split->size * 2) / 3;
	split->min = split->size / 3;
}

int	algo_hope(t_stack *stack_a, t_stack *stack_b, t_split *split)
{
	t_ssplit *ssplit;

	if (split->size <= 1)
	{
		if (split->pos == TOPB)
			ft_push(stack_b, stack_a, 'a');
		else if (split->pos == BOTA)
			ft_reverse_rotate(stack_a, 'a');
		else if (split->pos == BOTB)
		{
			ft_reverse_rotate(stack_b, 'b');
			ft_push(stack_b, stack_a, 'a');
		}
		return (0);
	}
	get_number(split);
	split_pos(stack_a, stack_b, split);
	ssplit = new_ssplit(split);
	if (ssplit == NULL)
		return (-1);
	algo_hope(stack_a, stack_b, ssplit->smax);
	algo_hope(stack_a, stack_b, ssplit->smid);
	algo_hope(stack_a, stack_b, ssplit->smin);
	free_ssplit(ssplit);
	return (0);
}

void	split_pos(t_stack *stack_a, t_stack *stack_b, t_split *split)
{
	int	len;
	
	len = 0;
	if (split->pos == TOPA)
		split_topa(stack_a, stack_b, split);
	else if (split->pos == TOPB)
		split_topb(stack_a, stack_b, split);
	else if (split->pos == BOTA)
		split_bota(stack_a, stack_b, split);
	else
		split_botb(stack_a, stack_b, split);
}
