/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_libft.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaolivei <yaolivei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 12:55:04 by yaolivei          #+#    #+#             */
/*   Updated: 2024/05/20 17:09:21 by yaolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned int	i;

	i = 0;
	while (i < n)
	{
		if (*s1 != *s2 || *s1 == '\0' || *s2 == '\0')
			return (*(unsigned char *)s1 - *(unsigned char *)s2);
		++s1;
		++s2;
		++i;
	}
	return (0);
}

int	check_min_max(int ac, char **av)
{
	int		j;
	int		i;

	j = 1;
	while (j < ac)
	{
		i = 0;
		while (av[j][i] == '-' || av[j][i] == '0')
			i++;
		if (ft_strlen(&av[j][i]) > 10)
			return (1);
		else if (ft_strlen(&av[j][i]) < 10)
			j++;
		else if (av[j][0] == '-')
		{
			if (ft_strncmp(av[j], "-2147483648", 11) > 0)
				return (1);
		}
		else if (ft_strncmp(av[j], "2147483647", 10) > 0)
			return (1);
	}
	return (0);
}
