/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: weitwang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/15 22:44:25 by weitwang          #+#    #+#             */
/*   Updated: 2026/11/22 21:21:08 by weitwang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_chunk_size(int size)
{
	int	chunk_size;

	chunk_size = 1;
	while ((long)chunk_size * chunk_size < size)
		chunk_size++;
	return (chunk_size);
}

static void	scan_chunk(t_node **a, t_node **b, int min, int chunk_size)
{
	int	scanned;

	scanned = stack_size(*a);
	while (scanned > 0)
	{
		if ((*a)->index >= min && (*a)->index < min + chunk_size)
		{
			pb(a, b);
			if ((*b)->index < min + chunk_size / 2)
				rb(b);
		}
		else
			ra(a);
		scanned--;
	}
}

static void	push_chunks(t_node **a, t_node **b, int size)
{
	int	chunk_size;
	int	min;

	chunk_size = get_chunk_size(size) * 2;
	min = 0;
	while (min < size)
	{
		scan_chunk(a, b, min, chunk_size);
		min += chunk_size;
	}
}

static void	push_back_to_a(t_node **a, t_node **b, int size)
{
	int	position;

	while (*b)
	{
		position = find_max_position(*b);
		if (position <= size / 2)
		{
			while (position-- > 0)
				rb(b);
		}
		else
		{
			while (position++ < size)
				rrb(b);
		}
		pa(a, b);
		size--;
	}
}

void	medium_sort(t_node **a, t_node **b)
{
	int	size;

	size = stack_size(*a);
	push_chunks(a, b, size);
	push_back_to_a(a, b, size);
}
