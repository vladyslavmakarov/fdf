/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmakarov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/02 14:33:56 by vmakarov          #+#    #+#             */
/*   Updated: 2017/02/02 14:33:57 by vmakarov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*copy;
	int		i;

	i = ft_strlen(s1);
	copy = (char *)malloc(i + 1);
	if (copy == '\0')
		return (0);
	ft_strcpy(copy, s1);
	return (copy);
}
