/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_quote.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hestela <hestela@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/05 15:38:35 by hestela           #+#    #+#             */
/*   Updated: 2014/02/07 18:47:17 by hestela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
#include "libft.h"
#include "42sh.h"

static void			ft_is_instring(char *quote, char *str);
static void			ft_del_list(t_quote **alist);
static void			ft_final_check(t_quote **alist, char quote);

int					ft_check_quote(char **line)
{
	char			quote;
	char			*str;
	t_quote			*list;

	list = NULL;
	quote = '\0';
	if (*line == NULL)
		return (0);
	str = *line;
	while (*str)
	{
		ft_is_instring(&quote, str);
		if (quote == '\0' && ft_strchr("({})", *str))
			ft_add_quote_to_list(&list, *str);
		str++;
	}
	if (quote != '\0' || list)
	{
		g_env.quote_wait = 1;
		ft_final_check(&list, quote);
		return (1);
	}
	else
		g_env.quote_wait = 0;
	return (0);
}

static void			ft_is_instring(char *quote, char *str)
{
	if (*quote == '\0' && ft_strchr("\"'`", *str))
		*quote = *str;
	else if (*quote == *str && *(str - 1) != '\\')
		*quote = '\0';
}

static void			ft_del_list(t_quote **alist)
{
	t_quote			*node;

	while (*alist)
	{
		node = *alist;
		*alist = (*alist)->prev;
		free(node);
	}
}

static void			ft_check_instring(char quote, t_quote *list)
{
	if (quote != '\0')
	{
		if (list)
			g_prompt_len += ft_putchar(' ');
		if (quote == '\'')
			g_prompt_len += ft_printf("%$quote", F_CYAN);
		else if (quote == '"')
			g_prompt_len += ft_printf("%$dquote", F_CYAN);
		else if (quote == '`')
			g_prompt_len += ft_printf("%$bquote", F_CYAN);
	}
}

static void			ft_final_check(t_quote **alist, char quote)
{
	t_quote			*start;

	g_prompt_len = 0;
	if (*alist)
	{
		while ((*alist)->prev)
			*alist = (*alist)->prev;
		start = *alist;
		while (*alist)
		{
			if ((*alist)->prev)
				g_prompt_len += ft_putchar(' ');
			if ((*alist)->c == '(')
				g_prompt_len += ft_printf("%$subsh", F_CYAN);
			else if ((*alist)->c == '{')
				g_prompt_len += ft_printf("%$cursh", F_CYAN);
			*alist = (*alist)->next;
		}
		*alist = start;
	}
	ft_check_instring(quote, *alist);
	g_prompt_len += ft_printf("$> ");
	ft_del_list(alist);
}
