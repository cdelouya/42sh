/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hestela <hestela@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/26 12:00:12 by hestela           #+#    #+#             */
/*   Updated: 2013/11/29 14:16:57 by hestela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
#include "libft.h"

static t_list		*ft_dup(t_list *lst);

t_list				*ft_lstmap(t_list *lst, t_list *(f)(t_list *elem))
{
	t_list		*start;
	t_list		*list_cpy;

	start = NULL;
	if (lst && f)
	{
		list_cpy = ft_dup(lst);
		if (list_cpy)
		{
			start = list_cpy;
			while (list_cpy)
			{
				list_cpy = f(list_cpy);
				list_cpy = list_cpy->next;
			}
		}
	}
	return (start);
}

static t_list		*ft_dup(t_list *lst)
{
	t_list		*list_cpy;
	t_list		*start;
	t_list		*tmp;

	start = NULL;
	if (lst)
	{
		list_cpy = ft_lstnew(lst->content, lst->content_size);
		if (list_cpy)
		{
			start = list_cpy;
			lst = lst->next;
			while (lst)
			{
				tmp = ft_lstnew(lst->content, lst->content_size);
				if (!tmp)
					return (NULL);
				lst = lst->next;
				list_cpy->next = tmp;
				list_cpy = list_cpy->next;
			}
		}
	}
	return (start);
}
