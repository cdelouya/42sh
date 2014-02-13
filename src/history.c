/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   history.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hestela <hestela@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/29 17:16:03 by hestela           #+#    #+#             */
/*   Updated: 2014/02/11 20:20:14 by hestela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
#include <termcap.h>
#include "libft.h"
#include "42sh.h"

void		ft_previous_cmd(int *position, char **line)
{
	if (!g_env.histo || !g_env.histo->prev)
	{
		ft_putchar(07);
		return ;
	}
	g_env.in_histo = 1;
	while (*position > 0)
		ft_move_left(position, *line);
	tputs(tgetstr("cd", NULL), 1, ft_put);
	if (*line)
		free(*line);
	g_env.histo = g_env.histo->prev;
	*line = ft_strdup(g_env.histo->line);
	ft_putstr(*line);
	*position += (int)ft_strlen(*line);
}

void		ft_next_cmd(int *position, char **line)
{
	if (!g_env.histo || !g_env.histo->next)
	{
		g_env.in_histo = 0;
		ft_putchar(07);
		return ;
	}
	while (*position > 0)
		ft_move_left(position, *line);
	tputs(tgetstr("cd", NULL), 1, ft_put);
	if (*line)
	free(*line);
	g_env.histo = g_env.histo->next;
	if (g_env.histo->line)
		*line = ft_strdup(g_env.histo->line);
	else
		*line = ft_strdup('\0');
	ft_putstr(*line);
	*position += (int)ft_strlen(*line);
}

void		ft_update_history(char *line)
{
	if (g_env.histo == NULL)
	{
		g_env.histo = malloc(sizeof(t_histo));
		g_env.histo->prev = NULL;
		g_env.histo->next = malloc(sizeof(t_histo));
		g_env.histo->line = ft_strdup(line);
		g_env.histo->start = g_env.histo;
		g_env.histo->next->start = g_env.histo->start;
		g_env.histo->next->prev = g_env.histo;
		g_env.histo = g_env.histo->next;
		g_env.histo->next = NULL;
		g_env.histo->line = NULL;
	}
	else
	{
		while (g_env.histo->next)
			g_env.histo = g_env.histo->next;
		g_env.histo->line = ft_strdup(line);
		g_env.histo->next = malloc(sizeof(t_histo));
		g_env.histo->next->start = g_env.histo->start;
		g_env.histo->next->prev = g_env.histo;
		g_env.histo = g_env.histo->next;
		g_env.histo->next = NULL;
		g_env.histo->line = NULL;
	}
}
