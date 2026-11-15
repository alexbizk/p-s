/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: weitwang <weitwang@student.42prague.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/28 17:46:24 by weitwang          #+#    #+#             */
/*   Updated: 2026/09/01 15:23:01 by weitwang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t				i;
	unsigned char		*d;
	const unsigned char	*s;

	i = 0;
	d = dest;
	s = src;
	while (i < n)
	{
		d[i] = s[i];
		i++;
	}
	return (dest);
}
/*
int	main(void)
{
	char	src[100];
	char	dest[100];
	size_t	n;

	printf("ENTER SOURCE: \n");
	scanf("%99s", src);
	printf("HOW MANY BYTES: \n");
	scanf("%zu", &n);
	ft_memcpy(dest, src, n);
	printf("DESTINATION: %s\n", dest);
	return (0);
}*/
