/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nodeadd_back.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: weitwang <weitwang@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/28 15:11:50 by weit              #+#    #+#             */
/*   Updated: 2026/11/08 23:46:59 by weitwang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
从当前 node 开始，一直沿着 next 往后走，
找到链表最后一个 node，
然后把它的地址返回。
*/
static t_node	*ft_nodelast(t_node *node)
{
	if (!node)
		return (NULL);
	while (node->next)
	{
		node = node->next;
	}
	return (node);
}

/*
把一个新的 node 加到链表（stack）的最后面。
*/
void	ft_nodeadd_back(t_node **node, t_node *new)
{
	if (!node || !new)
		return ;
	if (!*node) // 如果当前 stack 是空的。
		*node = new;
	else
		ft_nodelast(*node)->next = new;
}
