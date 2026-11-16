/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_valid_number.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: weitwang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/16 17:43:46 by weitwang          #+#    #+#             */
/*   Updated: 2026/11/16 18:14:00 by weitwang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_is_valid_number(char *str)
{
	int	i;
	long	n;
	int	sign;

	if (!str || !*str)
		return (0);
	i = 0;
	sign = 1;
	if (str[i] == '-')
		sign = -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (!str[i]) // 所以在跳过符号以后，要确认后面至少还有一个数字：
		return (0);
	n = 0;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		n = n * 10 + (str[i] - '0');
		if (n * sign > INT_MAX || n * sign < INT_MIN)
			return (0);
		i++;
	}
	return (1);
}
