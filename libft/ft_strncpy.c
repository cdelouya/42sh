/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hestela <hestela@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 08:40:12 by hestela           #+#    #+#             */
/*   Updated: 2013/11/25 19:31:28 by hestela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <string.h>
#include "libft.h"

char	*ft_strncpy(char *s1, const char *s2, size_t n)
{
	char	*start;

	start = s1;
	while (*s2 && n)
	{
		*s1 = *s2;
		s1++;
		s2++;
		n--;
	}
	while (n)
	{
		*s1 = '\0';
		s1++;
		n--;
	}
	return (start);
}
