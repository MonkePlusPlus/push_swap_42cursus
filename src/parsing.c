/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptheo <ptheo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 17:08:50 by ptheo             #+#    #+#             */
/*   Updated: 2024/09/05 16:47:34 by ptheo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

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
	if (nbr == NULL || nbr[0] == '\0')
		return (0);
	if (nbr[i] == '-' || nbr[i] == '+')
		i++;
	if (nbr[i] == 0)
		return (0);
	while (nbr[i])
	{
		if (!(nbr[i] >= '0' && nbr[i] <= '9'))
			return (0);
		i++;
	}
	return (1);
}

void	stack_error(t_cell **tab, t_stack *stack)
{
	if (stack == NULL)
		free_stack(stack);
	if (tab == NULL)
		free(tab);
}

int	create_stack_utils(t_stack *stack, char **number, t_cell ***tab, int i)
{
	t_cell	*temp;
	long	nbr;

	nbr = ft_atoi(number[i]);
	if (check_nbrdup(stack, nbr) == -1)
		return (free_stack(stack), -1);
	temp = new_cell(nbr);
	if (temp == NULL)
		return (free_stack(stack), -1);
	temp->index = i;
	(*tab)[i] = temp;
	ft_push_instack(stack, temp);
}

t_stack	*create_stack(int size, char **number, t_cell ***tab)
{
	t_stack	*stack;
	t_cell	*temp;
	int		i;

	i = size - 1;
	stack = new_stack(size);
	*tab = (t_cell **)malloc(sizeof(t_cell *) * (size));
	if (*tab == NULL || stack == NULL || size <= 0)
		return (stack_error(*tab, stack), NULL);
	while (i >= 0)
	{
		if (!check_number(number[i]))
			return (free_stack(stack), NULL);
		else
		{
			if (create_stack_utils(stack, number, tab, i) == -1)
				return (NULL);
		}
		i--;
	}
	return (stack);
}
