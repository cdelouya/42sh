/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hestela <hestela@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/11 14:52:31 by hestela           #+#    #+#             */
/*   Updated: 2013/12/11 14:53:30 by hestela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char		*ft_strrev(char *str)
{
	int		count;
	int		size;
	char	tmp;

	count = 0;
	size = 0;
	while (str[size])
		size++;
	size--;
	while (count < size)
	{
		tmp = str[size];
		str[size] = str[count];
		str[count] = tmp;
		count++;
		size--;
	}
	return (str);
}
