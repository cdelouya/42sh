/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ftoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hestela <hestela@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/27 18:42:15 by hestela           #+#    #+#             */
/*   Updated: 2014/01/30 21:00:11 by hestela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
#include "libft.h"

static int		ft_str_size(double n, size_t precision);
static void		ft_convert(char *str, double n, size_t precision);
static void		ft_convert_rest(char *str, double n, size_t prec, int dot);

char			*ft_ftoa(double n, size_t precision)
{
	char		*str;

	str = NULL;
	str = (char *) malloc(sizeof(*str) * ft_str_size(n, precision) + 1);
	if (str)
		ft_convert(str, n, precision);
	return (str);
}

static int		ft_str_size(double n, size_t precision)
{
	int			len;
	int			dot;

	len = 0;
	dot = 0;
	if (n < 0)
	{
		len++;
		n = -n;
	}
	while (n >= 1)
	{
		len++;
		n /= 10;
	}
	if (precision > 0)
		len++;
	len += precision;
	return (len);
}

static void		ft_convert(char *str, double n, size_t precision)
{
	int			dot;

	dot = 0;
	if (n < 0)
	{
		*str = '-';
		n = -n;
		str++;
	}
	while (n >= 1 && dot++ >= 0)
		n /= 10;
	ft_convert_rest(str, n, precision, dot);
}

static void		ft_convert_rest(char *str, double n, size_t prec, int dot)
{
	size_t		i;

	i = 0;
	while (dot--)
	{
		n *= 10;
		*str = (int)n + '0';
		str++;
		n -= (int)n;
	}
	if (prec > 0)
	{
		*str = '.';
		str++;
		while (i++ < prec)
		{
			n *= 10;
			*str = (int)n + '0';
			str++;
			n -= (int)n;
		}
	}
	*str = '\0';
}
