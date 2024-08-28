/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hope_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptheo <ptheo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 18:12:38 by ptheo             #+#    #+#             */
/*   Updated: 2024/08/28 19:06:51 by ptheo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	split_topa(t_stack *stack_a, t_stack *stack_b, t_split *split)
{
	t_cell	*current;

	current = stack_a->first;
	while (current && (split->size_max + split->size_mid + split->size_min)
		< split->size)
	{
		if (current->index > split->max)
		{
			ft_rotate(stack_a, 'a');
			split->size_max++;
		}
		else if (current->index <= split->max && current->index <= split->min)
		{
			ft_push(stack_a, stack_b, 'b');
			split->size_mid++;
		}
		else
		{
			ft_push(stack_a, stack_b, 'b');
			ft_rotate(stack_b, 'b');
			split->size_min++;
		}
		current = stack_a->first;
	}
}

void	split_topb(t_stack *stack_a, t_stack *stack_b, t_split *split)
{
	t_cell	*current;

	current = stack_b->first;
	while (current && (split->size_max + split->size_mid + split->size_min)
		< split->size)
	{
		if (current->index > split->max)
		{
			ft_push(stack_b, stack_a, 'a');
			split->size_max++;
		}
		else if (current->index <= split->max && current->index <= split->min)
		{
			ft_push(stack_b, stack_a, 'a');
			ft_rotate(stack_a, 'a');
			split->size_mid++;
		}
		else
		{
			ft_rotate(stack_b, 'b');
			split->size_min++;
		}
		current = stack_b->first;
	}
}

void	split_bota(t_stack *stack_a, t_stack *stack_b, t_split *split)
{
	t_cell	*current;

	current = stack_a->end;
	while (current && (split->size_max + split->size_mid + split->size_min)
		< split->size)
	{
		if (current->index > split->max)
		{
			ft_reverse_rotate(stack_a, 'a');
			split->size_max++;
		}
		else if (current->index <= split->max && current->index <= split->min)
		{
			ft_reverse_rotate(stack_a, 'a');
			ft_push(stack_a, stack_b, 'b');
			split->size_mid++;
		}
		else
		{
			ft_reverse_rotate(stack_a, 'a');
			ft_push(stack_a, stack_b, 'b');
			ft_rotate(stack_b, 'b');
			split->size_min++;
		}
		current = stack_a->end;
	}
}

void	split_botb(t_stack *stack_a, t_stack *stack_b, t_split *split)
{
	t_cell	*current;

	current = stack_b->end;
	while (current && (split->size_max + split->size_mid + split->size_min)
		< split->size)
	{
		if (current->index > split->max)
		{
			ft_reverse_rotate(stack_b, 'b');
			ft_push(stack_b, stack_a, 'a');
			split->size_max++;
		}
		else if (current->index <= split->max && current->index <= split->min)
		{
			ft_reverse_rotate(stack_b, 'b');
			split->size_mid++;
		}
		else
		{
			ft_reverse_rotate(stack_b, 'b');
			ft_push(stack_b, stack_a, 'a');
			ft_rotate(stack_a, 'a');
			split->size_min++;
		}
		current = stack_b->end;
	}
}