/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_up.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hestela <hestela@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/07 18:27:07 by hestela           #+#    #+#             */
/*   Updated: 2014/02/08 12:44:36 by hestela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
#include <termcap.h>
#include "libft.h"
#include "42sh.h"

static int		ft_can_move_up(int *position, char **line);
static void		ft_move_up2(int *position, char **line, int rest);

void			ft_move_up(int *position, char **line)
{
	int			rest;

	if (!ft_strchr(*line, '\n'))
	{
		if ((g_prompt_len + 1 + *position) / g_ws.ws_col == 0)
		{
			ft_putchar(7);
			return ;
		}
		rest = (g_prompt_len + 1 + *position) % g_ws.ws_col;
		ft_move_left(position, *line);
		while ((g_prompt_len + 1 + *position) % g_ws.ws_col != rest
			&& *position > 0)
			ft_move_left(position, *line);
	}
	else
	{
		rest = ft_can_move_up(position, line);
		if (rest == -1)
			ft_putchar(7);
		else
			ft_move_up2(position, line, rest);
	}
}

static int		ft_can_move_up(int *position, char **line)
{
	int			count;
	char		*str;
	int			i;
	int			rest;

	rest = 0;
	str = *line;
	count = 0;
	i = 0;
	while (str + i != str + *position)
	{
		if (*(str + i) == '\n')
		{
			rest = 0;
			count++;
		}
		(rest)++;
		i++;
	}
	if (count == 0)
		return (-1);
	else
		return (rest);
}

static void     ft_move_up2(int *position, char **line, int rest)
{
	char	*str;
	int		i;
	int		bool;

	bool = 0;
	i = 0;
	str = *line;
	ft_move_left(position, *line);
	while (*position > 0 && *(str + *position) != '\n')
		ft_move_left(position, *line);
	ft_move_left(position, *line);
	while (*position > 0 && *(str + *position - 1) != '\n')
		ft_move_left(position, *line);
	while (*(str + *position + 1) != '\n' && !bool)
	{
		ft_move_right(position, *line);
		i++;
		if (i + 1 == rest)
			bool = 1;
	}
}
