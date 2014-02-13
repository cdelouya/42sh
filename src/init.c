/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hestela <hestela@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/11 00:09:56 by hestela           #+#    #+#             */
/*   Updated: 2014/02/12 12:26:21 by hestela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <termcap.h>
#include "libft.h"
#include "42sh.h"

static void		ft_get_alias_list(void);
static void		ft_add_node(char *str);
static void		ft_create_node(char *alias, char *string);

void			ft_init(t_term *term)
{
	char		buf[1024];

	g_env.alias_lst = NULL;
	g_env.quote_wait = 0;
	signal(SIGINT, SIG_IGN);
	g_env.pid_list = NULL;
	g_env.cut = NULL;
	g_env.histo = NULL;
	ft_get_alias_list();
	if (tgetent(buf, ft_getenv(g_env.env, "TERM")) == -1)
		exit(EXIT_FAILURE);
	tcgetattr(0, term);
	term->c_lflag &= ~(ICANON);
	term->c_lflag &= ~(ECHO);
	term->c_lflag &= ~(ISIG);
	term->c_cc[VMIN] = 1;
	term->c_cc[VTIME] = 0;
	tcsetattr(0, 0, term);
}

static void		ft_get_alias_list(void)
{
	int			fd;
	char		*tmp;
	char		*path;

	tmp = ft_strjoin(ft_getenv(g_env.env, "HOME"), "/");
	path = ft_strjoin(tmp, ".zshrc");
	free(tmp);
	fd = open(path, O_RDONLY);
	tmp = NULL;
	while (ft_gnl(fd, &tmp) > 0)
	{
		if (ft_strstr(tmp, "alias"))
			ft_add_node(tmp);
	}
	if (g_env.alias_lst)
		g_env.alias_lst = g_env.alias_lst->start;
}

static void		ft_add_node(char *str)
{
	char		alias[50];
	char		string[200];
	int			i;

	i = 0;
	while (*str && *str != ' ')
		str++;
	str++;
	while (*str != '=')
	{
		alias[i] = *str;
		i++;
		str++;
	}
	str += 2;
	alias[i] = '\0';
	i = 0;
	while (*str != '\'' && *str)
	{
		string[i] = *str;
		str++;
		i++;
	}
	string[i] = '\0';
	ft_create_node(alias, string);
}

static void		ft_create_node(char *alias, char *string)
{
	static t_alias_lst		*start;

	if (!g_env.alias_lst)
	{
		g_env.alias_lst = malloc(sizeof(t_alias_lst));
		start = g_env.alias_lst;
		g_env.alias_lst->start = start;
		g_env.alias_lst->alias = ft_strdup(alias);
		g_env.alias_lst->string = ft_strdup(string);
		g_env.alias_lst->next = NULL;
		return ;
	}
	g_env.alias_lst->next = malloc(sizeof(t_alias_lst));
	g_env.alias_lst = g_env.alias_lst->next;
	g_env.alias_lst->next = NULL;
	g_env.alias_lst->start = start;
	g_env.alias_lst->alias = ft_strdup(alias);
	g_env.alias_lst->string = ft_strdup(string);
}
