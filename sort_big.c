/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewu <ewu@student.42heilbronn.de>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 12:42:01 by ewu               #+#    #+#             */
/*   Updated: 2024/11/25 19:21:05 by ewu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * the process of mv from stack @a to stack @b
 * find the node with cheapest flag == true
 * check pos of @cheap_node and cheap_node->target
 * do op wrt median T/F
 * ft_sort_node is to put cheapest node/target at top, ready to mv
 */
void	ft_mv_a(t_stack **a, t_stack **b)
{
	t_stack	*cheap;

	cheap = ft_find_cheap(*a);
	if (cheap->up_median && cheap->target->up_median)
		rarb(a, b, cheap);
	else if (!(cheap->up_median) && !(cheap->target->up_median))
		rrarrb(a, b, cheap);
	ft_sort_node(a, cheap, 'a');
	ft_sort_node(b, cheap->target, 'b');
	pb(b, a, 1);
}

void	ft_mv_b(t_stack **a, t_stack **b)
{
	ft_sort_node(a, (*b)->target, 'a');
	pa(a, b, 1);
}

void	ft_sort_final(t_stack **stack)
{
	t_stack	*smallest;

	smallest = ft_smallest(*stack);
	while ((*stack)->data != smallest->data)
	{
		if (smallest->up_median)
			ra(stack, 1);
		else if (!smallest->up_median)
			rra(stack, 1);
	}
}

/**
 * ft_sorted return 0 indicate sorted
 */
void	ft_sorting(t_stack **a, t_stack **b)
{
	size_t	size_a;

	size_a = ft_stacksize(*a);
	if (size_a-- > 3 && (ft_sorted(*a) != 2))
		pb(b, a, 1);
	if (size_a-- > 3 && (ft_sorted(*a) != 2))
		pb(b, a, 1);
	while (size_a-- > 3 && (ft_sorted(*a) != 2))
	{
		ft_atob(*a, *b);
		ft_mv_a(a, b);
	}
	ft_sort_three(a);
	while (*b)
	{
		ft_btoa(*a, *b);
		ft_mv_b(a, b);
	}
	ft_position(*a);
	ft_sort_final(a);
}
