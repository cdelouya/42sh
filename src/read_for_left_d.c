/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_for_left_d.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hestela <hestela@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/05 13:51:19 by hestela           #+#    #+#             */
/*   Updated: 2014/02/07 18:11:09 by hestela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
#include <unistd.h>
#include <termcap.h>
#include "libft.h"
#include "42sh.h"

static int		ft_get_key(char *str);
static void		ft_key(char *buf, char **line, int *position);
static void		ft_read_input(char **line, int *position);

void			ft_get_heredoc(char **line)
{
	char		*str;
	int			position;

	position = 0;
	if (*line)
	{
		free(*line);
		*line = NULL;
	}
	str = ft_strdup("\0");
	ft_read_input(&str, &position);
	ft_putchar('\n');
	*line = str;
}

static void		ft_read_input(char **line, int *position)
{
	int			ret;
	char		*buf;

	ret = 1;
	buf = ft_memalloc(42);
	while (!ft_strchr(buf, '\n') && ret > 0)
	{
		g_env.saved_line = line;
		ft_bzero(buf, 42);
		ret = read(0, buf, 1024);
		buf[ret] = '\0';
		if (ft_isprint(*buf))
		{
			ft_putchar(*buf);
			ft_add_char(line, *position, *buf);
			(*position)++;
			ft_bzero(buf, 42);
			if ((*position + g_prompt_len + 1) % g_ws.ws_col == 1)
				tputs(tgetstr("sf", NULL), 1, ft_put);
		}
		else if (*buf != '\n')
			ft_key(buf, line, position);
	}
	free(buf);
}

static void		ft_key(char *buf, char **line, int *position)
{
	int			key;

	key = ft_get_key(buf);
	if (key == ALT_W || key == ALT_W2)
		ft_cut(line, position);
	if (key == CTRL_X)
		ft_paste(line, position);
	if (key == CTRL_W)
		ft_copy(line, *position);
	if (key == CTRL_LEFT)
		ft_move_to_word_L(position, line);
	if (key == CTRL_RIGHT)
		ft_move_to_word_R(position, line);
	if (key == CTRL_A || key == HOME)
		ft_move_to_beg(position, *line);
	if (key == CTRL_E || key == END)
		ft_move_to_end(position, *line);
	if (key == LEFT)
		ft_move_left(position, *line);
	if (key == RIGHT)
		ft_move_right(position, *line);
	if (key == BACK)
		ft_back(position, line);
	if (key == CTRL_D || key == CTRL_C)
		*buf = '\n';
}

static int		ft_get_key(char *str)
{
	int			result;
	int			i;
	int			mult;
	int			value;

	result = 0;
	i = 0;
	while (i < 6)
	{
		mult = 10;
		value = str[i];
		while (value > 10)
		{
			mult *= 10;
			value /= 10;
		}
		result = result * mult + str[i];
		i++;
	}
	return (result);
}
