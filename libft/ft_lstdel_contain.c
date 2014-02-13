/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel_contain.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hestela <hestela@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/11 21:40:08 by hestela           #+#    #+#             */
/*   Updated: 2013/12/11 21:45:35 by hestela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

t_list		*ft_lstdel_contain(t_list *list, char *str)
{
	if (!list)
		return (NULL);
	if (ft_strcmp(list->content, str) == 0)
	{
		ft_lstdelone(&list, ft_bzero);
		list = ft_lstdel_contain(list, str);
		return (list);
	}
	else
	{
		list->next = ft_lstdel_contain(list->next, str);
		return (list);
	}
}
