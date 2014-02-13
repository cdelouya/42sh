/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hestela <hestela@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/11 21:18:30 by hestela           #+#    #+#             */
/*   Updated: 2013/12/12 19:26:45 by hestela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

double		ft_sqrt(double x)
{
	double		result;
	double		diff;

	if (x == 0.0 || x == 1.0)
		return (x);
	result = x;
	diff = result;
	result = 0.5 * (result + x / result);
	while (result != diff)
	{
		diff = result;
		result = 0.5 * (result + x / result);
	}
	return (result);
}
