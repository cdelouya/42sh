/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hestela <hestela@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/04 10:25:54 by hestela           #+#    #+#             */
/*   Updated: 2014/02/05 14:51:23 by hestela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
#include "libft.h"
#include "42sh.h"

static void		ft_is_instring(int *bool, char *str);
static int		ft_check_redir(t_cmd **alist, char *str, char **ptr);
static void		ft_add_to_list(t_cmd **alist, char *ptr, int redir);
static t_cmd	*ft_create_first_node(char *ptr, int redir);

t_cmd			*ft_parser(char **line)
{
	t_cmd		*list;
	int			instring;
	char		*ptr;
	char		*str;

	list = NULL;
	instring = 0;
	str = *line;
	ptr = str;
	while (*str)
	{
		ft_is_instring(&instring, str);
		if (!instring && ft_strchr("|<>;", *str))
			str += ft_check_redir(&list, str, &ptr);
		else
			str++;
	}
	ft_add_to_list(&list, ptr, 0);
	free(*line);
	*line = NULL;
	return (list);
}

static void		ft_is_instring(int *bool, char *str)
{
	if (!*bool && *str == '"')
		*bool = 1;
	else if (bool && *str == '"' && *(str - 1) != '\\')
		*bool = 0;
}

static int		ft_check_redir(t_cmd **alist, char *str, char **ptr)
{
	int			redir;
	int			inc;

	redir = 0;
	if (*str == '>' && *str == *(str + 1))
		redir = 4;
	else if (*str == '<' && *str == *(str + 1))
		redir = 5;
	else if (*str == '|')
		redir = 1;
	else if (*str == '>')
		redir = 2;
	else if (*str == '<')
		redir = 3;
	inc = 1;
	if ((*str == '>' || *str == '<') && *str == *(str + 1))
	{
		inc = 2;
		*(str + 1) = '\0';
	}
	*str = '\0';
	ft_add_to_list(alist, *ptr, redir);
	str += inc;
	*ptr = str;
	return (inc);
}

static void		ft_add_to_list(t_cmd **alist, char *ptr, int redir)
{
	t_cmd		*start;

	if (*alist == NULL)
		*alist = ft_create_first_node(ptr, redir);
	else
	{
		start = *alist;
		while ((*alist)->next)
			*alist = (*alist)->next;
		(*alist)->next = malloc(sizeof(t_cmd));
		*alist = (*alist)->next;
		(*alist)->line = ft_strdup(ptr);
		(*alist)->redir = redir;
		(*alist)->next = NULL;
		*alist = start;
	}
}

static t_cmd	*ft_create_first_node(char *ptr, int redir)
{
	t_cmd		*node;

	node = malloc(sizeof(t_cmd));
	node->line = ft_strdup(ptr);
	node->redir = redir;
	node->next = NULL;
	return (node);
}
