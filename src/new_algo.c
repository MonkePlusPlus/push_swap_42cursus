/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_algo.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptheo <ptheo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 17:05:03 by ptheo             #+#    #+#             */
/*   Updated: 2024/08/28 18:06:50 by ptheo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	find_middle(t_stack *stack_a, t_stack *stack_b, int size, int pos)
{
	t_cell	*current;
	int		sum;
	int		i;

	if (pos == TOPA)
		current = stack_a->first;
	else if (pos == TOPB)
		current = stack_b->first;
	else if (pos == BOTA)
		current = stack_a->end;
	else if (pos == BOTB)
		current = stack_b->end;
	i = 0;
	sum = 0;
	while (i < size && current != NULL)
	{
		sum += current->n;
		if (pos == TOPA || pos == TOPB)
			current = current->next;
		else
			current = current->previous;
	}
	return (sum / size);
}

void	new_algo(t_stack *stack_a, t_stack *stack_b, int size, int pos)
{
	int	size_big;
	int	size_small;
	int	mid;
	int	i;

	//if sort by pos or size 1 just go TOPA and if TOPA return ;
	size_big = 0;
	size_small = 0;
	if (size == 1 || is_sorted(stack_a, stack_b, size, pos))
	{
		if (pos == TOPB)
		{
			while (size_big < size)
			{
				ft_push(stack_b, stack_a, 'a');
				size_big++;
			}
		}
		else if (pos == BOTA)
		{
			while (size_big < size)
			{
				ft_rotate(stack_a, 'a');
				size_big++;
			}
		}
		else if (pos == BOTB)
		{
			while (size_big < size)
			{
				ft_rotate(stack_b, 'b');
				ft_push(stack_b, stack_a, 'a');
				size_big++;
			}
		}
		return ;
	}
	mid = find_middle(stack_a, stack_b, size, pos); //find mid
	// if TOPA : small = BOTA big = TOPB
	// if BOTA : small = BOTB big = TOPB
	// if TOPB : small = BOTA big = TOPA
	// if BOTB : small = BOTA big = TOPB
	i = 0;
	while (size_big + size_small < size)
	{
		if (pos == TOPA)
		{
			if (stack_a->first->n < mid)
			{
				ft_rotate(stack_a, 'a');
				size_small++;
			}
			else
			{
				ft_push(stack_a, stack_b, 'b');
				size_big++;
			}
		}
		else if (pos == TOPB)
		{
			if (stack_b->first->n < mid)
			{
				ft_rotate(stack_b, 'b');
				size_small++;
			}
			else
			{
				ft_push(stack_b, stack_a, 'a');
				size_big++;
			}
		}
		else if (pos == BOTA)
		{
			if (stack_a->end->n < mid)
			{
				ft_push(stack_a, stack_b, 'b');
				ft_rotate(stack_b, 'b');
				size_small++;
			}
			else
			{
				ft_push(stack_a, stack_b, 'b');
				size_big++;
			}
		}
		else
		{
			if (stack_b->end->n < mid)
			{
				ft_push(stack_b, stack_a, 'a');
				ft_rotate(stack_a, 'a');
				size_small++;
			}
			else
			{
				ft_rotate(stack_b, 'b');
				size_big++;
			}
		}
	}
	if (pos == TOPA)
	{
		new_algo(stack_a, stack_b, size_big, TOPB);
		new_algo(stack_a, stack_b, size_small, BOTA);
	}
	else if (pos == TOPB)
	{
		new_algo(stack_a, stack_b, size_big, TOPA);
		new_algo(stack_a, stack_b, size_small, BOTB);
	}
	else if (pos == BOTA)
	{
		new_algo(stack_a, stack_b, size_big, TOPB);
		new_algo(stack_a, stack_b, size_small, BOTB);
	}
	else
	{
		new_algo(stack_a, stack_b, size_big, TOPB);
		new_algo(stack_a, stack_b, size_small, BOTA);
	}
}