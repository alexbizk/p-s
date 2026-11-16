/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: weitwang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/09 16:33:01 by weitwang          #+#    #+#             */
/*   Updated: 2026/11/16 17:20:16 by weitwang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	move_min_to_top(t_node **a, int position, int node_count)
{
	if (position <= node_count / 2)
	{
		while (position > 0)
		{
			ra(a);
			position--;
		}
	}
	else
	{
		while (position < node_count)
		{
			rra(a);
			position++;
		}
	}
}

void	simple_sort(t_node **a, t_node **b)
{
	int	position;
	int	node_count;

	if (!*a || is_sorted(*a))//检查 Stack A 是否已经排序
        return ;
	while (*a)
	{
		node_count = stack_size(*a);//    计算 Stack A 当前有多少个节点
		position = find_min_position(*a);//    找到最小节点的位置
		move_min_to_top(a, position, node_count);//    使用 ra 或 rra 把最小节点移动到顶部
		pb(a, b);//    把最小节点放入 Stack B
	}
	while (*b)
		pa(a, b);
}
