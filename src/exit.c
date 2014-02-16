/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hestela <hestela@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/29 19:07:43 by hestela           #+#    #+#             */
/*   Updated: 2014/02/16 14:48:46 by hestela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>
#include <signal.h>
#include <stdlib.h>
#include <termios.h>
#include <termcap.h>
#include "libft.h"
#include "42sh.h"

static void		ft_free_history(void);
static void		ft_restore(t_term *term);
static void		ft_kill_zombies(void);

void			ft_exit(char **av, int type)
{
	char		answer[2];

	if (g_env.pid_list)
	{
		tputs(tgetstr("sc", NULL), 1, ft_put);
		ft_printf("%$42sh: %s%s" , INFOS_CLR, "You have suspended jobs."\
			, " Do you really want to quit? (y/n)");
		while (*answer != 'n' && *answer != 'y')
			read(0, answer, 1);
		if (*answer == 'n')
		{
			tputs(tgetstr("dl", NULL), 1, ft_put);
			tputs(tgetstr("rc", NULL), 1, ft_put);
			if (type == 0)
				ft_printf("%$%s 42sh (%T)%% "\
					, PROMPT_CLR, ft_getenv(g_env.env, "USER"));
			return ;
		}
		ft_putchar('\n');
	}
	ft_kill_zombies();
	ft_array_str_free(av);
	ft_restore(g_env.term);
	exit(EXIT_SUCCESS);
}

static void		ft_restore(t_term *term)
{
	t_alias_lst		*node;

	while (g_env.alias_lst)
	{
		node = g_env.alias_lst;
		g_env.alias_lst = g_env.alias_lst->next;
		free(node->alias);
		free(node->string);
		free(node);
	}
	ft_array_str_free(g_env.env);
	ft_array_str_free(g_env.path);
	ft_free_history();
	if (g_env.cut)
		free(g_env.cut);
	term->c_lflag |= ICANON;
	term->c_lflag |= ECHO;
	term->c_lflag |= ISIG;
	tcsetattr(0, 0, term);
	ft_printf("%$exit\n%$", F_WHITE, C_RESET);
}

static void		ft_free_history(void)
{
	if (g_env.histo)
	{
		while (g_env.histo->next)
			g_env.histo = g_env.histo->next;
		g_env.histo = g_env.histo->prev;
		free(g_env.histo->next);
		if (!g_env.histo->prev)
			return ;
		g_env.histo = g_env.histo->prev;
		while (g_env.histo->prev)
		{
			free(g_env.histo->next->line);
			free(g_env.histo->next);
			g_env.histo = g_env.histo->prev;
		}
		free(g_env.histo->next->line);
		free(g_env.histo->next);
		free(g_env.histo->line);
		free(g_env.histo);
		g_env.histo = NULL;
	}
}

static void		ft_kill_zombies(void)
{
	t_comp_lst		*node;

	if (g_comp_lst)
	{
		node = g_comp_lst;
		g_comp_lst = g_comp_lst->next;
		free(node->str);
		free(node);
	}
	if (g_env.pid_list)
	{
		g_env.pid_list = g_env.pid_list->start;
		while (g_env.pid_list)
		{
			kill(g_env.pid_list->pid, SIGKILL);
			g_env.pid_list = g_env.pid_list->next;
		}
	}
}
