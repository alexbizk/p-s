/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_flag.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: weitwang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/16 19:29:51 by weitwang          #+#    #+#             */
/*   Updated: 2026/11/16 19:30:21 by weitwang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	parse_flag(char *arg, int *strategy, int *bench)
{
	if (!ft_strncmp(arg, "--simple", 9))
		*strategy = STRAT_SIMPLE;
	else if (!ft_strncmp(arg, "--medium", 9))
		*strategy = STRAT_MEDIUM;
	else if (!ft_strncmp(arg, "--complex", 10))
		*strategy = STRAT_COMPLEX;
	else if (!ft_strncmp(arg, "--adaptive", 11))
		*strategy = STRAT_ADAPTIVE;
	else if (!ft_strncmp(arg, "--bench", 8))
		*bench = 1;
	else
		return (0);
	return (1);
}
