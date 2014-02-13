/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hestela <hestela@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/24 10:03:00 by hestela           #+#    #+#             */
/*   Updated: 2013/11/24 18:28:48 by hestela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*s;
	int		i;

	s = NULL;
	i = 0;
	if (!s1 || !s2)
		return (NULL);
	s = ft_strnew(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!s)
		return (NULL);
	while (*s1)
	{
		s[i] = *s1;
		s1++;
		i++;
	}
	while (*s2)
	{
		s[i] = *s2;
		s2++;
		i++;
	}
	s[i] = '\0';
	return (s);
}
