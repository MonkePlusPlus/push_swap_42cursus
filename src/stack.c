/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptheo <ptheo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 16:05:10 by ptheo             #+#    #+#             */
/*   Updated: 2024/07/31 19:34:11 by ptheo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	free_stack(t_stack *stack)
{
	t_cell	*current;
	t_cell	*temp;

	current = stack->first;
	while (current != NULL)
	{
		temp = current;
		current = current->next;
		free(temp);
	}
	free(stack);
}

t_stack	*new_stack(void)
{
	t_stack	*stack;

	stack = (t_stack *)malloc(sizeof(t_stack) * 1);
	stack->first = NULL;
	stack->end = NULL;
	return (stack);
}

t_cell	*new_cell(int n)
{
	t_cell	*cell;

	cell = (t_cell *)malloc(sizeof(t_cell) * 1);
	cell->n = n;
	cell->next = NULL;
	cell->previous = NULL;
	return (cell);
}

void	ft_push_instack(t_stack *stack, t_cell *new)
{
	t_cell	*temp;

	if (stack->first == NULL)
		stack->end = new;
	temp = stack->first;
	stack->first = new;
	new->next = temp;
	if (temp != NULL)
		temp->previous = new;
}

int	is_sorted(t_stack *stack)
{
	t_cell	*current;

	current = stack->first;
	while (current->next != NULL)
	{
		if (current->n > current->next->n)
			return (0);
	}
	return (1);
}
