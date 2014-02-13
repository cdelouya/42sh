/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_time_fd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hestela <hestela@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/12 12:18:52 by hestela           #+#    #+#             */
/*   Updated: 2013/12/12 13:23:24 by hestela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int		ft_put_time_fd(const time_t clock, int fd)
{
	char	**array;
	int		i;
	int		count;

	i = 0;
	count = 0;
	array = ft_strsplit(ctime(&clock), ' ');
	count += ft_putstr_fd(array[0], fd);
	count += ft_putchar_fd(' ', fd);
	count += ft_putstr_fd(array[2], fd);
	count += ft_putchar_fd(' ', fd);
	count += ft_putstr_fd(array[1], fd);
	count += ft_putchar_fd(' ', fd);
	while (array[4][i] != '\n')
	{
		count += ft_putchar_fd(array[4][i], fd);
		i++;
	}
	count += ft_putchar_fd(' ', fd);
	count += ft_putstr_fd(array[3], fd);
	return (count);
}
