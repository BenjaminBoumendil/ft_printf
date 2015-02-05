/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btree_find.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboumend <bboumend@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/24 22:30:35 by bboumend          #+#    #+#             */
/*   Updated: 2015/02/03 18:36:30 by bboumend         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_btree	*ft_btree_find(t_btree *node, void *n, size_t s, t_compar cmp)
{
	int		cmp_value;

	if (node)
	{
		cmp_value = cmp(node->content, node->content_size, n, s);
		if (!cmp_value)
			return (node);
		if (cmp_value > 0)
			return (ft_btree_find(node->right, n, s, cmp));
		return (ft_btree_find(node->left, n, s, cmp));
	}
	return (0);
}
