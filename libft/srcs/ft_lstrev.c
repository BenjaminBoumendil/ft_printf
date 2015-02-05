/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboumend <bboumend@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/16 16:01:22 by bboumend          #+#    #+#             */
/*   Updated: 2015/02/03 18:41:16 by bboumend         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstrev(t_list *lst)
{
	t_list	*out;

	out = NULL;
	while (lst)
	{
		ft_lstadd(&out, ft_lstnew(lst->content, lst->content_size));
		lst = lst->next;
	}
	return (out);
}
