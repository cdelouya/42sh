/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   jobs.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hestela <hestela@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/03 09:21:19 by hestela           #+#    #+#             */
/*   Updated: 2014/02/16 04:26:52 by hestela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <signal.h>
#include <termios.h>
#include "libft.h"
#include "42sh.h"

static int			ft_check_exist_job(int id);
static int			ft_got_id(char **av);
static void			ft_do_resume(int num);

void				ft_print_job_list(void)
{
	t_pidlst		*start;

	if (!g_env.pid_list)
		ft_printf_fd(2, "%$jobs: No suspended jobs%$\n", ERROR_CLR, TEXT_CLR);
	else
	{
		start = g_env.pid_list->start;
		g_env.pid_list = start;
		while (g_env.pid_list)
		{
			ft_printf("[%d] suspended %s\n"\
				, g_env.pid_list->num, g_env.pid_list->cmd);
			g_env.pid_list = g_env.pid_list->next;
		}
		g_env.pid_list = start;
	}
}


static int			ft_check_exist_job(int id)
{
	t_pidlst		*start;

	start = g_env.pid_list->start;
	g_env.pid_list = start;
	while (g_env.pid_list->num != id)
	{
		g_env.pid_list = g_env.pid_list->next;
		if (g_env.pid_list == NULL)
		{
			g_env.pid_list = start;
			return (0);
		}
	}
	return (1);
}

static int			ft_got_id(char **av)
{
	int				i;
	int				num;

	i = 0;
	num = 1;
	if (av[1])
	{
		while (av[1][i] && num)
		{
			if (!ft_isdigit(av[1][i]))
				num = 0;
			i++;
		}
		if (!num)
		{
			ft_printf_fd(2, "%$fg: Job not found: %s%$\n"\
				, ERROR_CLR, av[1], TEXT_CLR);
			return (-1);
		}
		num = ft_atoi(av[1]);
		return (num);
	}
	else
		return (0);
}

static void			ft_do_resume(int num)
{
	int				status;

	g_env.term->c_lflag |= ICANON;
	g_env.term->c_lflag |= ECHO;
	g_env.term->c_lflag |= ISIG;
	signal(SIGINT, ft_kill);
	tcsetattr(0, 0, g_env.term);
	ft_got_pid_node(num);
	ft_printf("%$42sh: Resume > %s%$\n", INFOS_CLR, g_env.in_exec, TEXT_CLR);
	if (ft_strcmp(g_env.in_exec, "emacs") == 0)
		ft_putstr(C_RESET);
	kill(g_env.thread, SIGCONT);
	waitpid(g_env.thread, &status, WUNTRACED);
	if (status == 0)
		ft_got_node_nbr();
	g_env.in_exec = NULL;
	tcgetattr(0, g_env.term);
	g_env.term->c_lflag &= ~(ICANON);
	g_env.term->c_lflag &= ~(ECHO);
	g_env.term->c_lflag &= ~(ISIG);
	g_env.term->c_cc[VMIN] = 1;
	g_env.term->c_cc[VTIME] = 0;
	tcsetattr(0, 0, g_env.term);
}

void				ft_resume(char **av)
{
	int				num;

	if (!g_env.pid_list)
	{
		ft_printf_fd(2, "%$fg: No current job%$\n", ERROR_CLR, C_RESET);
		return ;
	}
	num = ft_got_id(av);
	if (num == -1)
		return ;
	if (num != 0 && !ft_check_exist_job(num))
	{
		ft_printf_fd(2, "%$fg: Job not found: %d%$\n", ERROR_CLR, num, C_RESET);
		return ;
	}
	ft_do_resume(num);
	signal(SIGINT, SIG_IGN);
}
