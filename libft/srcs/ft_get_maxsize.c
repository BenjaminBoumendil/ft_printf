/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_maxsize.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboumend <bboumend@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/08 05:36:37 by bboumend          #+#    #+#             */
/*   Updated: 2015/02/03 18:36:50 by bboumend         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_maxsize(t_dlist *dlist, void *data)
{
	size_t	*c;

	c = (size_t *)data;
	if (dlist->content_size > *c)
		*c = dlist->content_size;
}

size_t	ft_get_maxsize(t_dlist *dlist)
{
	size_t	c;

	c = 0;
	ft_lstd_foreach(dlist, ft_maxsize, &c);
	return (c);
}
