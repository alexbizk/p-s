/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: weitwang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/15 22:44:25 by weitwang          #+#    #+#             */
/*   Updated: 2026/11/17 16:23:15 by weitwang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_chunk_size(int node_count)
{
	int	chunk_size;

	chunk_size = 1;
	while (chunk_size * chunk_size < node_count)
		chunk_size++;
	return (chunk_size);
}

static void	move_max_to_top(t_node **b, int position)
{
	int	node_count;

	node_count = stack_size(*b);
	if (position <= node_count / 2)
	{
		while (position > 0)
		{
			rb(b);
			position--;
		}
	}
	else
	{
		while (position < node_count)
		{
			rrb(b);
			position++;
		}
	}
}

static void	push_back_to_a(t_node **a, t_node **b)
{
	int	position;

	while (*b)
	{
		position = find_max_position(*b);
		move_max_to_top(b, position);
		pa(a, b);
	}
}

static void	push_chunk_to_b(t_node **a, t_node **b,
		int chunk_start, int chunk_end)
{
	int	chunk_pushed;

	chunk_pushed = 0;
	while (chunk_pushed < chunk_end - chunk_start + 1)
	{
		if ((*a)->index >= chunk_start && (*a)->index <= chunk_end)
		{
			pb(a, b);
			chunk_pushed++;
		}
		else
			ra(a);
	}
}

void	medium_sort(t_node **a, t_node **b)
{
	int	node_count;
	int	chunk_size;
	int	chunk_start;
	int	chunk_end;

	node_count = stack_size(*a);
	chunk_size = get_chunk_size(node_count);
	chunk_start = 0;
	while (chunk_start < node_count)
	{
		chunk_end = chunk_start + chunk_size - 1;
		if (chunk_end >= node_count)
			chunk_end = node_count - 1;
		push_chunk_to_b(a, b, chunk_start, chunk_end);
		chunk_start += chunk_size;
	}
	push_back_to_a(a, b);
}
