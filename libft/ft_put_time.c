/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_time.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hestela <hestela@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/12 12:16:53 by hestela           #+#    #+#             */
/*   Updated: 2013/12/12 13:23:16 by hestela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int		ft_put_time(const time_t clock)
{
	char	**array;
	int		i;
	int		count;

	i = 0;
	count = 0;
	array = ft_strsplit(ctime(&clock), ' ');
	count += ft_putstr(array[0]);
	count += ft_putchar(' ');
	count += ft_putstr(array[2]);
	count += ft_putchar(' ');
	count += ft_putstr(array[1]);
	count += ft_putchar(' ');
	while (array[4][i] != '\n')
	{
		count += ft_putchar(array[4][i]);
		i++;
	}
	count += ft_putchar(' ');
	count += ft_putstr(array[3]);
	return (count);
}
