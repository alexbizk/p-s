/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nodeclear.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: weitwang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/08 23:48:12 by weitwang          #+#    #+#             */
/*   Updated: 2026/11/17 16:24:52 by weitwang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_nodeclear(t_node **node)
{
	t_node	*suit;

	if (!node)
		return ;
	while (*node)
	{
		suit = (*node)->next;
		free(*node);
		*node = suit;
	}
}
