/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmakarov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/02 14:59:28 by vmakarov          #+#    #+#             */
/*   Updated: 2017/02/13 15:22:38 by vmakarov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*s1;
	int		j;

	if (s)
	{
		s1 = (char *)malloc(ft_strlen(s) + 1);
		j = 0;
		if (s1)
		{
			while (s[j] != '\0')
			{
				s1[j] = f(j, s[j]);
				j++;
			}
			s1[j] = '\0';
			return (s1);
		}
	}
	return (NULL);
}
