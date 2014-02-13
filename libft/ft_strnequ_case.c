/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ_case.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hestela <hestela@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/27 10:48:45 by hestela           #+#    #+#             */
/*   Updated: 2013/12/02 13:35:27 by hestela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int		ft_strnequ_case(char const *s1, char const *s2, size_t n)
{
	char	*cpy1;
	char	*cpy2;

	if (!s1 || !s2)
		return (1);
	cpy1 = ft_strdup(s1);
	cpy2 = ft_strdup(s2);
	ft_str_lowcase(cpy1);
	ft_str_lowcase(cpy2);
	return (ft_strnequ(cpy1, cpy2, n));
}
