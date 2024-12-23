/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewu <ewu@student.42heilbronn.de>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 12:39:24 by ewu               #+#    #+#             */
/*   Updated: 2024/11/25 19:12:50 by ewu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include <limits.h>
# include <math.h>
# include <stdbool.h>

typedef struct s_stack
{
	int				data;
	int				pos;
	int				op_price;
	bool			cheapest;
	bool			up_median;

	struct s_stack	*target;
	struct s_stack	*next;
	struct s_stack	*prev;
}					t_stack;

// swap operations
void				ft_swap(t_stack **stack_top);
void				sa(t_stack **a, int flag);
void				sb(t_stack **b, int flag);
void				ss(t_stack **a, t_stack **b, int flag);

// rotate operations
void				ft_rotate(t_stack **stack_top);
void				ra(t_stack **a, int flag);
void				rb(t_stack **b, int flag);
void				rr(t_stack **a, t_stack **b, int flag);
void				rarb(t_stack **a, t_stack **b, t_stack *cheap);

// rev_rotate ops
void				ft_revrot(t_stack **stack_top);
void				rra(t_stack **a, int flag);
void				rrb(t_stack **b, int flag);
void				rrr(t_stack **a, t_stack **b, int flag);
void				rrarrb(t_stack **a, t_stack **b, t_stack *cheap);

// push ops
void				ft_push(t_stack **dst_top, t_stack **src_top);
void				pa(t_stack **a, t_stack **b, int flag);
void				pb(t_stack **b, t_stack **a, int flag);

// error handle
void				ft_exit(t_stack **stack);
void				ft_error_exit(t_stack **stack);
int					ft_syntax_err(char *s);
int					ft_limit(long n);
int					ft_doubles(t_stack *stack, int n);

// stack utils
t_stack				*ft_bottom(t_stack *stack);
t_stack				*ft_biggest(t_stack *stack);
t_stack				*ft_smallest(t_stack *stack);
t_stack				*ft_newstack(int num);
size_t				ft_stacksize(t_stack *stack);
void				ft_stackadd_back(t_stack **stack, int num);
// void				ft_addnode(t_stack **stack, int num);
void				ft_position(t_stack *stack);
int					ft_sorted(t_stack *stack);

// sort utils
void				ft_find_target_a(t_stack *a, t_stack *b);
void				ft_find_target_b(t_stack *a, t_stack *b);
void				ft_opprice(t_stack *a, t_stack *b);
void				ft_cheap_flg(t_stack *stack);
void				ft_sort_node(t_stack **stack, t_stack *to_mv,
						char specifier);
t_stack				*ft_find_cheap(t_stack *stack);

// initial stack and sorting
void				ft_stack_init(char **av, t_stack **stack);
void				ft_atob(t_stack *a, t_stack *b);
void				ft_btoa(t_stack *a, t_stack *b);

// sort small
void				ft_sort_two(t_stack **stack);
void				ft_sort_three(t_stack **stack);

// sort big
void				ft_mv_a(t_stack **a, t_stack **b);
void				ft_mv_b(t_stack **a, t_stack **b);
void				ft_sort_final(t_stack **a);
void				ft_sorting(t_stack **a, t_stack **b);

/**
 * handle errors
 * stack init
 * nodes init
 * stack utils
 * operations
 * algorithm
 */
#endif