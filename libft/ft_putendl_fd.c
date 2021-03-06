/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hestela <hestela@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/24 09:47:22 by hestela           #+#    #+#             */
/*   Updated: 2013/12/11 09:43:49 by hestela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int		ft_putendl_fd(char const *s, int fd)
{
	int		i;

	i = 0;
	if (s)
	{
		while (*s)
		{
			i += ft_putchar_fd(*s, fd);
			s++;
		}
		i += ft_putchar_fd('\n', fd);
	}
	return (i);
}
