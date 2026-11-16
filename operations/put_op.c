/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_op.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: weitwang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/16 18:55:00 by weitwang          #+#    #+#             */
/*   Updated: 2026/11/16 19:06:15 by weitwang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	put_op(char *name, int id)
{
	int	*count;

	ft_putendl_fd(name, 1);
	count = op_counter();//来初始化这个array的指针
	count[id] = count[id] + 1;
}
