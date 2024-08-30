/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptheo <ptheo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 17:08:50 by ptheo             #+#    #+#             */
/*   Updated: 2024/08/30 00:57:49 by ptheo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	len_lst(char **lst)
{
	int	i;

	i = 0;
	while (lst[i])
		i++;
	return (i);
}

char	**split_arg(int ac, char **av)
{
	char	**result;
	char	*join;
	int		i;

	i = 1;
	join = NULL;
	while (i < ac)
	{
		join = ft_strjoin(join, av[i]);
		i++;
	}
	result = better_split(join, WHITE_SPACE);
	free(join);
	return (result);
}

int	check_number(char *nbr)
{
	int	i;

	i = 0;
	if (nbr[i] == '-' || nbr[i] == '+')
		i++;
	while (nbr[i])
	{
		if (!(nbr[i] >= '0' && nbr[i] <= '9'))
			return (0);
		i++;
	}
	return (1);
}

t_stack	*create_stack(int size, char **number, t_cell ***tab)
{
	t_stack	*stack;
	t_cell	*temp;
	int		i;

	i = size - 1;
	stack = new_stack(size);
	if (stack == NULL)
		return (NULL);
	*tab = (t_cell **)malloc(sizeof(t_cell *) * (size));
	if (*tab == NULL)
		return (NULL);
	while (i >= 0)
	{
		if (!check_number(number[i]))
			return (free_stack(stack), NULL);
		else
		{
			temp = new_cell(ft_atoi(number[i]));
			if (temp == NULL)
				return (free_stack(stack), NULL);
			temp->index = i;
			(*tab)[i] = temp;
			ft_push_instack(stack, temp);
		}
		i--;
	}
	return (stack);
}
