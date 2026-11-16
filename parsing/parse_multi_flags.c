/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_multi_flags.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: weitwang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/16 19:35:03 by weitwang          #+#    #+#             */
/*   Updated: 2026/11/16 19:43:56 by weitwang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	parse_multi_flags(char **argv, int *strategy, int *bench)
{
	int	i;

	*strategy = STRAT_ADAPTIVE;//默认使用自适应算法，因为题目规定不写选项时用 --adaptive
	*bench = 0;//默认不开 bench
	i = 1;
	while (argv[i])
	{
		if (is_flag(argv[i]))//是 "--bench"，不是 NULL → 进入循环
		{
			if (!parse_flag(argv[i], strategy, bench))//是选项吗？是 → 交给 parse_flag
				return (0);
		}
		i++;
	}
	return (1);
}
