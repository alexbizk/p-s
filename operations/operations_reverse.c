/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_reverse.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: weitwang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/08 23:53:11 by weitwang          #+#    #+#             */
/*   Updated: 2026/11/09 00:00:11 by weitwang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_node **a)
{
	if (!a || !*a || !(*a)->next)
		return ;
	reverse_rotate_nodes(a);
	ft_putendl_fd("rra", 1);
}

void	rrb(t_node **b)
{
	if (!b || !*b || !(*b)->next)
		return ;
	reverse_rotate_nodes(b);
	ft_putendl_fd("rrb", 1);
}

void	rrr(t_node **a, t_node **b)
{
	if ((!a || !*a || !(*a)->next)
		&& (!b || !*b || !(*b)->next))
		return ;
	reverse_rotate_nodes(a);
	reverse_rotate_nodes(b);
	ft_putendl_fd("rrr", 1);
}
