/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hestela <hestela@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 08:40:57 by hestela           #+#    #+#             */
/*   Updated: 2014/01/30 21:07:04 by hestela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <string.h>
#include "libft.h"

char	*ft_strstr(const char *s1, const char *s2)
{
	int		length;

	if (!*s2)
		return ((char *)s1);
	length = ft_strlen(s2);
	while (*s1)
	{
		if (*s1 == *s2)
			if (ft_strncmp(s1, s2, length) == 0)
				return ((char *)s1);
		s1++;
	}
	return (NULL);
}
