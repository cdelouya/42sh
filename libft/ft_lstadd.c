/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hestela <hestela@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/26 11:38:56 by hestela           #+#    #+#             */
/*   Updated: 2013/11/26 11:45:12 by hestela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
#include "libft.h"

void	ft_lstadd(t_list **alst, t_list *new)
{
	if (*alst && alst && new)
	{
		new->next = *alst;
		*alst = new;
	}
}
