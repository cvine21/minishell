/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvine <cvine@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 17:58:46 by cvine             #+#    #+#             */
/*   Updated: 2022/05/11 12:06:40 by cvine            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

pid_t	create_child(int *fd)
{
	pid_t	pid;

	if (pipe(fd) == -1)
	{
		printf("herdoc pipe error");
		exit(EXIT_FAILURE);
	}
	pid = fork();
	if (pid == -1)
	{
		perror("Fork error");
		exit(EXIT_FAILURE);
	}
	return (pid);
}

void	parent(int *fd, int pid, int *fdin)
{
	int status;

	(void)fdin;
	waitpid(pid, &status, 0);
	if (WIFEXITED(status))
		g_exit_status = WEXITSTATUS(status);
	close(fd[1]);
	if (dup2(fd[0], STDIN_FILENO) == -1)
	{
		perror("dup error");
		exit (EXIT_FAILURE);
	}
	close(fd[0]);
}

void	heredoc(char *limiter, int *fdin)
{
	int		fd[2];
	char	*str;
	pid_t	pid;

	pid = create_child(fd);
	if (!pid)
	{
		close(fd[0]);
		while(1)
		{
			str = readline("> ");
			if (!strcmp(limiter, str))
				exit (1);
			ft_putendl_fd(str, fd[1]);
		}
		close(fd[1]);
	}
	else
		parent(fd, pid, fdin);
}