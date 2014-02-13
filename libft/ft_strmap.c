/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hestela <hestela@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/23 18:25:14 by hestela           #+#    #+#             */
/*   Updated: 2013/11/29 21:35:15 by hestela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*str;
	int		i;

	str = NULL;
	i = 0;
	if (s && f)
	{
		str = ft_memalloc(ft_strlen(s) + 1);
		if (str)
		{
			while (*s)
			{
				str[i] = f(*s);
				s++;
				i++;
			}
			str[i] = '\0';
		}
	}
	return (str);
}
