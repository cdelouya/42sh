/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   autocomp_tool_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hestela <hestela@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/16 03:59:42 by hestela           #+#    #+#             */
/*   Updated: 2014/02/16 14:34:57 by hestela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char			*ft_get_comp_path(char *begin)
{
	char		buf[1024];
	int			i;

	i = 0;
	ft_bzero(buf, 1024);
	while (begin[i])
	{
		buf[i] = begin[i];
		i++;
	}
	while (buf[i] != '/')
	{
		buf[i] = '\0';
		i--;
	}
	return (ft_strdup(buf));
}

char			*ft_get_comp_rest(char *begin)
{
	char		buf[1024];
	int			i;
	int			j;

	ft_bzero(buf, 1024);
	i = ft_strlen(begin);
	j = 0;
	while (begin[i] != '/')
		i--;
	i++;
	while (begin[i])
	{
		buf[j] = begin[i];
		i++;
		j++;
	}
	buf[j] = '*';
	return (ft_strdup(buf));
}
