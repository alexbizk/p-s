/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: weitwang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/16 20:31:13 by weitwang          #+#    #+#             */
/*   Updated: 2026/09/16 20:47:37 by weitwang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_nbrlength(int n)
{
	int		len;
	long	nb;

	len = 1;
	nb = n;
	if (nb < 0)
	{
		nb = -nb;
		len++;
	}
	while (nb > 9)
	{
		nb = nb / 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	long	nbr;
	int		len;
	char	*p;

	nbr = n;
	len = ft_nbrlength(n);
	p = malloc(len + 1);
	if (!p)
		return (NULL);
	p[len] = '\0';
	if (nbr < 0)
	{
		p[0] = '-';
		nbr = -nbr;
	}
	len = len - 1;
	while (nbr > 9)
	{
		p[len] = nbr % 10 + '0';
		nbr = nbr / 10;
		len--;
	}
	p[len] = nbr + '0';
	return (p);
}
