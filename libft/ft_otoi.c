/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_otoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hestela <hestela@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/11 14:32:17 by hestela           #+#    #+#             */
/*   Updated: 2013/12/12 10:12:26 by hestela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

long		ft_otoi(long n)
{
	long	decimal;
	long	i;
	long	rem;

	decimal = 0;
	i = 0;
	while (n != 0)
	{
		rem = n % 10;
		n /= 10;
		decimal += rem * ft_pow(8, i);
		i++;
	}
	return (decimal);
}
