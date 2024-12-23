/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewu <ewu@student.42heilbronn.de>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 20:36:38 by ewu               #+#    #+#             */
/*   Updated: 2024/11/25 19:13:20 by ewu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * sort b in Desdending order
 * so target in @b is biggest smaller nbr
 * @example if @a.data > @b.data && b.data > best_match
 * prove @b.data is close to @a.data than best_match
 * so it is better match, update 'best_match' value
 * @note: best_match && cur_b reset for every new node in @a
 */
void	ft_find_target_a(t_stack *a, t_stack *b)
{
	t_stack		*cur_b;
	t_stack		*target_in_b;
	long int	best_match;

	if (!a || !b)
		return ;
	while (a != NULL)
	{
		best_match = LONG_MIN;
		cur_b = b;
		while (cur_b)
		{
			if ((a->data) > (cur_b->data) && (cur_b->data) > best_match)
			{
				best_match = cur_b->data;
				target_in_b = cur_b;
			}
			cur_b = cur_b->next;
		}
		if (best_match == LONG_MIN)
			a->target = ft_biggest(b);
		else
			a->target = target_in_b;
		a = a->next;
	}
}

// ascedending, smallest big
void	ft_find_target_b(t_stack *a, t_stack *b)
{
	t_stack	*cur_a;
	t_stack	*target_in_a;
	long	best_match;

	if (!a || !b)
		return ;
	while (b != NULL)
	{
		cur_a = a;
		best_match = LONG_MAX;
		while (cur_a)
		{
			if ((cur_a->data) > b->data && (cur_a->data) < best_match)
			{
				best_match = cur_a->data;
				target_in_a = cur_a;
			}
			cur_a = cur_a->next;
		}
		if (best_match == LONG_MAX)
			b->target = ft_smallest(a);
		else
			b->target = target_in_a;
		b = b->next;
	}
}

/**
 * opprice = steps_in_a + steps_in_b (to put both node on top)
 * if up_half, ra/rb is cheaper. step = index
 * @example : index = 0, mean at top already, so 0 step
 * index 2 (out of len=5), ra 2 times to top
 * if low_half, rra/rrb cheaper, step = len - index
 */
void	ft_opprice(t_stack *a, t_stack *b)
{
	size_t	size_a;
	size_t	size_b;

	size_a = ft_stacksize(a);
	size_b = ft_stacksize(b);
	while (a != NULL)
	{
		a->op_price = a->pos;
		if (!(a->up_median))
			a->op_price = size_a - (a->pos);
		if (a->target->up_median)
			a->op_price += a->target->pos;
		else
			a->op_price += size_b - (a->target->pos);
		a = a->next;
	}
}
