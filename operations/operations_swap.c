/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_swap.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: weitwang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/08 23:53:03 by weitwang          #+#    #+#             */
/*   Updated: 2026/11/16 19:01:14 by weitwang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_node **a)
{
	if (!a || !*a || !(*a)->next)
		return ;
	swap_nodes(a);
	put_op("sa", OP_SA);
}

void	sb(t_node **b)
{
	if (!b || !*b || !(*b)->next)
		return ;
	swap_nodes(b);
	put_op("sb", OP_SB);
}

void	ss(t_node **a, t_node **b)
{
	if ((!a || !*a || !(*a)->next) && (!b || !*b || !(*b)->next))
		return ;
	swap_nodes(a);
	swap_nodes(b);
	put_op("ss", OP_SS);
}
