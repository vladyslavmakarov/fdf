/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmakarov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/02 14:48:56 by vmakarov          #+#    #+#             */
/*   Updated: 2017/02/02 14:49:01 by vmakarov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_strncpy_sp(char *dst, const char *src, size_t len)
{
	size_t i;

	i = 0;
	while (i < len && src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}

char		*ft_strncat(char *s1, const char *s2, size_t n)
{
	int i;

	i = ft_strlen(s1);
	ft_strncpy_sp(&s1[i], s2, n);
	return (s1);
}
