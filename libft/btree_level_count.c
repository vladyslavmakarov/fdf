/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_level_count.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmakarov <vmakarov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/13 17:06:28 by vmakarov          #+#    #+#             */
/*   Updated: 2017/08/14 19:32:55 by vmakarov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	max(int a, int b)
{
	if (a > b)
		return (a);
	else
		return (b);
}

int			btree_level_count(t_btree *root)
{
	if (!root)
		return (0);
	return (max(btree_level_count(root->left), btree_level_count(root->right))
			+ 1);
}
