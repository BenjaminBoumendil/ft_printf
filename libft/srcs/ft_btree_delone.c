/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btree_delone.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboumend <bboumend@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/24 21:59:52 by bboumend          #+#    #+#             */
/*   Updated: 2015/02/03 18:36:26 by bboumend         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		rebuild_tree(t_btree *n, t_btree *i, t_btree **r, t_compar cmp)
{
	if (n)
	{
		if (n != i)
			ft_btree_insert(r, n, cmp);
		rebuild_tree(n->left, i, r, cmp);
		rebuild_tree(n->right, i, r, cmp);
	}
}

t_btree			*ft_btree_delone(t_btree **r, void *n, size_t s, t_compar cmp)
{
	t_btree	*removed;
	t_btree	*new_tree;

	new_tree = 0;
	removed = ft_btree_find(*r, n, s, cmp);
	rebuild_tree(*r, removed, &new_tree, cmp);
	*r = new_tree;
	return (removed);
}
