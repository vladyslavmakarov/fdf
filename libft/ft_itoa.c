/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmakarov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/02 15:13:26 by vmakarov          #+#    #+#             */
/*   Updated: 2017/02/08 16:52:39 by vmakarov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	char	*deal_positive(int n, int length, char *res)
{
	char *temp;

	temp = res;
	while (length > 0)
	{
		res[length-- - 1] = n % 10 + '0';
		n = n / 10;
		temp++;
	}
	*temp = '\0';
	return (res);
}

static	char	*deal_negative(int n, int length, char *res)
{
	char *temp;

	temp = res;
	n = -n;
	while (length > 0)
	{
		res[length-- - 1] = n % 10 + '0';
		n = n / 10;
		temp++;
	}
	res[length] = '-';
	*temp = '\0';
	return (res);
}

static	int		ft_size_of_array(int n)
{
	int size;

	size = 0;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		if (n == -2147483648)
			n = n + 2;
		n = n * (-1);
		while (n > 0)
		{
			n = n / 10;
			size++;
		}
		return (size + 1);
	}
	while (n > 0)
	{
		n = n / 10;
		size++;
	}
	return (size);
}

char			*ft_itoa(int n)
{
	char	*res;
	int		i;

	i = ft_size_of_array(n);
	if (!(res = (char *)malloc(sizeof(char) * (i + 1))))
		return (NULL);
	if (n == -2147483648)
		return (ft_memcpy(res, "-2147483648", i));
	if (n == 2147483647)
	{
		res = ft_strdup("2147483647");
		return (res);
	}
	if (n > -2147483648 && n < 2147483647 && n >= 0)
	{
		res = deal_positive(n, i, res);
		return (res);
	}
	if (n > -2147483648 && n < 2147483647 && n < 0)
	{
		res = deal_negative(n, i, res);
		return (res);
	}
	return (NULL);
}
