/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hestela <hestela@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/26 09:37:24 by hestela           #+#    #+#             */
/*   Updated: 2014/01/30 21:02:12 by hestela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
#include "libft.h"

t_list		*ft_lstnew(void const *content, size_t content_size)
{
	t_list		*node;

	node = NULL;
	node = (t_list *) malloc(sizeof(t_list));
	if (node)
	{
		if (content)
		{
			node->content = (void *) malloc(content_size);
			node->content = ft_memcpy(node->content, content, content_size);
			node->content_size = content_size;
		}
		else
		{
			node->content = NULL;
			node->content_size = 0;
		}
		node->next = NULL;
	}
	return (node);
}
