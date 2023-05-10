/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppotier <ppotier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 16:13:53 by ppotier           #+#    #+#             */
/*   Updated: 2023/04/28 17:20:35 by rgodtsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(t_stack **stack)
{
	t_stack	*tmp;
	t_stack	*bottom;

	tmp = *stack;
	*stack = (*stack)->next;
	bottom = get_stack_bottom(*stack);
	tmp->next = NULL;
	bottom->next = tmp;
}

void	do_ra(t_stack **a)
{
	rotate(a);
	ft_printf("ra\n");
}

void	do_rb(t_stack **b)
{
	rotate(b);
	ft_printf("rb\n");
}

void	do_rr(t_stack **a, t_stack **b)
{
	rotate(a);
	rotate(b);
	ft_printf("rr\n");
}
