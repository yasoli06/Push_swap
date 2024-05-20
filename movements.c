/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaolivei <yaolivei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 18:52:29 by yaolivei          #+#    #+#             */
/*   Updated: 2024/04/26 13:41:48 by yaolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rr_a(t_stack *a)
{
	t_node	*last;
	t_node	*temp;

	temp = a->first;
	last = a->first;
	if (a == NULL || a->first == NULL)
		return ;
	while (temp->next != NULL)
	{
		last = temp;
		temp = temp->next;
	}
	last->next = NULL;
	temp->next = a->first;
	a->first = temp;
	write(1, "rra\n", 4);
}

void	rotate_a(t_stack *a)
{
	t_node	*temp;
	t_node	*last;

	temp = a->first;
	last = a->first;
	if (a == NULL || a->first == NULL)
		return ;
	while (last->next != NULL)
	{
		last = last->next;
	}
	a->first = temp->next;
	last->next = temp;
	temp->next = NULL;
	write(1, "ra\n", 3);
}

void	swap(t_stack *stack)
{
	t_node	*temp;
	t_node	*swap;

	temp = stack->first;
	swap = stack->first;
	temp = temp->next;
	swap->next = temp->next;
	temp->next = swap;
	stack->first = temp;
	write(1, "sa\n", 3);
}

void	push_b(t_stack *a, t_stack *b)
{
	t_node	*temp;

	temp = a->first;
	a->first = temp->next;
	if (b->first == NULL)
		temp->next = NULL;
	else
		temp->next = b->first;
	b->first = temp;
	b->large++;
	a->large--;
	write(1, "pb\n", 3);
}

void	push_a(t_stack *b, t_stack *a)
{
	t_node	*temp;

	temp = b->first;
	b->first = temp->next;
	if (a->first == NULL)
		temp->next = NULL;
	else
		temp->next = a->first;
	a->first = temp;
	a->large++;
	b->large--;
	write(1, "pa\n", 3);
}
