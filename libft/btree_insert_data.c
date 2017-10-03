/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_insert_data.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmakarov <vmakarov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/13 17:06:28 by vmakarov          #+#    #+#             */
/*   Updated: 2017/08/14 19:31:11 by vmakarov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	btree_insert_data(t_btree **root, void *item, int (*cmpf)
							(void *, void *))
{
	t_btree *fork;

	if (!*root)
	{
		*root = btree_create_node(item);
		return ;
	}
	fork = *root;
	if ((*cmpf)(item, fork->item) < 0)
	{
		if (fork->left)
			btree_insert_data(&fork->left, item, cmpf);
		else
			fork->left = btree_create_node(item);
	}
	else
	{
		if (fork->right)
			btree_insert_data(&fork->right, item, cmpf);
		else
			fork->right = btree_create_node(item);
	}
}
