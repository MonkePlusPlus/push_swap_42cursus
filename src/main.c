/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptheo <ptheo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 15:41:04 by ptheo             #+#    #+#             */
/*   Updated: 2024/07/31 19:33:17 by ptheo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	main(int ac, char **av)
{
	t_stack	*stack;
	char	**list;

	if (ac > 1)
	{
		list = split_arg(ac, av);
		stack = create_stack(len_lst(list), list);
		free_error(list, len_lst(list));
		if (stack != NULL)
		{
			print_stack(stack);
			free_stack(stack);
		}
		else
			ft_putstr_fd("Error\n", 1);
	}
	else
		ft_putstr_fd("Error\n", 1);
	return (0);
}
