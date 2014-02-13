/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hestela <hestela@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/11 10:33:11 by hestela           #+#    #+#             */
/*   Updated: 2013/12/11 10:36:41 by hestela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static double		ft_convert_rest(const char *str);

double				ft_atof(const char *str)
{
	double		result;
	double		rest;
	int			sign;

	if (!str || !*str)
		return (0);
	result = 0;
	rest = 0;
	sign = 1;
	if (*str && *str == '-')
	{
		str++;
		sign = -1;
	}
	while (*str && *str >= '0' && *str <= '9')
	{
		result = result * 10 + (*str - '0');
		str++;
	}
	if (*str == '.' && *(str + 1) >= '0' && *(str + 1) <= '9'
		&& *str && *(str + 1))
		rest = ft_convert_rest(str);
	return (sign * (result + rest));
}

static double		ft_convert_rest(const char *str)
{
	double		rest;
	int			i;
	int			after;

	rest = 0;
	i = 0;
	after = 0;
	str++;
	while (*str && *str >= '0' && *str <= '9')
	{
		rest = rest * 10 + (*str - '0');
		str++;
		after++;
	}
	while (i++ < after)
		rest /= 10;
	return (rest);
}
