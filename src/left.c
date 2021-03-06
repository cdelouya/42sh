/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   left.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hestela <hestela@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/15 12:51:18 by hestela           #+#    #+#             */
/*   Updated: 2014/02/16 04:32:32 by hestela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include "libft.h"
#include "42sh.h"

static void			ft_left(char *cmd1, char *cmd2, char **env, char **av1);
static int			ft_check_path(char *file);
static char			*ft_split_path(char *path, int *i);
static int			ft_check_dir(char *path, char *file);

void				ft_exec_left(char **av1, char **av2, char **env)
{
	char			*tmp;
	char			*cmd1;
	char			*cmd2;

	if (!ft_check_path(av2[0]))
		return ;
	tmp = NULL;
	cmd1 = NULL;
	cmd2 = NULL;
	tmp = ft_strjoin("/", av1[0]);
	free(av1[0]);
	av1[0] = ft_strdup(tmp);
	free(tmp);
	cmd1 = ft_check_exist(av1[0]);
	if (access(av2[0], F_OK) == 0)
		cmd2 = av2[0];
	if (cmd1 && cmd2)
		ft_left(cmd1, cmd2, env, av1);
	if (!cmd2)
		ft_printf_fd(2, "%$42sh: file not found: %s%$\n"\
			, ERROR_CLR, av2[0], TEXT_CLR);
}

static int		ft_check_path(char *file)
{
	t_stat		file_stat;
	char		*path;
	int			i;

	i = 0;
	stat(file, &file_stat);
	path = ft_split_path(file, &i);
	while (path)
	{
		if (!ft_check_dir(path, file))
			return (0);
		free(path);
		path = ft_split_path(file, &i);
	}
	return (1);
}

static char		*ft_split_path(char *path, int *i)
{
	int				j;
	char			*str;

	j = 0;
	if (path[*i] == '\0')
		return (NULL);
	(*i)++;
	while (path[*i - 1] != '/' && path[*i])
		(*i)++;
	str = (char*) malloc(sizeof(*str) * (*i) + 1);
	str[*i] = '\0';
	while (j < *i)
	{
		str[j] = path[j];
		j++;
	}
	return (str);
}

static int		ft_check_dir(char *path, char *file)
{
	t_stat		file_stat;

	stat(path, &file_stat);
	if (ft_strlen(path) == ft_strlen(file))
	{
		if (S_ISDIR(file_stat.st_mode) || !(file_stat.st_mode & S_IRUSR))
		{
			ft_printf_fd(2, "%$42sh: permission denied: %s%$\n"\
				, ERROR_CLR, path, TEXT_CLR);
			return (0);
		}
	}
	else if (S_ISDIR(file_stat.st_mode))
	{
		if (!(file_stat.st_mode & S_IXUSR))
		{
			ft_printf_fd(2, "%$42sh: permission denied: %s%$\n" \
				, ERROR_CLR, path, TEXT_CLR);
			return (0);
		}
	}
	return (1);
}

static void			ft_left(char *cmd1, char *cmd2, char **env, char **av1)
{
	int				fd;
	pid_t			thread;

	thread = -1;
	fd = open(cmd2, O_RDONLY);
	if (fd < 0)
		ft_printf("Error");
	thread = fork();
	if (thread == 0)
	{
		dup2(fd, 0);
		execve(cmd1, av1, env);
	}
	else if (thread == -1)
		ft_putstr("error");
	close(fd);
	wait(0);
}
