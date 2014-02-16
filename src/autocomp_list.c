/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   autocomp_list.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hestela <hestela@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/16 14:32:31 by hestela           #+#    #+#             */
/*   Updated: 2014/02/16 15:22:04 by hestela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
#include <dirent.h>
#include <sys/stat.h>
#include "libft.h"
#include "42sh.h"

static void		ft_add_node(char *ent, char *new, t_stat file_stats);
static void		ft_sort_comp_list(void);
static void		ft_sort(t_comp_lst **alst);
static void		ft_lstchg(t_comp_lst **alst);

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
		ft_sort_comp_list();
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

static void		ft_sort_comp_list(void)
{
	if (g_comp_lst)
	{
		g_comp_lst = g_comp_lst->start;
		ft_sort(&g_comp_lst);
		g_comp_lst->start = g_comp_lst;
		while (g_comp_lst->next)
		{
			g_comp_lst->next->start = g_comp_lst->start;
			g_comp_lst = g_comp_lst->next;
		}
		g_comp_lst = g_comp_lst->start;
	}
}

static void		ft_sort(t_comp_lst **alst)
{
	int				len;
	int				i;
	t_comp_lst		**tmp;

	i = 0;
	len = 1;
	tmp = alst;
	while (g_comp_lst->next)
	{
		len++;
		g_comp_lst = g_comp_lst->next;
	}
	g_comp_lst = g_comp_lst->start;
	while (i < len)
	{
		while ((*tmp)->next)
		{
			if (ft_strcmp((*tmp)->str, (*tmp)->next->str) > 0)
				ft_lstchg(tmp);
			tmp = &(*tmp)->next;
		}
		i++;
		tmp = alst;
	}
	tmp = NULL;
}

static void		ft_lstchg(t_comp_lst **alst)
{
	t_comp_lst		*tmp;

	tmp = *alst;
	*alst = (*alst)->next;
	tmp->next = (*alst)->next;
	(*alst)->next = tmp;
}
