/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_array_str_print.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hestela <hestela@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/27 11:53:00 by hestela           #+#    #+#             */
/*   Updated: 2013/11/30 21:39:51 by hestela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	ft_array_str_print(char **array)
{
	int		i;

	i = 0;
	if (array && *array)
	{
		while (array[i])
		{
			ft_putstr(array[i]);
			ft_putchar('\n');
			i++;
		}
	}
}
