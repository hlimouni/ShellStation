/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iltafah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 01:10:11 by iltafah           #+#    #+#             */
/*   Updated: 2021/06/14 15:21:02 by iltafah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_list;
	t_list	*tmp;

	if (lst && f && del)
	{
		new_list = ft_lstnew((*f)(lst->content));
		if (!new_list)
			return (NULL);
		tmp = new_list;
		lst = lst->next;
		while (lst)
		{
			tmp->next = ft_lstnew((*f)(lst->content));
			if (!tmp->next)
			{
				ft_lstclear(&new_list, del);
				return (NULL);
			}
			tmp = tmp->next;
			lst = lst->next;
		}
	}
	else
		new_list = NULL;
	return (new_list);
}
