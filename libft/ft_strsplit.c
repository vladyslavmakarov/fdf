/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmakarov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/02 15:15:57 by vmakarov          #+#    #+#             */
/*   Updated: 2017/02/02 15:24:20 by vmakarov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_len(const char *s, char c, int position_beg)
{
	int length;

	length = 0;
	while (s[position_beg] != c && s[position_beg])
	{
		length++;
		position_beg++;
	}
	return (length);
}

static int	ft_position_beg(const char *s, char c, int word_number)
{
	int j;
	int position;

	position = 0;
	j = 0;
	while (word_number > 0)
	{
		if ((s[j - 1] == c && s[j] != c) || j == 0)
			position = j;
		if ((s[j] != c) && ((s[j + 1] == c) || (s[j + 1] == '\0')))
			word_number--;
		j++;
	}
	return (position);
}

static int	ft_size_of_array(const char *s, char c)
{
	int i;
	int size_array;

	size_array = 0;
	i = 0;
	if (!s)
		return (0);
	while (s[i])
	{
		if ((s[i] != c) && ((s[i + 1] == c) || (s[i + 1] == '\0')))
			size_array++;
		i++;
	}
	return (size_array);
}

char		**ft_strsplit(const char *s, char c)
{
	int		size_array;
	char	**result;
	int		word_number;

	if (s == NULL)
		return (NULL);
	size_array = ft_size_of_array(s, c);
	if (!(result = (char **)malloc(sizeof((char *)s) * (size_array + 1))))
		return (NULL);
	word_number = 0;
	while (size_array >= 1)
	{
		result[word_number] = ft_strsub(s, ft_position_beg(s, c, word_number
					+ 1), ft_len(s, c, ft_position_beg(s, c, word_number + 1)));
		size_array--;
		word_number++;
	}
	result[word_number] = NULL;
	return (result);
}
