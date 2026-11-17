/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_bench.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: weitwang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/17 01:50:44 by weitwang          #+#    #+#             */
/*   Updated: 2026/11/17 01:57:20 by weitwang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	put_percent(double disorder)
{
	int	x;

	x = (int)(disorder * 10000 + 0.5);
	ft_putnbr_fd(x / 100, 2);
	ft_putchar_fd('.', 2);
	if (x % 100 < 10)
		ft_putchar_fd('0', 2);
	ft_putnbr_fd(x % 100, 2);
	ft_putchar_fd('%', 2);
}

static char	*complexity(int strategy)
{
	if (strategy == STRAT_SIMPLE)
		return ("O(n^2)");
	if (strategy == STRAT_MEDIUM)
		return ("O(n*sqrt(n))");
	return ("O(n log n)");
}

static void	put_strategy(int strategy, double disorder)
{
	ft_putstr_fd("[bench] strategy:  ", 2);
	if (strategy == STRAT_SIMPLE)
		ft_putstr_fd("Simple", 2);
	else if (strategy == STRAT_MEDIUM)
		ft_putstr_fd("Medium", 2);
	else if (strategy == STRAT_COMPLEX)
		ft_putstr_fd("Complex", 2);
	else
	{
		ft_putstr_fd("Adaptive", 2);
		strategy = adaptive_choice(disorder);
	}
	ft_putstr_fd(" / ", 2);
	ft_putendl_fd(complexity(strategy), 2);
}

static void	put_count(char *name, int id)
{
	ft_putstr_fd(name, 2);
	ft_putstr_fd(":  ", 2);
	ft_putnbr_fd(op_counter()[id], 2);
	ft_putstr_fd("  ", 2);
}

void	print_bench(double disorder, int strategy)
{
	ft_putstr_fd("[bench] disorder:  ", 2);
	put_percent(disorder);
	ft_putchar_fd('\n', 2);
	put_strategy(strategy, disorder);
	ft_putstr_fd("[bench] total_ops:  ", 2);
	ft_putnbr_fd(total_ops(), 2);
	ft_putchar_fd('\n', 2);
	ft_putstr_fd("[bench] ", 2);
	put_count("sa", OP_SA);
	put_count("sb", OP_SB);
	put_count("ss", OP_SS);
	put_count("pa", OP_PA);
	put_count("pb", OP_PB);
	ft_putchar_fd('\n', 2);
	ft_putstr_fd("[bench] ", 2);
	put_count("ra", OP_RA);
	put_count("rb", OP_RB);
	put_count("rr", OP_RR);
	put_count("rra", OP_RRA);
	put_count("rrb", OP_RRB);
	put_count("rrr", OP_RRR);
	ft_putchar_fd('\n', 2);
}
