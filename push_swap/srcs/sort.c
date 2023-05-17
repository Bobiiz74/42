/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppotier <ppotier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 14:14:57 by ppotier           #+#    #+#             */
/*   Updated: 2023/05/17 16:11:58 by rgodtsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*Il ne doit en rester que 3 dans a;
Les plus petites d'abord et apres les plus grandes sont push dans b.*/
void	remain_three(t_stack **a, t_stack **b)
{
	int	stack_size;
	int	pushed;
	int	i;

	stack_size = get_stack_size(*a);
	pushed = 0;
	i = 0;
	while (stack_size > 6 && i < stack_size && pushed < stack_size / 2)
	{
		if ((*a)->index <= stack_size / 2)
		{
			do_pb(a, b);
			pushed++;
		}
		else
			do_ra(a);
		i++;
	}
	while (stack_size - pushed > 3)
	{
		do_pb(a, b);
		pushed++;
	}
}

/* get_position:
*	Donne une position pour chaque elements dans la stack
*	Example stack:
*		value:		 3	 0	 9	 1
*		index:		[3]	[1]	[4]	[2]
*		position:	<0>	<1>	<2>	<3>
*		Donc si ceci est la stack b, il coute 0 move de pa;
*		Mais il coute 2move de b pour push 9 sur la stack a;*/
void	get_position(t_stack **stack)
{
	t_stack	*tmp;
	int		i;

	tmp = *stack;
	i = 0;
	while (tmp)
	{
		tmp->pos = i;
		tmp = tmp->next;
		i++;
	}
}

/*get targ :
* Choisit la meilleure position cible dans la pile A pour l'indice donné de
* un élément dans la pile B. Vérifie d'abord si l'indice de l'élément B peut
* être placé quelque part entre les éléments de la pile A, en vérifiant si
* il y a un élément dans la pile A avec un index plus grand. Sinon, il trouve l'
* élément avec le plus petit index dans A et l'affecte comme position cible.
*	--- Exemple:
* target_pos commence à INT_MAX
* Indice B : 3
* A contient les index : 9 4 2 1 0
* 9 > 3 && 9 < INT_MAX : target_pos mis à jour à 9
* 4 > 3 && 4 < 9 : position cible mise à jour à 4
* 2 < 3 && 2 < 4 : pas de mise à jour !
* Donc target_pos doit être la position de l'index 4, puisqu'il est
* l'indice le plus proche.
*	--- Exemple:
* target_pos commence à INT_MAX
* Indice B : 20
* A contient des index : 16 4 3
* 16 < 20 : pas de mise à jour ! target_pos = INT_MAX
* 4 < 20 : pas de mise à jour ! target_pos = INT_MAX
* 3 < 20 : pas de mise à jour ! target_pos = INT_MAX
* ... target_pos reste à INT MAX, besoin de changer de stratégie.
* 16 < 20 : target_pos mis à jour à 20
* 4 < 20 : target_pos mis à jour à 4
* 3 < 20 : target_pos mis à jour à 3
* Donc target_pos doit être la position de l'index 3, puisque c'est
* la "fin" de la pile.
*/
int	get_target(t_stack **a, int index_b, int target_index, int targ_pos)
{
	t_stack	*tmp;

	tmp = *a;
	while (tmp)
	{
		if (tmp->index > index_b && tmp->index < target_index)
		{
			target_index = tmp->index;
			targ_pos = tmp->pos;
		}
		tmp = tmp->next;
	}
	if (target_index != INT_MAX)
		return (targ_pos);
	tmp = *a;
	while (tmp)
	{
		if (tmp->index < target_index)
		{
			target_index = tmp->index;
			targ_pos = tmp->pos;
		}
		tmp = tmp->next;
	}
	return (targ_pos);
}

/*Donne un nombre dans la stack a pour la position dans sa stack;
La target va donner le spot pour que l'element de b soit sorted;
cela va donner un ordre du coup d'un mouvement; */
void	get_target_pos(t_stack **a, t_stack **b)
{
	t_stack	*tmp;
	int		target_pos;

	tmp = *b;
	get_position(a);
	get_position(b);
	target_pos = 0;
	while (tmp)
	{
		target_pos = get_target(a, tmp->index, INT_MAX, target_pos);
		tmp->targ = target_pos;
		tmp = tmp->next;
	}
}

void	sort(t_stack **a, t_stack **b)
{
	remain_three(a, b);
	quick_sort(a);
	while (*b)
	{
		get_target_pos(a, b);
		get_cost(a, b);
		get_cheap_move(a, b);
	}
	if (!ft_is_sorted(*a))
		shift_stack(a);
}
