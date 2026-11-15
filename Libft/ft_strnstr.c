/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: weitwang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/30 16:48:52 by weitwang          #+#    #+#             */
/*   Updated: 2026/09/01 14:25:59 by weitwang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_match(const char *a, const char *b, size_t len)
{
	size_t	i;

	i = 0;
	while (*a == *b && *b && i < len)
	{
		a++;
		b++;
		i++;
	}
	return (i);
}

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t		i;
	size_t		t;
	const char	*l;

	if (!*little)
		return ((char *)big);
	t = 0;
	l = little;
	while (*big && t < len)
	{
		i = ft_match(big, little, len - t);
		big = big + i;
		little = little + i;
		t = t + i;
		if (!*little)
			return ((char *)(big - i));
		big = big - i + 1;
		t = t - i + 1;
		i = 0;
		little = l;
	}
	return (NULL);
}
