/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gnl.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hestela <hestela@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/02 15:21:32 by hestela           #+#    #+#             */
/*   Updated: 2014/02/05 14:14:23 by hestela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>
#include <stdlib.h>
#include "libft.h"

static char		**ft_get_rest(int fd, char **tmp);
static int		ft_read(char **tmp, int fd);
static void		ft_keep_rest(char **rest, char *tmp);
static void		ft_cpyline(char **line, char *tmp);

int				ft_gnl(int const fd, char **line)
{
	char		*tmp;
	int			ret;
	char		**rest;

	if (BUFF_SIZE < 1)
		return (-1);
	if (fd < 0)
		return (-1);
	tmp = ft_strdup("\0");
	if (*line)
	{
		free(*line);
		*line = NULL;
	}
	rest = ft_get_rest(fd, &tmp);
	ret = ft_read(&tmp, fd);
	ft_keep_rest(rest, tmp);
	if (ret < 1)
		return (ret);
	ft_cpyline(line, tmp);
	return (1);
}

static char		**ft_get_rest(int fd, char **tmp)
{
	static t_gnl		my_struct;

	if (fd == my_struct.fd_prev)
	{
		if (my_struct.rest[fd])
		{
			free(*tmp);
			*tmp = ft_strdup(my_struct.rest[fd]);
			free(my_struct.rest[fd]);
			my_struct.rest[fd] = NULL;
		}
	}
	else
	{
		my_struct.fd_prev = fd;
		if (my_struct.rest[fd])
		{
			free(*tmp);
			*tmp = ft_strdup(my_struct.rest[fd]);
			free(my_struct.rest[fd]);
			my_struct.rest[fd] = NULL;
		}
	}
	return (&my_struct.rest[fd]);
}

static int		ft_read(char **tmp, int fd)
{
	char		*buf;
	int			ret;
	char		*join;

	buf = ft_memalloc(BUFF_SIZE + 1);
	join = NULL;
	ret = 1;
	while (!ft_strchr(buf, '\n') && ret > 0 && !ft_strchr(*tmp, '\n'))
	{
		ret = read(fd, buf, BUFF_SIZE);
		buf[ret] = '\0';
		join = ft_strjoin(*tmp, buf);
		*tmp = ft_strdup(join);
		free(join);
	}
	free(buf);
	if (**tmp)
		return (1);
	else
		return (ret);
}

static void		ft_keep_rest(char **rest, char *tmp)
{
	char		*new;

	if (ft_strchr(tmp, '\n'))
	{
		new = ft_strdup(ft_strchr(tmp, '\n'));
		new++;
		*rest = ft_strdup(new);
		new--;
		free(new);
	}
	else
		*rest = NULL;
}

static void		ft_cpyline(char **line, char *tmp)
{
	int			len;
	int			i;

	len = 0;
	i = 0;
	while (tmp[i] != '\n' && tmp[i] != '\0')
	{
		len++;
		i++;
	}
	*line = ft_memalloc(len + 1);
	ft_strncpy(*line, tmp, len);
	free(tmp);
}
