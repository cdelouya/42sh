/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace_star.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hestela <hestela@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/13 16:02:35 by hestela           #+#    #+#             */
/*   Updated: 2014/02/16 04:12:32 by hestela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>
#include <stdlib.h>
#include "libft.h"
#include "42sh.h"

static void		ft_instring(char *quote, char c, int d);
static void		ft_find_star(char **line, int i, char *stared, char *path);
static char		*ft_get_path(char *str, int i, int *j);
static char		*ft_get_stared(char *str, int *j);

void			ft_replace_star(char **line)
{
	char		*str;
	char		quote;
	int			i;
	char		*stared;
	char		*path;

	i = 0;
	quote = '\0';
	str = *line;
	while (str[i])
	{
		ft_instring(&quote, str[i], str[i - 1]);
		if (str[i] == '*' && quote == '\0')
		{
			stared = NULL;
			path = NULL;
			ft_find_star(line, i, stared, path);
			if (path)
				free(path);
			if (stared)
				free(stared);
			str = *line;
		}
		i++;
	}
}

static void		ft_find_star(char **line, int i, char *stared, char *path)
{
	int			j;
	char		*new;

	j = i;
	while (!ft_strchr(" ;><&|", line[0][j]) && j >= 0)
		j--;
	j++;
	path = ft_get_path(*line, i, &j);
	stared = ft_get_stared(*line, &j);
	if (path && access(path, F_OK) != 0)
	{
		ft_printf_fd(2, "%$42sh: No matches found: %s%s%$\n"\
			, F_RED, path, stared, F_WHITE);
		return ;
	}
	new = ft_replace_star_2(path, stared, &j, *line);
	if (!new)
	{
		ft_printf_fd(2, "%$42sh: No matches found: %s%s%$\n"\
			, F_RED, path, stared, F_WHITE);
		return ;
	}
	ft_update_stared_line(line, new, i);
	free(new);
}

static void		ft_instring(char *quote, char c, int d)
{
	if (*quote == '\0' && ft_strchr("\"'", c))
		*quote = c;
	else if (*quote == c && d != '\\')
		*quote = '\0';
}

static char		*ft_get_path(char *str, int i, int *j)
{
	char		path[1024];
	char		*ret;
	int			k;

	k = 0;
	ft_bzero(path, 1024);
	while (*j < i)
	{
		path[k] = str[*j];
		(*j)++;
		k++;
	}
	while (path[k] != '/' && k >= 0)
	{
		path[k] = '\0';
		k--;
		(*j)--;
	}
	(*j)++;
	if (!*path)
		return (NULL);
	ret = ft_strdup(path);
	return (ret);
}

static char		*ft_get_stared(char *str, int *j)
{
	char		stared[1024];
	int			k;
	char		*ret;

	ft_bzero(stared, 1024);
	k = 0;
	while (!ft_strchr(" ;><&|", str[*j]) && str[*j] != '/' && str[*j])
	{
		stared[k] = str[*j];
		k++;
		(*j)++;
	}
	ret = ft_strdup(stared);
	return (ret);
}
