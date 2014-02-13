/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_array_str_dup.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hestela <hestela@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/27 21:52:24 by hestela           #+#    #+#             */
/*   Updated: 2014/02/03 23:09:38 by hestela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
#include "libft.h"

static char		**ft_create_array(int str_nbr, int *str_size);
static void		ft_copy_array(int nbr, int *size, char **copy, char **array);

char			**ft_array_str_dup(char **array)
{
	char		**copy;
	int			*str_size;
	size_t		i;

	copy = NULL;
	i = 0;
	if (array && *array)
	{
		str_size = (int *) malloc(sizeof(*str_size) * ft_array_str_len(array));
		while (i < ft_array_str_len(array))
		{
			str_size[i] = ft_strlen(array[i]) + 1;
			i++;
		}
		copy = ft_create_array(ft_array_str_len(array), str_size);
		if (copy)
			ft_copy_array(ft_array_str_len(array), str_size, copy, array);
	}
	return (copy);
}

static char		**ft_create_array(int str_nbr, int *str_size)
{
	char	**array;
	int		i;

	i = 0;
	array = NULL;
	array = (char **) malloc(sizeof(*array) * str_nbr + 1);
	i = 0;
	if (array)
	{
		while (i < str_nbr)
		{
			array[i] = (char *) malloc(sizeof(**array) * str_size[i]);
			if (array[i] == NULL)
				return (NULL);
			i++;
		}
		array[i] = '\0';
	}
	return (array);
}

static void		ft_copy_array(int nbr, int *size, char **copy, char **array)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (i < nbr)
	{
		while (j < size[i])
		{
			copy[i][j] = array[i][j];
			j++;
		}
		j = 0;
		i++;
	}
}
