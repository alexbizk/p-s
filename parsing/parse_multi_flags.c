/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_multi_flags.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: weitwang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/16 19:35:03 by weitwang          #+#    #+#             */
/*   Updated: 2026/11/17 16:21:02 by weitwang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	parse_multi_flags(char **argv, int *strategy, int *bench)
{
	int	i;

	*strategy = STRAT_ADAPTIVE;
	*bench = 0;
	i = 1;
	while (argv[i])
	{
		if (is_flag(argv[i]))
		{
			if (!parse_flag(argv[i], strategy, bench))
				return (0);
		}
		i++;
	}
	return (1);
}
