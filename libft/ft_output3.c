/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_output3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hestela <hestela@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/17 22:00:27 by hestela           #+#    #+#             */
/*   Updated: 2014/01/04 14:52:58 by hestela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdarg.h>
#include "libft.h"

static void		ft_opt1(const char *form, va_list *ap, int *i, int *count);
static void		ft_opt1_b(const char *form, va_list ap, int *i, int *count);
static void		ft_opt2(const char *form, va_list *ap, int *i, int *count);
static void		ft_opt2_b(const char *form, va_list ap, int *i, int *count);

void			ft_flags3(const char *form, va_list *ap, int *i, int *count)
{
	if (form[*i] == '+')
		ft_opt1(form, ap, i, count);
	else if (form[*i] == ' ')
		ft_opt2(form, ap, i, count);
	else
		ft_flags4(form, ap, i, count);
}

static void		ft_opt1(const char *form, va_list *ap, int *i, int *count)
{
	int			j;
	va_list		apcpy;

	j = 0;
	va_copy(apcpy, *ap);
	(*i)++;
	while (ft_strchr(".* 0123456789", form[*i]))
	{
		j++;
		(*i)++;
	}
	ft_opt1_b(form, apcpy, i, count);
	*i -= j;
	if (ft_strchr(".* ", form[*i]))
		ft_flags2(form, ap, i, count);
	else
		ft_flags1(form, ap, i, count);
}

static void		ft_opt1_b(const char *form, va_list ap, int *i, int *count)
{
	int		index;

	index = 0;
	if (ft_strchr("zlhL", form[*i]))
		index = 1;
	if (ft_strchr("uid", form[*i + index]))
	{
		if (va_arg(ap, int) > 0)
			*count += ft_putchar('+');
	}
	if (ft_strchr("feE", form[*i + index]))
	{
		if (va_arg(ap, double) > 0)
			*count += ft_putchar('+');
	}
}

static void		ft_opt2(const char *form, va_list *ap, int *i, int *count)
{
	int			index;
	int			j;
	va_list		apcpy;

	index = 0;
	j = 0;
	va_copy(apcpy, *ap);
	(*i)++;
	while (ft_strchr(".* 0123456789", form[*i]))
	{
		j++;
		(*i)++;
	}
	ft_opt2_b(form, apcpy, i, count);
	*i -= j;
	if (ft_strchr(".*+", form[*i]))
		ft_flags2(form, ap, i, count);
	else
		ft_flags1(form, ap, i, count);
}

static void		ft_opt2_b(const char *form, va_list ap, int *i, int *count)
{
	int		index;

	index = 0;
	if (ft_strchr("zlhL", form[*i]))
		index = 1;
	if (ft_strchr("uid", form[*i + index]))
	{
		if (va_arg(ap, int) > 0)
			*count += ft_putchar(' ');
	}
	if (ft_strchr("feE", form[*i + index]))
	{
		if (va_arg(ap, double) > 0)
			*count += ft_putchar(' ');
	}
}
