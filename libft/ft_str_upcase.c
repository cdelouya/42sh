/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_upcase.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hestela <hestela@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/27 20:35:19 by hestela           #+#    #+#             */
/*   Updated: 2013/11/27 20:59:05 by hestela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_str_upcase(char *str)
{
	char	*start;

	start = str;
	if (str)
	{
		while (*str)
		{
			*str = ft_toupper(*str);
			str++;
		}
	}
	return (start);
}
