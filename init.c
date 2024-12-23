/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewu <ewu@student.42heilbronn.de>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 23:32:00 by ewu               #+#    #+#             */
/*   Updated: 2024/11/25 19:12:59 by ewu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * read input, and create stack a
 * error check
 * 2 cases: string input --> ft_split && nbr
 */
void	ft_stack_init(char **av, t_stack **stack)
{
	long int	n;
	int			i;

	i = 0;
	while (av[i])
	{
		if (ft_syntax_err(av[i]))
			ft_error_exit(stack);
		n = ft_atol(av[i]);
		if (ft_limit(n) != 0)
			ft_error_exit(stack);
		if (ft_doubles(*stack, (int)n))
			ft_error_exit(stack);
		ft_stackadd_back(stack, (int)n);
		i++;
	}
}

/**
 * the process of finding the place of 'node' in @b
 * find the index of a&b, find the up_mid value (T/F)
 * based on index, find the target pos in @b for each node
 * calculate the price of the mv of each node to the target pos
 * set cheapest == T for cheapest mv_price node
 */
void	ft_atob(t_stack *a, t_stack *b)
{
	ft_position(a);
	ft_position(b);
	ft_find_target_a(a, b);
	ft_opprice(a, b);
	ft_cheap_flg(a);
}

/**
 * get index of @a and @b nodes
 * find place to put back nodes
 * no checking bc @b descending order already
 */
void	ft_btoa(t_stack *a, t_stack *b)
{
	ft_position(a);
	ft_position(b);
	ft_find_target_b(a, b);
}
