/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmakarov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/02 14:56:09 by vmakarov          #+#    #+#             */
/*   Updated: 2017/02/13 15:20:16 by vmakarov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char *fresh;
	char *temp;

	if (!s1 || !s2)
		return (NULL);
	if (!(fresh = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1)))
		return (NULL);
	temp = fresh;
	while (*s1 != '\0')
		*temp++ = *s1++;
	while (*s2 != '\0')
		*temp++ = *s2++;
	*temp = '\0';
	return (fresh);
}
