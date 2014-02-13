/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_array_int_rsort.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hestela <hestela@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/27 11:22:21 by hestela           #+#    #+#             */
/*   Updated: 2013/11/29 12:09:01 by hestela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	ft_array_int_rsort(int *array, size_t size)
{
	unsigned int		i;
	unsigned int		j;

	i = 0;
	j = 1;
	if (array && size)
	{
		while (i < size)
		{
			while (j < size)
			{
				if (array[j - 1] < array[j])
					ft_int_swap(&array[j - 1], &array[j]);
				j++;
			}
			j = 1;
			i++;
		}
	}
}
