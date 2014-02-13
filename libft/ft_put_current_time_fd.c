/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_current_time_fd.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hestela <hestela@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/12 13:00:10 by hestela           #+#    #+#             */
/*   Updated: 2014/02/07 12:15:08 by hestela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int		ft_put_current_time_fd(int fd)
{
	char		**array;
	int			i;
	int			count;
	time_t		clock;

	clock = time(NULL);
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
	ft_array_str_free(array);
	return (count);
}
