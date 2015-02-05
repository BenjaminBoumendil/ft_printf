/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btree_new.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboumend <bboumend@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/24 18:16:11 by bboumend          #+#    #+#             */
/*   Updated: 2015/02/03 18:36:37 by bboumend         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_btree	*ft_btree_new(void *content, size_t content_size)
{
	t_btree	*new_elem;

	new_elem = malloc(sizeof(t_btree));
	if (new_elem)
	{
		new_elem->content_size = (content ? content_size : 0);
		new_elem->content = (content ? malloc(sizeof(content_size)) : 0);
		if (new_elem->content)
			ft_memcpy(new_elem->content, content, content_size);
		new_elem->right = NULL;
		new_elem->left = NULL;
	}
	return (new_elem);
}
