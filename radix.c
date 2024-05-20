/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaolivei <yaolivei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 19:23:20 by yaolivei          #+#    #+#             */
/*   Updated: 2024/04/26 13:45:33 by yaolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	count_max_bit(t_stack *a)
{
	int		i;
	int		n_bits;
	t_node	*temp;

	i = -1;
	temp = a->first;
	while (temp)
	{
		if (i < temp->index)
			i = temp->index;
		temp = temp->next;
	}
	n_bits = 31;
	while ((i >> n_bits & 1) != 1)
	{
		n_bits--;
	}
	return (n_bits);
}

void	radix(t_stack *a, t_stack *b)
{
	int	bit_max;
	int	i;
	int	bit;

	bit_max = count_max_bit(a);
	list_len(a);
	bit = 0;
	while (bit <= bit_max)
	{
		i = a->large;
		while (i > 0)
		{
			if (((a->first->index >> bit) & 1) == 0)
				push_b(a, b);
			else if (((a->first->index >> bit) & 1) == 1)
				rotate_a(a);
			i--;
		}
		while (b->large > 0)
			push_a(b, a);
		bit++;
	}
}
