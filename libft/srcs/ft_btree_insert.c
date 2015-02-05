/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btree_insert.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboumend <bboumend@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/24 19:27:03 by bboumend          #+#    #+#             */
/*   Updated: 2015/02/03 18:36:34 by bboumend         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		recurse_insert(t_btree *node, t_btree *n, t_compar cmp)
{
	if (cmp(node->content, node->content_size, n->content, n->content_size) < 0)
	{
		if (!node->left)
			node->left = n;
		else
			recurse_insert(node->left, n, cmp);
	}
	else
	{
		if (!node->right)
			node->right = n;
		else
			recurse_insert(node->right, n, cmp);
	}
}

void			ft_btree_insert(t_btree **root, t_btree *node, t_compar cmp)
{
	if (!*root)
		*root = node;
	else
		recurse_insert(*root, node, cmp);
}
