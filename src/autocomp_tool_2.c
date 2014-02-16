/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   autocomp_tool_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hestela <hestela@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/16 03:59:42 by hestela           #+#    #+#             */
/*   Updated: 2014/02/16 04:02:13 by hestela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
#include <dirent.h>
#include <sys/stat.h>
#include "libft.h"
#include "42sh.h"

static void		ft_add_node(char *ent, char *new, t_stat file_stats);

void			ft_add_comp_list(char *path, char *to_comp)
{
	DIR			*dir;
	t_dirent	*ent;
	char		*new;
	t_stat		file_stats;

	dir = opendir(path);
	if (dir)
	{
		ent = readdir(dir);
		ent = readdir(dir);
		ent = readdir(dir);
		while (ent)
		{
			if (ft_match(ent->d_name, to_comp))
			{
				new = ft_strjoin(path, ent->d_name);
				stat(new, &file_stats);
				ft_add_node(ent->d_name, new, file_stats);
			}
			ent = readdir(dir);
		}
		if (g_comp_lst)
			g_comp_lst = g_comp_lst->start;
		closedir(dir);
	}
}

static void		ft_add_node(char *ent, char *new, t_stat file_stats)
{
	free(new);
	if (S_ISDIR(file_stats.st_mode))
		new = ft_strjoin(ent, "/");
	else
		new = ft_strdup(ent);
	if (!g_comp_lst)
	{
		g_comp_lst = malloc(sizeof(t_comp_lst));
		g_comp_lst->start = g_comp_lst;
		g_comp_lst->next = NULL;
		g_comp_lst->str = ft_strdup(new);
	}
	else
	{
		while (g_comp_lst->next)
			g_comp_lst = g_comp_lst->next;
		g_comp_lst->next = malloc(sizeof(t_comp_lst));
		g_comp_lst->next->start = g_comp_lst->start;
		g_comp_lst = g_comp_lst->next;
		g_comp_lst->next = NULL;
		g_comp_lst->str = ft_strdup(new);
	}
	free(new);
}

char			*ft_get_comp_path(char *begin)
{
	char		buf[1024];
	int			i;

	i = 0;
	ft_bzero(buf, 1024);
	while (begin[i])
	{
		buf[i] = begin[i];
		i++;
	}
	while (buf[i] != '/')
	{
		buf[i] = '\0';
		i--;
	}
	return (ft_strdup(buf));
}

char			*ft_get_comp_rest(char *begin)
{
	char		buf[1024];
	int			i;
	int			j;

	ft_bzero(buf, 1024);
	i = ft_strlen(begin);
	j = 0;
	while (begin[i] != '/')
		i--;
	i++;
	while (begin[i])
	{
		buf[j] = begin[i];
		i++;
		j++;
	}
	buf[j] = '*';
	return (ft_strdup(buf));
}
