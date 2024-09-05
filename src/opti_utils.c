/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opti_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptheo <ptheo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 16:22:23 by ptheo             #+#    #+#             */
/*   Updated: 2024/09/05 16:26:51 by ptheo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	post_opti_rrotate_a(t_cell *current)
{
	t_cell	*temp;

	temp = current;
	while (current->previous)
	{
		if (current->n == M_PA || current->n == M_PB || current->n == M_RR
			|| current->n == M_RRR || current->n == M_SS)
			return ;
		if (current->n == M_RB || current->n == M_SB)
			return ;
		else if (current->n == M_RRB)
		{
			temp->n = M_RRR;
			delete_cell(current);
			return ;
		}
		current = current->previous;
	}
}

void	post_opti_rrotate_b(t_cell *current)
{
	t_cell	*temp;

	temp = current;
	while (current->previous)
	{
		if (current->n == M_PA || current->n == M_PB || current->n == M_RR
			|| current->n == M_RRR || current->n == M_SS)
			return ;
		if (current->n == M_RA || current->n == M_SA)
			return ;
		else if (current->n == M_RRA)
		{
			temp->n = M_RRR;
			delete_cell(current);
			return ;
		}
		current = current->previous;
	}
}
