/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_max_position.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: weitwang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/16 17:22:12 by weitwang          #+#    #+#             */
/*   Updated: 2026/11/16 17:32:33 by weitwang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_max_position(t_node *stack)
{
	int	position;
	int	max_index;
	int	max_position;

	position = 0;
	max_index = stack->index;
	max_position = 0;
	while (stack)
	{
		if (stack->index > max_index)
		{
			max_index = stack->index;
			max_position = position;
		}
		position++;
		stack = stack->next;
	}
	return (max_position);
}
