/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hestela <hestela@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/29 18:06:30 by hestela           #+#    #+#             */
/*   Updated: 2014/02/11 14:11:12 by hestela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void		ft_env(char **av, char **env)
{
	int		i;
	int		j;
	char	*str;

	if (av[0])
	{
		i = 0;
		while (env[i])
		{
			j = -1;
			str = env[i];
			ft_putstr(F_GREEN);
			while (str[j] != '=' && j++ >= -1)
				ft_putchar(str[j]);
			ft_putstr(F_WHITE);
			while (str[j] && j++ >= -1)
				ft_putchar(str[j]);
			ft_putchar('\n');
			i++;
		}
	}
}
