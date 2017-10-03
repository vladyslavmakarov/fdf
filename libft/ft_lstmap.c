/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmakarov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/03 10:59:04 by vmakarov          #+#    #+#             */
/*   Updated: 2017/02/04 18:49:52 by vmakarov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *res;
	t_list *temp;
	t_list *temp_res;

	if (!lst)
		return (NULL);
	temp = (*f)(lst);
	res = ft_lstnew(temp->content, temp->content_size);
	temp_res = res;
	lst = lst->next;
	while (lst != NULL)
	{
		temp = (*f)(lst);
		temp_res->next = ft_lstnew(temp->content, temp->content_size);
		temp_res = temp_res->next;
		lst = lst->next;
	}
	return (res);
}
