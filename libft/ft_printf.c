/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hestela <hestela@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/10 08:39:39 by hestela           #+#    #+#             */
/*   Updated: 2013/12/20 16:22:18 by hestela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdarg.h>
#include "libft.h"

int			ft_printf(const char *format, ...)
{
	int			count;
	int			i;
	va_list		ap;

	count = 0;
	i = 1;
	va_start(ap, format);
	while (format[i - 1])
	{
		if ((format[i - 1] != '%'
			|| (format[i - 1] == '%' && format[i] == '%')) && format[i - 1])
		{
			count += ft_putchar(format[i - 1]);
			i++;
		}
		else if (ft_strchr("csndifxXpoEebulLztT#", format[i]))
			ft_flags1(format, &ap, &i, &count);
		else if (ft_strchr("*. + $ ^ 123456789", format[i]))
			ft_flags2(format, &ap, &i, &count);
		else
			i++;
	}
	va_end(ap);
	return (count);
}
