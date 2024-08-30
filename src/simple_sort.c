/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptheo <ptheo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 17:20:58 by ptheo             #+#    #+#             */
/*   Updated: 2024/08/30 03:15:17 by ptheo            ###   ########.fr       */
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
	else
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

	sort_for_one(stack_a, stack_b, split);
	sort_for_one(stack_a, stack_b, split);
	sort_for_one(stack_a, stack_b, split);
	current = stack_a->first;
	if (current->index > current->next->index
		&& current->index > current->next->next->index)
		ft_swap(stack_a, 'a');
	current = stack_a->first;
	if (current->next->index > current->index && current->next->index > current->next->next->index)
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
	return ;
}
