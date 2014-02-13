/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hestela <hestela@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/24 09:31:57 by hestela           #+#    #+#             */
/*   Updated: 2013/12/30 13:37:45 by hadrienestela    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>
#include "libft.h"

int		ft_putstr_fd(char const *s, int fd)
{
	int		i;

	i = 0;
	if (s)
	{
		i = ft_strlen(s);
		write(fd, s, i);
		s++;
	}
	else
		i = ft_putstr_fd("(null)", fd);
	return (i);
}
