/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hestela <hestela@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 21:03:08 by hestela           #+#    #+#             */
/*   Updated: 2014/01/30 21:06:25 by hestela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <string.h>

char	*ft_strrchr(const char *s, int c)
{
	char	*start;

	start = (char *)s;
	if (!s)
		return (NULL);
	while (*s)
		s++;
	while (s != start && *s != (char)c)
		s--;
	if (*s == (char)c)
		return ((char *)s);
	return (NULL);
}
