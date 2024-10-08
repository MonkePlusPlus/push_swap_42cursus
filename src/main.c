/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptheo <ptheo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 15:41:04 by ptheo             #+#    #+#             */
/*   Updated: 2024/09/05 16:46:47 by ptheo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	push_swap(char **list, int size)
{
	t_data	data;
	t_split	*split;

	data.tab = NULL;
	data.stack_a = create_stack(size, list, &data.tab);
	data.stack_b = new_stack(0);
	data.move = new_stack(0);
	free_error(list, size);
	split = new_split(size, TOPA);
	if (data.stack_a != NULL && data.stack_b != NULL && split != NULL
		&& data.tab != NULL && data.move != NULL)
	{
		algo_index(&data.tab, 0, size - 1);
		algo_hope(&data, split);
		post_opti(&data);
		read_move(&data);
		ft_freeall(&data, split);
	}
	else
		return (ft_freeall(&data, split),
			ft_putstr_fd("Error\n", 2), -1);
	return (0);
}

int	main(int ac, char **av)
{
	char	**list;
	int		size;

	if (ac > 1)
	{
		list = split_arg(ac, av);
		if (list == NULL)
			return (ft_putstr_fd("Error\n", 2), 1);
		size = len_lst(list);
		push_swap(list, size);
	}
	return (0);
}
