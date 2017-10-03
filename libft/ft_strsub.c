/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmakarov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/02 14:45:03 by vmakarov          #+#    #+#             */
/*   Updated: 2017/02/13 15:26:28 by vmakarov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*s1;
	int		i;

	if (s)
	{
		s1 = (char *)malloc(len + 1);
		i = 0;
		if (s1)
		{
			while (len > 0)
			{
				s1[i] = s[start];
				len--;
				start++;
				i++;
			}
			s1[i] = '\0';
			return (s1);
		}
	}
	return (0);
}
