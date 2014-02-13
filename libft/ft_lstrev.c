/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hestela <hestela@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/07 16:37:35 by hestela           #+#    #+#             */
/*   Updated: 2013/12/07 16:42:20 by hestela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void		ft_lstrev(t_list **alst)
{
	t_list		*tmp1;
	t_list		*tmp2;

	if (*alst != NULL)
	{
		tmp1 = (*alst)->next;
		(*alst)->next = NULL;
		while (tmp1 != NULL)
		{
			tmp2 = tmp1->next;
			tmp1->next = *alst;
			*alst = tmp1;
			tmp1 = tmp2;
		}
	}
}
