/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: weitwang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/09 16:39:12 by weitwang          #+#    #+#             */
/*   Updated: 2026/11/10 16:15:12 by weitwang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "Libft/libft.h"
# include <limits.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_node
{
	int				value;
	int				index;
	struct s_node	*next;
}					t_node;

/* Linked list */
t_node	*ft_nodenew(int value);
void	ft_nodeadd_back(t_node **node, t_node *new);
void	ft_print_stack(t_node *node);
void	ft_nodeclear(t_node **node);

/* Stack utilities */
void	assign_index(t_node *stack);
int		is_sorted(t_node *stack);
int		stack_size(t_node *stack);

/* Parsing */
int		ft_is_valid_number(char *str);
int		ft_has_duplicate(t_node *a, int value);
void	free_stack(t_node **stack);
void	error_exit(t_node **stack);
t_node	*parse_args(int argc, char **argv);

/* Operation helpers */
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

/* Sorting */
void	sort_stack(t_node **a);
void	simple_sort(t_node **a, t_node **b);
void	radix_sort(t_node **a, t_node **b);

#endif
