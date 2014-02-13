/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hestela <hestela@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 13:14:35 by hestela           #+#    #+#             */
/*   Updated: 2013/12/10 14:01:08 by hestela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <string.h>

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*str1;
	unsigned char	*str2;

	if (s1 && s2 && n)
	{
		str1 = (unsigned char*)s1;
		str2 = (unsigned char*)s2;
		while (n--)
		{
			if (*str1 != *str2)
				return (*str1 - *str2);
			str1++;
			str2++;
		}
	}
	return (0);
}
