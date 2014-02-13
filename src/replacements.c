/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replacements.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hestela <hestela@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/11 22:30:21 by hestela           #+#    #+#             */
/*   Updated: 2014/02/13 00:52:16 by hestela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
#include "libft.h"
#include "42sh.h"

void		ft_do_replacements(char **line)
{
	ft_replace_alias(line);
	if (ft_strchr(*line, '~'))
		ft_replace_tilde(line);
	if (ft_strchr(*line, '$'))
		ft_replace_variable(line);
}
