/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptheo <ptheo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 17:20:58 by ptheo             #+#    #+#             */
/*   Updated: 2024/09/05 15:15:32 by ptheo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	simple_sort(t_data *data, t_split *split)
{
	if (split->size == 1)
		sort_for_one(data, split);
	else if (split->size == 2)
		sort_for_two(data, split);
	else if (split->size == 3)
		sort_for_three(data, split);
	else if (data->stack_a->size == 5 && data->stack_b->size == 0)
		sort_for_five(data, split);
}

void	sort_for_one(t_data *data, t_split *split)
{
	if (split->pos == TOPB)
		ft_push(data, data->stack_b, data->stack_a, 'a');
	else if (split->pos == BOTA)
		ft_reverse_rotate(data, data->stack_a, 'a');
	else if (split->pos == BOTB)
	{
		ft_reverse_rotate(data, data->stack_b, 'b');
		ft_push(data, data->stack_b, data->stack_a, 'a');
	}
}

void	sort_for_two(t_data *data, t_split *split)
{
	t_cell	*current;

	sort_for_one(data, split);
	sort_for_one(data, split);
	current = data->stack_a->first;
	if (current->index > current->next->index)
		ft_swap(data, data->stack_a, 'a');
}

void	sort_for_three(t_data *data, t_split *split)
{
	t_cell	*current;

	if (data->stack_a->size == 3 && data->stack_b->size == 0)
	{
		sort_for_three_only(data, split);
		return ;
	}
	sort_for_one(data, split);
	sort_for_one(data, split);
	sort_for_one(data, split);
	current = data->stack_a->first;
	if (current->index > current->next->index
		&& current->index > current->next->next->index)
		ft_swap(data, data->stack_a, 'a');
	current = data->stack_a->first;
	if (current->next->index > current->index && current->next->index
		> current->next->next->index)
	{
		ft_rotate(data, data->stack_a, 'a');
		ft_swap(data, data->stack_a, 'a');
		ft_reverse_rotate(data, data->stack_a, 'a');
	}
	split->pos = TOPA;
	sort_for_two(data, split);
}

void	sort_for_five(t_data *data, t_split *split)
{
	t_cell	*current;
	int		good;

	current = data->stack_a->first;
	good = 0;
	while (good < 2)
	{
		if (current->index == 1 || current->index == 2)
		{
			ft_push(data, data->stack_a, data->stack_b, 'b');
			good++;
		}
		else
			ft_rotate(data, data->stack_a, 'a');
		current = data->stack_a->first;
	}
	sort_for_three_only(data, split);
	ft_push(data, data->stack_b, data->stack_a, 'a');
	ft_push(data, data->stack_b, data->stack_a, 'a');
	sort_for_two(data, split);
}
