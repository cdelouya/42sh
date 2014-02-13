/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hestela <hestela@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 12:42:28 by hestela           #+#    #+#             */
/*   Updated: 2014/01/04 14:52:19 by hestela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <string.h>

void	*ft_memccpy(void *s1, const void *s2, int c, size_t n)
{
	char	*a;
	char	*b;

	a = (char *) s1;
	b = (char *) s2;
	while (n)
	{
		*a = *b;
		a++;
		if (*b == c)
			return (a++);
		b++;
		n--;
	}
	return (NULL);
}
