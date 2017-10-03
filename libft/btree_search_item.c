/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_search_item.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmakarov <vmakarov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/13 17:06:28 by vmakarov          #+#    #+#             */
/*   Updated: 2017/08/14 19:29:54 by vmakarov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*btree_search_item(t_btree *root, void *data_ref,
							int (*cmpf)(void *, void *))
{
	void *searched_item;

	searched_item = NULL;
	if (root)
	{
		searched_item = btree_search_item(root->left, data_ref, cmpf);
		if (!searched_item && ((*cmpf)(root->item, data_ref) == 0))
			searched_item = root->item;
		if (!searched_item)
			searched_item = btree_search_item(root->right, data_ref, cmpf);
	}
	return (searched_item);
}
