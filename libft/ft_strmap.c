/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmakarov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/02 14:36:40 by vmakarov          #+#    #+#             */
/*   Updated: 2017/02/13 15:21:32 by vmakarov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
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
				s1[j] = f(s[j]);
				j++;
			}
			s1[j] = '\0';
			return (s1);
		}
	}
	return (NULL);
}
