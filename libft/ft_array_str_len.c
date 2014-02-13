/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_array_str_len.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hestela <hestela@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/27 12:49:33 by hestela           #+#    #+#             */
/*   Updated: 2013/11/30 21:42:21 by hestela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>

size_t		ft_array_str_len(char **array)
{
	int		length;
	int		i;

	length = 0;
	i = 0;
	if (array && *array)
	{
		while (array[i])
		{
			length++;
			i++;
		}
	}
	return (length);
}
