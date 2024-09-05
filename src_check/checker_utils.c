/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptheo <ptheo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 16:43:55 by ptheo             #+#    #+#             */
/*   Updated: 2024/09/05 18:53:10 by ptheo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

int	find_move_utils(t_data *data, char *line)
{
	if (ft_strcmp(line, RRA) == 0)
		reverse_rotate_check(data->stack_a);
	else if (ft_strcmp(line, RRB) == 0)
		reverse_rotate_check(data->stack_b);
	else if (ft_strcmp(line, RRR) == 0)
	{
		reverse_rotate_check(data->stack_b);
		reverse_rotate_check(data->stack_a);
	}
	else
		return (-1);
}

int	find_move(t_data *data, char *line)
{
	if (ft_strcmp(line, SA) == 0)
		swap_check(data->stack_a);
	else if (ft_strcmp(line, SB) == 0)
		swap_check(data->stack_b);
	else if (ft_strcmp(line, SS) == 0)
	{
		swap_check(data->stack_a);
		swap_check(data->stack_b);
	}
	else if (ft_strcmp(line, PA) == 0)
		push_check(data->stack_b, data->stack_a);
	else if (ft_strcmp(line, PB) == 0)
		push_check(data->stack_a, data->stack_b);
	else if (ft_strcmp(line, RA) == 0)
		rotate_check(data->stack_a);
	else if (ft_strcmp(line, RB) == 0)
		rotate_check(data->stack_b);
	else if (ft_strcmp(line, RR) == 0)
	{
		rotate_check(data->stack_b);
		rotate_check(data->stack_a);
	}
	else
		return (find_move_utils(data, line));
	return (1);
}

int	checker_move(t_data	*data)
{
	char	*line;

	line = get_next_line(0);
	while (line)
	{
		if (find_move(data, line) == -1)
			return (ft_putstr_fd("Error\n", 2), free(line), -1);
		free(line);
		line = get_next_line(0);
	}
	if (is_sorted_check(data->stack_a, data->stack_b))
		return (ft_putstr_fd("OK\n", 1), 1);
	else
		return (ft_putstr_fd("KO\n", 1), -1);
}
