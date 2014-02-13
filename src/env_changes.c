/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_changes.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hestela <hestela@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/08 11:11:34 by hestela           #+#    #+#             */
/*   Updated: 2014/02/08 11:30:05 by hestela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
#include "libft.h"
#include "42sh.h"

static void		ft_check_var1(char **av);
static void		ft_check_var2(char **av);

void			ft_env_changes(void)
{
	char		**av;

	av = (char**) malloc(sizeof(*av) * 4);
	av[0] = (char*) malloc(sizeof(**av) * 20);
	av[1] = (char*) malloc(sizeof(**av) * 20);
	av[2] = (char*) malloc(sizeof(**av) * 100);
	av[3] = '\0';
	ft_strcpy(av[0], "setenv");
	ft_check_var1(av);
	ft_check_var2(av);
	ft_array_str_free(av);
}

static void		ft_check_var1(char **av)
{
	if (!ft_getenv(g_env.env, "PATH"))
	{
		ft_strcpy(av[1], "PATH");
		ft_strcpy(av[2], "/usr/local/bin:/usr/bin:/bin:/usr/"\
			"sbin:/sbin:/opt/X11/bin:/usr/texbin");
		ft_builtin(av);
	}
	if (!ft_getenv(g_env.env, "USER"))
	{
		ft_strcpy(av[1], "USER");
		ft_strcpy(av[2],"unknow_user");
		ft_builtin(av);
	}
	if (!ft_getenv(g_env.env, "HOME"))
	{
		ft_strcpy(av[1], "HOME");
		ft_strcpy(av[2],"/");
		ft_builtin(av);
	}
}

static void		ft_check_var2(char **av)
{
	if (!ft_getenv(g_env.env, "OLDPWD"))
	{
		ft_strcpy(av[1], "OLDPWD");
		ft_strcpy(av[2], ft_getenv(g_env.env, "HOME"));
		ft_builtin(av);
	}
	if (!ft_getenv(g_env.env, "PWD"))
	{
		ft_strcpy(av[1], "PWD");
		ft_strcpy(av[2], ft_getenv(g_env.env, "HOME"));
		ft_builtin(av);
		ft_strcpy(av[0], "cd");
		ft_strcpy(av[1], ft_getenv(g_env.env, "PWD"));
		free(av[2]);
		av[2] = '\0';
		ft_builtin(av);
	}
}
