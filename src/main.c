/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptheo <ptheo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 15:41:04 by ptheo             #+#    #+#             */
/*   Updated: 2024/09/04 17:20:18 by ptheo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	push_swap(char **list, int size)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	t_cell	**tab;
	t_split	*split;

	tab = NULL;
	stack_a = create_stack(size, list, &tab);
	stack_b = new_stack(0);
	free_error(list, size);
	split = new_split(size, TOPA);
	if (stack_a != NULL && stack_b != NULL && split != NULL && tab != NULL)
	{
		algo_index(&tab, 0, size - 1);
		algo_hope(stack_a, stack_b, split);
		free_stack(stack_a);
		free_stack(stack_b);
		free(tab);
		free(split);
	}
	else
		return (ft_freeall(stack_a, stack_b, split, tab),
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
	else
		ft_putstr_fd("Error\n", 2);
	return (0);
}
