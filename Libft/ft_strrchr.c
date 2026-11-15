/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: weitwang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/25 20:32:55 by weitwang          #+#    #+#             */
/*   Updated: 2026/09/01 15:30:05 by weitwang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*p;

	p = NULL;
	while (*s)
	{
		if ((unsigned char)*s == (unsigned char)c)
			p = (char *)s;
		s++;
	}
	if ((unsigned char)c == '\0')
		p = (char *)s;
	return (p);
}
