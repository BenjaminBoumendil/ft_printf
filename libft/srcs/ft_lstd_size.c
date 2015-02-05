/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstd_size.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboumend <bboumend@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/04 23:50:04 by bboumend          #+#    #+#             */
/*   Updated: 2015/02/03 18:40:58 by bboumend         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		ft_lstd_count(t_dlist *dlist, void *data)
{
	size_t	*c;

	UN(dlist);
	c = (size_t *)data;
	++(*c);
}

size_t			ft_lstd_size(t_dlist **dlist)
{
	size_t	c;

	c = 0;
	ft_lstd_foreach(*dlist, ft_lstd_count, &c);
	return (c);
}
