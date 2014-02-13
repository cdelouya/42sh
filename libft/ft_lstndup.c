/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hestela <hestela@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/27 09:57:05 by hestela           #+#    #+#             */
/*   Updated: 2013/11/29 12:17:27 by hestela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
#include "libft.h"

t_list		*ft_lstndup(t_list *lst, size_t n)
{
	t_list		*list_cpy;
	t_list		*start;
	t_list		*tmp;

	start = NULL;
	if (lst && n)
	{
		list_cpy = ft_lstnew(lst->content, lst->content_size);
		n--;
		if (list_cpy && n)
		{
			start = list_cpy;
			lst = lst->next;
			while (lst && n--)
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
