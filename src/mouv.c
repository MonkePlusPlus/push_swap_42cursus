/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouv.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptheo <ptheo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 16:17:31 by ptheo             #+#    #+#             */
/*   Updated: 2024/09/05 18:38:10 by ptheo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_cell	*get_end(t_stack *stack)
{
	t_cell	*current;

	current = stack->first;
	if (current == NULL)
		return (NULL);
	while (current->next)
		current = current->next;
	return (current);
}

void	ft_swap(t_data *data, t_stack *stack, char a)
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
	if (a == 'a')
		push_move(data, M_SA);
	else
		push_move(data, M_SB);
}

void	ft_push(t_data *data, t_stack *stack_1, t_stack *stack_2, char a)
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
	if (a == 'a')
		push_move(data, M_PA);
	else
		push_move(data, M_PB);
}

void	ft_rotate(t_data *data, t_stack *stack, char a)
{
	t_cell	*temp;
	t_cell	*current;

	if (stack->size < 3)
		return (ft_swap(data, stack, a));
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
	if (a == 'a')
		push_move(data, M_RA);
	else
		push_move(data, M_RB);
}

void	ft_reverse_rotate(t_data *data, t_stack *stack, char a)
{
	t_cell	*temp;
	t_cell	*current;

	if (stack->size < 3)
		return (ft_swap(data, stack, a));
	temp = stack->first;
	if (temp == NULL)
		return ;
	current = get_end(stack);
	current->next = temp;
	stack->first = current;
	temp->previous = current;
	current->previous->next = NULL;
	current->previous = NULL;
	if (a == 'a')
		push_move(data, M_RRA);
	else
		push_move(data, M_RRB);
}
