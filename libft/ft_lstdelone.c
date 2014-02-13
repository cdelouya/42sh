/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hestela <hestela@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/26 10:12:31 by hestela           #+#    #+#             */
/*   Updated: 2013/11/28 17:09:17 by hestela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
#include "libft.h"

void	ft_lstdelone(t_list **alst, void (*del)(void *, size_t))
{
	t_list		*ret;

	ret = NULL;
	if (alst && *alst && del)
	{
		del((*alst)->content, (*alst)->content_size);
		(*alst)->content = NULL;
		(*alst)->content_size = 0;
		ret = (*alst)->next;
		free(*alst);
		*alst = ret;
	}
}
