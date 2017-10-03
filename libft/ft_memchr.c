/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmakarov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/02 14:27:52 by vmakarov          #+#    #+#             */
/*   Updated: 2017/02/02 14:27:56 by vmakarov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*s1;
	size_t			i;

	s1 = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		if (s1[i] == (unsigned char)c)
			return (s1 + i);
		i++;
	}
	return (0);
}
