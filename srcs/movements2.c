/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cacarval <cacarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 12:18:18 by cacarval          #+#    #+#             */
/*   Updated: 2023/08/14 12:13:53 by cacarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_a(t_stack **a, int i)
{
	t_stack	*temp;
	t_stack	*head;

	if (a != NULL && ft_lstsize_ps(*a) >= 2)
	{
		head = *a;
		temp = *a;
		while (temp->next != NULL)
			temp = temp->next;
		*a = head->next;
		temp->next = head;
		temp = temp->next;
		temp->next = NULL;
	}
	if (i != 1)
		ft_printf("ra\n");
}

void	rotate_b(t_stack **b, int i)
{
	t_stack	*temp;
	t_stack	*head;

	if (b != NULL && ft_lstsize_ps(*b) >= 2)
	{
		head = *b;
		temp = *b;
		while (temp->next != NULL)
			temp = temp->next;
		*b = head->next;
		temp->next = head;
		temp = temp->next;
		temp->next = NULL;
	}
	if (i != 1)
		ft_printf("rb\n");
}

void	rrotate_a(t_stack **a, int i)
{
	t_stack	*temp;

	if (a != NULL && ft_lstsize_ps(*a) >= 2)
	{
		temp = *a;
		while (temp->next->next != NULL)
			temp = temp->next;
		temp->next->next = *a;
		*a = temp->next;
		temp->next = NULL;
	}
	if (i != 1)
		ft_printf("rra\n");
}

void	rrotate_b(t_stack **b, int i)
{
	t_stack	*temp;

	if (b != NULL && ft_lstsize_ps(*b) >= 2)
	{
		temp = *b;
		while (temp->next->next != NULL)
			temp = temp->next;
		temp->next->next = *b;
		*b = temp->next;
		temp->next = NULL;
	}
	if (i != 1)
		ft_printf("rrb\n");
}

void	rr(t_stack **a, t_stack **b, int i)
{
	rotate_a(a, 1);
	rotate_b(b, 1);
	if (i != 0)
		ft_printf("rr\n");
}
