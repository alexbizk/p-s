/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: weitwang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/16 21:01:45 by weitwang          #+#    #+#             */
/*   Updated: 2026/09/16 21:18:38 by weitwang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned int	ft_count_words(char const *s, char c)
{
	unsigned int	i;

	i = 0;
	while (*s)
	{
		while (*s == c)
		{
			s++;
		}
		if (*s)
		{
			i++;
			while (*s && *s != c)
				s++;
		}
	}
	return (i);
}

static void	ft_free_split(char **p, unsigned int i)
{
	while (i > 0)
	{
		i--;
		free(p[i]);
	}
	free(p);
}

static int	ft_fill(char **p, char const *s, char c, unsigned int words)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	while (i < words)
	{
		while (*s && (*s == c))
			s++;
		j = 0;
		while (s[j] && (s[j] != c))
			j++;
		p[i] = ft_substr(s, 0, j);
		if (!p[i])
		{
			ft_free_split(p, i);
			return (0);
		}
		s = s + j;
		i++;
	}
	p[i] = NULL;
	return (1);
}

char	**ft_split(char const *s, char c)
{
	char			**p;
	unsigned int	words;

	if (!s)
		return (NULL);
	words = ft_count_words(s, c);
	p = malloc(sizeof(char *) * (words + 1));
	if (!p)
		return (NULL);
	if (ft_fill(p, s, c, words))
		return (p);
	return (NULL);
}
