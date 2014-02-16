/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hestela <hestela@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/29 18:10:49 by hestela           #+#    #+#             */
/*   Updated: 2014/02/16 04:31:39 by hestela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>
#include <dirent.h>
#include <stdlib.h>
#include "libft.h"
#include "42sh.h"

static void		ft_option(char **env, int *change);
static void		ft_path(char **av, int *change);
static void		ft_check_permission(char **av);
static void		ft_apply_changes(char **env);

void			ft_cd(char **av, char **env)
{
	int			change;
	int			i;

	i = 0;
	change = 0;
	if (av[1] == NULL || (*av[1] == '-' && *(av[1] + 1) == '-'))
	{
		chdir(ft_getenv(env, "HOME"));
		change = 1;
	}
	else if (*av[1] == '-')
		ft_option(env, &change);
	else if (ft_array_str_len(av) > 3)
		ft_printf_fd(2, "%$cd: too many arguments\n%$", ERROR_CLR, TEXT_CLR);
	else if (ft_array_str_len(av) > 2)
		ft_printf_fd(2, "%$cd: string not in pwd: %s%$\n"\
			, ERROR_CLR, av[1], TEXT_CLR);
	else
		ft_path(av, &change);
	if (change)
		ft_apply_changes(env);
}

static void		ft_option(char **env, int *change)
{
	char		*str;

	str = NULL;
	chdir(ft_getenv(env, "OLDPWD"));
	str = ft_strstr(ft_getenv(env, "OLDPWD"), ft_getenv(env, "USER"));
	if (str)
		ft_printf("~%s\n", str + ft_strlen(ft_getenv(env,"USER")));
	else
		ft_printf("%s\n", ft_getenv(env, "OLDPWD"));
	*change = 1;
}

static void		ft_path(char **av, int *change)
{
	DIR			*dir;

	dir = opendir(av[1]);
	if (!dir)
		ft_check_permission(av);
	else
	{
		chdir(av[1]);
		*change = 1;
	}
	if (dir)
		closedir(dir);
}

static void		ft_check_permission(char **av)
{
	if (access(av[1], F_OK) == 0)
		ft_printf_fd(2, "%$cd: permission denied: %s\n%$"\
			, ERROR_CLR, av[1], TEXT_CLR);
	else
		ft_printf_fd(2, "%$cd: no such file or directory: %s\n%$"\
			, ERROR_CLR, av[1], TEXT_CLR);
}

static void		ft_apply_changes(char **env)
{
	char		**new;
	char		*value;
	char		*tmp;

	value = ft_getenv(env, "PWD");
	tmp = ft_strjoin("* OLDPWD ", value);
	new = ft_strsplit(tmp, ' ');
	free(tmp);
	ft_setenv(new, env);
	ft_array_str_free(new);
	value = getcwd(NULL, 200);
	tmp = ft_strjoin("* PWD ", value);
	new = ft_strsplit(tmp, ' ');
	free(tmp);
	ft_setenv(new, env);
	ft_array_str_free(new);
	value = NULL;
	tmp = NULL;
	new = NULL;
}
