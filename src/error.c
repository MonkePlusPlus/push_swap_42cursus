/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptheo <ptheo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 19:27:22 by ptheo             #+#    #+#             */
/*   Updated: 2024/09/05 15:34:21 by ptheo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_freeall(t_data *data, t_split *split)
{
	if (data->stack_a != NULL)
		free_stack(data->stack_a);
	if (data->stack_b != NULL)
		free_stack(data->stack_b);
	if (split != NULL)
		free(split);
	if (data->tab != NULL)
		free(data->tab);
	if (data->move != NULL)
		free_stack(data->move);
}
