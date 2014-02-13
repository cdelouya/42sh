/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstprint.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hestela <hestela@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/28 00:04:01 by hestela           #+#    #+#             */
/*   Updated: 2014/01/30 21:02:43 by hestela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
#include <stdlib.h>

void	ft_lstprint(t_list *lst)
{
	while (lst)
	{
		if (lst->content)
		{
			if (lst->content_size == 1)
				ft_putchar(*(char *)lst->content);
			else if (lst->content_size == 4 || lst->content_size == 2)
				ft_putnbr(*(int *)lst->content);
			else if (lst->content_size == 8)
				ft_putfnbr(*(double *)lst->content, 6);
			else
				ft_putstr((char *)lst->content);
		}
		else
			ft_putstr("NULL");
		lst = lst->next;
		ft_putchar('\n');
	}
}
