/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_output5_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hestela <hestela@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/20 15:03:01 by hestela           #+#    #+#             */
/*   Updated: 2014/01/30 20:57:45 by hestela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdarg.h>
#include "libft.h"

static void		ft_prec(const char *form, va_list *ap, int *i, int *count);
static void		ft_int(const char *form, va_list *ap, int **t, int *count);
static void		ft_long(const char *form, va_list *ap, int **t, int *count);

void			ft_flags5fd(const char *form, va_list *ap, int *i, int *count)
{
	if (form[*i] == '*' || (form[*i] >= '1' && form[*i] <= '9'))
		ft_prec(form, ap, i, count);
}

static void		ft_prec(const char *form, va_list *ap, int *i, int *count)
{
	int			precision;
	int			*tab[2];

	precision = 0;
	if (form[*i] == '*')
	{
		precision = va_arg(*ap, int);
		(*i)++;
	}
	else
	{
		while (form[*i] >= '0' && form[*i] <= '9')
		{
			precision = (precision * 10) + (form[*i] - 48);
			(*i)++;
		}
	}
	tab[0] = i;
	tab[1] = &precision;
	if (ft_strchr("xXdiuosp", form[*i]))
		ft_int(form, ap, tab, count);
	else if (ft_strchr("lLzh", form[*i])
			&& ft_strchr("oudixX", form[*i + 1]))
		ft_long(form, ap, tab, count);
}

static void		ft_int(const char *form, va_list *ap, int **t, int *count)
{
	int			*i;
	int			precision;
	int			len;
	va_list		apcpy;

	i = t[0];
	precision = *t[1];
	len = 0;
	va_copy(apcpy, *ap);
	if (ft_strchr("dui", form[*i]))
		len = ft_strlen(ft_itoa(va_arg(apcpy, long)));
	else if (ft_strchr("Xx", form[*i]))
		len = ft_strlen(ft_itoh(va_arg(apcpy, long)));
	else if (ft_strchr("o", form[*i]))
		len = ft_strlen(ft_itoa(ft_itoo(va_arg(apcpy, long))));
	else if (ft_strchr("s", form[*i]))
		len = ft_strlen(va_arg(apcpy, char*));
	else if (ft_strchr("p", form[*i]))
		len = 2 + ft_strlen(ft_itoh(va_arg(apcpy, long)));
	while (len < precision)
	{
		*count += ft_putchar_fd(' ', g_fd);
		len++;
	}
	ft_flags1fd(form, ap, i, count);
}

static void		ft_long(const char *form, va_list *ap, int **t, int *count)
{
	int			*i;
	int			precision;
	int			len;
	va_list		apcpy;

	i = t[0];
	precision = *t[1];
	len = 0;
	va_copy(apcpy, *ap);
	if (ft_strchr("lzh", form[*i]) && form[*i + 1] == 'o')
		len = ft_strlen(ft_itoa(ft_itoo(va_arg(apcpy, long))));
	else if (ft_strchr("lzh", form[*i]) && ft_strchr("udi", form[*i + 1]))
		len = ft_strlen(ft_itoa(va_arg(apcpy, long)));
	else if (ft_strchr("lzh", form[*i]) && ft_strchr("xX", form[*i + 1]))
		len = ft_strlen(ft_itoh(va_arg(apcpy, long)));
	while (len < precision)
	{
		*count += ft_putchar_fd(' ', g_fd);
		len++;
	}
	ft_flags1fd(form, ap, i, count);
}
