/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_caps.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hestela <hestela@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/27 20:55:13 by hestela           #+#    #+#             */
/*   Updated: 2013/11/29 12:26:53 by hestela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char		*ft_str_caps(char *str)
{
	int		i;

	i = 0;
	ft_str_lowcase(str);
	if (str[0] >= 97 && str[0] <= 122)
	{
		str[0] = ft_toupper(str[0]);
		i++;
	}
	while (str[i])
	{
		if ((str[i - 1] < 65 || str[i - 1] > 90)
			&& (str[i - 1] < 97 || str[i - 1] > 122))
			str[i] = ft_toupper(str[i]);
		i++;
	}
	return (str);
}
