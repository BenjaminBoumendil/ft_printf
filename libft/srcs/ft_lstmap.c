/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboumend <bboumend@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/18 17:14:01 by bboumend          #+#    #+#             */
/*   Updated: 2014/04/18 17:22:00 by bboumend         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*it;
	t_list	*new_lst;
	t_list	*res;

	it = lst;
	new_lst = NULL;
	while (it)
	{
		res = f(it);
		ft_lstpushback(&new_lst, ft_lstnew(res->content, res->content_size));
		it = it->next;
	}
	return (new_lst);
}
