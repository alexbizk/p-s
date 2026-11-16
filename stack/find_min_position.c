/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_min_position.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: weitwang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/16 17:20:04 by weitwang          #+#    #+#             */
/*   Updated: 2026/11/16 17:37:56 by weitwang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_min_position(t_node *stack)
{
	int	position;
	int	min_index;
	int	min_position;

	position = 0;
	min_index = stack->index;
	min_position = 0;
	while (stack)
	{
		if (stack->index < min_index)
		{
			min_index = stack->index;
			min_position = position;
		}
		position++;
		stack = stack->next;
	}
	return (min_position);
}
