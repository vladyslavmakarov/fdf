/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmakarov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/02 14:18:08 by vmakarov          #+#    #+#             */
/*   Updated: 2017/02/02 14:18:55 by vmakarov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t i;
	size_t j;

	i = 0;
	j = 0;
	if (size == 0)
		return (ft_strlen(src));
	while (i < size && dst[i] != '\0')
		i++;
	j = i;
	while (src && i < size - 1)
	{
		dst[i] = src[i - j];
		i++;
	}
	if (i < size)
		dst[i] = '\0';
	return (j + ft_strlen(src));
}
