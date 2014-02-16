/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hestela <hestela@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/28 10:08:01 by hestela           #+#    #+#             */
/*   Updated: 2014/02/16 04:19:27 by hestela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <termios.h>
#include <termcap.h>
#include <sys/wait.h>
#include <sys/ioctl.h>
#include "libft.h"
#include "42sh.h"

static void		ft_update_cmd(char **line);
static void		ft_exec_list(t_cmd *list);
static void		ft_exec_redir(char *cmd1, char *cmd2, int redir);
static void		ft_del_list(t_cmd *list);

int				main(void)
{
	char		*str;
	t_cmd		*list;

	g_env.path = NULL;
	g_env.env = NULL;
	ft_check_env();
	str = NULL;
	list = NULL;
	ioctl(1, TIOCGWINSZ, &g_ws);
	signal(SIGWINCH, ft_resize);
	g_env.term = malloc(sizeof(t_term));
	ft_init(g_env.term);
	while (1)
	{
		g_prompt_len = ft_printf("%$%s 42sh (%T)%% "\
			, PROMPT_CLR, ft_getenv(g_env.env, "USER"));
		g_env.in_histo = 0;
		ft_update_cmd(&str);
		ft_update_history(str);
		ft_do_replacements(&str);
		list = ft_parser(&str);
		ft_exec_list(list);
		ft_del_list(list);
	}
	return (0);
}

static void		ft_update_cmd(char **line)
{
	char		*tmp;
	char		*tmp2;

	while (ft_check_quote(line) || *line == NULL)
	{
		if (*line)
			tmp = ft_strdup(*line);
		else
			tmp = ft_strdup('\0');
		if (*tmp)
		{
			tmp2 = ft_strjoin(tmp, "\n");
			free(tmp);
			tmp = ft_strdup(tmp2);
			free(tmp2);
		}
		ft_get_input(line);
		tmp2 = ft_strdup(*line);
		if (*line)
			free(*line);
		*line = ft_strjoin(tmp, tmp2);
		free(tmp);
		free(tmp2);
	}
	ft_printf("%$", TEXT_CLR);
}

static void		ft_exec_list(t_cmd *list)
{
	char		**av;

	av = NULL;
	while (list)
	{
		if (list->redir == 0)
		{
			av = ft_split_args(list->line);
			if (!ft_builtin(av))
				ft_exec(av);
			ft_array_str_free(av);
			list = list->next;
		}
		else
		{
			ft_exec_redir(list->line, list->next->line, list->redir);
			list = list->next->next;
		}
	}
}

static void		ft_exec_redir(char *cmd1, char *cmd2, int redir)
{
	char		**av1;
	char		**av2;
	void		(*f[5])(char**, char**, char**);

	if (ft_is_empty(cmd1) || ft_is_empty(cmd2))
	{
		ft_printf_fd(2, "%$42sh: parse error%$\n", ERROR_CLR, TEXT_CLR);
		return ;
	}
	f[0] = &ft_exec_pipe;
	f[1] = &ft_exec_right;
	f[2] = &ft_exec_left;
	f[3] = &ft_exec_right_d;
	f[4] = &ft_exec_left_d;
	av1 = ft_split_args(cmd1);
	av2 = ft_split_args(cmd2);
	f[redir - 1](av1, av2, g_env.env);
	ft_array_str_free(av1);
	ft_array_str_free(av2);
}

static void		ft_del_list(t_cmd *list)
{
	t_cmd		*node;

	while (list)
	{
		node = list;
		list = list->next;
		free(node->line);
		free(node);
	}
}
