/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hestela <hestela@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 13:24:04 by hestela           #+#    #+#             */
/*   Updated: 2014/01/30 21:04:12 by hestela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <string.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	char		*a;

	if (s)
	{
		a = (char *)s;
		while (n)
		{
			if (*a == (char)c)
				return ((void *)a);
			a++;
			n--;
		}
	}
	return (NULL);
}
