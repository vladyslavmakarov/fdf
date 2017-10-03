/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmakarov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/06 22:07:48 by vmakarov          #+#    #+#             */
/*   Updated: 2017/02/13 15:15:55 by vmakarov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_recursive_factorial(int nb)
{
	if ((nb < 0) || (nb > 12))
		return (0);
	if (nb == 0)
		return (1);
	if (nb > 0)
		return (nb * ft_recursive_factorial(nb - 1));
	else
		return (0);
}
