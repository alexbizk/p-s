#include "push_swap.h"

static void	move_max_to_top(t_node **b, int position)
{
	int	node_count;

	node_count = stack_size(*b);
	if (position <= node_count / 2)
	{
		while (position > 0)
		{
			rb(b);
			position--;
		}
	}
	else
	{
		while (position < node_count)
		{
			rrb(b);
			position++;
		}
	}
}

static int	get_chunk_size(int node_count)
{
	int	chunk_size;

	chunk_size = 1;
	while (chunk_size * chunk_size < node_count)
		chunk_size++;
	return (chunk_size);
}

static void	push_back_to_a(t_node **a, t_node **b)
{
	int	position;

	while (*b)
	{
		position = find_max_position(*b);
		move_max_to_top(b, position);
		pa(a, b);
	}
}

static int	find_max_position(t_node *b)
{
	int	max_index;
	int	max_position;
	int	current_position;

	max_index = b->index;
	max_position = 0;
	current_position = 0;
	while (b)
	{
		if (b->index > max_index)
		{
			max_index = b->index;
			max_position = current_position;
		}
		current_position++;
		b = b->next;
	}
	return (max_position);
}

chunk_pushed = 0;
while (chunk_pushed < chunk_end - chunk_start + 1)
{
	if ((*a)->index >= chunk_start && (*a)->index <= chunk_end)
	{
		pb(a, b);
		if ((*b)->index <= mid)
			rb(b);
		chunk_pushed++;
	}
	else
		ra(a);

}

void	medium_sort(t_node **a, t_node **b)

{

	/* 1. 计算 chunk_size */
	/* 2. 按照 Chunk 将 A 的节点推入 B */
	/* 3. 按照 index 从大到小将 B 推回 A */

}

/*
既然最终都要把 A 中的所有节点推到 B，为什么还要分 Chunk？

答案是：不分 Chunk 也完全可以完成排序。Chunk 的主要作用是减少操作次数，而不是保证排序正确。

*/
