/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setenv.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hestela <hestela@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/05 14:22:05 by hestela           #+#    #+#             */
/*   Updated: 2014/02/08 10:56:47 by hestela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
#include "libft.h"
#include "42sh.h"

static int		ft_exist(char *var, char **env);
static char		**ft_add_new_var(char **env, char *name, char *value);
static void		ft_update_value(char **env, char *name, char *value);

char			**ft_setenv(char **av, char **env)
{
	if (av[1] == NULL)
		ft_array_str_print(env);
	else
	{
		if (!ft_exist(av[1], env))
			env = ft_add_new_var(env, av[1], av[2]);
		else
			ft_update_value(env, av[1], av[2]);
	}
	return (env);
}

static int		ft_exist(char *var, char **env)
{
	int			i;

	i = 0;
	while (env[i])
	{
		if (ft_strncmp(env[i], var, ft_strlen(var)) == 0
			&& *(env[i] + ft_strlen(var)) == '=')
			return (1);
		i++;
	}
	return (0);
}

static char		**ft_add_new_var(char **env, char *name, char *value)
{
	char		**envcpy;
	int			i;
	int			len;
	char		*tmp;

	envcpy = NULL;
	i = 0;
	len = (int) ft_array_str_len(env);
	envcpy = (char**) malloc(sizeof(*envcpy) * len + 3);
	while (env[i])
	{
		envcpy[i] = ft_strdup(env[i]);
		i++;
	}
	if (!value)
		envcpy[i] = ft_strjoin(name, "=");
	else
	{
		tmp = ft_strjoin(name, "=");
		envcpy[i] = ft_strjoin(tmp, value);
		free(tmp);
	}
	envcpy[i + 1] = NULL;
	envcpy[0] = ft_strdup(env[0]);
	return (envcpy);
}

static void		ft_update_value(char **env, char *name, char *value)
{
	int			i;
	char		*tmp;

	i = 0;
	while (ft_strncmp(env[i], name, ft_strlen(name)) != 0)
		i++;
	if (!value)
	{
		free(env[i]);
		env[i] = ft_strjoin(name, "=");
	}
	else
	{
		tmp = ft_strjoin(name, "=");
		env[i] = ft_strjoin(tmp, value);
		free(tmp);
	}
}
