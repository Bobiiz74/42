/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppotier <ppotier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 13:56:46 by ppotier           #+#    #+#             */
/*   Updated: 2023/04/28 17:36:53 by rgodtsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*element du bas vers le haut*/
void	rev_rotate(t_stack **stack)
{
	t_stack	*tmp;
	t_stack	*bottom;
	t_stack	*be_bottom;

	bottom = get_stack_bottom(*stack);
	be_bottom = get_stack_be_bottom(*stack);
	tmp = *stack;
	*stack = bottom;
	(*stack)->next = tmp;
	be_bottom->next = NULL;
}

void	do_rra(t_stack **a)
{
	rev_rotate(a);
	ft_printf("rra\n");
}

void	do_rrb(t_stack **b)
{
	rev_rotate(b);
	ft_printf("rrb\n");
}

void	do_rrr(t_stack **a, t_stack **b)
{
	rev_rotate(a);
	rev_rotate(b);
	ft_printf("rrr\n");
}

/*donne du 2e au dernier de la liste*/
t_stack	*get_stack_be_bottom(t_stack *stack)
{
	while (stack && stack->next && stack->next->next != NULL)
		stack = stack->next;
	return (stack);
}
