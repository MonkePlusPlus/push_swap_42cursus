/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptheo <ptheo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 16:42:51 by ptheo             #+#    #+#             */
/*   Updated: 2024/09/05 18:51:15 by ptheo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdint.h>
# include <limits.h>
# include "push_swap.h"
# include "get_next_line.h"

int		checker(char **list, int size);
int		checker_move(t_data	*data);
int		find_move(t_data *data, char *line);
int		find_move_utils(t_data *data, char *line);
int		ft_strcmp(const char *s1, const char *s2);
void	swap_check(t_stack *stack);
void	push_check(t_stack *stack_1, t_stack *stack_2);
void	rotate_check(t_stack *stack);
void	reverse_rotate_check(t_stack *stack);
int		is_sorted_check(t_stack *stack_a, t_stack *stack_b);

#endif