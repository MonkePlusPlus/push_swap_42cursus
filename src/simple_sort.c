/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptheo <ptheo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 17:20:58 by ptheo             #+#    #+#             */
/*   Updated: 2024/09/04 17:16:40 by ptheo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	simple_sort(t_stack *stack_a, t_stack *stack_b, t_split *split)
{
	if (split->size == 1)
		sort_for_one(stack_a, stack_b, split);
	else if (split->size == 2)
		sort_for_two(stack_a, stack_b, split);
	else if (split->size == 3)
		sort_for_three(stack_a, stack_b, split);
	else if (stack_a->size == 5 && stack_b->size == 0)
		sort_for_five(stack_a, stack_b, split);
}

void	sort_for_one(t_stack *stack_a, t_stack *stack_b, t_split *split)
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
}

void	sort_for_two(t_stack *stack_a, t_stack *stack_b, t_split *split)
{
	t_cell	*current;

	sort_for_one(stack_a, stack_b, split);
	sort_for_one(stack_a, stack_b, split);
	current = stack_a->first;
	if (current->index > current->next->index)
		ft_swap(stack_a, 'a');
}

void	sort_for_three(t_stack *stack_a, t_stack *stack_b, t_split *split)
{
	t_cell	*current;

	if (stack_a->size == 3 && stack_b->size == 0)
	{
		sort_for_three_only(stack_a, stack_b, split);
		return ;
	}
	sort_for_one(stack_a, stack_b, split);
	sort_for_one(stack_a, stack_b, split);
	sort_for_one(stack_a, stack_b, split);
	current = stack_a->first;
	if (current->index > current->next->index
		&& current->index > current->next->next->index)
		ft_swap(stack_a, 'a');
	current = stack_a->first;
	if (current->next->index > current->index && current->next->index
		> current->next->next->index)
	{
		ft_rotate(stack_a, 'a');
		ft_swap(stack_a, 'a');
		ft_reverse_rotate(stack_a, 'a');
	}
	split->pos = TOPA;
	sort_for_two(stack_a, stack_b, split);
}

void	sort_for_five(t_stack *stack_a, t_stack *stack_b, t_split *split)
{
	t_cell	*current;
	int		good;

	current = stack_a->first;
	good = 0;
	while (good < 2)
	{
		if (current->index == 1 || current->index == 2)
		{
			ft_push(stack_a, stack_b, 'b');
			good++;
		}
		else
			ft_rotate(stack_a, 'a');
		current = stack_a->first;
	}
	sort_for_three_only(stack_a, stack_b, split);
	ft_push(stack_b, stack_a, 'a');
	ft_push(stack_b, stack_a, 'a');
	sort_for_two(stack_a, stack_b, split);
}
