/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hestela <hestela@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/29 08:47:12 by hestela           #+#    #+#             */
/*   Updated: 2014/01/30 21:03:14 by hestela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
#include "libft.h"

static void		ft_lstchg(t_list **alst);
static char		*ft_strconvert(t_list *node);

void			ft_lstsort(t_list **alst)
{
	int			i;
	int			len;
	char		*str1;
	char		*str2;
	t_list		**tmp;

	i = 0;
	tmp = alst;
	len = ft_lstlen(*alst);
	while (i < len)
	{
		while ((*tmp)->next)
		{
			str1 = ft_strconvert(*tmp);
			str2 = ft_strconvert((*tmp)->next);
			if (ft_strcmp(str1, str2) > 0)
				ft_lstchg(tmp);
			free(str1);
			free(str2);
			tmp = &(*tmp)->next;
		}
		i++;
		tmp = alst;
	}
	tmp = NULL;
}

static void		ft_lstchg(t_list **alst)
{
	t_list		*tmp;

	tmp = *alst;
	*alst = (*alst)->next;
	tmp->next = (*alst)->next;
	(*alst)->next = tmp;
}

static char		*ft_strconvert(t_list *node)
{
	char		*ret;

	if (node->content_size == 1)
	{
		ret = (char *) malloc(sizeof(*ret) * 2);
		ret[0] = *(char *) node->content;
		ret[1] = '\0';
	}
	else if (node->content_size == 4 || node->content_size == 2)
		ret = ft_itoa(*(int *) node->content);
	else if (node->content_size == 8)
		ret = ft_ftoa(*(double *) node->content, 10);
	else
		ret = ft_strdup((char *) node->content);
	return (ret);
}
