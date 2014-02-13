/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hestela <hestela@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/23 17:23:19 by hestela           #+#    #+#             */
/*   Updated: 2014/01/30 21:03:53 by hestela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
#include <string.h>
#include "libft.h"

void	*ft_memalloc(size_t size)
{
	char	*ptr;

	ptr = NULL;
	if (size)
	{
		ptr = (char *) malloc(sizeof(*ptr) * size);
		if (ptr)
			ft_bzero(ptr, size);
		else
			return (NULL);
	}
	return ((void *)ptr);
}
