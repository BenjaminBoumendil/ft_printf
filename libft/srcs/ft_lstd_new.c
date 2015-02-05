/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstd_new.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboumend <bboumend@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/02 22:13:18 by bboumend          #+#    #+#             */
/*   Updated: 2015/02/03 18:40:51 by bboumend         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_dlist	*ft_lstd_new(const void *content, size_t content_size)
{
	t_dlist	*new_elem;

	new_elem = malloc(sizeof(t_dlist));
	if (new_elem)
	{
		if (content != 0)
		{
			new_elem->content = ft_memalloc(content_size);
			ft_memcpy(new_elem->content, content, content_size);
			new_elem->content_size = content_size;
		}
		else
		{
			new_elem->content = NULL;
			new_elem->content_size = 0;
		}
		new_elem->select = 0;
		new_elem->next = NULL;
		new_elem->previous = NULL;
	}
	return (new_elem);
}
