/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: weitwang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/28 15:12:11 by weit              #+#    #+#             */
/*   Updated: 2026/11/17 01:59:46 by weitwang         ###   ########.fr       */
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
	a = parse_args(argc, argv);
	if (!a)
		return (1);
	sort_with_options(&a, strategy, bench);
	ft_nodeclear(&a);
	return (0);
}


// int	main(int argc, char **argv)
// {
// 	t_node	*a;
// 	t_node	*b;
// 	int		strategy;
// 	int		bench;

// 	if (!parse_multi_flags(argv, &strategy, &bench))
// 	{
// 		ft_putendl_fd("Error", 2);
// 		return (1);
// 	}
// 	if (argc < 2)
// 		return (0);
// 	a = parse_args(argc, argv);
// 	if (!a)
// 		return (1);
// 	b = NULL;
// 	if (!is_sorted(a))
// 	{
// 		assign_index(a);
// 		sort_stack(&a, &b, strategy);
// 	}
// 	ft_nodeclear(&a);
// 	ft_nodeclear(&b);
// 	return (0);
// }
/*
int	push_swap(int argc, char **argv)
{
	t_node	*a;
	int		i;
	int		value;

	a = NULL;
	// (void)argc; // 为了暂时避免编译器报 unused parameter（参数没有使用）。
	// (void)argv;
	if (argc < 2)
		return (0);
	i = 1;
	while (i < argc)
	{
		if (!ft_is_valid_number(argv[i])) // 1 → valid; 0 → not valid
		{
			ft_nodeclear(&a);
			ft_putendl_fd("Error", 2); // 2 = stderr  标准错误
			return (1);
			// return (0); → 程序正常结束 return (1); → 程序因为错误等原因非正常/失败结束
		}
		value = ft_atoi(argv[i]);
		if (ft_has_duplicate(a, value)) // 1 → 有重复0 → 没有重复
		{
			ft_nodeclear(&a);
			ft_putendl_fd("Error", 2); // 2 = stderr  标准错误
			return (1);
		}
		ft_nodeadd_back(&a, ft_nodenew(value));
		// 把 argv[i] 转成整数 → 用这个整数创建一个 node → 把这个 node 加到 stack a 的最后。
		i++;
	}
	ft_print_stack(a);
	ft_nodeclear(&a);
	return (0);
}
*/

/*
#include "push_swap.h"

int	push_swap(int argc, char **argv)

{

	t_node	*a;
	if (argc < 2)
		return (0);
	a = parse_args(argc, argv);
	if (!a)
		return (1);
	if (!is_sorted(a))
	{
		assign_index(a);
		sort_stack(&a);
	}
	ft_nodeclear(&a);
	return (0);

}

int		is_sorted(t_node *stack);
void	sort_stack(t_node **a);


#include "push_swap.h"

int	push_swap(int argc, char **argv)

{

	t_node	*a;
	if (argc < 2)
		return (0);
	a = parse_args(argc, argv);
	if (!a)
		return (1);
	if (!is_sorted(a))
	{
		assign_index(a);
		sort_stack(&a);
	}
	ft_nodeclear(&a);
	return (0);

}
*/
