/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptheo <ptheo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 17:23:33 by ptheo             #+#    #+#             */
/*   Updated: 2024/09/04 17:29:03 by ptheo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	print_stack(t_stack *stack)
{
	t_cell	*current;

	current = stack->first;
	while (current != NULL)
	{
		printf("%ld : %d\n", current->n, current->index);
		current = current->next;
	}
	printf("end\n");
}

void	ft_putstr_fd(const char *str, int fd)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(fd, &str[i], 1);
		i++;
	}
}

void	print_tab(t_cell **tab, int size)
{
	int	i;

	i = 0;
	if (tab == NULL)
		return ;
	while (i < size)
	{
		printf("%ld:%d / ", tab[i]->n, tab[i]->index);
		i++;
	}
}
