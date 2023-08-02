/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cacarval <cacarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 12:18:06 by cacarval          #+#    #+#             */
/*   Updated: 2023/08/02 13:21:00 by cacarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*swap_a(t_stack *a, int i)
{
	int	temp;

	temp = 0;
	if (ft_lstsize_ps(a) <= 1)
		return (a);
	else
	{
		temp = a->data;
		a->data = a->next->data;
		a->next->data = temp;
		if (i != 1)
			ft_printf("sa\n");
		return (a);
	}
}

t_stack	*swap_b(t_stack *b, int i)
{
	int	temp;

	temp = 0;
	if (ft_lstsize_ps(b) <= 1)
		return (b);
	else
	{
		temp = b->data;
		b->data = b->next->data;
		b->next->data = temp;
		if (i != 1)
			ft_printf("sb\n");
		return (b);
	}
}

void	rrr(t_stack **a, t_stack **b, int i)
{
	rrotate_a(a, 1);
	rrotate_b(b, 1);
	if (i != 0)
		ft_printf("rrr\n");
}

void	push_b(t_stack **b, t_stack **a, int i)
{
	t_stack	*temp;

	if (!(*a))
		return ;
	temp = *a;
	*a = (*a)->next;
	temp->next = *b;
	*b = temp;
	if (i != 1)
		ft_printf("pb\n");
}

void	push_a(t_stack **b, t_stack **a, int i)
{
	t_stack	*temp;

	if (!(*b))
		return ;
	temp = *b;
	*b = (*b)->next;
	temp->next = *a;
	*a = temp;
	if (i != 1)
		ft_printf("pa\n");
}
