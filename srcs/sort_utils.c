/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cacarval <cacarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 12:20:02 by cacarval          #+#    #+#             */
/*   Updated: 2023/08/09 12:22:59 by cacarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

int	mv_calcs2(t_info info_a, t_info info_b)
{
	int	nbr_m;

	nbr_m = 0;
	if (info_a.rotations >= info_a.size / 2)
		nbr_m = info_a.size - info_a.rotations;
	else if (info_b.rotations >= info_b.size / 2)
		nbr_m = info_b.size - info_b.rotations;
	else
		nbr_m = calc(info_b.rotations, info_a.rotations);
	return (nbr_m);
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
		nbr_m = mv_calcs2(info_a, info_b);
	return (++nbr_m);
}
