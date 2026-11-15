/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: weitwang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/16 22:04:10 by weitwang          #+#    #+#             */
/*   Updated: 2026/09/16 22:05:28 by weitwang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*suit;

	if (!lst || !del)
		return ;
	while (*lst)
	{
		suit = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = suit;
	}
}
