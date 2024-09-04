/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hope_utils2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptheo <ptheo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 01:39:57 by ptheo             #+#    #+#             */
/*   Updated: 2024/09/04 16:22:14 by ptheo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	free_ssplit(t_ssplit *ssplit)
{
	if (ssplit)
	{
		if (ssplit->smax)
			free(ssplit->smax);
		if (ssplit->smid)
			free(ssplit->smid);
		if (ssplit->smin)
			free(ssplit->smin);
		free(ssplit);
	}
}

void	get_number(t_split *split)
{
	split->split_max = split->min + (((split->max - split->min) * 2) / 3);
	split->split_min = split->min + ((split->max - split->min) / 3);
	if (split->size < 10)
		split->split_min = split->min;
}

t_cell	*get_first(t_stack *stack_a, t_stack *stack_b, t_split *split)
{
	t_cell	*current;

	if (split->pos == TOPA)
		current = stack_a->first;
	else if (split->pos == TOPB)
		current = stack_b->first;
	else if (split->pos == BOTA)
		current = get_end(stack_a);
	else if (split->pos == BOTB)
		current = get_end(stack_b);
	else
		current = NULL;
	return (current);
}

void	get_limit(t_stack *stack_a, t_stack *stack_b, t_split *split)
{
	t_cell	*current;
	int		max;
	int		min;
	int		i;

	current = get_first(stack_a, stack_b, split);
	if (current == NULL)
		return ;
	max = current->index;
	min = current->index;
	i = 0;
	while (current && i < split->size)
	{
		if (max < current->index)
			max = current->index;
		if (min > current->index)
			min = current->index;
		if (split->pos == TOPA || split->pos == TOPB)
			current = current->next;
		else
			current = current->previous;
		i++;
	}
	split->max = max;
	split->min = min;
}
