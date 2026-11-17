/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compute_disorder.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: weitwang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/16 22:51:17 by weitwang          #+#    #+#             */
/*   Updated: 2026/11/17 01:26:43 by weitwang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*走过去问每一个人："你后面有没有比你矮的人？"每发现一个，就记一笔"排错了"。最后算排错的占全部配对的多少。*/
double	compute_disorder(t_node *stack)
{
	t_node	*i;//现在被问的那个人
	t_node	*j;//站在 i 后面、正在被比较的人
	long	mistakes;//记了多少笔"排错了"
	long	pairs;//一共比较了多少对

	mistakes = 0;
	pairs = 0;
	i = stack;
	while (i)
	{
		j = i->next;
		while (j)
		{
			pairs++;
			if (i->value > j->value)
				mistakes++;
			j = j->next;
		}
		i = i->next;
	}
	if (pairs == 0)//栈里只有 0 个或 1 个数时，一对都没有，不能做除法（除以 0 会出错），直接返回 0
		return (0.0);
	return ((double)mistakes / pairs);
}
