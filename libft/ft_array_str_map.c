/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_array_str_map.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hestela <hestela@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/27 22:41:41 by hestela           #+#    #+#             */
/*   Updated: 2013/11/27 22:47:00 by hestela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
#include "libft.h"

char	**ft_array_str_map(char **array, char *(*f)(char *))
{
	char	**copy;

	copy = NULL;
	if (array && *array)
	{
		copy = ft_array_str_dup(array);
		if (copy)
			ft_array_str_iter(copy, f);
	}
	return (copy);
}
