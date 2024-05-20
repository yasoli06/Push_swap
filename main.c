/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaolivei <yaolivei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 19:15:19 by yaolivei          #+#    #+#             */
/*   Updated: 2024/05/20 17:07:06 by yaolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	create_ring(t_stack *a, int ac, char **av)
{
	int		j;
	int		first_flag;
	t_node	*temp;
	t_node	*new;

	j = 1;
	first_flag = 1;
	while (j < ac)
	{
		new = malloc(sizeof(t_node) * 1);
		if (!new)
			return (0);
		new->value = ft_atoi(av[j]);
		if (first_flag == 1)
		{
			a->first = new;
			first_flag = 0;
		}
		else
			temp->next = new;
		new->next = NULL;
		temp = new;
		j++;
	}
	return (0);
}

int	check_dup(int ac, char **av)
{
	int		j;
	int		i;

	j = 1;
	while (j < ac)
	{
		i = j + 1;
		while (i < ac)
		{
			if (ft_atoi(av[j]) == ft_atoi(av[i]))
				return (1);
			i++;
		}
		j++;
	}
	return (0);
}

int	check_int(int ac, char **av)
{
	int	i;
	int	j;

	j = 1;
	while (j < ac)
	{
		i = 0;
		if (av[j][0] == '-')
			i++;
		while (av[j][i])
		{
			if (av[j][i] < '0' || av[j][i] > '9')
				return (1);
			i++;
		}
		j++;
	}
	return (0);
}

int	check_args(int ac, char **av)
{
	int	i;

	i = 0;
	if (ac <= 2)
		return (0);
	if (check_int(ac, av))
		return (0);
	if (check_dup(ac, av))
		return (0);
	if (check_min_max(ac, av))
		return (0);
	return (1);
}

int	main(int ac, char **av)
{
	t_stack	a;
	t_stack	b;

	a.large = 0;
	b.large = 0;
	a.first = NULL;
	a.first = NULL;
	if (check_args(ac, av) == 0)
	{
		write(1, "Error1\n", 7);
		return (0);
	}
	create_ring(&a, ac, av);
	assign_index(a.first);
	if (stack_sorted(&a))
		return (0);
	list_len(&a);
	list_len(&b);
	sort_stack(&a, &b);
	free_list(&a);
	return (0);
}
