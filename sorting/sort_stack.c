/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: weitwang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/15 23:09:32 by weitwang          #+#    #+#             */
/*   Updated: 2026/11/16 19:52:37 by weitwang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_stack(t_node **a, t_node **b, int strategy)
{
	if (strategy == STRAT_SIMPLE)
		simple_sort(a, b);
	else if (strategy == STRAT_MEDIUM)
		medium_sort(a, b);
	else if (strategy == STRAT_COMPLEX)
		radix_sort(a, b);
	else
		adaptive_sort(a, b);
}
