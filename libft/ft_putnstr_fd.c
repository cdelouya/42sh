/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnstr_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hestela <hestela@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/17 13:51:17 by hestela           #+#    #+#             */
/*   Updated: 2013/12/17 13:55:01 by hestela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int		ft_putnstr_fd(char const *s, size_t n, int fd)
{
	int		i;

	i = 0;
	if (s)
	{
		while (*s && n)
		{
			i += ft_putchar_fd(*s, fd);
			s++;
			n--;
		}
	}
	else
		i += ft_putnstr_fd("(null)", n, fd);
	return (i);
}
