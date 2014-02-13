/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_time_to_str.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hestela <hestela@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/12 13:54:33 by hestela           #+#    #+#             */
/*   Updated: 2013/12/12 13:57:49 by hestela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
#include "libft.h"

static char		*ft_suite(char **array);

char			*ft_time_to_str(const time_t clock)
{
	char	**array;
	char	*str;
	char	*tmp;

	array = ft_strsplit(ctime(&clock), ' ');
	str = ft_strjoin(array[0], " ");
	tmp = ft_strdup(str);
	str = ft_strjoin(tmp, array[2]);
	free(tmp);
	tmp = ft_strdup(str);
	free(str);
	str = ft_strjoin(tmp, " ");
	free(tmp);
	tmp = ft_strdup(str);
	free(str);
	str = ft_strjoin(tmp, array[1]);
	free(tmp);
	tmp = ft_strdup(str);
	free(str);
	str = ft_strjoin(tmp, ft_suite(array));
	free(tmp);
	return (str);
}

static char		*ft_suite(char **array)
{
	char	*str;
	char	*year;
	char	*tmp;
	int		i;

	i = 0;
	year = ft_memalloc(5);
	while (array[4][i] != '\n')
	{
		year[i] = array[4][i];
		i++;
	}
	year[4] = '\0';
	str = ft_strjoin(" ", year);
	free(year);
	tmp = ft_strdup(str);
	free(str);
	str = ft_strjoin(tmp, " ");
	free(tmp);
	tmp = ft_strdup(str);
	free(str);
	str = ft_strjoin(tmp, array[3]);
	free(tmp);
	return (str);
}
