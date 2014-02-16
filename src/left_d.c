/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   left_d.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hestela <hestela@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/15 12:55:18 by hestela           #+#    #+#             */
/*   Updated: 2014/02/16 04:33:08 by hestela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include "libft.h"
#include "42sh.h"

static void			ft_left_d(char *cmd1, char *cmd2, char **env, char **av1);

void				ft_exec_left_d(char **av1, char **av2, char **env)
{
	char		*tmp;
	char		*cmd1;
	char		*cmd2;

	tmp = NULL;
	tmp = ft_strjoin("/", av1[0]);
	free(av1[0]);
	av1[0] = ft_strdup(tmp);
	free(tmp);
	cmd1 = ft_check_exist(av1[0]);
	cmd2 = av2[0];
	if (cmd1)
		ft_left_d(cmd1, cmd2, env, av1);
}

static void			ft_write_buf(char *cmd2)
{
	int			fd;
	char		*str;
	char		*ptr;

	str = ft_strdup('\0');
	ptr = NULL;
	fd = open("/tmp/buffer", O_RDWR | O_CREAT | O_TRUNC, 0777);
	while (!ft_strstr(str, cmd2))
	{
		if (*str)
			ft_putendl_fd(str, fd);
		g_prompt_len = ft_printf("%$heredoc_$> %$", PROMPT_CLR, TEXT_CLR);
		ft_get_heredoc(&str);
	}
	ptr = ft_strstr(str, cmd2);
	while (str != ptr)
	{
		write(fd, str, 1);
		str++;
	}
	close(fd);
}

static void			ft_left_d(char *cmd1, char *cmd2, char **env, char **av1)
{
	pid_t		thread;
	int			fd;

	ft_write_buf(cmd2);
	fd = -1;
	fd = open("/tmp/buffer", O_RDONLY);
	thread = -1;
	thread = fork();
	if (thread == 0)
	{
		dup2(fd, 0);
		execve(cmd1, av1, env);
		ft_putchar('\n');
	}
	else if (thread == -1)
		ft_putstr("error");
	close(fd);
	wait(0);
}
