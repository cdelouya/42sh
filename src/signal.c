/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hestela <hestela@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/02 22:45:07 by hestela           #+#    #+#             */
/*   Updated: 2014/02/16 13:45:42 by hestela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <signal.h>
#include <stdlib.h>
#include <sys/ioctl.h>
#include "libft.h"
#include "42sh.h"

void			ft_resize(int sig)
{
	sig = sig;
	ioctl(1, TIOCGWINSZ, &g_ws);
}

void			ft_kill(int sig)
{
	int		i;

	sig = sig;
	if (g_env.in_exec)
	{
		kill(g_env.thread, SIGKILL);
		ft_printf("%$\n42sh: Killed > %s%$\n", INFOS_CLR, g_env.in_exec, C_RESET);
		g_env.in_exec = NULL;
		if (g_env.pid_list)
			ft_got_node_nbr();
	}
	else
	{
		ft_printf("%$\n%s 42sh (%T)%s "\
			, PROMPT_CLR, ft_getenv(g_env.env, "USER"), "%");
		i = ft_strlen(*g_env.saved_line);
		free(*g_env.saved_line);
		*g_env.saved_line = ft_strdup("\0");
	}
}

void			ft_suspend(int sig)
{
	char		cp[2];

	cp[0] = 6;
	cp[1] = 0;
	sig = sig;
	if (g_env.in_exec)
	{
		ft_add_to_pid_list(g_env.thread, g_env.in_exec);
		ioctl(0, TIOCSTI, cp);
		ft_printf("%$\n42sh: Suspended > %s%$\n"\
			, INFOS_CLR, g_env.in_exec, C_RESET);
		g_env.in_exec = NULL;
	}
}

void			ft_got_node_nbr(void)
{
	t_pidlst	*start;

	if (g_env.pid_list)
	{
		start = g_env.pid_list->start;
		g_env.pid_list = start;
		while (g_env.pid_list->next)
		{
			if (g_env.pid_list->pid == g_env.thread)
			{
				ft_del_pid_node(g_env.pid_list->num);
				return ;
			}
			g_env.pid_list = g_env.pid_list->next;
		}
		if (g_env.pid_list->pid == g_env.thread)
			ft_del_pid_node(g_env.pid_list->num);
	}
}
