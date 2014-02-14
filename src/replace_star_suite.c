/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace_star_suite.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hestela <hestela@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/14 04:02:14 by hestela           #+#    #+#             */
/*   Updated: 2014/02/14 04:19:29 by hestela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>
#include <stdlib.h>
#include <dirent.h>
#include "libft.h"
#include "42sh.h"

static void		ft_update_new(char *path, char *file, char *rest, char *new);
static char		*ft_get_rest(char *str, int *j);

char			*ft_replace_star_2(char *path, char *stared, int *j, char *str)
{
	char		*rest;
	DIR			*dir;
	t_dirent	*file;
	char		new[4096];
	int			i;

	i = 0;
	ft_bzero(new, 4096);
	rest = ft_get_rest(str, j);
	if (path)
		dir = opendir(path);
	else
		dir = opendir(".");
	file = readdir(dir);
	while (file)
	{
		if (ft_match(file->d_name, stared) && file->d_name[0] != '.')
			ft_update_new(path, file->d_name, rest, new);
		file = readdir(dir);
	}
	if (rest)
		free(rest);
	closedir(dir);
	return (ft_strdup(new));
}

void			ft_update_stared_line(char **line, char *new, int i)
{
	char		*str;
	char		newline[10240];
	int			j;
	int			k;

	j = 0;
	k = 0;
	str = *line;
	ft_bzero(newline, 10240);
	while (!ft_strchr(" ;><&|", str[i]) && i >= 0)
		i--;
	i++;
	while (j < i && j++ >= 0 && k++ >= 0)
		newline[k - 1] = str[j - 1];
	while (*new && k++ >= 0)
	{
		newline[k - 1] = *new;
		new++;
	}
	while (!ft_strchr(" ;><&|", str[j]) && str[j])
		j++;
	while (str[j] && k++ >= 0 && j++ >= 0)
		newline[k - 1] = str[j - 1];
	free(*line);
	*line = ft_strdup(newline);
}

static char		*ft_get_rest(char *str, int *j)
{
	char		rest[1024];
	int			i;
	char		*ret;

	i = 0;
	ft_bzero(rest, 1024);
	while (str[*j] && !ft_strchr(" ;><&|", str[*j]))
	{
		rest[i] = str[*j];
		i++;
		(*j)++;
	}
	if (!*rest)
		return (NULL);
	ret = ft_strdup(rest);
	return (ret);
}

static void		ft_update_new(char *path, char *file, char *rest, char *new)
{
	char		*str;
	int			i;

	i = 0;
	while (*new)
		new++;
	str = ft_str_multi_join(3, path, file, rest);
	while (str[i])
	{
		*new = str[i];
		new++;
		i++;
	}
	*new = ' ';
	free(str);
}
