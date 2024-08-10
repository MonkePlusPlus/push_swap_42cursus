/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptheo <ptheo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 15:41:04 by ptheo             #+#    #+#             */
/*   Updated: 2024/08/10 18:25:08 by ptheo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	main(int ac, char **av)
{
	t_stack	*stack;
	t_cell	**tab;
	char	**list;
	int		size;

	tab = NULL;
	if (ac > 1)
	{
		list = split_arg(ac, av);
		size = len_lst(list);
		stack = create_stack(size, list, &tab);
		free_error(list, size);
		if (stack != NULL)
		{
			//print_stack(stack);
			algo_index(&tab, 0, size - 1);
			//print_tab(tab, size);
			//second_algo(stack);
			//print_stack(stack);
			sort_stack(stack, size);
			free_stack(stack);
			free(tab);
		}
		else
			ft_putstr_fd("Error\n", 2);
	}
	else
		ft_putstr_fd("Error\n", 2);
	return (0);
}
