/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cacarval <cacarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 12:20:53 by cacarval          #+#    #+#             */
/*   Updated: 2023/08/02 12:52:30 by cacarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"

typedef struct stack
{
	long			data;
	struct stack	*next;
}					t_stack;

typedef struct info
{
	int		rotations;
	int		size;
	long	data;
}				t_info;

t_stack		*stack_init(char *argv[], int flag);
t_stack		*create_node(long dt);
void		free_list(t_stack **lst, int i);
void		free_array_ps(char *array[], int flag);
void		check_args(char *argv[], int flag);
void		check_dup(t_stack *a);
void		check_int_max_min(t_stack *a);
int			check_sort(t_stack *a);
void		error(void);
int			ft_lstsize_ps(t_stack *a);
int			check_position(t_stack *list, int target);
int			min(t_stack *list);
int			max(t_stack *list);
void		sort_two(t_stack **a);
void		sort_three(t_stack **a);
void		sort_four(t_stack **a, t_stack **b);
void		sort_five(t_stack **a, t_stack **b);
void		sort_hundred(t_stack **a, t_stack **b);
void		sort(t_stack **a, t_stack **b, t_info nbr2sort,
				t_info target);
void		put_all_a(t_stack **a, t_stack **b);
int			mv_calcs(t_info info_a, t_info info_b);
t_info		a_nbr2move(t_stack *a, t_stack *b, t_info info_a);
t_info		b_target(t_stack *b, int data_a);
/******************Movements************************/
t_stack		*swap_a(t_stack *a, int i);
t_stack		*swap_b(t_stack *b, int i);
void		push_b(t_stack **b, t_stack **a, int i);
void		push_a(t_stack **b, t_stack **a, int i);
void		rotate_a(t_stack **a, int i);
void		rotate_b(t_stack **b, int i);
void		rrotate_a(t_stack **a, int i);
void		rrotate_b(t_stack **b, int i);
void		ss(t_stack *a, t_stack *b, int i);
void		rr(t_stack **a, t_stack **b, int i);
void		rrr(t_stack **a, t_stack **b, int i);

#endif