/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   autocomp_tool_1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hestela <hestela@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/16 03:56:56 by hestela           #+#    #+#             */
/*   Updated: 2014/02/16 04:08:28 by hestela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
#include <dirent.h>
#include "libft.h"
#include "42sh.h"

static char		*ft_comp_file_4(char **ln, int ps, char *path, char *to_add);
static void		ft_refresh_2(char **ln, int *ps, int pv, char *new);

void			ft_comp_refresh(char **line, char *buf, int *ps, int pv)
{
	while (*ps < (int)ft_strlen(*line))
		ft_move_right(ps, *line);
	while (*ps > 0)
		ft_back(ps, line);
	free(*line);
	*line = ft_strdup(buf);
	*ps += ft_putstr(*line);
	while (*ps != pv)
		ft_move_left(ps, *line);
	while (!ft_strchr(" ;|<>&", line[0][*ps]))
		ft_move_right(ps, *line);
}

void			ft_comp_file_3(char **ln, int pv, int *ps, char *path)
{
	char		*new;

	new = ft_comp_file_4(ln, pv, path, g_comp_lst->str);
	ft_refresh_2(ln, ps, pv, new);
	if (!g_comp_lst->next)
		g_comp_lst = g_comp_lst->start;
	else
		g_comp_lst = g_comp_lst->next;
}

static char		*ft_comp_file_4(char **ln, int ps, char *path, char *to_add)
{
	char		buf[2048];
	int			i[2];

	ft_bzero(buf, 2048);
	i[0] = 0;
	i[1] = 0;
	while (i[0] < ps && i[0]++ >= 0 && i[1]++ >= 0)
		buf[i[0] - 1] = ln[0][i[1] - 1];
	while (!ft_strchr(" ;|<>&", ln[0][i[1]]))
		i[1]++;
	if (path)
	{
		while (*path && i[0]++ >= 0)
		{
			buf[i[0] - 1] = *path;
			path++;
		}
	}
	while (*to_add && i[0]++ >= 0 && to_add++)
		buf[i[0] - 1] = *(to_add - 1);
	while (ln[0][i[1]] && i[0]++ >= 0 && i[1]++ >= 0)
		buf[i[0] - 1] = ln[0][i[1] - 1];
	return (ft_strdup(buf));
}

static void		ft_refresh_2(char **ln, int *ps, int pv, char *new)
{
	while (*ps < (int)ft_strlen(*ln))
		ft_move_right(ps, *ln);
	while (*ps > 0)
		ft_back(ps, ln);
	free(*ln);
	*ln = ft_strdup(new);
	free(new);
	*ps += ft_putstr(*ln);
	while (*ps != pv)
		ft_move_left(ps, *ln);
	while (!ft_strchr(" ;|<>&", ln[0][*ps]))
		ft_move_right(ps, *ln);
}

void			ft_comp_path(char **ln, int pv, char *buf)
{
	int			i[3];

	i[0] = 0;
	i[1] = 0;
	i[2] = 0;
	while (i[0] < pv)
	{
		buf[i[0]] = ln[0][i[1]];
		i[0]++;
		i[1]++;
	}
	while (g_comp_lst->str[i[2]])
	{
		buf[i[0]] = g_comp_lst->str[i[2]];
		i[2]++;
		i[0]++;
	}
	while (!ft_strchr(" ;><&|", ln[0][i[1]]))
		i[1]++;
	while (ln[0][i[1]])
	{
		buf[i[0]] = ln[0][i[1]];
		i[0]++;
		i[1]++;
	}
}
