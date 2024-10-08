/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptheo <ptheo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 15:28:35 by ptheo             #+#    #+#             */
/*   Updated: 2024/09/05 18:24:14 by ptheo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdint.h>
# include <limits.h>

# define WHITE_SPACE " \f\n\r\t\v"

# define SA "sa\n"
# define SB "sb\n"
# define SS "ss\n"
# define PA "pa\n"
# define PB "pb\n"
# define RA "ra\n"
# define RB "rb\n"
# define RR "rr\n"
# define RRA "rra\n"
# define RRB "rrb\n"
# define RRR "rrr\n"

# define M_SA 1
# define M_SB 2
# define M_SS 3
# define M_PA 4
# define M_PB 5
# define M_RA 6
# define M_RB 7
# define M_RR 8
# define M_RRA 9
# define M_RRB 10
# define M_RRR 11

# define TOPA 1
# define TOPB 2
# define BOTA 3
# define BOTB 4

/* STACK STRUCT */

typedef struct s_cell
{
	long			n;
	int				index;
	struct s_cell	*next;
	struct s_cell	*previous;
}				t_cell;

typedef struct s_stack
{
	t_cell	*first;
	t_cell	*end;
	int		size;
}				t_stack;

typedef struct s_split
{
	int	size;
	int	pos;
	int	split_max;
	int	split_min;
	int	max;
	int	min;
	int	size_max;
	int	size_mid;
	int	size_min;
}				t_split;

typedef struct s_ssplit
{
	t_split	*smax;
	t_split	*smid;
	t_split	*smin;
}				t_ssplit;

typedef struct s_data
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	t_stack	*move;
	t_cell	**tab;
}				t_data;

/* STACK FUNCTION */
void	ft_push_instack(t_stack *stack, t_cell *new);
void	free_stack(t_stack *stack);
t_stack	*new_stack(int size);
t_cell	*new_cell(long n);
int		is_sorted(t_stack *stack_a, t_stack *stack_b);
int		is_empty(t_stack *stack);

/* STACK MOUVEMENT */
void	ft_swap(t_data *data, t_stack *stack, char a);
void	ft_push(t_data *data, t_stack *stack_1, t_stack *stack_2, char a);
void	ft_rotate(t_data *data, t_stack *stack, char a);
void	ft_reverse_rotate(t_data *data, t_stack *stack, char a);

/* PARSING */
int		check_number(char *nbr);
t_stack	*create_stack(int size, char **number, t_cell ***tab);
int		create_stack_utils(t_stack *stack, char **number, t_cell ***tab, int i);
char	**split_arg(int ac, char **av);
int		len_lst(char **lst);
int		check_nbrdup(t_stack *stack, long nbr);

/* PRINT */
void	print_stack(t_stack *stack);
void	ft_putstr_fd(const char *str, int fd);
void	print_tab(t_cell **tab, int size);

/* UTILS */
long	ft_atoi(const char *nptr);
char	*ft_strjoin(char *s1, char const *s2);
size_t	ft_strlen(const char *str);

/* SPLIT */
int		check_char(char s, char *c);
char	**better_split(char const *s, char *c);
int		check_ifc(char const *s, int i, char *c);
int		count_words(char const *s, char *c);
void	fullfill(char const *s, char *result, int start, int end);
void	*free_error(char **p, int index);

/* ALGORITHM */
int		algo_index(t_cell ***tab, int low, int high);
void	new_algo(t_stack *stack_a, t_stack *stack_b, int size, int pos);

/* HOPE PROJECT */
int		push_swap(char **list, int size);
void	split_topa(t_data *data, t_split *split);
void	split_topb(t_data *data, t_split *split);
void	split_bota(t_data *data, t_split *split);
void	split_botb(t_data *data, t_split *split);
t_split	*new_split(int size, int pos);
int		algo_hope(t_data *data, t_split *split);
void	split_pos(t_data *data, t_split *split);
void	free_ssplit(t_ssplit *ssplit);
void	get_limit(t_data *data, t_split *split);
t_cell	*get_end(t_stack *stack);
t_cell	*get_first(t_data *data, t_split *split);
void	get_number(t_split *split);;
void	ft_freeall(t_data *data, t_split *split);
void	split_utils(t_data *data, t_split *split);

/* SIMPLE SORT */
void	simple_sort(t_data *data, t_split *split);
void	sort_for_one(t_data *data, t_split *split);
void	sort_for_two(t_data *data, t_split *split);
void	sort_for_three(t_data *data, t_split *split);
void	sort_for_five(t_data *data, t_split *split);
void	sort_for_three_only(t_data *data, t_split *split);

/* MOVE STACK */
int		push_move(t_data *data, int move);
void	print_move(t_cell *current);
void	read_move(t_data *data);
void	delete_cell(t_cell *cell);

/* POST OPTI */
void	post_opti(t_data *data);
void	post_opti_swap_a(t_cell *current);
void	post_opti_swap_b(t_cell *current);
void	post_opti_rotate_a(t_cell *current);
void	post_opti_rotate_b(t_cell *current);
void	post_opti_rrotate_a(t_cell *current);
void	post_opti_rrotate_b(t_cell *current);

#endif