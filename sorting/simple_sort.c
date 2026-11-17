/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: weitwang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/09 16:33:01 by weitwang          #+#    #+#             */
/*   Updated: 2026/11/17 16:35:45 by weitwang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	move_min_to_top(t_node **a, int position, int node_count)
{
	if (position <= node_count / 2)
	{
		while (position > 0)
		{
			ra(a);
			position--;
		}
	}
	else
	{
		while (position < node_count)
		{
			rra(a);
			position++;
		}
	}
}

void	simple_sort(t_node **a, t_node **b)
{
	int	position;
	int	node_count;

	if (!*a || is_sorted(*a))
		return ;
	while (*a)
	{
		node_count = stack_size(*a);
		position = find_min_position(*a);
		move_min_to_top(a, position, node_count);
		pb(a, b);
	}
	while (*b)
		pa(a, b);
}
