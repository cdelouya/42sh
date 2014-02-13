/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hestela <hestela@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/26 21:02:37 by hestela           #+#    #+#             */
/*   Updated: 2013/11/29 12:14:49 by hestela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
#include "libft.h"

t_list		*ft_lstdup(t_list *lst)
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
