/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppotier <ppotier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 15:06:13 by ppotier           #+#    #+#             */
/*   Updated: 2023/04/28 17:23:09 by rgodtsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* do_rev_rotate_both:
*	Reverse rotates both stack A and B until one of them is in position.
*	The given cost is negative since both positions are in the bottom half
*	of their respective stacks. The cost is increased as the stacks are
*	rotated, when one reaches 0, the stack has been rotated as far as possible
*	and the top position is correct.
*/
void	do_rev_both(t_stack **a, t_stack **b, int *cost_a, int *cost_b)
{
	while (*cost_a < 0 && *cost_b < 0)
	{
		(*cost_a)++;
		(*cost_b)++;
		do_rrr(a, b);
	}
}

void	rotate_both(t_stack **a, t_stack **b, int *cost_a, int *cost_b)
{
	while (*cost_a > 0 && *cost_b > 0)
	{
		(*cost_a)--;
		(*cost_b)--;
		do_rr(a, b);
	}
}

void	do_rotate_a(t_stack **a, int *cost_a)
{
	while (*cost_a)
	{
		if (*cost_a > 0)
		{
			do_ra(a);
			(*cost_a)--;
		}
		else if (*cost_a < 0)
		{	
			do_rra(a);
			(*cost_a)++;
		}
	}
}

void	do_rotate_b(t_stack **b, int *cost_b)
{
	while (*cost_b)
	{
		if (*cost_b > 0)
		{
			do_rb(b);
			(*cost_b)--;
		}
		else if (*cost_b < 0)
		{
			do_rrb(b);
			(*cost_b)++;
		}
	}
}

void	do_move(t_stack **a, t_stack **b, int cost_a, int cost_b)
{
	if (cost_a < 0 && cost_b < 0)
		do_rev_both(a, b, &cost_a, &cost_b);
	else if (cost_a > 0 && cost_b > 0)
		rotate_both(a, b, &cost_a, &cost_b);
	do_rotate_a(a, &cost_a);
	do_rotate_b(b, &cost_b);
	do_pa(a, b);
}
