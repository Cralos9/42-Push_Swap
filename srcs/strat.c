/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_strat.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cacarval <cacarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 12:20:12 by cacarval          #+#    #+#             */
/*   Updated: 2023/08/02 11:46:59 by cacarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	min_max(t_stack *b, t_info info_a)
{
	t_info		info_b;
	int			target;

	target = max(b);
	info_b.size = ft_lstsize_ps(b);
	info_b.rotations = check_position(b, target);
	return (mv_calcs(info_a, info_b));
}

int	btw_min_max(t_stack *b, int data_a, t_info info_a)
{
	t_stack		*temp_b;
	t_info		info_b;
	int			target;

	temp_b = b;
	target = min(b);
	info_b.size = ft_lstsize_ps(b);
	while (temp_b != NULL)
	{
		if (data_a > temp_b->data)
		{
			if (target < temp_b->data)
				target = temp_b->data;
		}
		temp_b = temp_b->next;
	}
	info_b.rotations = check_position(b, target);
	return (mv_calcs(info_a, info_b));
}

t_info	a_nbr2move(t_stack *a, t_stack *b, t_info info_a)
{
	t_stack		*temp_a;
	t_info		nbr2move;
	int			moves;
	int			cheaper_nbr;

	cheaper_nbr = 0;
	temp_a = a;
	info_a.rotations = 0;
	while (temp_a != NULL)
	{
		if (temp_a->data > max(b) || temp_a->data < min(b))
			moves = min_max(b, info_a);
		else if (temp_a->data < max(b) && temp_a->data > min(b))
			moves = btw_min_max(b, temp_a->data, info_a);
		if (cheaper_nbr > moves || info_a.rotations == 0)
		{
			cheaper_nbr = moves;
			nbr2move.rotations = info_a.rotations;
			nbr2move.data = temp_a->data;
		}
		info_a.rotations++;
		temp_a = temp_a->next;
	}
	return (nbr2move);
}

t_info	b_target(t_stack *b, int data_a)
{
	t_stack		*temp_b;
	t_info		target;

	temp_b = b;
	if (data_a > max(b) || data_a < min(b))
	{
		target.data = max(b);
		target.rotations = check_position(b, target.data);
		return (target);
	}
	else
		target.data = min(b);
	while (temp_b != NULL)
	{
		if (data_a > temp_b->data)
		{
			if (target.data < temp_b->data)
				target.data = temp_b->data;
		}
		temp_b = temp_b->next;
	}
	target.rotations = check_position(b, target.data);
	return (target);
}
