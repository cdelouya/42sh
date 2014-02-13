/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hestela <hestela@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 08:40:33 by hestela           #+#    #+#             */
/*   Updated: 2014/01/30 21:06:09 by hestela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <string.h>
#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	int				length;
	unsigned int	i;

	if (!s2 || !s2 || !n)
		return (NULL);
	if (!*s2)
		return ((char *)s1);
	length = ft_strlen(s2);
	i = 0;
	if ((unsigned int)length > n)
		return (NULL);
	while (*s1 && i < n - (length - 1))
	{
		if (*s1 == *s2)
		{
			if (ft_strncmp(s1, s2, length) == 0)
				return ((char *)s1);
		}
		s1++;
		i++;
	}
	return (NULL);
}
