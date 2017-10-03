/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmakarov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/03 09:29:46 by vmakarov          #+#    #+#             */
/*   Updated: 2017/02/03 12:35:08 by vmakarov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list *temp;
	t_list *temp_next;

	temp = *alst;
	while (temp)
	{
		temp_next = temp->next;
		del(temp->content, temp->content_size);
		free(temp);
		temp = temp->next;
	}
	*alst = NULL;
}
