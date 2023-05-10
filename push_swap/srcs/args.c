/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgodtsch <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 17:52:56 by rgodtsch          #+#    #+#             */
/*   Updated: 2023/04/28 18:05:16 by rgodtsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	**ft_split_args(char **str, char c)
{
	char	**args;

	args = ft_split(str[1], c);
	if (!args)
		return (NULL);
	return (args);
}
