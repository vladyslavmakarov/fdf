/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmakarov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/02 14:55:16 by vmakarov          #+#    #+#             */
/*   Updated: 2017/02/04 21:21:11 by vmakarov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strnequ(char const *s1, char const *s2, size_t n)
{
	size_t i;

	if (s1 && s2)
	{
		i = 0;
		while (*(s1 + i) && *(s2 + i) && i < n - 1)
		{
			if (*(s1 + i) != *(s2 + i))
				return (0);
			i++;
		}
		if (n)
		{
			return (*((unsigned char *)s1 + i) < *((unsigned char *)s2 + i)
					? 0 : 1);
		}
	}
	return (1);
}
