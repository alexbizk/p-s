/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: weitwang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/09 16:35:24 by weitwang          #+#    #+#             */
/*   Updated: 2026/11/17 01:36:03 by weitwang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	assign_index(t_node *stack)
{
	t_node	*current;//指向当前需要计算排名的 node。我现在正在计算哪个数字的排名？
	t_node	*compare;//遍历整个 Stack，寻找比 current 更小的数字。

	current = stack;
	while (current)
	{
		current->index = 0;
		compare = stack;///重制
		while (compare)
		{
			if (compare->value < current->value)//内层循环的目的只有一个：找出 Stack A 中有多少个数字比 current 小。把所有数字拿来和它比较。
				current->index++;
			compare = compare->next;//每比较一个 node 就移动
		}
		current = current->next;//内层循环全部结束后移动
	}
}

int	is_sorted(t_node *stack)
{
	while (stack && stack->next)
	{
		if (stack->value > stack->next->value)
			return (0);
		stack = stack->next;
	}
	return (1);
}

int	stack_size(t_node *stack)
{
	int	count;

	count = 0;
	while (stack)
	{
		count++;
		stack = stack->next;
	}
	return (count);
}
