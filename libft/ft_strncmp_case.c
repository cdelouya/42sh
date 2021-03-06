/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp_case.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hestela <hestela@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/30 09:07:48 by hestela           #+#    #+#             */
/*   Updated: 2013/12/01 10:12:15 by hestela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int		ft_strncmp_case(const char *s1, const char *s2, size_t n)
{
	char	*cpy1;
	char	*cpy2;

	if (!s1 || !s2 || !n)
		return (0);
	cpy1 = ft_strdup(s1);
	cpy2 = ft_strdup(s2);
	ft_str_lowcase(cpy1);
	ft_str_lowcase(cpy2);
	return (ft_strncmp(cpy1, cpy2, n));
}
