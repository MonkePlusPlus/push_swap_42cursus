/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   post.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptheo <ptheo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 15:25:42 by ptheo             #+#    #+#             */
/*   Updated: 2024/09/09 19:39:37 by ptheo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	push_move(t_data *data, int move)
{
	t_cell	*c;

	if (data->move == NULL)
		return (-1);
	c = new_cell(move);
	if (c == NULL)
	{
		free_stack(data->move);
		data->move = NULL;
		ft_putstr_fd("Error\n", 2);
		return (-1);
	}
	ft_push_instack(data->move, c);
	return (0);
}

void	print_move(t_cell *current)
{
	if (current->n == M_PA)
		ft_putstr_fd(PA, 1);
	else if (current->n == M_PB)
		ft_putstr_fd(PB, 1);
	else if (current->n == M_SA)
		ft_putstr_fd(SA, 1);
	else if (current->n == M_SB)
		ft_putstr_fd(SB, 1);
	else if (current->n == M_SS)
		ft_putstr_fd(SS, 1);
	else if (current->n == M_RA)
		ft_putstr_fd(RA, 1);
	else if (current->n == M_RB)
		ft_putstr_fd(RB, 1);
	else if (current->n == M_RR)
		ft_putstr_fd(RR, 1);
	else if (current->n == M_RRA)
		ft_putstr_fd(RRA, 1);
	else if (current->n == M_RRB)
		ft_putstr_fd(RRB, 1);
	else if (current->n == M_RRR)
		ft_putstr_fd(RRR, 1);
}

void	read_move(t_data *data)
{
	t_cell	*current;

	current = get_end(data->move);
	while (current)
	{
		print_move(current);
		current = current->previous;
	}
}

void	delete_cell(t_cell *cell)
{
	if (cell->previous != NULL)
		cell->previous->next = cell->next;
	if (cell->next != NULL)
		cell->next->previous = cell->previous;
	free(cell);
}

void	post_opti(t_data *data)
{
	t_cell	*current;

	current = get_end(data->move);
	while (current && current->previous)
	{
		if (current->n == M_RA)
			post_opti_rotate_a(current);
		else if (current->n == M_RB)
			post_opti_rotate_b(current);
		else if (current->n == M_RRA)
			post_opti_rrotate_a(current);
		else if (current->n == M_RRB)
			post_opti_rrotate_b(current);
		else if (current->n == M_SA)
			post_opti_swap_a(current);
		else if (current->n == M_SB)
			post_opti_swap_b(current);
		current = current->previous;
	}
}
