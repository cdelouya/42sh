/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace_alias.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hestela <hestela@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/13 00:50:53 by hestela           #+#    #+#             */
/*   Updated: 2014/02/13 01:37:05 by hestela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
#include "libft.h"
#include "42sh.h"

static void		ft_check_alias(char **line, char *alias, char *string, int i);
static void		ft_instring(char *quote, char c, int d);

void			ft_replace_alias(char **line)
{
	t_alias_lst		*start;
	char			*alias;
	char			*string;
	int				i;

	i = 0;
	if (g_env.alias_lst)
	{
		start = g_env.alias_lst;
		while (g_env.alias_lst)
		{
			alias = g_env.alias_lst->alias;
			string = g_env.alias_lst->string;
			ft_check_alias(line, alias, string, i);
			g_env.alias_lst = g_env.alias_lst->next;
		}
		g_env.alias_lst = start;
	}
}

static void		ft_free_and_dup(char **line, char *buf, int i)
{
	buf[i] = '\0';
	if (ft_strlen(*line) != ft_strlen(buf))
	{
		free(*line);
		*line = ft_strdup(buf);
	}
}

static void		ft_check_alias(char **line, char *alias, char *string, int i)
{
	char		buf[2048];
	char		*str;
	int			len;
	char		quote;

	str = *line;
	quote = '\0';
	len = ft_strlen(alias);
	while (*str)
	{
		ft_instring(&quote, *str, *(str - 1));
		if (ft_strncmp(alias, str, len) == 0
			&& (ft_strchr(" >|<;\"'`", *(str - 1)) || str == *line)
			&& quote == '\0' && ft_strchr(" >|<;\"'`\0", *(str + len)))
		{
			while (*string && string++ && i++ >= 0)
				buf[i - 1] = *(string - 1);
			str += len;
		}
		else if (i++ >= 0 && str++)
			buf[i] = *str;
	}
	ft_free_and_dup(line, buf, i);
}

static void		ft_instring(char *quote, char c, int d)
{
	if (*quote == '\0' && ft_strchr("\"'", c))
		*quote = c;
	else if (*quote == c && d != '\\')
		*quote = '\0';
}
