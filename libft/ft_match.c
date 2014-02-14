/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_match.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hestela <hestela@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/13 15:53:54 by hestela           #+#    #+#             */
/*   Updated: 2014/02/13 15:55:24 by hestela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int			ft_match(char *s1, char *s2)
{
	if (*s2 != '*')
	{
		if (*s1 == '\0' && *s2 == '\0')
			return (1);
		else if (*s1 == *s2)
			return (ft_match(s1 + 1, s2 + 1));
		else if (*s1 != *s2)
			return (0);
	}
	else
	{
		if (*(s2 + 1) == '\0')
			return (1);
		else if (*(s2 + 1) == '*')
			return (ft_match(s1, s2 + 1));
		else if (*s1 == *(s2 + 1))
			return (ft_match((s1 + 1), (s2 + 2)) || ft_match((s1 + 1), s2));
		else if (*s1 == '\0')
			return (0);
		else if (*s1 != *(s2 + 1))
			return (ft_match((s1 + 1), s2));
	}
	return (0);
}
