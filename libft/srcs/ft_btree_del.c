/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btree_del.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboumend <bboumend@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/24 21:50:15 by bboumend          #+#    #+#             */
/*   Updated: 2015/02/03 18:36:21 by bboumend         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		recurse_free(t_btree *node, t_deleter del)
{
	if (node)
	{
		recurse_free(node->right, del);
		recurse_free(node->left, del);
		del(node->content, node->content_size);
		free(node);
	}
}

void			ft_btree_del(t_btree **root, t_deleter del)
{
	t_btree	*tmp;

	tmp = *root;
	if (tmp)
	{
		recurse_free(tmp, del);
		*root = 0;
	}
}
