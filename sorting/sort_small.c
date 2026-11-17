/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: weitwang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/17 16:02:27 by weitwang          #+#    #+#             */
/*   Updated: 2026/11/17 16:02:32 by weitwang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_small(t_node **a, t_node **b)
{
	int	size;
	int	pos;

	size = stack_size(*a);
	while (size > 3)
	{
		pos = find_min_position(*a);
		if (pos <= size / 2)
			while (pos-- > 0)
				ra(a);
		else
			while (pos++ < size)
				rra(a);
		pb(a, b);
		size--;
	}
	if (size == 3)
		sort_three(a);
	else if (size == 2 && (*a)->index > (*a)->next->index)
		sa(a);
	while (*b)
		pa(a, b);
}
