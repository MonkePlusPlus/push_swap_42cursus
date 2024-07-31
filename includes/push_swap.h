/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptheo <ptheo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 15:28:35 by ptheo             #+#    #+#             */
/*   Updated: 2024/07/31 19:28:11 by ptheo            ###   ########.fr       */
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

/* STACK STRUCT */

typedef struct	s_cell
{
	int				n;
	struct s_cell	*next;
	struct s_cell	*previous;
}				t_cell;

typedef struct	s_stack
{
	t_cell	*first;
	t_cell	*end;
}				t_stack;

/* STACK FUNCTION */
void	ft_push_instack(t_stack *stack, t_cell *new);
void	free_stack(t_stack *stack);
t_stack	*new_stack();
t_cell	*new_cell(int n);
int		is_sorted(t_stack *stack);

/* STACK MOUVEMENT */
void	ft_swap(t_stack *stack);
void	ft_push(t_stack *stack_1, t_stack *stack_2);
void	ft_rotate(t_stack *stack);
void	ft_reverse_rotate(t_stack *stack);

/* PARSING */
int	check_number(char *nbr);
t_stack *create_stack(int size, char **number);
char	**split_arg(int ac, char **av);
int	len_lst(char **lst);

/* PRINT */
void    print_stack(t_stack *stack);
void	ft_putstr_fd(const char *str, int fd);

/* UTILS */
int		ft_atoi(const char *nptr);
char	*ft_strjoin(char *s1, char const *s2);
size_t	ft_strlen(const char *str);

/* SPLIT */
int	check_char(char s, char *c);
char	**better_split(char const *s, char *c);
int	check_ifc(char const *s, int i, char *c);
int	count_words(char const *s, char *c);
void	fullfill(char const *s, char *result, int start, int end);
void	*free_error(char **p, int index);


#endif