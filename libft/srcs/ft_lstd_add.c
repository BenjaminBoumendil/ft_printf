/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstd_add.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboumend <bboumend@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/02 22:29:58 by bboumend          #+#    #+#             */
/*   Updated: 2015/02/03 18:40:38 by bboumend         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstd_add(t_dlist **alst, t_dlist *new)
{
	t_dlist	*tmp;

	if (alst)
	{
		if (*alst)
		{
			tmp = *alst;
			while (tmp->next != *alst)
				tmp = tmp->next;
			new->next = *alst;
			new->previous = tmp;
			tmp->next = new;
			(*alst)->previous = new;
		}
		else
		{
			new->next = new;
			new->previous = new;
		}
		*alst = new;
	}
}
