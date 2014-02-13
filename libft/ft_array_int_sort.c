/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_array_int_sort.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hestela <hestela@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/27 10:56:34 by hestela           #+#    #+#             */
/*   Updated: 2013/11/27 11:30:00 by hestela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	ft_array_int_sort(int *array, size_t size)
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
				if (array[j - 1] > array[j])
					ft_int_swap(&array[j - 1], &array[j]);
				j++;
			}
			j = 1;
			i++;
		}
	}
}
