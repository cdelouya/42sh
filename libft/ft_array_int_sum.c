/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_array_int_sum.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hestela <hestela@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/27 14:51:01 by hestela           #+#    #+#             */
/*   Updated: 2013/11/27 15:18:54 by hestela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <string.h>

double		ft_array_int_sum(int *array, size_t size)
{
	double			result;
	unsigned int	i;

	result = 0;
	i = 0;
	if (array)
	{
		while (i < size)
		{
			result += array[i];
			i++;
		}
	}
	return (result);
}
