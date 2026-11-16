/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_reverse.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: weitwang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/08 23:53:11 by weitwang          #+#    #+#             */
/*   Updated: 2026/11/16 18:58:44 by weitwang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_node **a)
{
	if (!a || !*a || !(*a)->next)
		return ;
	reverse_rotate_nodes(a);
	put_op("rra", OP_RRA);
}

void	rrb(t_node **b)
{
	if (!b || !*b || !(*b)->next)
		return ;
	reverse_rotate_nodes(b);
	put_op("rrb", OP_RRB);
}

void	rrr(t_node **a, t_node **b)
{
	if ((!a || !*a || !(*a)->next)
		&& (!b || !*b || !(*b)->next))
		return ;
	reverse_rotate_nodes(a);
	reverse_rotate_nodes(b);
	put_op("rrr", OP_RRR);
}
