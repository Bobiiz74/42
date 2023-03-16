/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgodtsch <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 15:42:00 by rgodtsch          #+#    #+#             */
/*   Updated: 2023/03/16 15:43:21 by rgodtsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void ft_putchar(char c)
{
	write(1, &c, 1);
}

void ft_putstr(char *str)
{
	int i = 0;
	while(str[i])
	{
		ft_putchar(str[i]);
		i++;
	}
}

int	main(int argc, char **argv)
{	
	int argc_copy;
	char **argv_copy;
	if (argc == 1)
		return(0);
	if (argc == 2)
		printf("%s", "zebi la mouche 2");
	if (argc > 2)
	{
		argc_copy = argc;
		argv_copy = create_tab(argc, argv);
		if(check_error(argv) == 0)
			create_pile_a(argc_copy, argv_copy);
	}

	return (0);
}

int	check_error(char **tab)
{
	int i = 1;
	int j = 0;
	while(tab[i])
	{
		j = 0;
		while(tab[i][j])
		{
			
			if((tab[i][j] >= '0' && tab[i][j] <= '9') || tab[i][j] == '-')
				j++;
			else
			{
				ft_putstr("Error\n");
				return(1);
			}
		}
		i++;
	}
	return(0);
}

char **create_tab(int len, char **values)
{
	char **tab;
	int i;
	
	i = 1;
	tab = malloc(sizeof(*tab) * len);
	if(!tab)
		return(NULL);
	while(i < len)
	{
		tab[i-1] = ft_strdup(values[i]);
		i++;
		//printf("%s\n", tab[i-1]);
	}
	tab[i-1] = NULL;
	return(tab);
}

void create_pile_a(int len, char **tab_ascii)
{
	int *tab;

	int i;

	i = 0;
	tab = malloc(sizeof(int) * len);
	if(!tab)
		exit(1);
	while(i < (len-1))
	{
		//printf("%s ceci est un tab de int\n", tab_ascii[i]);
		tab[i] = ft_atoi(tab_ascii[i]);
		i++;
	}
	sort_int_tab(tab, len);
}

int *sort_int_tab(int *tab, int len)
{
	int i = 0;
	int tmp;
	printf("%d\n", tab[0]);
	printf("%d\n", tab[1]);
	printf("%d\n", tab[2]);
	printf("%d\n", tab[3]);
	printf("%d\n\n", tab[4]);


	while(i < len)
	{
		if(tab[i] > tab[i+1])
		{
			tmp = tab[i];
			//printf("%d\n", tab[i]);
			tab[i] = tab[i+1];
			tab[i+1] = tmp;
			i = 0;
		}
		else 
			i++;
	}
	printf("%d\n", tab[0]);
	printf("%d\n", tab[1]);
	printf("%d\n", tab[2]);
	printf("%d\n", tab[3]);
	printf("%d\n", tab[4]);





	return(tab);
}
