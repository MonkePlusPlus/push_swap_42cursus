/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptheo <ptheo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 16:44:09 by ptheo             #+#    #+#             */
/*   Updated: 2024/09/05 18:53:26 by ptheo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

int	is_sorted_check(t_stack *stack_a, t_stack *stack_b)
{
	t_cell	*current;
	int		i;

	if (!is_empty(stack_b))
		return (0);
	current = stack_a->first;
	while (current->next)
	{
		if (current->n > current->next->n)
			return (0);
		current = current->next;
	}
	return (1);
}

void	swap_check(t_stack *stack)
{
	t_cell	*temp;
	t_cell	*second;

	if (stack->size < 2)
		return ;
	if (stack->first == NULL)
		return ;
	if (stack->first->next == NULL)
		return ;
	temp = stack->first;
	stack->first = temp->next;
	temp->next = stack->first->next;
	if (temp->next != NULL)
		temp->next->previous = temp;
	temp->previous = stack->first;
	stack->first->next = temp;
	stack->first->previous = NULL;
}

void	push_check(t_stack *stack_1, t_stack *stack_2)
{
	t_cell	*temp;

	if (stack_1->first == NULL)
		return ;
	temp = stack_1->first;
	stack_1->first = temp->next;
	if (stack_1->first != NULL)
		stack_1->first->previous = NULL;
	temp->next = stack_2->first;
	if (temp->next != NULL)
		temp->next->previous = temp;
	stack_2->first = temp;
	stack_1->size -= 1;
	stack_2->size += 1;
}

void	rotate_check(t_stack *stack)
{
	t_cell	*temp;
	t_cell	*current;

	temp = stack->first;
	if (temp == NULL)
		return ;
	current = temp->next;
	if (current == NULL)
		return ;
	while (current->next != NULL)
		current = current->next;
	stack->first = temp->next;
	current->next = temp;
	temp->previous = current;
	temp->next = NULL;
}

void	reverse_rotate_check(t_stack *stack)
{
	t_cell	*temp;
	t_cell	*current;

	temp = stack->first;
	if (temp == NULL)
		return ;
	current = get_end(stack);
	current->next = temp;
	stack->first = current;
	temp->previous = current;
	current->previous->next = NULL;
	current->previous = NULL;
}
