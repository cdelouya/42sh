/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hestela <hestela@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/24 12:56:57 by hestela           #+#    #+#             */
/*   Updated: 2013/11/30 13:25:59 by hestela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
#include <string.h>
#include "libft.h"

static size_t		ft_lentrim(const char *s);

char				*ft_strtrim(char const *s)
{
	char	*str;
	int		n;

	if (!s)
		return (NULL);
	if (ft_lentrim(s) == ft_strlen(s))
		return (ft_strdup(s));
	str = NULL;
	str = ft_memalloc(ft_lentrim(s) + 1);
	n = ft_lentrim(s);
	if (str)
	{
		while (*s == ' ' || *s == '\n' || *s == '\t')
			s++;
		ft_strncpy(str, s, n);
		str[n] = '\0';
	}
	return (str);
}

static size_t		ft_lentrim(const char *s)
{
	size_t	length;

	length = 0;
	while (*s == ' ' || *s == '\n' || *s == '\t')
		s++;
	if (!*s)
		return (length);
	while (*s)
	{
		length++;
		s++;
	}
	s--;
	while (*s == ' ' || *s == '\n' || *s == '\t')
	{
		length--;
		s--;
	}
	return (length);
}
