/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cacarval <cacarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 12:18:47 by cacarval          #+#    #+#             */
/*   Updated: 2023/08/14 10:58:14 by cacarval         ###   ########.fr       */
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

void	error(void)
{
	write(2, "Error\n", 6);
	exit(1);
}

void	free_list(t_stack **lst, int i)
{
	t_stack	*temp;

	while (*lst != NULL)
	{
		temp = *lst;
		*lst = (*lst)->next;
		free(temp);
	}
	if (i == 1)
		error();
}

void	free_array_ps(char *array[], int flag)
{
	int	i;

	i = 0;
	while (array[i])
		free(array[i++]);
	free(array);
	if (flag == 1)
		error();
}
