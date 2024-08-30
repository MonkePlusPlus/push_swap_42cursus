/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouv.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptheo <ptheo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 16:17:31 by ptheo             #+#    #+#             */
/*   Updated: 2024/08/30 02:14:26 by ptheo            ###   ########.fr       */
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

void	ft_swap(t_stack *stack, char a)
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
		ft_putstr_fd(SA, 1);
	else
		ft_putstr_fd(SB, 1);
}

void	ft_push(t_stack *stack_1, t_stack *stack_2, char a)
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
		ft_putstr_fd(PA, 1);
	else
		ft_putstr_fd(PB, 1);
}

void	ft_rotate(t_stack *stack, char a)
{
	t_cell	*temp;
	t_cell	*current;

	if (stack->size < 3)
		return (ft_swap(stack, a));
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
		ft_putstr_fd(RA, 1);
	else
		ft_putstr_fd(RB, 1);
}

void	ft_reverse_rotate(t_stack *stack, char a)
{
	t_cell	*temp;
	t_cell	*current;

	if (stack->size < 3)
		return (ft_swap(stack, a));
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
		ft_putstr_fd(RRA, 1);
	else
		ft_putstr_fd(RRB, 1);
}
