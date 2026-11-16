/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: weitwang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/28 14:43:28 by weit              #+#    #+#             */
/*   Updated: 2026/11/16 19:27:04 by weitwang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	free_split(char **split)
{
	int	i;

	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}

static int	add_number(t_node **a, char *str)
{
	t_node	*new;
	int		value;

	if (!ft_is_valid_number(str))
		return (0);
	value = ft_atoi(str);
	if (ft_has_duplicate(*a, value))
		return (0);
	new = ft_nodenew(value);
	if (!new)
		return (0);
	ft_nodeadd_back(a, new);
	return (1);
}

static int	add_argument(t_node **a, char *arg)
{
	char	**numbers;
	int		i;

	numbers = ft_split(arg, ' ');
	if (!numbers)
		return (0);
	i = 0;
	if (!numbers[0])
	{
		free_split(numbers);
		return (0);
	}
	while (numbers[i])
	{
		if (!add_number(a, numbers[i]))
		{
			free_split(numbers);
			return (0);
		}
		i++;
	}
	free_split(numbers);
	return (1);
}

t_node	*parse_args(int argc, char **argv)
{
	t_node *a;
	int i;

	a = NULL;
	i = 1;
	while (i < argc)
	{
		if (!is_flag(argv[i]) && !add_argument(&a, argv[i]))
		{
			ft_nodeclear(&a);
			ft_putendl_fd("Error", 2);
			return (NULL);
		}
		i++;
	}
	return (a);
}
