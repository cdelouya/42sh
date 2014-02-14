/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hestela <hestela@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/29 19:22:55 by hestela           #+#    #+#             */
/*   Updated: 2014/02/13 23:51:16 by hestela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>
#include <sys/wait.h>
#include <termios.h>
#include <stdlib.h>
#include "libft.h"
#include "42sh.h"

static void		ft_restore_term_for_exec(char *cmd, int *status);

void			ft_exec(char **av)
{
	char		*tmp;
	char		*cmd;
	int			status;
	int			ret;

	tmp = NULL;
	tmp = ft_strjoin("/", av[0]);
	free(av[0]);
	av[0] = ft_strdup(tmp);
	free(tmp);
	cmd = ft_check_exist(av[0]);
	if (cmd)
	{
		g_env.thread = fork();
		if (g_env.thread == 0)
		{
			g_env.in_exec = NULL;
			ret = execve(cmd, av, g_env.env);
			ft_putnbr(ret);
		}
		else
			ft_restore_term_for_exec(av[0] + 1, &status);
	}
	free(cmd);
}

static void		ft_restore_term_for_exec(char *cmd, int *status)
{
	g_env.term->c_lflag |= ICANON;
	g_env.term->c_lflag |= ECHO;
	g_env.term->c_lflag |= ISIG;
	signal(SIGINT, ft_kill);
	tcsetattr(0, 0, g_env.term);
	g_env.in_exec = cmd;
	waitpid(g_env.thread, status, WUNTRACED);
	g_env.in_exec = NULL;
	tcgetattr(0, g_env.term);
	g_env.term->c_lflag &= ~(ICANON);
	g_env.term->c_lflag &= ~(ECHO);
	g_env.term->c_lflag &= ~(ISIG);
	g_env.term->c_cc[VMIN] = 1;
	g_env.term->c_cc[VTIME] = 0;
	tcsetattr(0, 0, g_env.term);
	signal(SIGINT, SIG_IGN);
}

int				ft_builtin(char **av)
{
	if (ft_strcmp_case("env", av[0]) == 0)
		ft_env(av, g_env.env);
	else if (ft_strcmp_case("echo", av[0]) == 0)
		ft_echo(av);
	else if (ft_strcmp_case("cd", av[0]) == 0)
		ft_cd(av, g_env.env);
	else if (ft_strcmp_case("unsetenv", av[0]) == 0)
	{
		g_env.env = ft_unsetenv(av, g_env.env);
		ft_env_changes();
	}
	else if (ft_strcmp_case("setenv", av[0]) == 0)
	{
		g_env.env = ft_setenv(av, g_env.env);
		ft_env_changes();
	}
	else if (ft_strcmp_case("exit", av[0]) == 0)
		ft_exit(av, 1);
	else if (ft_strcmp_case("fg", av[0]) == 0)
		ft_resume(av);
	else if (ft_strcmp_case("jobs", av[0]) == 0)
		ft_print_job_list();
	else
		return (0);
	return (1);
}
