/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   edit_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hestela <hestela@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/29 11:57:50 by hestela           #+#    #+#             */
/*   Updated: 2014/02/11 20:43:20 by hestela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
#include <termcap.h>
#include "libft.h"
#include "42sh.h"

static void		ft_copy_str(int *b, int *a, char *str, char *cpy);
static void		ft_refresh(char *cpy, char *str, int position, int a);

void			ft_del_char(char **line, int position)
{
	char		*str;
	char		*cpy;
	int			a;
	int			b;
	int			bool;

	str = *line;
	bool = 0;
	a = 0;
	b = 0;
	cpy = (char *) malloc(sizeof(char) * ft_strlen(str) + 1);
	while (str[b])
	{
		if (b == position - 1)
			b++;
		else
		{
			cpy[a] = str[b];
			a++;
			b++;
		}
	}
	cpy[a] = '\0';
	free(*line);
	*line = cpy;
}


void			ft_add_char(char **line, int position, char c)
{
	char		*str;
	char		*cpy;
	int			a;
	int			b;
	int			bool;

	str = *line;
	bool = 0;
	a = 0;
	b = 0;
	cpy = (char *) malloc(sizeof(char) * ft_strlen(str) + 2);
	while (b < (int)ft_strlen(str) + 1)
	{
		if (b == position && bool == 0)
		{
			cpy[a] = c;
			a++;
			bool = 1;
		}
		else
			ft_copy_str(&b, &a, str, cpy);
	}
	ft_refresh(cpy, str, position, a);
	*line = cpy;
}

static void		ft_copy_str(int *b, int *a, char *str, char *cpy)
{
	cpy[*a] = str[*b];
	(*a)++;
	(*b)++;
}

static void		ft_refresh(char *cpy, char *str, int position, int a)
{
	cpy[a] = '\0';
	tputs(tgetstr("sc", NULL), 1, ft_put);
	ft_putstr(str + position);
	tputs(tgetstr("rc", NULL), 1, ft_put);
}
