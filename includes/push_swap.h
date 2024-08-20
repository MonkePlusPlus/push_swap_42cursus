/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptheo <ptheo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 15:28:35 by ptheo             #+#    #+#             */
/*   Updated: 2024/08/20 18:16:45 by ptheo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdint.h>

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

# define TOPA 1
# define TOPB 2
# define BOTA 3
# define BOTB 4

/* STACK STRUCT */

typedef struct	s_cell
{
	int				n;
	int				index;
	struct s_cell	*next;
	struct s_cell	*previous;
}				t_cell;

typedef struct	s_stack
{
	t_cell	*first;
	t_cell	*end;
	int		middle;
}				t_stack;

/* STACK FUNCTION */
void	ft_push_instack(t_stack *stack, t_cell *new);
void	free_stack(t_stack *stack);
t_stack	*new_stack(void);
t_cell	*new_cell(int n);
int		is_sorted(t_stack *stack_a, t_stack *stack_b, int size, int pos);
int 	is_empty(t_stack *stack);

/* STACK MOUVEMENT */
void	ft_swap(t_stack *stack, char a);
void	ft_push(t_stack *stack_1, t_stack *stack_2, char a);
void	ft_rotate(t_stack *stack, char a);
void	ft_reverse_rotate(t_stack *stack, char a);

/* PARSING */
int		check_number(char *nbr);
t_stack *create_stack(int size, char **number, t_cell ***tab);
char	**split_arg(int ac, char **av);
int		len_lst(char **lst);

/* PRINT */
void    print_stack(t_stack *stack);
void	ft_putstr_fd(const char *str, int fd);
void	print_tab(t_cell **tab, int size);

/* UTILS */
int		ft_atoi(const char *nptr);
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
//int	sort_stack(t_stack *stack_a);
//int	second_algo(t_stack *stack_a);
int		algo_index(t_cell ***tab, int low, int high);
int		sort_stack(t_stack *stack_a, int size);
void	new_algo(t_stack *stack_a, t_stack *stack_b, int size, int pos);

#endif