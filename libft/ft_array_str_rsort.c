/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_array_str_rsort.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hestela <hestela@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/27 13:22:43 by hestela           #+#    #+#             */
/*   Updated: 2013/11/29 13:47:54 by hestela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static void		ft_swap_ptr(char **array, int index);

void			ft_array_str_rsort(char **array)
{
	int		i;
	int		j;
	int		len;

	i = 0;
	j = 1;
	if (array && *array)
	{
		len = ft_array_str_len(array);
		if (len > 1)
		{
			while (i < len)
			{
				while (j < len)
				{
					ft_swap_ptr(array, j);
					j++;
				}
				j = 1;
				i++;
			}
		}
	}
}

static void		ft_swap_ptr(char **array, int index)
{
	char	*ptr;

	ptr = array[index];
	if (ft_strcmp(array[index], array[index - 1]) > 0)
	{
		array[index] = array[index - 1];
		array[index - 1] = ptr;
	}
}
