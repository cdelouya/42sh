/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hestela <hestela@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/26 10:53:48 by hestela           #+#    #+#             */
/*   Updated: 2013/11/29 12:13:49 by hestela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list		*node;

	node = NULL;
	if (*alst && alst && del)
	{
		node = *alst;
		while (node)
			ft_lstdelone(&node, del);
		*alst = NULL;
	}
}
