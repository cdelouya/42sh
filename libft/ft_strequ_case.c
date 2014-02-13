/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strequ_case.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hestela <hestela@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/29 12:24:15 by hestela           #+#    #+#             */
/*   Updated: 2013/12/01 10:12:38 by hestela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int		ft_strequ_case(char const *s1, char const *s2)
{
	char	*cpy1;
	char	*cpy2;

	if (!s1 || !s2)
		return (1);
	cpy1 = ft_strdup(s1);
	cpy2 = ft_strdup(s2);
	ft_str_lowcase(cpy1);
	ft_str_lowcase(cpy2);
	return (ft_strequ(cpy1, cpy2));
}
