/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: weitwang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/28 15:12:11 by weit              #+#    #+#             */
/*   Updated: 2026/11/22 21:13:02 by weitwang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_with_options(t_node **a, int strategy, int bench)
{
	t_node	*b;
	double	disorder;

	b = NULL;
	disorder = compute_disorder(*a);
	if (!is_sorted(*a))
	{
		assign_index(*a);
		sort_stack(a, &b, strategy);
	}
	if (bench)
		print_bench(disorder, strategy);
	ft_nodeclear(&b);
}

static int	only_flags(int argc, char **argv)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (!is_flag(argv[i]))
			return (0);
		i++;
	}
	return (1);
}

int	main(int argc, char **argv)
{
	t_node	*a;
	int		strategy;
	int		bench;

	if (argc < 2)
		return (0);
	if (!parse_multi_flags(argv, &strategy, &bench))
	{
		ft_putendl_fd("Error", 2);
		return (1);
	}
	if (only_flags(argc, argv))
		return (0);
	a = parse_args(argc, argv);
	if (!a)
		return (1);
	sort_with_options(&a, strategy, bench);
	ft_nodeclear(&a);
	return (0);
}
