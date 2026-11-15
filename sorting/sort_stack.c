/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: weitwang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/15 23:09:32 by weitwang          #+#    #+#             */
/*   Updated: 2026/11/15 23:17:10 by weitwang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_stack(t_node **a, t_node **b)
{
	int	size;

	size = stack_size(*a);
	if (size <= 5)
		simple_sort(a, b);
	else if (size <= 100)
		medium_sort(a, b);
	else
		radix_sort(a, b);
}
