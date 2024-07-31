/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouv.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptheo <ptheo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 16:17:31 by ptheo             #+#    #+#             */
/*   Updated: 2024/07/31 19:34:28 by ptheo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_swap(t_stack *stack)
{
	t_cell	*temp;
	t_cell	*second;

	if (stack->first == NULL)
		return ;
	if (stack->first->next == NULL)
		return ;
	temp = stack->first;
	stack->first = temp->next;
	temp->next = stack->first->next;
	if (temp->next->previous != NULL)
		temp->next->previous = temp;
	temp->previous = stack->first;
	stack->first->next = temp;
	stack->first->previous = NULL;
}

void	ft_push(t_stack *stack_1, t_stack *stack_2)
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
}

void	ft_rotate(t_stack *stack)
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
}

void	ft_reverse_rotate(t_stack *stack)
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
	stack->first = current;
	current->next = temp;
	temp->previous = current;
	current->previous->next = NULL;
	current->previous = NULL;
}
