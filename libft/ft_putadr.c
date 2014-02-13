/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putadr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hestela <hestela@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/11 16:59:44 by hestela           #+#    #+#             */
/*   Updated: 2013/12/17 08:41:18 by hestela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int			ft_putadr(void const *p)
{
	int		count;

	count = 0;
	count += ft_putstr("0x");
	count += ft_putstr(ft_itoh((unsigned long)p));
	return (count);
}
