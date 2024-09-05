/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptheo <ptheo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 17:30:24 by ptheo             #+#    #+#             */
/*   Updated: 2024/09/05 14:47:51 by ptheo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	check_nbrdup(t_stack *stack, long nbr)
{
	t_cell	*current;

	if (nbr > INT_MAX || nbr < INT_MIN)
		return (-1);
	current = stack->first;
	while (current)
	{
		if (nbr == current->n)
			return (-1);
		current = current->next;
	}
	return (0);
}

int	len_lst(char **lst)
{
	int	i;

	i = 0;
	while (lst[i])
		i++;
	return (i);
}

int	is_empty(t_stack *stack)
{
	return (stack->first == NULL);
}
