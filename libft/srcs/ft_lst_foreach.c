/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_foreach.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboumend <bboumend@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/09 20:23:10 by bboumend          #+#    #+#             */
/*   Updated: 2015/02/03 18:40:33 by bboumend         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lst_foreach(t_list *list, t_listf f, void *data)
{
	if (list)
	{
		while (list)
		{
			f(list, data);
			list = list->next;
		}
	}
}
