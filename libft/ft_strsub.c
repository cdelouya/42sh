/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hestela <hestela@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/24 11:57:10 by hestela           #+#    #+#             */
/*   Updated: 2013/11/30 13:13:53 by hestela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
#include <string.h>
#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char				*str;
	unsigned int		i;

	str = NULL;
	i = 0;
	if (!s)
		return (NULL);
	str = ft_strnew(len + 1);
	if (str)
	{
		while (len)
		{
			str[i] = s[start];
			i++;
			start++;
			len--;
		}
		str[i] = '\0';
	}
	return (str);
}
