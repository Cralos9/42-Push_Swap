/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cacarval <cacarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 10:32:22 by cacarval          #+#    #+#             */
/*   Updated: 2023/04/17 11:13:29 by cacarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int c)
{
	if (((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')
			|| (c >= '0' && c <= '9')))
		return (1);
	return (0);
}
