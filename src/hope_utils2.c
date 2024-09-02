/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hope_utils2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptheo <ptheo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 01:39:57 by ptheo             #+#    #+#             */
/*   Updated: 2024/09/02 19:57:01 by ptheo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	get_limit(t_stack *stack_a, t_stack *stack_b, t_split *split)
{
	t_cell	*current;
	int		max;
	int		min;
	int		i;

	if (split->pos == TOPA)
		current = stack_a->first;
	else if (split->pos == TOPB)
		current = stack_b->first;
	else if (split->pos == BOTA)
		current = get_end(stack_a);
	else
		current = get_end(stack_b);
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
