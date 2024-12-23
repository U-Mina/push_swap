/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_op.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewu <ewu@student.42heilbronn.de>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 17:59:38 by ewu               #+#    #+#             */
/*   Updated: 2024/11/25 19:13:11 by ewu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * reverse ro is to mv last on as 1st
 * 2nd last node is set as last by setting next point to NULL
 * @implements: bottom->prev->next = NULL
 * @implements: '->' op is about pointer assign
 * '=' is value assign
 * assign 'bottom->next'(original stack_top node)'s pointer
 * botton->next->prev = bottom
 * @Q: bottom->prev->next = NULL; ?
 */
void	ft_revrot(t_stack **stack_top)
{
	t_stack	*bottom;
	t_stack	*new_bot;

	if (!stack_top || !(*stack_top) || !((*stack_top)->next))
		return ;
	bottom = ft_bottom(*stack_top);
	new_bot = bottom->prev;
	new_bot->next = NULL;
	bottom->next = *stack_top;
	bottom->prev = NULL;
	*stack_top = bottom;
	bottom->next->prev = bottom;
}

void	rra(t_stack **a, int flag)
{
	ft_revrot(a);
	if (flag != 0)
		ft_printf("rra\n");
}

void	rrb(t_stack **b, int flag)
{
	ft_revrot(b);
	if (flag != 0)
		ft_printf("rrb\n");
}

void	rrr(t_stack **a, t_stack **b, int flag)
{
	ft_revrot(a);
	ft_revrot(b);
	if (flag != 0)
		ft_printf("rrr\n");
}

/**
 * check the topush_node and target_node's pos
 * mv w.r.t. median, and update pos
 */
void	rrarrb(t_stack **a, t_stack **b, t_stack *cheap)
{
	while (*a != cheap && *b != cheap->target)
	{
		rrr(a, b, 1);
	}
	ft_position(*a);
	ft_position(*b);
}
