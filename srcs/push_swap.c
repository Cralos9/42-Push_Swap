/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cacarval <cacarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 12:20:44 by cacarval          #+#    #+#             */
/*   Updated: 2023/08/14 10:57:48 by cacarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	which_sort(t_stack **a, t_stack **b)
{
	int	size_a;

	size_a = ft_lstsize_ps(*a);
	if (size_a == 2)
		sort_two(a);
	else if (size_a == 3)
		sort_three(a);
	else if (size_a == 4)
		sort_four(a, b);
	else if (size_a == 5)
		sort_five(a, b);
	else
		sort_hundred(a, b);
}

void	split_arg(t_stack *a, t_stack *b, char *argv[], int argc)
{
	argv = ft_split(argv[1], ' ');
	if (!argv[0])
		free_array_ps(argv, 1);
	check_args(argv, 0);
	a = stack_init(argv, 0);
	free_array_ps(argv, 0);
	check_int_max_min(a);
	check_dup(a);
	if (argc >= 2)
		which_sort(&a, &b);
	free_list(&a, 0);
	exit(0);
}

int	main(int argc, char *argv[])
{
	t_stack	*a;
	t_stack	*b;

	a = NULL;
	b = NULL;
	if (argc == 1)
		return (0);
	else if (argv[1][0] == '\0')
		error();
	if (argc == 2 && ft_strchr(argv[1], ' '))
		split_arg(a, b, argv, argc);
	check_args(argv, 1);
	a = stack_init(argv, 1);
	check_int_max_min(a);
	check_dup(a);
	if (argc >= 2)
		which_sort(&a, &b);
	free_list(&a, 0);
}
