/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nodeclear.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: weitwang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/08 23:48:12 by weitwang          #+#    #+#             */
/*   Updated: 2026/11/10 16:12:15 by weitwang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_nodeclear(t_node **node)
{
	t_node	*suit;

	if (!node)
		return ;
	while (*node) /*只要当前还有 node，就继续循环。*/
	{
		suit = (*node)->next;// 这行代码只是让 suit 记住第二个 node 的地址。
		free(*node);//    释放当前 node。
		*node = suit;
	}
}

/*
那为什么 ft_nodeclear() 要使用 t_node **node？
因为我们不仅想读取链表，还想修改外面的变量 a。
*/
