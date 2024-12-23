/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sw_op.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewu <ewu@student.42heilbronn.de>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 12:41:50 by ewu               #+#    #+#             */
/*   Updated: 2024/11/25 19:13:32 by ewu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * **stack: enable the modify of head PTR in 'stack'
 * third_node = new_top->next; //init nodes
 * 	*stack_top = new_top; //start swap
 * new_top->prev = NULL; //the 1st node, so NULL for prev
 */
void	ft_swap(t_stack **stack_top)
{
	t_stack	*new_top;
	t_stack	*old_top;
	t_stack	*third_node;

	if (!stack_top || !(*stack_top) || !((*stack_top)->next))
		return ;
	new_top = (*stack_top)->next;
	old_top = *stack_top;
	third_node = new_top->next;
	*stack_top = new_top;
	new_top->prev = NULL;
	new_top->next = old_top;
	old_top->prev = new_top;
	old_top->next = third_node;
	if (third_node)
		third_node->prev = old_top;
}

/**
 * flag: 1/0 to indicate print or not at this moment
 */
void	sa(t_stack **a, int flag)
{
	ft_swap(a);
	if (flag != 0)
		ft_printf("sa\n");
}

void	sb(t_stack **b, int flag)
{
	ft_swap(b);
	if (flag != 0)
		ft_printf("sb\n");
}

void	ss(t_stack **a, t_stack **b, int flag)
{
	ft_swap(a);
	ft_swap(b);
	if (flag != 0)
		ft_printf("ss\n");
}
