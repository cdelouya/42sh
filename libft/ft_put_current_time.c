/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_current_time.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hestela <hestela@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/12 12:57:14 by hestela           #+#    #+#             */
/*   Updated: 2014/02/07 12:14:48 by hestela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int		ft_put_current_time(void)
{
	char		**array;
	int			i;
	int			count;
	time_t		clock;

	clock = time(NULL);
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
	ft_array_str_free(array);
	return (count);
}
