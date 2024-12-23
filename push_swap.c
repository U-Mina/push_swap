/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewu <ewu@student.42heilbronn.de>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 12:49:25 by ewu               #+#    #+#             */
/*   Updated: 2024/11/25 19:13:06 by ewu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;

	a = NULL;
	b = NULL;
	if (ac == 1 || (ac == 2 && !av[1][0]))
	{
		return (1);
	}
	else if (ac == 2)
		av = ft_split(av[1], ' ');
	ft_stack_init(av + 1, &a);
	if (ft_sorted(a) != 0)
	{
		if (ft_stacksize(a) == 2)
			ft_sort_two(&a);
		else if (ft_stacksize(a) == 3)
			ft_sort_three(&a);
		else
			ft_sorting(&a, &b);
	}
	ft_exit(&a);
	return (0);
}
