/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptheo <ptheo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 18:07:00 by ptheo             #+#    #+#             */
/*   Updated: 2024/08/20 18:25:39 by ptheo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
/*
int	sort_stack(t_stack *stack_a, int size)
{
	t_stack	*stack_b;
	t_cell	*cell_a;
	t_cell	*cell_b;
	int		good;
	int		index;
	int		i;

	i = 0;
	good = 0;
	index = 0;
	stack_b = new_stack();
	while (!good)
	{
		cell_a = stack_a->first;
		cell_b = stack_b->first;
		if (is_sorted(stack_a, 0) && is_empty(stack_b))
			good = 1;
		else if (is_sorted(stack_b, 1) && (is_empty(stack_a) || (is_sorted(stack_a, 0) && cell_a->n >= cell_b->n)))
			ft_push(stack_b, stack_a, 'a');
		else if (cell_a && cell_a->index == index)
		{
			ft_push(stack_a, stack_b, 'b');
			index++;

		}
		else if (cell_a && cell_a->next && cell_a->next->index == index)
			ft_swap(stack_a, 'a');
		else if (cell_a && stack_a->end->index == index)
			ft_reverse_rotate(stack_a, 'a');
		else
		{
			ft_rotate(stack_a, 'a');
		}
		i++;
	}
	return (1);
}*/
