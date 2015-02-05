/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstd_delone.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboumend <bboumend@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/05 22:45:08 by bboumend          #+#    #+#             */
/*   Updated: 2015/02/03 18:40:41 by bboumend         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstd_delone(t_dlist **dlist, t_dlist *ptr)
{
	t_dlist		*tmp_previous;
	t_dlist		*tmp_next;

	tmp_previous = ptr->previous;
	tmp_next = ptr->next;
	if (ptr == *dlist)
		*dlist = (ptr == tmp_next ? 0 : tmp_next);
	free(ptr->content);
	free(ptr);
	tmp_previous->next = tmp_next;
	tmp_next->previous = tmp_previous;
}
