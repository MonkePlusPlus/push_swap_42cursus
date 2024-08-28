/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptheo <ptheo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 16:05:10 by ptheo             #+#    #+#             */
/*   Updated: 2024/08/28 19:27:43 by ptheo            ###   ########.fr       */
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
	if (stack == NULL)
		return (NULL);
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

int	is_sorted(t_stack *stack_a, t_stack *stack_b, int size, int pos)
{
	t_cell	*current;
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
	while (i < size
		&& ((current->next != NULL && (pos == TOPA || pos == TOPB))
		|| (current->previous != NULL && (pos == BOTA || pos == BOTB))))
	{
		if (pos == TOPA && current->n > current->next->n)
			return (0);
		else if (pos == TOPB && current->n < current->next->n)
			return (0);
		else if ((pos == BOTA || pos == BOTB) && current->n < current->previous->n)
			return (0);
		if (pos == TOPA || pos == TOPB)
			current = current->next;
		else
			current = current->previous;
		i++;
	}
	return (1);
}
