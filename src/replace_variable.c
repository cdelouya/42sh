/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace_variable.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hestela <hestela@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/11 22:56:55 by hestela           #+#    #+#             */
/*   Updated: 2014/02/13 02:18:28 by hestela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
#include "libft.h"
#include "42sh.h"

static char		*ft_get_var(char *s);
static int		ft_cat_var(char *str, int *i, char *buf);
static void		ft_instring(char *quote, char c, char d);

void			ft_replace_variable(char **line)
{
	char		buf[2048];
	char		*str;
	int			i;
	char		quote;

	quote = '\0';
	str = *line;
	i = 0;
	while (*str)
	{
		ft_instring(&quote, *str, *(str - 1));
		if (*str == '$' && ft_get_var(str) && quote == '\0')
			str += ft_cat_var(str, &i, buf);
		else
		{
			buf[i] = *str;
			str++;
			i++;
		}
	}
	buf[i] = '\0';
	free(*line);
	*line = ft_strdup(buf);
}

static void		ft_instring(char *quote, char c, char d)
{
	if (*quote == '\0' && c == '\'')
		*quote = c;
	else if (*quote == c && d != '\\')
		*quote =  '\0';
}

static char		*ft_get_var(char *s)
{
	char		buf[100];
	int			j;

	j = 0;
	s++;
	while (*s != ' ' && *s != '\n' && *s != '\0' && *s != '/'
		   && *s != '<' && *s != '>' && *s != '|' && *s != '"'
		   && *s != '\'' && *s != '`')
	{
		buf[j] = *s;
		s++;
		j++;
	}
	buf[j] = '\0';
	return (ft_getenv(g_env.env, buf));
}

static int		ft_cat_var(char *str, int *i, char *buf)
{
	int			count;
	char		*var;

	count = 0;
	var = ft_get_var(str);
	str++;
	count++;
	if (var)
	{
		while (*str != ' ' && *str != '\n' && *str != '\0'
			&& *str != '/' && *str != '<' && *str != '>'
			&& *str != '|' && *str != '"' && *str != '\''
			&& *str != '`')
		{
			str++;
			count++;
		}
		while (*var)
		{
			buf[*i] = *var;
			var++;
			(*i)++;
		}
	}
	return (count);
}
