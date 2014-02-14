/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_multi_join.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hestela <hestela@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/14 02:08:09 by hestela           #+#    #+#             */
/*   Updated: 2014/02/14 02:44:10 by hestela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdarg.h>
#include <stdlib.h>
#include "libft.h"

static int		ft_get_len(va_list ap, int ac);
static void		ft_copy(char *str, char *src, int *j);

char			*ft_str_multi_join(int ac, ...)
{
	char		*str;
	va_list		ap;
	int			len;
	int			i;
	int			j;

	j = 0;
	i = 0;
	va_start(ap, ac);
	len = ft_get_len(ap, ac);
	str = (char*) malloc(sizeof(*str) *len);
	while (i < ac)
	{
		ft_copy(str, va_arg(ap, char*), &j);
		i++;
	}
	str[j] = '\0';
	va_end(ap);
	return (str);
}

static int		ft_get_len(va_list ap, int ac)
{
	int			i;
	int			len;
	va_list		cpy;

	va_copy(cpy, ap);
	i = 0;
	len = 0;
	while (i < ac)
	{
		len += ft_strlen(va_arg(cpy, char*));
		i++;
	}
	len++;
	return (len);
}

static void		ft_copy(char *str, char *src, int *j)
{
	if (src)
	{
		while (*src)
		{
			str[*j] = *src;
			src++;
			(*j)++;
		}
	}
}
