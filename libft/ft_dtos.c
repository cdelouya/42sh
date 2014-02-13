/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dtos.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hestela <hestela@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/12 20:34:01 by hestela           #+#    #+#             */
/*   Updated: 2013/12/13 08:01:44 by hestela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
#include "libft.h"

char		*ft_dtos(double n, int precision)
{
	char		*str;
	char		*tmps;
	double		tmp;
	int			pow;
	char		*exp;

	pow = 0;
	tmp = n;
	while (tmp > 10)
	{
		pow++;
		tmp /= 10;
	}
	tmps = ft_ftoa(tmp, precision);
	str = ft_strjoin(tmps, "e+");
	free(tmps);
	tmps = ft_strdup(str);
	free(str);
	if (pow < 10)
		exp = ft_strjoin("0", ft_itoa(pow));
	else
		exp = ft_strjoin("", ft_itoa(pow));
	str = ft_strjoin(tmps, exp);
	free(tmps);
	return (str);
}
