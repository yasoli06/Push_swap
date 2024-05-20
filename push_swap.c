/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaolivei <yaolivei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 15:42:15 by yaolivei          #+#    #+#             */
/*   Updated: 2024/04/26 13:42:48 by yaolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_3(t_stack *a)
{
	t_node	*temp;
	t_node	*last;

	temp = a->first;
	last = a->first;
	last = last->next->next;
	temp = temp->next;
	if (a->first->index > temp->index && a->first->index > last->index)
		rotate_a(a);
	if (temp->index > a->first->index && temp->index > last->index)
		rr_a(a);
	if (a->first->index > a->first->next->index)
		swap(a);
}

void	put_on_top(t_stack *a, int n)
{
	int		i;
	t_node	*temp;

	i = 0;
	temp = a->first;
	while (temp->index != n)
	{
		temp = temp->next;
		i++;
	}
	if (i < a->large / 2)
	{
		while (a->first->index != n)
			rotate_a(a);
	}
	else
	{
		while (a->first->index != n)
			rr_a(a);
	}
}

void	sort_small(t_stack *a, t_stack *b)
{
	put_on_top(a, 0);
	push_b(a, b);
	if (a->large == 4)
	{
		put_on_top(a, 1);
		push_b(a, b);
	}
	sort_3(a);
	while (b->first)
		push_a(b, a);
}

void	sort_max_3(t_stack *a)
{
	t_node	*temp;

	temp = a->first;
	if (list_len(a) <= 3)
	{
		if (a->first->index == 2)
			rotate_a(a);
		else if (temp->next->index == 2)
			rr_a(a);
		if (a->first->index != 0)
			swap(a);
	}
}

void	sort_stack(t_stack *a, t_stack *b)
{
	if (a->large <= 3)
		sort_max_3(a);
	else if (a->large == 4 || a->large == 5)
		sort_small(a, b);
	else if (a->large > 5)
		radix(a, b);
}
