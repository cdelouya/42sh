/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hestela <hestela@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 08:39:56 by hestela           #+#    #+#             */
/*   Updated: 2013/11/24 12:15:57 by hestela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <string.h>

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	if (!s1 || !s2 || !n)
		return (0);
	while (n)
	{
		if (*s1 != *s2)
		{
			if (*s1 > *s2)
				return (1);
			else
				return (-1);
		}
		if (*s1 == 0)
			return (0);
		s1++;
		s2++;
		n--;
	}
	return (0);
}
