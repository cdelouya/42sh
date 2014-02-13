/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putfnbr_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hestela <hestela@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/11 09:57:44 by hestela           #+#    #+#             */
/*   Updated: 2013/12/13 08:00:34 by hestela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static int		ft_print_rest(double n, size_t prcision, int fd);

int				ft_putfnbr_fd(double n, size_t precision, int fd)
{
	int			dot;
	int			count;

	dot = 0;
	count = ft_putnbr_fd((long)n, fd);
	if (n < 0)
		n = -n;
	while (n >= 1 && dot++ >= 0)
		n /= 10;
	while (dot--)
	{
		n *= 10;
		n -= (int)n;
	}
	count += ft_print_rest(n, precision, fd);
	return (count);
}

static int		ft_print_rest(double n, size_t precision, int fd)
{
	size_t		i;
	int			count;

	i = 0;
	count = 0;
	if (precision > 0)
	{
		ft_putchar_fd('.', fd);
		count++;
	}
	while (i++ < precision)
	{
		n *= 10;
		ft_putchar_fd((int)n + '0', fd);
		n -= (int)n;
		count++;
	}
	return (count);
}
