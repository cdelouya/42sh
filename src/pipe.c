/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hestela <hestela@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/15 12:35:54 by hestela           #+#    #+#             */
/*   Updated: 2014/02/05 15:25:48 by hestela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>
#include "libft.h"
#include "42sh.h"

static void		ft_pipe(char **cmd, char **env, char **av1, char **av2);
static void		ft_check_cmd(char **cmd, char **env, char **av1, char **av2);

void			ft_exec_pipe(char **av1, char**av2, char **env)
{
	char		*tmp;
	char		**cmd;

	cmd = (char**) malloc(sizeof(*cmd) * 2);
	tmp = NULL;
	tmp = ft_strjoin("/", av1[0]);
	free(av1[0]);
	av1[0] = ft_strdup(tmp);
	free(tmp);
	cmd[0] = ft_check_exist(av1[0]);
	tmp = ft_strjoin("/", av2[0]);
	free(av2[0]);
	av2[0] = ft_strdup(tmp);
	free(tmp);
	cmd[1] = ft_check_exist(av2[0]);
	ft_check_cmd(cmd, env, av1, av2);
}

static void		ft_check_cmd(char **cmd, char **env, char **av1, char **av2)
{
	pid_t		thread;

	if (cmd[0] && cmd[1])
	{
		thread = fork();
		if (thread == 0)
			ft_pipe(cmd, env, av1, av2);
		else
			wait(0);
	}
}

static void		ft_pipe(char **cmd, char **env, char **av1, char **av2)
{
	pid_t		thread;
	int			fdes[2];

	thread = -1;
	pipe(fdes);
	thread = fork();
	if (thread == 0)
	{
		dup2(fdes[WRITE], 1);
		close(fdes[READ]);
		execve(cmd[0], av1, env);
	}
	else if (thread == -1)
	{
		close(fdes[WRITE]);
		close(fdes[READ]);
	}
	dup2(fdes[READ], 0);
	close(fdes[WRITE]);
	wait(0);
	execve(cmd[1], av2, env);
}
