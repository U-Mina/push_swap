/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewu <ewu@student.42heilbronn.de>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 01:52:18 by ewu               #+#    #+#             */
/*   Updated: 2024/11/25 19:13:23 by ewu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_cheap_flg(t_stack *stack)
{
	long	mv_price;
	t_stack	*cheap_node;

	if (!stack)
		return ;
	mv_price = LONG_MAX;
	while (stack)
	{
		if ((stack->op_price) < mv_price)
		{
			mv_price = stack->op_price;
			cheap_node = stack;
		}
		stack = stack->next;
	}
	cheap_node->cheapest = true;
}

// by checking the cheapest flag to find the cheap node
t_stack	*ft_find_cheap(t_stack *stack)
{
	if (!stack)
		return (NULL);
	while (stack)
	{
		if (stack->cheapest)
			return (stack);
		stack = stack->next;
	}
	return (NULL);
}

/**
 * to put the to_mv(wanted) node at top
 */
void	ft_sort_node(t_stack **stack, t_stack *to_mv, char specifier)
{
	if (!stack || !(*stack))
		return ;
	while (*stack != to_mv)
	{
		if (specifier == 'a')
		{
			if (to_mv->up_median)
				ra(stack, 1);
			else
				rra(stack, 1);
		}
		else if (specifier == 'b')
		{
			if (to_mv->up_median)
				rb(stack, 1);
			else
				rrb(stack, 1);
		}
	}
}
