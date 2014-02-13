/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hestela <hestela@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/23 17:35:13 by hestela           #+#    #+#             */
/*   Updated: 2013/11/30 07:53:56 by hestela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <string.h>
#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*str;
	int		i;

	str = NULL;
	i = 0;
	if (size)
	{
		str = ft_memalloc(size + 1);
		if (str)
		{
			while (size)
			{
				str[i] = '\0';
				size--;
				i++;
			}
			str[i] = '\0';
		}
	}
	return (str);
}
