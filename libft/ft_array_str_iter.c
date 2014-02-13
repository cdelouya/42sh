/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_array_str_iter.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hestela <hestela@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/27 21:23:03 by hestela           #+#    #+#             */
/*   Updated: 2013/11/30 21:43:32 by hestela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	ft_array_str_iter(char **array, char *(*f)(char *))
{
	int		i;

	i = 0;
	if (array && *array)
	{
		while (array[i])
		{
			f(array[i]);
			i++;
		}
	}
}
