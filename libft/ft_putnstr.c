/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hestela <hestela@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/17 13:49:31 by hestela           #+#    #+#             */
/*   Updated: 2013/12/17 13:53:18 by hestela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int			ft_putnstr(char const *s, size_t n)
{
	int		i;

	i = 0;
	if (s)
	{
		while (*s && n)
		{
			i += ft_putchar(*s);
			s++;
			n--;
		}
	}
	else
		i += ft_putnstr("(null)", n);
	return (i);
}
