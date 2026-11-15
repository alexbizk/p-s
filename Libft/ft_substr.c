/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: weitwang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/16 21:30:31 by weitwang          #+#    #+#             */
/*   Updated: 2026/09/16 21:33:03 by weitwang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char		*p;
	size_t		i;

	if (!s)
		return (NULL);
	if (start >= ft_strlen(s))
		return ((ft_strdup("")));
	i = 0;
	while ((i < len) && s[start + i])
		i++;
	p = malloc (i + 1);
	if (!p)
		return (NULL);
	ft_memcpy(p, s + start, i);
	p[i] = '\0';
	return (p);
}
