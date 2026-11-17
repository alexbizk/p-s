/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: weitwang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/17 15:52:13 by weitwang          #+#    #+#             */
/*   Updated: 2026/11/17 15:52:15 by weitwang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_node **a)
{
	int	max_pos;

	max_pos = find_max_position(*a);
	if (max_pos == 0)
		ra(a);
	else if (max_pos == 1)
		rra(a);
	if ((*a)->index > (*a)->next->index)
		sa(a);
}
