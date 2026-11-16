/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   total_ops.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: weitwang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/16 19:20:30 by weitwang          #+#    #+#             */
/*   Updated: 2026/11/16 19:20:37 by weitwang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	total_ops(void)
{
	int	*count;
	int	total;
	int	i;

	count = op_counter();
	total = 0;
	i = 0;
	while (i < 11)
	{
		total = total + count[i];
		i++;
	}
	return (total);
}
