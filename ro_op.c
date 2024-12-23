/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ro_op.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewu <ewu@student.42heilbronn.de>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 17:20:18 by ewu               #+#    #+#             */
/*   Updated: 2024/11/25 19:13:13 by ewu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rotate(t_stack **stack_top)
{
	t_stack	*bottom;

	if (!stack_top || !(*stack_top) || !((*stack_top)->next))
		return ;
	bottom = ft_bottom(*stack_top);
	bottom->next = *stack_top;
	*stack_top = (*stack_top)->next;
	(*stack_top)->prev = NULL;
	bottom->next->prev = bottom;
	bottom->next->next = NULL;
}

void	ra(t_stack **a, int flag)
{
	ft_rotate(a);
	if (flag != 0)
		ft_printf("ra\n");
}

void	rb(t_stack **b, int flag)
{
	ft_rotate(b);
	if (flag != 0)
		ft_printf("rb\n");
}

void	rr(t_stack **a, t_stack **b, int flag)
{
	ft_rotate(a);
	ft_rotate(b);
	if (flag != 0)
		ft_printf("rr\n");
}

void	rarb(t_stack **a, t_stack **b, t_stack *cheap)
{
	while (*a != cheap && *b != cheap->target)
	{
		rr(a, b, 1);
	}
	ft_position(*a);
	ft_position(*b);
}
