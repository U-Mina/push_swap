/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_handle.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewu <ewu@student.42heilbronn.de>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 22:09:02 by ewu               #+#    #+#             */
/*   Updated: 2024/11/25 19:12:11 by ewu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * start checking 1st element in str (digits or sign)
 * 2nd element can only be digits!
 * if sign, return
 */
int	ft_syntax_err(char *s)
{
	if (!(*s == '-' || *s == '+' || ft_isdigit(*s)))
		return (-2);
	if ((*s == '-' || *s == '+') && !ft_isdigit(s[1]))
		return (-2);
	while (*++s)
	{
		if (!ft_isdigit(*s))
			return (-2);
	}
	return (0);
}

int	ft_limit(long n)
{
	if (n > INT_MAX || n < INT_MIN)
		return (-2);
	else
		return (0);
}

int	ft_doubles(t_stack *stack, int n)
{
	if (!stack)
		return (0);
	while (stack)
	{
		if (stack->data == n)
			return (-2);
		stack = stack->next;
	}
	return (0);
}

// cur->data = 0 for cleaning up, not vital necessary
void	ft_exit(t_stack **stack)
{
	t_stack	*cur;
	t_stack	*next;

	if (!stack || !(*stack))
		return ;
	cur = *stack;
	while (cur)
	{
		next = cur->next;
		cur->data = 0;
		free(cur);
		cur = next;
	}
	*stack = NULL;
}

void	ft_error_exit(t_stack **stack)
{
	ft_exit(stack);
	write(2, "Error\n", 6);
	exit(EXIT_FAILURE);
}
