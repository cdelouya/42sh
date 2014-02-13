/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_array_int_max.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hestela <hestela@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/30 12:37:28 by hestela           #+#    #+#             */
/*   Updated: 2013/11/30 12:49:07 by hestela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <string.h>

int		ft_array_int_max(int *array, size_t size)
{
	int					result;
	unsigned int		i;

	result = 0;
	if (array && size)
	{
		result = array[0];
		i = 0;
		while (i < size)
		{
			if (array[i] > result)
				result = array[i];
			i++;
		}
	}
	return (result);
}
