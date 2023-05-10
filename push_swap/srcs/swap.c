/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppotier <ppotier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 13:05:58 by ppotier           #+#    #+#             */
/*   Updated: 2023/04/28 17:47:40 by rgodtsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*swap 2elemt d'une stack*/
void	swap(t_stack *stack)
{
	int	tmp;

	if (stack == NULL || stack->next == NULL)
		return ;
	tmp = stack->value;
	stack->value = stack->next->value;
	stack->next->value = tmp;
	tmp = stack->index;
	stack->index = stack->next->index;
	stack->next->index = tmp;
}

/*swap les 2premiers elem et printf "sa"*/
void	do_sa(t_stack **a)
{
	swap(*a);
	ft_printf("sa\n");
}

/*swap 2prem elem de b*/
void	do_sb(t_stack **b)
{
	swap(*b);
	ft_printf("sb\n");
}

void	do_ss(t_stack **a, t_stack **b)
{
	swap(*a);
	swap(*b);
	ft_printf("ss\n");
}
