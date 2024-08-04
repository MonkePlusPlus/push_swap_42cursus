/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptheo <ptheo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 15:41:04 by ptheo             #+#    #+#             */
/*   Updated: 2024/08/04 21:03:34 by ptheo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	main(int ac, char **av)
{
	t_stack	*stack;
	t_cell	**tab;
	char	**list;
	int		size;

	if (ac > 1)
	{
		list = split_arg(ac, av);
		size = len_lst(list);
		stack = create_stack(size, list, tab);
		free_error(list, size);
		if (stack != NULL)
		{
			//print_stack(stack);
			print_tab(tab, size);
			//second_algo(stack);
			//print_stack(stack);
			free_stack(stack);
		}
		else
			ft_putstr_fd("Error\n", 2);
	}
	else
		ft_putstr_fd("Error\n", 2);
	return (0);
}
