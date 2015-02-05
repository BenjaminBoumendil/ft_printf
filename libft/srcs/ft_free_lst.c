/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_lst.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboumend <bboumend@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/09 21:11:02 by bboumend          #+#    #+#             */
/*   Updated: 2015/02/03 18:36:43 by bboumend         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_free_lst(t_list **list)
{
	t_list	*tmp;

	if (list)
	{
		while (*list)
		{
			tmp = (*list)->next;
			free((*list)->content);
			free(*list);
			*list = tmp;
		}
	}
}
