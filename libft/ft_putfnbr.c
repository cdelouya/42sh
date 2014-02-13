/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putfnbr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hestela <hestela@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/27 18:56:25 by hestela           #+#    #+#             */
/*   Updated: 2013/12/13 07:59:12 by hestela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static int		ft_print_rest(double n, size_t precision);

int				ft_putfnbr(double n, size_t precision)
{
	int			dot;
	int			count;

	dot = 0;
	count = ft_putnbr((long)n);
	if (n < 0)
		n = -n;
	while (n >= 1 && dot++ >= 0)
		n /= 10;
	while (dot--)
	{
		n *= 10;
		n -= (int)n;
	}
	count += ft_print_rest(n, precision);
	return (count);
}

static int		ft_print_rest(double n, size_t precision)
{
	size_t		i;
	int			count;

	i = 0;
	count = 0;
	if (precision > 0)
	{
		ft_putchar('.');
		count++;
	}
	while (i++ < precision)
	{
		n *= 10;
		ft_putchar((int)n + '0');
		n -= (int)n;
		count++;
	}
	return (count);
}
