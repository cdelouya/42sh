/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hestela <hestela@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 13:33:13 by hestela           #+#    #+#             */
/*   Updated: 2014/01/30 21:04:51 by hestela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <string.h>

void	*ft_memmove(void *s1, const void *s2, size_t n)
{
	void	*ret;

	ret = s1;
	if ((s1 <= s2 || s1 >= s2 + n) && s1 && s2)
	{
		while (n--)
		{
			*(char *)s1 = *(char *)s2;
			s1++;
			s2++;
		}
	}
	else if (s1 && s2)
	{
		s1 += n - 1;
		s2 += n - 1;
		while (n--)
		{
			*(char *)s1 = *(char *)s2;
			s1--;
			s2--;
		}
	}
	return (ret);
}
