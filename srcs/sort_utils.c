/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cacarval <cacarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 12:20:02 by cacarval          #+#    #+#             */
/*   Updated: 2023/08/02 13:21:08 by cacarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ss(t_stack *a, t_stack *b, int i)
{
	swap_a(a, 1);
	swap_b(b, 1);
	if (i != 0)
		ft_printf("ss\n");
}

int	max(t_stack *list)
{
	int	max;

	max = list->data;
	while (list != NULL)
	{
		if (list->data > max)
			max = list->data;
		list = list->next;
	}
	return (max);
}

int	min(t_stack *list)
{
	int	min;

	min = list->data;
	while (list != NULL)
	{
		if (list->data < min)
			min = list->data;
		list = list->next;
	}
	return (min);
}

int	calc(int b, int a)
{
	if (b > a)
		return (b);
	else
		return (a);
}

int	mv_calcs(t_info info_a, t_info info_b)
{
	int	nbr_m;

	nbr_m = 0;
	if (info_a.rotations > 0 && info_b.rotations > 0) 
	{
		if (info_a.rotations >= info_a.size / 2 && \
				info_b.rotations >= info_b.size / 2)
			nbr_m = calc(info_b.size - info_b.rotations, \
				info_a.size - info_a.rotations);
		else if (info_a.rotations > info_a.size / 2 && \
				info_b.rotations < info_b.size / 2)
			nbr_m = (info_a.size - info_a.rotations) + info_b.rotations;
		else if (info_b.rotations > info_b.size / 2 && \
				info_a.rotations < info_a.size / 2)
			nbr_m = (info_b.size - info_b.rotations) + info_a.rotations;
		else
			nbr_m = calc(info_b.rotations, info_a.rotations);
	}
	else
		nbr_m = calc(info_b.rotations, info_a.rotations);
	return (++nbr_m);
}
