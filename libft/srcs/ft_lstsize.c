/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboumend <bboumend@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/17 13:49:10 by bboumend          #+#    #+#             */
/*   Updated: 2015/02/03 18:41:19 by bboumend         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_lstsize(t_list **list)
{
	t_list	*tmp;
	size_t	size;

	size = 0;
	tmp = *list;
	while (tmp)
	{
		tmp = tmp->next;
		++size;
	}
	return (size);
}
