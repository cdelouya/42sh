/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hestela <hestela@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/24 13:46:14 by hestela           #+#    #+#             */
/*   Updated: 2014/01/30 21:06:49 by hestela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
#include "libft.h"

static int		ft_str_nbr(char const *s, char c);
static int		ft_str_size(char const *s, char c);

char			**ft_strsplit(char const *s, char c)
{
	char		**array;
	int			str_nbr;
	int			i;

	array = NULL;
	if (s)
	{
		i = 0;
		str_nbr = ft_str_nbr(s, c);
		array = (char **) malloc(sizeof(char *) * str_nbr + 1);
		if (!array)
			return (NULL);
		while (str_nbr--)
		{
			while (*s == c && *s)
				s++;
			array[i] = ft_strsub(s, 0, ft_str_size(s, c));
			if (!array[i])
				return (NULL);
			s += ft_str_size(s, c);
			i++;
		}
		array[i] = '\0';
	}
	return (array);
}

static int		ft_str_nbr(char const *s, char c)
{
	int		i;
	int		word;

	i = 0;
	word = 0;
	while (*s)
	{
		if (word == 0 && *s != c)
		{
			word = 1;
			i++;
		}
		else if (word == 1 && *s == c)
			word = 0;
		s++;
	}
	return (i);
}

static int		ft_str_size(char const *s, char c)
{
	int		length;

	length = 0;
	while (*s != c && *s != '\0')
	{
		length++;
		s++;
	}
	return (length);
}
