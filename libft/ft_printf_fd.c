/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hestela <hestela@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/10 08:39:39 by hestela           #+#    #+#             */
/*   Updated: 2013/12/20 16:22:27 by hestela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdarg.h>
#include "libft.h"

int			ft_printf_fd(int fd, const char *format, ...)
{
	int			count;
	int			i;
	va_list		ap;

	g_fd = fd;
	count = 0;
	i = 1;
	va_start(ap, format);
	while (format[i - 1])
	{
		if ((format[i - 1] != '%'
			|| (format[i - 1] == '%' && format[i] == '%')) && format[i - 1])
		{
			count += ft_putchar_fd(format[i - 1], g_fd);
			i++;
		}
		else if (ft_strchr("csndifxXpoEebulLztT#", format[i]))
			ft_flags1fd(format, &ap, &i, &count);
		else if (ft_strchr("*. + $ ^ 123456789", format[i]))
			ft_flags2fd(format, &ap, &i, &count);
		else
			i++;
	}
	va_end(ap);
	return (count);
}
