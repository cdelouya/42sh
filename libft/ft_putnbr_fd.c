/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hestela <hestela@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/24 09:37:31 by hestela           #+#    #+#             */
/*   Updated: 2013/12/11 09:56:52 by hestela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int		ft_putnbr_fd(long n, int fd)
{
	int		i;

	i = 1;
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		i += ft_putnbr_fd(n - (n * 2), fd);
	}
	else if (n >= 10)
	{
		i += ft_putnbr_fd(n / 10, fd);
		ft_putnbr_fd(n % 10, fd);
	}
	else
	{
		ft_putchar_fd(n + '0', fd);
	}
	return (i);
}
