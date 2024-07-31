/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptheo <ptheo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 17:28:25 by ptheo             #+#    #+#             */
/*   Updated: 2024/07/31 19:35:43 by ptheo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	check_char(char s, char *c)
{
	int	i;

	i = 0;
	while (c[i])
	{
		if (c[i] == s)
			return (1);
		i++;
	}
	return (0);
}

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str != NULL && str[i])
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char const *s2)
{
	char	*str;
	int		index;
	int		i;

	i = 0;
	index = 0;
	str = malloc((ft_strlen((char *)s1)
				+ ft_strlen((char *)s2) + 2) * sizeof(char));
	if (!str)
		return (NULL);
	while (s1 != NULL && s1[i])
	{
		str[index++] = s1[i++];
	}
	i = 0;
	while (s2[i])
	{
		str[index++] = s2[i];
		i++;
	}
	str[index] = ' ';
	str[index + 1] = '\0';
	if (s1)
		free(s1);
	return (str);
}

int	ft_atoi(const char *nptr)
{
	int	i;
	int	result;
	int	signe;

	i = 0;
	result = 0;
	signe = 1;
	while ((nptr[i] >= '\t' && nptr[i] <= '\r') || nptr[i] == 32)
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			signe = -signe;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		result = result * 10 + (nptr[i] - '0');
		i++;
	}
	return (result * signe);
}
