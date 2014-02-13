/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quote_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hestela <hestela@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/06 18:45:23 by hestela           #+#    #+#             */
/*   Updated: 2014/02/06 19:35:50 by hestela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
#include "42sh.h"

static void		ft_add_new_node(t_quote **alist, char c);
static void		ft_create_first_node(t_quote **alist, char c);
static void		ft_del_node(t_quote **alist);

void			ft_add_quote_to_list(t_quote **alist, char c)
{
	if (!*alist && (c == ')' || c == '}'))
		return ;
	if (!*alist)
		ft_create_first_node(alist, c);
	else
	{
		if ((c == ')' && (*alist)->c == '(')
			|| (c == '}' && (*alist)->c == '{'))
			ft_del_node(alist);
		else if (c == '(' || c == '{')
			ft_add_new_node(alist, c);
	}
}

static void		ft_add_new_node(t_quote **alist, char c)
{
	(*alist)->next = malloc(sizeof(t_quote));
	(*alist)->next->prev = *alist;
	*alist = (*alist)->next;
	(*alist)->c = c;
	(*alist)->next = NULL;
}

static void		ft_create_first_node(t_quote **alist, char c)
{
	*alist = malloc(sizeof(t_quote));
	(*alist)->c = c;
	(*alist)->prev = NULL;
	(*alist)->next = NULL;
}

static void		ft_del_node(t_quote **alist)
{
	if ((*alist)->prev == NULL)
	{
		free(*alist);
		*alist = NULL;
	}
	else
	{
		*alist = (*alist)->prev;
		free((*alist)->next);
		(*alist)->next = NULL;
	}
}
