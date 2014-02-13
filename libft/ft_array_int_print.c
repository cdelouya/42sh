/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_array_int_print.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hestela <hestela@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/27 11:28:24 by hestela           #+#    #+#             */
/*   Updated: 2013/11/27 13:13:58 by hestela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	ft_array_int_print(int *array, size_t size)
{
	unsigned int		i;

	i = 0;
	if (array && size)
	{
		while (i < size)
		{
			ft_putnbr(array[i]);
			ft_putchar('\n');
			i++;
		}
	}
}
