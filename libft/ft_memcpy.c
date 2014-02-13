/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hestela <hestela@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 12:26:26 by hestela           #+#    #+#             */
/*   Updated: 2014/01/30 21:04:27 by hestela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <string.h>

void	*ft_memcpy(void *s1, const void *s2, size_t n)
{
	char	*a;
	char	*b;

	a = (char *)s1;
	b = (char *)s2;
	while (n)
	{
		*a = *b;
		a++;
		b++;
		n--;
	}
	return (s1);
}