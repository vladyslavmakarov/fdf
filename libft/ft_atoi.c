/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmakarov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/02 14:57:31 by vmakarov          #+#    #+#             */
/*   Updated: 2017/02/02 15:06:56 by vmakarov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int	i;
	int	flag;
	int	res;

	res = 0;
	i = 0;
	flag = 1;
	while ((str[i] == '\n') || (str[i] == '\t') || (str[i] == '\v') ||
			(str[i] == ' ') || (str[i] == '\f') || (str[i] == '\r'))
		i++;
	if (str[i] == 43 || str[i] == 45)
	{
		if (str[i] == 45)
			flag = -1;
		i++;
	}
	while (str[i] && str[i] <= 57 && str[i] >= 48)
	{
		if (i >= 19 && flag == 1)
			return (-1);
		if (i >= 19 && flag == -1)
			return (0);
		res = res * 10 + str[i++] - '0';
	}
	return (res * flag);
}
