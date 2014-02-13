/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putadr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hestela <hestela@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/11 17:03:16 by hestela           #+#    #+#             */
/*   Updated: 2013/12/17 08:41:45 by hestela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int			ft_putadr_fd(void const *p, int fd)
{
	int		count;

	count = 0;
	count += ft_putstr_fd("0x", fd);
	count += ft_putstr_fd(ft_itoh((unsigned long)p), fd);
	return (count);
}
