/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: weitwang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/09 16:39:12 by weitwang          #+#    #+#             */
/*   Updated: 2026/11/17 02:01:51 by weitwang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "Libft/libft.h"
# include <limits.h>
# include <stdlib.h>
# include <unistd.h>

# define OP_SA 0
# define OP_SB 1
# define OP_SS 2
# define OP_PA 3
# define OP_PB 4
# define OP_RA 5
# define OP_RB 6
# define OP_RR 7
# define OP_RRA 8
# define OP_RRB 9
# define OP_RRR 10
# define STRAT_ADAPTIVE 0
# define STRAT_SIMPLE 1
# define STRAT_MEDIUM 2
# define STRAT_COMPLEX 3

typedef struct s_node
{
	int				value;
	int				index;
	struct s_node	*next;
}					t_node;

/* stack - Linked list */
t_node	*ft_nodenew(int value);
void	ft_nodeadd_back(t_node **node, t_node *new);
void	ft_print_stack(t_node *node);
void	ft_nodeclear(t_node **node);

/* Stack utilities */
void	assign_index(t_node *stack);
int		is_sorted(t_node *stack);
int		stack_size(t_node *stack);
int		find_min_position(t_node *stack);
int		find_max_position(t_node *stack);

/* Parsing */
int		ft_is_valid_number(char *str);
int		ft_has_duplicate(t_node *a, int value);
t_node	*parse_args(int argc, char **argv);
int	is_flag(char *arg);
int	parse_flag(char *arg, int *strategy, int *bench);
int	parse_multi_flags(char **argv, int *strategy, int *bench);

/* Operation - Operation helpers */
void	swap_nodes(t_node **stack);
void	push_node(t_node **src, t_node **dst);
void	rotate_nodes(t_node **stack);
void	reverse_rotate_nodes(t_node **stack);

/* Swap */
void	sa(t_node **a);
void	sb(t_node **b);
void	ss(t_node **a, t_node **b);

/* Push */
void	pa(t_node **a, t_node **b);
void	pb(t_node **a, t_node **b);

/* Rotate */
void	ra(t_node **a);
void	rb(t_node **b);
void	rr(t_node **a, t_node **b);

/* Reverse rotate */
void	rra(t_node **a);
void	rrb(t_node **b);
void	rrr(t_node **a, t_node **b);

/* Operation - Operation counter */
int		*op_counter(void);
void	put_op(char *name, int id);
int		total_ops(void);

/* Sorting */
void	sort_stack(t_node **a, t_node **b, int strategy);
void	simple_sort(t_node **a, t_node **b);
void	radix_sort(t_node **a, t_node **b);
void	medium_sort(t_node **a, t_node **b);
void	adaptive_sort(t_node **a, t_node **b);
int		adaptive_choice(double disorder);
double	compute_disorder(t_node *stack);

/* Bench */
void	print_bench(double disorder, int strategy);

#endif
