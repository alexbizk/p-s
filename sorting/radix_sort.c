/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: weitwang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/08 23:46:24 by weitwang          #+#    #+#             */
/*   Updated: 2026/11/09 16:36:30 by weitwang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_max_bits(int max_index)
{
	int	bits;

	bits = 0;
	while (max_index > 0)
	{
		max_index = max_index >> 1;
		bits++;
	}
	return (bits);
}

static void	sort_by_bit(t_node **a, t_node **b,
	int bit_position, int node_count)
{
	int	i;

	i = 0;
	while (i < node_count)
	{
		if (((*a)->index >> bit_position) & 1)
			ra(a);
		else
			pb(a, b);
		i++;
	}
	while (*b)
		pa(a, b);
}

void	radix_sort(t_node **a, t_node **b)
{
	int	node_count;
	int	bit_count;
	int	bit_position;
	int	max_index;

	node_count = stack_size(*a);
	max_index = node_count - 1;
	bit_count = get_max_bits(max_index);
	bit_position = 0;
	while (bit_position < bit_count)
	{
		sort_by_bit(a, b, bit_position, node_count);
		bit_position++;
	}
}
/*
建议按照以下顺序：

1. stack_size.c
2. radix_sort.c（包含 get_max_bits()、sort_by_bit() 和 radix_sort()）
3. sort_three.c
4. sort_five.c
5. sort_stack.c
6. 修改 main.c
7. 编写 Makefile
8. 编译、测试、运行 Norminette*/
