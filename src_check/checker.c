/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptheo <ptheo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 16:42:22 by ptheo             #+#    #+#             */
/*   Updated: 2024/09/05 18:52:38 by ptheo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

int	checker(char **list, int size)
{
	t_data	data;
	t_split	*split;

	data.tab = NULL;
	split = NULL;
	data.move = NULL;
	data.stack_a = create_stack(size, list, &data.tab);
	data.stack_b = new_stack(0);
	free_error(list, size);
	if (data.stack_a != NULL && data.stack_b != NULL)
	{
		checker_move(&data);
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
		checker(list, size);
	}
	return (0);
}
