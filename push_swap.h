/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaolivei <yaolivei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 19:13:13 by yaolivei          #+#    #+#             */
/*   Updated: 2024/05/20 16:44:22 by yaolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <limits.h>
# include <limits.h>
# include <unistd.h>
# include <stdio.h>

typedef struct s_node
{
	int				value;
	int				index;
	struct s_node	*next;
}	t_node;

typedef struct s_stack
{
	int		large;
	t_node	*first;
	char	*name;
}	t_stack;

// MAIN // 5
int		create_ring(t_stack *a, int ac, char **av);
int		check_dup(int ac, char **av);
int		check_int(int ac, char **av);
int		check_args(int ac, char **av);

// UTIL // 5
int		ft_atoi(const char *str);
int		list_len(t_stack *stack);
void	free_list(t_stack *stack);
int		stack_sorted(t_stack *a);
//void	print_stack(t_stack *a);
void	assign_index(t_node *lst);

// MOVEMENTS // 5
void	rr_a(t_stack *a);
void	rotate_a(t_stack *a);
void	swap(t_stack *stack);
void	push_b(t_stack *a, t_stack *b);
void	push_a(t_stack *b, t_stack *a);

// PUSH_SWAP // 5
void	sort_3(t_stack *a);
void	put_on_top(t_stack *a, int n);
void	sort_small(t_stack *a, t_stack *b);
void	sort_max_3(t_stack *a);
void	sort_stack(t_stack *a, t_stack *b);

// RADIX // 2
int		count_max_bit(t_stack *a);
void	radix(t_stack *a, t_stack *b);

// UTILS_LIBFT //
size_t	ft_strlen(const char *s);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		check_min_max(int ac, char **av);

#endif