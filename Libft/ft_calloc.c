/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: weitwang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/01 12:53:03 by weitwang          #+#    #+#             */
/*   Updated: 2026/09/01 14:21:12 by weitwang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	char	*p;
	size_t	t;

	if (size != 0 && nmemb > (size_t)-1 / size)
		return (NULL);
	t = nmemb * size;
	p = malloc(t);
	if (!p)
		return (NULL);
	while (t > 0)
	{
		p[t - 1] = 0;
		t = t - 1;
	}
	return (p);
}
