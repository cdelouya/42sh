/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_array_str_free.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hestela <hestela@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/27 12:16:14 by hestela           #+#    #+#             */
/*   Updated: 2013/12/03 14:54:14 by hestela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>

void	ft_array_str_free(char **array)
{
	int		i;

	i = 0;
	if (array)
	{
		if (*array)
		{
			while (array[i])
			{
				free(array[i]);
				array[i] = NULL;
				i++;
			}
		}
		free(array);
		array = NULL;
	}
}
