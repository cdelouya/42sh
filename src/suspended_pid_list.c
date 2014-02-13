/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   suspended_pid_list.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hestela <hestela@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/02 23:01:07 by hestela           #+#    #+#             */
/*   Updated: 2014/02/05 14:34:32 by hestela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <termcap.h>
#include <termios.h>
#include <stdlib.h>
#include "libft.h"
#include "42sh.h"

static void			ft_create_list(pid_t thread, char *cmd);
static void			ft_del_first(void);

void				ft_add_to_pid_list(pid_t thread, char *cmd)
{
	t_pidlst		*start;

	if (g_env.pid_list == NULL)
		ft_create_list(thread, cmd);
	else
	{
		start = g_env.pid_list->start;
		g_env.pid_list = start;
		while (g_env.pid_list)
		{
			if (g_env.pid_list->pid == thread)
				return ;
			g_env.pid_list = g_env.pid_list->next;
		}
		g_env.pid_list = start;
		while (g_env.pid_list->next)
			g_env.pid_list = g_env.pid_list->next;
		g_env.pid_list->next = malloc(sizeof(t_pidlst));
		g_env.pid_list->next->start = g_env.pid_list->start;
		g_env.pid_list->next->num = g_env.pid_list->num + 1;
		g_env.pid_list = g_env.pid_list->next;
		g_env.pid_list->pid = thread;
		g_env.pid_list->cmd = ft_strdup(cmd);
		g_env.pid_list->next = NULL;
	}
}

static void			ft_create_list(pid_t thread, char *cmd)
{
	g_env.pid_list = malloc(sizeof(t_pidlst));
	g_env.pid_list->start = g_env.pid_list;
	g_env.pid_list->pid = thread;
	g_env.pid_list->cmd = ft_strdup(cmd);
	g_env.pid_list->num = 1;
	g_env.pid_list->next = NULL;
}

void				ft_got_pid_node(int id)
{
	g_env.pid_list = g_env.pid_list->start;
	if (!id)
	{
		while (g_env.pid_list->next)
			g_env.pid_list = g_env.pid_list->next;
		g_env.in_exec = g_env.pid_list->cmd;
		g_env.thread = g_env.pid_list->pid;
	}
	else
	{
		while (g_env.pid_list->num != id)
			g_env.pid_list = g_env.pid_list->next;
		g_env.in_exec = g_env.pid_list->cmd;
		g_env.thread = g_env.pid_list->pid;
	}
}

static void			ft_del_first(void)
{
	t_pidlst		*node;
	t_pidlst		*start;

	node = g_env.pid_list;
	start = g_env.pid_list->next;
	while (g_env.pid_list)
	{
		g_env.pid_list->num--;
		g_env.pid_list->start = start;
		g_env.pid_list = g_env.pid_list->next;
	}
	g_env.pid_list = start;
	free(node->cmd);
	free(node);
}

void				ft_del_pid_node(int id)
{
	t_pidlst		*node;
	t_pidlst		*start;

	start = g_env.pid_list->start;
	g_env.pid_list = start;
	if (g_env.pid_list->next == NULL)
	{
		free(g_env.pid_list->cmd);
		free(g_env.pid_list);
		g_env.pid_list = NULL;
	}
	else if (g_env.pid_list->num == id)
		ft_del_first();
	else
	{
		while (g_env.pid_list->next->num != id)
			g_env.pid_list = g_env.pid_list->next;
		node = g_env.pid_list->next;
		g_env.pid_list->next = g_env.pid_list->next->next;
		free(node->cmd);
		free(node);
	}
}
