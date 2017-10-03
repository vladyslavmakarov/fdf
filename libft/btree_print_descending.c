/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_print_descending.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmakarov <vmakarov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/13 17:06:28 by vmakarov          #+#    #+#             */
/*   Updated: 2017/08/14 19:31:54 by vmakarov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	btree_print_descending(t_btree *root)
{
	if (root->right)
		btree_print_descending(root->right);
	ft_putstr(root->item);
	if (root->left)
		btree_print_descending(root->left);
}
