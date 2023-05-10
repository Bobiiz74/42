/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppotier <ppotier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 13:42:23 by ppotier           #+#    #+#             */
/*   Updated: 2023/04/28 18:38:33 by rgodtsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_free(char **str)
{
	int	i;

	i = 0;
	if (!str)
		return ;
	while (str[i] != NULL)
	{
		free(str[i]);
		i++;
	}
	free(str);
}

int	ft_check_int(char *num)
{
	int	res;
	int	len;

	len = ft_strlen(num);
	if (len > 11 || (len > 10 && num[0] != '-'))
		return (0);
	else if (num[0] == '-' && len == 11)
	{
		res = ft_strncmp(num, "-2147483648", 12);
		if (res > 0)
			return (0);
		else
			return (1);
	}
	else if (num[0] != '-' && len == 10)
	{
		res = ft_strncmp(num, "2147483647", 11);
		if (res > 0)
			return (0);
		else
			return (1);
	}
	else
		return (1);
}

void	free_stack(t_stack **stack)
{
	t_stack	*tmp;

	if (!stack || !(*stack))
		return ;
	while (*stack)
	{
		tmp = (*stack)->next;
		free(*stack);
		*stack = tmp;
	}
	*stack = NULL;
}

void	ft_error(t_stack **a, t_stack **b)
{
	if (a == NULL || *a != NULL)
		free_stack(a);
	if (b == NULL || *b != NULL)
		free_stack(b);
	ft_putstr_fd("Error\n", 2);
	exit (1);
}
