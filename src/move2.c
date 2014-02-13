/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hestela <hestela@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/29 15:12:19 by hestela           #+#    #+#             */
/*   Updated: 2014/02/07 18:43:12 by hestela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
#include <termcap.h>
#include "libft.h"
#include "42sh.h"

static void		ft_multiligne(int *position, char **line);
static void		ft_multi_suite(int *position, char **line);

void			ft_move_to_beg(int *position, char *str)
{
	int			i;

	i = 0;
	if (*position == 0)
	{
		ft_putchar(07);
		return ;
	}
	while (*position > 0)
	{
		ft_move_left(position, str);
	}
}

void			ft_move_to_end(int *position, char *str)
{
	if (*position == (int)ft_strlen(str))
	{
		ft_putchar(07);
		return ;
	}
	while (*position < (int)ft_strlen(str))
	{
		ft_move_right(position, str);
	}
}

void			ft_back(int *position, char **line)
{
	int			i;

	i = 0;
	if (*position == 0 || *(line[0] + *position - 1) == '\n')
	{
		if (*position == 0)
			ft_putchar(07);
		else
			ft_multiligne(position, line);
		return ;
	}
	tputs(tgetstr("le", NULL), 1, ft_put);
	if ((*position + g_prompt_len) % g_ws.ws_col == 0)
	{
		tputs(tgetstr("sr", NULL), 1, ft_put);
		if (g_env.in_histo != 0)
			tputs(tgetstr("sf", NULL), 1, ft_put);
		while (i++ < g_ws.ws_col)
			tputs(tgetstr("nd", NULL), 1, ft_put);
	}
	tputs(tgetstr("dc", NULL), 1, ft_put);
	ft_del_char(line, *position);
	(*position)--;
}

static void		ft_multiligne(int *position, char **line)
{
	char		*start;
	char		*str;
	int			i;

	i = 0;
	start = line[0];
	(*position) -= 2;
	str = line[0] + *position;
	tputs(tgetstr("sr", NULL), 1, ft_put);
	while (*(str - 1) != '\n' && str != start)
		str--;
	if (str == start)
	{
		while (i++ < g_prompt_len)
			tputs(tgetstr("nd", NULL), 1, ft_put);
	}
	while (*(str + 1) != '\n')
	{
		tputs(tgetstr("nd", NULL), 1, ft_put);
		str++;
	}
	ft_multi_suite(position, line);
}

static void		ft_multi_suite(int *position, char **line)
{
	(*position) += 2;
	tputs(tgetstr("nd", NULL), 1, ft_put);
	ft_del_char(line, *position);
	tputs(tgetstr("cd", NULL), 1, ft_put);
	(*position)--;
	tputs(tgetstr("sc", NULL), 1, ft_put);
	ft_putstr(*line + *position);
	tputs(tgetstr("rc", NULL), 1, ft_put);
}
