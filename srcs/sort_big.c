/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cacarval <cacarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 12:19:05 by cacarval          #+#    #+#             */
/*   Updated: 2023/08/09 11:56:24 by cacarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_min_max(t_stack **a, t_stack **b, int size)
{
	int	position;

	position = check_position(*a, min(*a));
	while ((*a)->data != min(*a))
	{
		if (position > size / 2)
			rrotate_a(a, 0);
		else
			rotate_a(a, 0);
	}
	push_a(b, a, 0);
}

void	sort_btw_min_max(t_stack **a, t_stack **b, int size)
{
	t_stack	*temp_a;
	int		position;
	int		target;

	target = max(*a);
	temp_a = *a;
	while (temp_a != NULL)
	{
		if (target > temp_a->data && temp_a->data > (*b)->data)
			target = temp_a->data;
		temp_a = temp_a->next;
	}
	position = check_position(*a, target);
	while ((*a)->data != target)
	{
		if (position > size / 2)
			rrotate_a(a, 0);
		else
			rotate_a(a, 0);
	}
	push_a(b, a, 0);
}

void	put_all_a(t_stack **a, t_stack **b)
{
	int		size;

	while (*b != NULL)
	{
		size = ft_lstsize_ps(*a);
		if ((*b)->data > max(*a) || (*b)->data < min(*a))
			sort_min_max(a, b, size);
		else if ((*b)->data < max(*a) && (*b)->data > min(*a))
			sort_btw_min_max(a, b, size);
	}
}

void	rotating_a(t_stack **a)
{
	int	size;
	int	position;

	position = check_position(*a, min(*a));
	size = ft_lstsize_ps(*a);
	while ((*a)->data != min(*a))
	{
		if (position > size / 2)
			rrotate_a(a, 0);
		else
			rotate_a(a, 0);
	}
}

void	sort_hundred(t_stack **a, t_stack **b)
{
	t_info	info_a;
	t_info	nbr2sort;
	t_info	target;

	if (check_sort(*a) == 0)
		return ;
	push_b(b, a, 0);
	push_b(b, a, 0);
	info_a.size = ft_lstsize_ps(*a);
	while (info_a.size > 3)
	{
		nbr2sort = a_nbr2move(*a, *b, info_a);
		nbr2sort.size = ft_lstsize_ps(*a);
		target = b_target(*b, nbr2sort.data);
		target.size = ft_lstsize_ps(*b);
		sort(a, b, nbr2sort, target);
		info_a.size = ft_lstsize_ps(*a);
	}
	sort_three(a);
	put_all_a(a, b);
	rotating_a(a);
}
