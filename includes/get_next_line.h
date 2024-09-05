/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptheo <ptheo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 19:02:21 by ptheo             #+#    #+#             */
/*   Updated: 2024/09/05 17:02:00 by ptheo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

char	*get_next_line(int fd);
char	*ft_get_strdup(char *s);
char	*ft_concat(char *s1, char *s2, size_t len);
char	*ft_get_calloc(size_t size, size_t number);
char	**resmalloc(int len, int len_f);
char	**rebuf(char *buf, int len);
char	*ft_get_strlcpy(char *dest, char *src, int start, int end);
void	ft_get_bzero(char *str, size_t size);
int		check_n_len(char *buf, int len);

#endif