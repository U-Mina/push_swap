/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewu <ewu@student.42heilbronn.de>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 20:53:06 by ewu               #+#    #+#             */
/*   Updated: 2024/11/25 19:13:18 by ewu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * check 1st > 2nd ? sa : no mv
 */
void	ft_sort_two(t_stack **stack)
{
	if ((*stack)->data > (*stack)->next->data)
		sa(stack, 1);
}

/**
 * if 1st==biggest ? ra : cmp 2nd
 * if 3rd at bottom already, check: 1st > 2nd? sa : no mv
 */
void	ft_sort_three(t_stack **stack)
{
	t_stack	*biggest;

	biggest = ft_biggest(*stack);
	if ((*stack) == biggest)
		ra(stack, 1);
	else if ((*stack)->next == biggest)
		rra(stack, 1);
	if (((*stack)->data) > ((*stack)->next->data))
		sa(stack, 1);
}
