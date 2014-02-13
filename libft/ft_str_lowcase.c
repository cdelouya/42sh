/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_lowcase.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hestela <hestela@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/27 20:49:18 by hestela           #+#    #+#             */
/*   Updated: 2013/11/27 20:58:12 by hestela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_str_lowcase(char *str)
{
	char	*start;

	start = str;
	if (str)
	{
		while (*str)
		{
			*str = ft_tolower(*str);
			str++;
		}
	}
	return (start);
}
