/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaolivei <yaolivei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 17:04:18 by yaolivei          #+#    #+#             */
/*   Updated: 2024/04/26 13:46:24 by yaolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_atoi(const char *str)
{
	int		num;
	int		mul;

	mul = 1;
	num = 0;
	while (*str == '\n' || *str == ' ' || *str == '\t'
		|| *str == '\v' || *str == '\f' || *str == '\r')
	{
		str++;
	}
	if (*str == '-')
	{
		mul = mul * -1;
		str++;
	}
	else if (*str == '+')
		str++;
	while ((*str >= '0') && (*str <= '9'))
	{
		num = num * 10 + *str - '0';
		str++;
	}
	return (num * mul);
}

int	list_len(t_stack *stack)
{
	t_node	*temp;
	int		i;

	if (stack->first == NULL)
		return (0);
	temp = stack->first;
	i = 0;
	while (temp->next)
	{
		temp = temp->next;
		i++;
	}
	stack->large = i + 1;
	return (i);
}

void	free_list(t_stack *stack)
{
	t_node	*temp;
	t_node	*head;

	head = stack->first;
	while (head)
	{
		temp = head;
		head = head->next;
		free(temp);
	}
}

int	stack_sorted(t_stack *a)
{
	t_node	*temp;

	temp = a->first;
	while (temp->next)
	{
		if (temp->index > temp->next->index)
			return (0);
		temp = temp->next;
	}
	free_list(a);
	return (1);
}

void	assign_index(t_node *lst)
{
	t_node	*temp;
	t_node	*first;
	int		j;

	first = lst;
	while (lst)
	{
		j = 0;
		temp = first;
		while (temp)
		{
			if (temp->value < lst->value)
				j++;
			temp = temp->next;
		}
		lst->index = j;
		lst = lst->next;
	}
}
