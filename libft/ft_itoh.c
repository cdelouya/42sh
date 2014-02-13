/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoh.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hestela <hestela@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/11 15:12:32 by hestela           #+#    #+#             */
/*   Updated: 2014/01/30 21:01:40 by hestela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
#include "libft.h"

static void		ft_convert(char *hex, int *i, long n);
static void		ft_minus(char *hex, int *i);

char			*ft_itoh(long n)
{
	char		*hex;
	char		*str;
	int			i;
	int			minus;

	i = 0;
	minus = 0;
	hex = (char *) malloc(sizeof(*hex) * 40);
	if (n < 0)
	{
		n = -n;
		minus = 1;
	}
	ft_convert(hex, &i, n);
	if (minus == 1)
		ft_minus(hex, &i);
	hex[i] = '\0';
	ft_strrev(hex);
	str = (char *) malloc(sizeof(*str) * ft_strlen(hex) + 1);
	ft_strcpy(str, hex);
	free(hex);
	return (str);
}

static void		ft_minus(char *hex, int *i)
{
	hex[*i] = '-';
	(*i)++;
}

static void		ft_convert(char *hex, int *i, long n)
{
	long		rem;

	if (!n)
	{
		hex[*i] = '0';
		(*i)++;
	}
	else
	{
		while (n != 0)
		{
			rem = n % 16;
			if (rem >= 10 && rem <= 15)
				hex[*i] = rem + 87;
			else
				hex[*i] = rem + 48;
			(*i)++;
			n /= 16;
		}
	}
}
