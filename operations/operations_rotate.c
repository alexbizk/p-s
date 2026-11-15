/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_rotate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: weitwang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/08 23:52:55 by weitwang          #+#    #+#             */
/*   Updated: 2026/11/09 00:00:15 by weitwang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_node **a)
{
	if (!a || !*a || !(*a)->next)
		return ;
	rotate_nodes(a);
	ft_putendl_fd("ra", 1);
}

void	rb(t_node **b)
{
	if (!b || !*b || !(*b)->next)
		return ;
	rotate_nodes(b);
	ft_putendl_fd("rb", 1);
}

void	rr(t_node **a, t_node **b)
{
	if ((!a || !*a || !(*a)->next)
		&& (!b || !*b || !(*b)->next))
		return ;
	rotate_nodes(a);
	rotate_nodes(b);
	ft_putendl_fd("rr", 1);
}
