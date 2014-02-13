/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hestela <hestela@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/29 20:51:45 by hestela           #+#    #+#             */
/*   Updated: 2013/11/29 21:32:17 by hestela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
#include "libft.h"

char	*ft_strndup(const char *s1, size_t n)
{
	char	*copy;

	copy = NULL;
	copy = ft_memalloc(n + 1);
	if (copy)
	{
		ft_strncpy(copy, s1, n);
		copy[n] = '\0';
	}
	return (copy);
}
