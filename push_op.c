/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_op.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewu <ewu@student.42heilbronn.de>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 18:50:46 by ewu               #+#    #+#             */
/*   Updated: 2024/11/25 19:13:03 by ewu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// topush->prev = NULL; 1st and last node
void	ft_push(t_stack **dst_top, t_stack **src_top)
{
	t_stack	*topush;

	if (!(*src_top))
		return ;
	topush = *src_top;
	*src_top = (*src_top)->next;
	if (*src_top)
		(*src_top)->prev = NULL;
	topush->prev = NULL;
	if (!*dst_top)
	{
		*dst_top = topush;
		topush->next = NULL;
	}
	else
	{
		topush->next = *dst_top;
		topush->next->prev = topush;
		topush->prev = NULL;
		*dst_top = topush;
	}
}

void	pa(t_stack **a, t_stack **b, int flag)
{
	ft_push(a, b);
	if (flag != 0)
		ft_printf("pa\n");
}

void	pb(t_stack **b, t_stack **a, int flag)
{
	ft_push(b, a);
	if (flag != 0)
		ft_printf("pb\n");
}
