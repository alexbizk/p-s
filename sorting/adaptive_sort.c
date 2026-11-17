/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adaptive_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: weitwang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/15 23:15:12 by weitwang          #+#    #+#             */
/*   Updated: 2026/11/17 01:48:10 by weitwang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	adaptive_choice(double disorder)
{
	if (disorder < 0.2)
		return (STRAT_SIMPLE);
	if (disorder < 0.5)
		return (STRAT_MEDIUM);
	return (STRAT_COMPLEX);
}

void	adaptive_sort(t_node **a, t_node **b)
{
	int	choice;

	choice = adaptive_choice(compute_disorder(*a));
	if (choice == STRAT_SIMPLE)
		simple_sort(a, b);
	else if (choice == STRAT_MEDIUM)
		medium_sort(a, b);
	else
		radix_sort(a, b);
}
