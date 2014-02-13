/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unsetenv.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hestela <hestela@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/29 18:32:38 by hestela           #+#    #+#             */
/*   Updated: 2014/01/29 18:43:19 by hestela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
#include "libft.h"

static char		**ft_unset(char **env, char *var);
static char		**ft_copyenv(int i, char **env);

char			**ft_unsetenv(char **av, char **env)
{
	int			i;

	i = 1;
	if (av[1] == NULL)
		ft_printf_fd(2, "%$unsetenv: Too few arguments.\n%$", F_RED, F_WHITE);
	else
	{
		while (av[i])
		{
			env = ft_unset(env, av[i]);
			i++;
		}
	}
	return (env);
}

static char		**ft_unset(char **env, char *var)
{
	int			i;

	i = 0;
	while (env[i])
	{
		if (ft_strncmp(env[i], var, ft_strlen(var)) == 0
			&& *(env[i] + ft_strlen(var)) == '=')
			return (ft_copyenv(i, env));
		i++;
	}
	return (env);
}

static char		**ft_copyenv(int i, char **env)
{
	int			j;
	int			len;
	char		**envcpy;

	j = 0;
	envcpy = NULL;
	len = (int) ft_array_str_len(env);
	envcpy = (char**) malloc(sizeof(*envcpy) * len);
	envcpy[len - 1] = '\0';
	while (j < i)
	{
		envcpy[j] = ft_strdup(env[j]);
		j++;
	}
	while (env[j + 1])
	{
		envcpy[j] = ft_strdup(env[j + 1]);
		j++;
	}
	ft_array_str_free(env);
	return (envcpy);
}
