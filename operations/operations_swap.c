/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_swap.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: weitwang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/08 23:53:03 by weitwang          #+#    #+#             */
/*   Updated: 2026/11/09 00:00:19 by weitwang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_node **a)
{
	if (!a || !*a || !(*a)->next)
		return ;
	swap_nodes(a);
	ft_putendl_fd("sa", 1);
}

void	sb(t_node **b)
{
	if (!b || !*b || !(*b)->next)
		return ;
	swap_nodes(b);
	ft_putendl_fd("sb", 1);
}

void	ss(t_node **a, t_node **b)
{
	if ((!a || !*a || !(*a)->next) && (!b || !*b || !(*b)->next))
		return ;
	swap_nodes(a);
	swap_nodes(b);
	ft_putendl_fd("ss", 1);
}
