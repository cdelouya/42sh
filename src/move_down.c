/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_down.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hestela <hestela@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/07 21:04:47 by hestela           #+#    #+#             */
/*   Updated: 2014/02/08 12:50:37 by hestela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
#include <termcap.h>
#include "libft.h"
#include "42sh.h"

static void		ft_multiligne(int *position, char **line, int rest);
static int		ft_can_move_down(int *position, char **line);
static void     ft_move_down2(int *position, char **line, int rest);

void			ft_move_down(int *position, char **line)
{
	int			rest;
	int			len1;
	int			len2;

	rest = 0;
	if (!ft_strchr(*line, '\n'))
	{
		len1 = g_prompt_len + 1 + *position;
		len2 = g_prompt_len + 1 + (int)ft_strlen(*line);
		if (len1 / g_ws.ws_col == len2 / g_ws.ws_col)
		{
			ft_putchar(7);
			return ;
		}
		rest = (g_prompt_len + 1 + *position) % g_ws.ws_col;
		ft_move_right(position, *line);
		while ((g_prompt_len + 1 + *position) % g_ws.ws_col != rest
			&& *position < (int)ft_strlen(*line))
			ft_move_right(position, *line);
	}
	else
		ft_multiligne(position, line, rest);
}

static void		ft_multiligne(int *position, char **line, int rest)
{
	rest = ft_can_move_down(position, line);
	if (rest == -1)
		ft_putchar(7);
	else
		ft_move_down2(position, line, rest);
}

static int		ft_get_rest(int *position, char *str)
{
	int			rest;
	int			i;

	i = 0;
	rest = 0;
	while (str + i != str + *position)
	{
		if (*(str + i) == '\n')
			rest = 0;
		rest++;
		i++;
	}
	return (rest);
}

static int		ft_can_move_down(int *position, char **line)
{
	int			count;
	char		*str;
	int			i;
	int			rest;

	rest = 0;
	str = *line;
	count = 0;
	rest = ft_get_rest(position, str);
	i = 0;
	while (*(str + *position + i))
	{
		if (*(str + *position + i) == '\n')
			count++;
		i++;
	}
	if (count == 0)
		return (-1);
	else
		return (rest);
}

static void     ft_move_down2(int *position, char **line, int rest)
{
	char		*str;
	int			bool;
	int			i;

	i = 0;
	bool = 0;
	str = *line;
	ft_move_right(position, *line);
	while (*(str + *position) && *(str + *position - 1) != '\n')
		ft_move_right(position, *line);
	while (*(str + *position + 1) != '\n' && !bool && *(str + *position + 1))
	{
		ft_move_right(position, *line);
		i++;
		if (i + 1 == rest)
			bool = 1;
	}
}
