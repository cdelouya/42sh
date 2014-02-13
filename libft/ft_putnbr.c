/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hestela <hestela@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/24 09:34:35 by hestela           #+#    #+#             */
/*   Updated: 2013/12/10 21:04:01 by hestela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int		ft_putnbr(long n)
{
	int		i;

	i = 1;
	if (n < 0)
	{
		ft_putchar('-');
		i += ft_putnbr(n - (n * 2));
	}
	else if (n >= 10)
	{
		i += ft_putnbr(n / 10);
		ft_putnbr(n % 10);
	}
	else
	{
		ft_putchar(n + '0');
	}
	return (i);
}
