/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_sort_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptheo <ptheo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 16:43:15 by ptheo             #+#    #+#             */
/*   Updated: 2024/09/05 15:18:08 by ptheo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sort_for_three_only(t_data *data, t_split *split)
{
	t_cell	*current;

	current = data->stack_a->first;
	if (current->index < current->next->index && current->next->index
		> current->next->next->index && current->index
		< current->next->next->index)
		ft_swap(data, data->stack_a, 'a');
	current = data->stack_a->first;
	if (current->index > current->next->index && current->index
		> current->next->next->index)
		ft_rotate(data, data->stack_a, 'a');
	current = data->stack_a->first;
	if (current->index > current->next->index && current->index
		< current->next->next->index)
		ft_swap(data, data->stack_a, 'a');
	current = data->stack_a->first;
	if (current->index < current->next->index && current->index
		> current->next->next->index)
		ft_reverse_rotate(data, data->stack_a, 'a');
}
