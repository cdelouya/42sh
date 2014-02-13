/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_array_int_avg.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hestela <hestela@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/27 15:13:42 by hestela           #+#    #+#             */
/*   Updated: 2013/11/27 18:41:42 by hestela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

float		ft_array_int_avg(int *array, size_t size)
{
	float		result;

	result = 0;
	if (array)
		result = ft_array_int_sum(array, size) / size;
	return (result);
}
