/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hadrienestela <hestela@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/29 01:15:17 by hadrienestela     #+#    #+#             */
/*   Updated: 2013/12/29 01:16:53 by hadrienestela    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char		*ft_getenv(char **env, char *var)
{
	int		i;

	i = 0;
	while (env[i])
	{
		if (ft_strncmp(env[i], var, ft_strlen(var)) == 0
			&& *(env[i] + ft_strlen(var)) == '=')
			return (env[i] + ft_strlen(var) + 1);
		i++;
	}
	return (NULL);
}
