/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewu <ewu@student.42heilbronn.de>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 22:17:17 by ewu               #+#    #+#             */
/*   Updated: 2024/11/25 19:13:29 by ewu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ft_newstack(int num)
{
	t_stack	*new_stack;

	new_stack = malloc(sizeof(t_stack));
	if (new_stack == NULL)
		return (NULL);
	new_stack->data = num;
	new_stack->next = NULL;
	new_stack->cheapest = 0;
	return (new_stack);
}

void	ft_stackadd_back(t_stack **stack, int num)
{
	t_stack	*new;
	t_stack	*last;

	new = ft_newstack(num);
	if (!stack || !new)
		return ;
	if (!(*stack))
	{
		*stack = new;
		new->prev = NULL;
	}
	else
	{
		last = ft_bottom(*stack);
		last->next = new;
		new->prev = last;
	}
}

/**
 * 1st argument is at TOP, so index 0 is up-median position
 * traverse whole stack, assign index for each one
 * and assign bool value for cheapest or not
 */
void	ft_position(t_stack *stack)
{
	int	i;
	int	median;

	i = 0;
	if (!stack)
		return ;
	median = ft_stacksize(stack) / 2;
	while (stack)
	{
		stack->pos = i;
		if (i <= median)
			stack->up_median = true;
		else
			stack->up_median = false;
		stack = stack->next;
		i++;
	}
}
