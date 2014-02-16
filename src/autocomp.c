/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   autocomp.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hestela <hestela@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/14 15:59:09 by hestela           #+#    #+#             */
/*   Updated: 2014/02/16 04:01:00 by hestela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
#include <dirent.h>
#include "libft.h"
#include "42sh.h"

static int		ft_iscmd(char *str, int i);
static void		ft_file_completion(char **line, int *position, int *autocomp);
static void		ft_cmd_completion(char **line, int *position, int *autocomp);
static void		ft_free_list(void);

void			ft_autocomp(char **line, int *position, int *autocomp)
{
	static int		cmd;

	if (*autocomp == 0)
	{
		if (g_comp_lst)
			ft_free_list();
		g_comp_lst = NULL;
		cmd = ft_iscmd(*line, *position);
	}
	if (!cmd)
		ft_file_completion(line, position, autocomp);
	else
		ft_cmd_completion(line, position, autocomp);
}

static int		ft_iscmd(char *str, int i)
{
	int			nbr;

	nbr = 0;
	if (i == 0)
		return (1);
	if (!ft_strchr(";><&|", str[i - 1]))
	{
		nbr = 1;
		i--;
	}
	while (!ft_strchr(";><&|", str[i]) && i >= 0)
	{
		if (str[i] != ' ' && str[i + 1] == ' ')
			nbr++;
		i--;
	}
	if (nbr == 0 || nbr == 1)
		return (1);
	else
		return (0);
}

static void		ft_file_completion(char **line, int *position, int *autocomp)
{
	static int		prev;
	static int		prevpos;

	if (*autocomp == 0)
	{
		prev = 0;
		prevpos = *position;
	}
	if ((line[0][prevpos - 1] == ' ' && ft_strchr(" \0", line[0][prevpos]))
		|| prev == 1)
	{
		prev = 1;
		ft_comp_current_dir(line, position, prevpos, autocomp);
	}
	else if (prev == 2 || line[0][prevpos - 1] != ' ')
	{
		prev = 2;
		while (line[0][*position - 1] != ' ')
			ft_move_left(position, *line);
		prevpos = *position;
		ft_comp_file(line, position, prevpos, autocomp);
	}
}

static void		ft_cmd_completion(char **line, int *position, int *autocomp)
{
	static int		prev;
	static int		prevpos;

	if (*autocomp == 0)
		prev = 0;
	if (*autocomp == 0)
		prevpos = *position;
	if (prev == 1 || (ft_strchr(" ;><&|", line[0][prevpos - 1])
		&& ft_strchr(" \0", line[0][prevpos]))
		|| (*position == 0 && ft_strchr(" ;><&|\0", line[0][prevpos])))
	{
		prev = 1;
		ft_complete_all_cmd(line, position, prevpos, autocomp);
	}
	else
	{
		while (*position > 0 && !ft_strchr(" ;<>&|", line[0][*position - 1]))
			ft_move_left(position, *line);
		prevpos = *position;
		prev = 2;
		ft_comp_cmd(line, position, prevpos, autocomp);
	}
}

static void		ft_free_list(void)
{
	t_comp_lst		*node;

	g_comp_lst = g_comp_lst->start;
	while (g_comp_lst)
	{
		node = g_comp_lst;
		g_comp_lst = g_comp_lst->next;
		free(node->str);
		free(node);
	}
}
