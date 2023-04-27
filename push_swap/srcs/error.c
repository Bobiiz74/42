/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppotier <ppotier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 13:42:23 by ppotier           #+#    #+#             */
/*   Updated: 2023/04/21 16:09:47 by ppotier          ###   ########.fr       */
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

int	ft_check_int(char *strnum)
{
	int	res;
	int	len;

	len = ft_strlen(strnum) - 1;
	// res = 0;
	if (len > 11)
		return (0);
	if (len > 10 && strnum[0] != '-')
		return (0);
	else if (strnum[0] == '-' && len == 11)
	{
		res = ft_strncmp(strnum, "-2147483648", 12);
		if (res > 0)
			return (0);
		else
			return (1);
	}
	else if (strnum[0] != '-' && len == 10)
	{
		res = ft_strncmp(strnum, "2147483647", 11);
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
