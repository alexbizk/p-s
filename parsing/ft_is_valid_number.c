/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_valid_number.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: weit <weit@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/28 15:11:42 by weit              #+#    #+#             */
/*   Updated: 2026/10/28 15:11:43 by weit             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_is_valid_number(char *str)
{
	int i;
	long n;
	int sign;

	if (!str || !*str)
		return (0);
	i = 0;
	sign = 1;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	if (!str[i]) // 所以在跳过符号以后，要确认后面至少还有一个数字：
		return (0);
	n = 0;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		n = n * 10 + (str[i] - '0');
		i++;
	}
	n = n * sign;
	if ((n <= INT_MAX) && (n >= INT_MIN))
		return (1);
	return (0);
}