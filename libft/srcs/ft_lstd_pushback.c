/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstd_pushback.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboumend <bboumend@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/02 23:03:33 by bboumend          #+#    #+#             */
/*   Updated: 2015/02/03 18:40:55 by bboumend         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstd_pushback(t_dlist **begin, t_dlist *new)
{
	t_dlist	*tmp;

	if (begin)
	{
		if (*begin)
		{
			tmp = *begin;
			while (tmp->next != *begin)
				tmp = tmp->next;
			tmp->next = new;
			(*begin)->previous = new;
			new->next = *begin;
			new->previous = tmp;
		}
		else
		{
			new->next = new;
			new->previous = new;
			*begin = new;
		}
	}
}
