/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_htoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hestela <hestela@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/11 15:29:45 by hestela           #+#    #+#             */
/*   Updated: 2013/12/13 13:41:13 by hestela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static void		ft_convert(char *hex, int i, long *sum);

long			ft_htoi(char *hex)
{
	int			i;
	long		sum;
	int			minus;

	i = 0;
	minus = 0;
	if (hex[i] == '-')
		minus = 1;
	sum = 0;
	ft_convert(hex, i, &sum);
	if (ft_strcmp(hex, "10") == 0)
		return (16);
	if (ft_strcmp(hex, "-10") == 0)
		return (-16);
	if (sum > 15)
		sum++;
	if (minus)
		return (-sum);
	return (sum);
}

static void		ft_convert(char *hex, int i, long *sum)
{
	int			len;

	len = 0;
	while (hex[len] != '\0')
		len++;
	while (hex[i] != '\0')
	{
		if (hex[i] >= '0' && hex[i] <= '9')
			*sum += (hex[i] - '0') * ft_pow(16, len - 1);
		if (hex[i] >= 'A' && hex[i] <= 'F')
			*sum += (hex[i] - 55) * ft_pow(16, len - 1);
		if (hex[i] >= 'a' && hex[i] <= 'f')
			*sum += (hex[i] - 87) * ft_pow(16, len - 1);
		i++;
		len--;
	}
}
