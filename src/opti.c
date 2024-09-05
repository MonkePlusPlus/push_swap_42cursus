/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opti.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptheo <ptheo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 15:56:38 by ptheo             #+#    #+#             */
/*   Updated: 2024/09/05 16:26:50 by ptheo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	post_opti_swap_a(t_cell *current)
{
	t_cell	*temp;

	temp = current;
	while (current->previous)
	{
		if (current->n == M_PA || current->n == M_PB || current->n == M_RR
			|| current->n == M_RRR || current->n == M_SS)
			return ;
		if (current->n == M_RB || current->n == M_RRB)
			return ;
		else if (current->n == M_SB)
		{
			temp->n = M_SS;
			delete_cell(current);
			return ;
		}
		current = current->previous;
	}
}

void	post_opti_swap_b(t_cell *current)
{
	t_cell	*temp;

	temp = current;
	while (current->previous)
	{
		if (current->n == M_PA || current->n == M_PB || current->n == M_RR
			|| current->n == M_RRR || current->n == M_SS)
			return ;
		if (current->n == M_RA || current->n == M_RRA)
			return ;
		else if (current->n == M_SA)
		{
			temp->n = M_SS;
			delete_cell(current);
			return ;
		}
		current = current->previous;
	}
}

void	post_opti_rotate_a(t_cell *current)
{
	t_cell	*temp;

	temp = current;
	while (current->previous)
	{
		if (current->n == M_PA || current->n == M_PB || current->n == M_RR
			|| current->n == M_RRR || current->n == M_SS)
			return ;
		if (current->n == M_SB || current->n == M_RRB)
			return ;
		else if (current->n == M_RB)
		{
			temp->n = M_RR;
			delete_cell(current);
			return ;
		}
		current = current->previous;
	}
}

void	post_opti_rotate_b(t_cell *current)
{
	t_cell	*temp;

	temp = current;
	while (current->previous)
	{
		if (current->n == M_PA || current->n == M_PB || current->n == M_RR
			|| current->n == M_RRR || current->n == M_SS)
			return ;
		if (current->n == M_SA || current->n == M_RRA)
			return ;
		else if (current->n == M_RA)
		{
			temp->n = M_RR;
			delete_cell(current);
			return ;
		}
		current = current->previous;
	}
}
