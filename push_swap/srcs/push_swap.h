/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppotier <ppotier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 13:15:21 by ppotier           #+#    #+#             */
/*   Updated: 2023/05/17 18:02:33 by rgodtsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include <stdio.h>
# include <unistd.h>
# include <limits.h>
# include <stdlib.h>
# include <stddef.h>

typedef struct s_stack
{
	int				value;
	int				index;
	int				pos;
	int				targ;
	int				cost_a;
	int				cost_b;
	struct s_stack	*next;
}	t_stack;

// main.c
int		main(int ac, char **av);
t_stack	*fill_value(int ac, char **av);
void	push_swap(t_stack **a, t_stack **b, int size);
int		ft_is_sorted(t_stack *a);
int		ft_check_av(char **av);
// ft_check_intput.c
int		args_is_digit(char *str);
int		check_doubles(char **av);
int		args_is_zero(char *str);
int		ft_check_input(int ac, char **av);
int		nb_cmp(const char *s1, const char *s2);
// utils.c
void	give_index(t_stack *a, int size);
int		get_stack_size(t_stack *stack);
void	stack_add(t_stack **stack, t_stack *new);
t_stack	*ft_stack_new(int value);
t_stack	*get_stack_bottom(t_stack *stack);
//args.c
char	**ft_split_args(char *str);
int		is_valid_args(char **args, int ac);
// error.c
int		ft_check_int(char *strnum);
void	ft_free(char **str);
void	free_stack(t_stack **stack);
void	ft_error(t_stack **a, t_stack **b);
// swap.c
void	swap(t_stack *stack);
void	do_sa(t_stack **a);
void	do_sb(t_stack **b);
void	do_ss(t_stack **a, t_stack **b);
// rotate.c
void	rotate(t_stack **stack);
void	do_ra(t_stack **a);
void	do_rb(t_stack **b);
void	do_rr(t_stack **a, t_stack **b);
// quick_sort.c
int		find_high_index(t_stack *stack);
void	quick_sort(t_stack **stack);
// rev_rotate.c
void	rev_rotate(t_stack **stack);
void	do_rra(t_stack **a);
void	do_rrb(t_stack **b);
void	do_rrr(t_stack **a, t_stack **b);
t_stack	*get_stack_be_bottom(t_stack *stack);
// sort.c
void	sort(t_stack **a, t_stack **b);
void	get_target_pos(t_stack **a, t_stack **b);
int		get_target(t_stack **a, int index_b, int target_index, int targ_pos);
void	get_position(t_stack **stack);
void	remain_three(t_stack **a, t_stack **b);
// cost.c
void	get_cost(t_stack **a, t_stack **b);
int		nb_abs(int nb);
void	get_cheap_move(t_stack **a, t_stack **b);
int		get_lowest_index(t_stack **a);
void	shift_stack(t_stack **a);
// move.c
void	do_move(t_stack **a, t_stack **b, int cost_a, int cost_b);
void	do_rev_both(t_stack **a, t_stack **b, int *cost_a, int *cost_b);
void	rotate_both(t_stack **a, t_stack **b, int *cost_a, int *cost_b);
void	do_rotate_a(t_stack **a, int *cost_a);
void	do_rotate_b(t_stack **b, int *cost_b);
// push.c
void	push(t_stack **a, t_stack **b);
void	do_pa(t_stack **a, t_stack **b);
void	do_pb(t_stack **a, t_stack **b);

#endif
