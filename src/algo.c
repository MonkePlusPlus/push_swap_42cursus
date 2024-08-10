/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptheo <ptheo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 15:09:15 by ptheo             #+#    #+#             */
/*   Updated: 2024/08/10 18:06:03 by ptheo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_lswap(t_cell **t1, t_cell **t2)
{
	t_cell	*temp;
	int		index;

	temp = *t1;
	*t1 = *t2;
	*t2 = temp;
}

int	partition(t_cell ***tab, int low, int high)
{
	t_cell	**t;
	int		pivot;
	int		i;
	int		j;

	t = *tab;
	pivot = t[high]->n;
	i = low - 1;
	j = low;
	while (j <= high - 1)
	{
		if (t[j]->n < pivot)
		{
			i++;
			ft_lswap(&t[i], &t[j]);
		}
		j++;
	}
	ft_lswap(&t[i + 1], &t[high]);
	return (i + 1);
}

void	give_index(t_cell ***tab, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		(*tab)[i]->index = i;
		i++;
	}
}

int	algo_index(t_cell ***tab, int low, int high)
{
	int	pivot;

	if (low < high)
	{
		pivot = partition(tab, low, high);
		algo_index(tab, low, pivot - 1);
		algo_index(tab, pivot + 1, high);
	}
	give_index(tab, high + 1);
	return (1);
}

/*
int	sort_stack(t_stack *stack_a)
{
	t_stack *stack_b;
	t_cell	*cell_a;
	t_cell	*cell_b;
	int		good;

	good = 0;
	stack_b = new_stack();
	while (!good)
    {
		cell_a = stack_a->first;
		cell_b = stack_b->first;
		if (is_sorted(stack_a, 0) && is_empty(stack_b))
			good = 1;
		else if (is_sorted(stack_b, 1) && (is_empty(stack_a) || is_sorted(stack_a, 0)) && cell_a->n > cell_b->n)
			ft_push(stack_b, stack_a, 'a');
		else if (cell_a && cell_a->next && cell_a->n > cell_a->next->n)
			ft_swap(stack_a, 'a');
		else if (cell_a && cell_a->n > stack_a->end->n)
			ft_reverse_rotate(stack_a, 'a');
		else if (cell_a && cell_b && cell_a->n > cell_b->n)
			ft_push(stack_a, stack_b, 'b');
		else if (cell_b && cell_b->n > stack_b->end->n)
			ft_reverse_rotate(stack_b, 'b');
		else if (cell_b && cell_b->n < stack_b->end->n)
			ft_rotate(stack_b, 'b');
		else if (cell_a && cell_b && cell_a->n < stack_b->end->n)
			ft_push(stack_a, stack_b, 'b');
		else if (cell_a && is_empty(stack_b))
			ft_push(stack_a, stack_b, 'b');
		else if (cell_b && cell_b->next && cell_b->n > cell_b->next->n)
			ft_swap(stack_b, 'b');
		else if (cell_a->n > stack_a->middle)
			ft_push(stack_a, stack_b, 'b');
		else if (cell_a->n <= stack_a->middle)
			ft_rotate(stack_a, 'a');
	}
	free_stack(stack_b);
	print_stack(stack_a);
	return (1);
}

int	second_algo(t_stack *stack_a)
{
	t_stack *stack_b;
	t_cell	*cell_a;
	t_cell	*cell_b;
	int		good;
	int		i;

	good = 0;
	i = 0;
	stack_b = new_stack();
	while (!good)
    {
		printf("stack_A : \n");
		print_stack(stack_a);
		printf("stack_B : \n");
		print_stack(stack_b);
		printf("\n");
		cell_a = stack_a->first;
		cell_b = stack_b->first;
		if (is_sorted(stack_a, 0) && is_empty(stack_b))
			good = 1;
		else if (is_sorted(stack_b, 1) && (is_empty(stack_a) || (is_sorted(stack_a, 0) && cell_a && cell_b && cell_a->n >= cell_b->n)))
			ft_push(stack_b, stack_a, 'a');
		else if (cell_a && cell_a->next && cell_a->n > cell_a->next->n)
			ft_swap(stack_a, 'a');
		else if (cell_a && is_empty(stack_b))
			ft_push(stack_a, stack_b, 'b');
		else if (cell_a && cell_b && cell_a->n >= cell_b->n)
			ft_push(stack_a, stack_b, 'b');
		else if (cell_a && cell_b && cell_a->n < cell_b->n)
			ft_rotate(stack_b, 'b');
		else if (cell_b && cell_b->n <= stack_b->end->n)
			ft_rotate(stack_b, 'b');
		else if (cell_b && cell_b->next && cell_b->n > cell_b->next->n)
			ft_swap(stack_b, 'b');
		else if (cell_a && cell_b && cell_a->n <= stack_b->end->n)
			ft_push(stack_a, stack_b, 'b');
		else
			ft_push(stack_b, stack_a, 'a');
		i++;
	}
	print_stack(stack_a);
	return (0);
}*/