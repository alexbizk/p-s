/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_push.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: weitwang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/08 23:53:18 by weitwang          #+#    #+#             */
/*   Updated: 2026/11/09 00:00:07 by weitwang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_node **a, t_node **b)
{
	if (!a || !b || !*b)
		return ;
	push_node(b, a);
	ft_putendl_fd("pa", 1);
}

void	pb(t_node **a, t_node **b)
{
	if (!a || !b || !*a)
		return ;
	push_node(a, b);
	ft_putendl_fd("pb", 1);
}
