/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sort_three.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cacarval <cacarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 12:19:52 by cacarval          #+#    #+#             */
/*   Updated: 2023/08/02 11:46:11 by cacarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_stack **a)
{
	int	data1;
	int	data2;
	int	data3;

	data1 = (*a)->data;
	data2 = (*a)->next->data;
	data3 = (*a)->next->next->data;
	if (data1 > data2 && data2 < data3 && data1 < data3)
		swap_a(*a, 0);
	else if (data1 > data2 && data2 > data3 && data1 > data3)
	{
		swap_a(*a, 0);
		rrotate_a(a, 0);
	}
	else if (data1 > data2 && data2 < data3 && data1 > data3)
		rotate_a(a, 'a');
	else if (data1 < data2 && data2 > data3 && data1 < data3)
	{
		swap_a(*a, 0);
		rotate_a(a, 'a');
	}
	else if (data1 < data2 && data2 > data3 && data1 > data3)
		rrotate_a(a, 0);
}

void	sort_two(t_stack **a)
{
	if ((*a)->data > (*a)->next->data)
		swap_a(*a, 0);
}
