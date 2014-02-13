/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_array_int_min.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hestela <hestela@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/30 12:32:38 by hestela           #+#    #+#             */
/*   Updated: 2013/11/30 12:49:18 by hestela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <string.h>

int		ft_array_int_min(int *array, size_t size)
{
	int					result;
	unsigned int		i;

	result = 0;
	if (array && size)
	{
		i = 0;
		result = array[0];
		while (i < size)
		{
			if (array[i] < result)
				result = array[i];
			i++;
		}
	}
	return (result);
}
