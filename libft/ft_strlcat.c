/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hestela <hestela@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 10:10:28 by hestela           #+#    #+#             */
/*   Updated: 2013/11/23 16:28:46 by hestela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <string.h>
#include "libft.h"

size_t		ft_strlcat(char *dst, const char *src, size_t size)
{
	char		*dstcpy;
	char		*srccpy;
	size_t		sizecpy;
	size_t		dstlen;

	dstcpy = dst;
	srccpy = (char *) src;
	sizecpy = size;
	while (sizecpy && *dstcpy)
	{
		dstcpy++;
		sizecpy--;
	}
	dstlen = dstcpy - dst;
	size -= dstlen;
	if (!size)
		return (dstlen + ft_strlen(srccpy));
	ft_strncat(dst, src, size - 1);
	while (*srccpy)
		srccpy++;
	return (dstlen + (srccpy - src));
}
