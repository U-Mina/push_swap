/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewu <ewu@student.42heilbronn.de>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 21:01:53 by ewu               #+#    #+#             */
/*   Updated: 2024/11/25 19:13:26 by ewu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ft_biggest(t_stack *stack)
{
	t_stack	*biggest;

	if (!stack)
		return (NULL);
	if (!stack->next)
		return (stack);
	biggest = stack;
	while (stack)
	{
		if ((stack->data) > (biggest->data))
			biggest = stack;
		stack = stack->next;
	}
	return (biggest);
}

t_stack	*ft_smallest(t_stack *stack)
{
	t_stack	*smallest;

	if (!stack)
		return (NULL);
	if (!stack->next)
		return (stack);
	smallest = stack;
	while (stack)
	{
		if ((stack->data) < (smallest->data))
			smallest = stack;
		stack = stack->next;
	}
	return (smallest);
}

t_stack	*ft_bottom(t_stack *stack)
{
	if (!stack)
		return (NULL);
	while (stack->next != NULL)
		stack = stack->next;
	return (stack);
}

// return 2 indicates sorted, -2 means no
// if (!stack->next)
// 	return (1);
// Q: what will be the case if just one element??
int	ft_sorted(t_stack *stack)
{
	if (!stack)
		return (1);
	while (stack->next)
	{
		if ((stack->data) > (stack->next->data))
			return (-2);
		stack = stack->next;
	}
	return (2);
}

size_t	ft_stacksize(t_stack *stack)
{
	size_t	len;
	t_stack	*cur;

	if (!stack)
		return (0);
	cur = stack;
	len = 0;
	while (cur)
	{
		cur = cur->next;
		len++;
	}
	return (len);
}
