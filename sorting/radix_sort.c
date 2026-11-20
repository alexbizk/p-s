/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: weitwang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/08 23:46:24 by weitwang          #+#    #+#             */
/*   Updated: 2026/11/20 01:19:59 by weitwang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_max_bits(int max_index)
{
	int	bits;

	bits = 0;
	while (max_index > 0)
	{
		max_index = max_index >> 1;
		bits++;
	}
	return (bits);
}

static void	sort_by_bit(t_node **a, t_node **b,
	int bit_position, int node_count)
{
	int	i;

	i = 0;
	while (i < node_count)
	{
		if (((*a)->index >> bit_position) & 1)
			ra(a);
		else
			pb(a, b);
		i++;
	}
	while (*b)
		pa(a, b);
}

void	radix_sort(t_node **a, t_node **b)
{
	int	node_count;
	int	bit_count;
	int	bit_position;
	int	max_index;

	node_count = stack_size(*a);
	max_index = node_count - 1;
	bit_count = get_max_bits(max_index);
	bit_position = 0;
	while (bit_position < bit_count)
	{
		sort_by_bit(a, b, bit_position, node_count);
		bit_position++;
	}
}
