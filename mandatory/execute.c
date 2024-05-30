/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rolee <rolee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 19:57:09 by rolee             #+#    #+#             */
/*   Updated: 2024/05/30 11:59:57 by rolee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	execute_first_command(t_data *data, char *env[])
{
	int	pid;

	pid = fork();
	if (pid == 0)
	{
		close(data->pipe[READ_END]);
		dup2(data->infile_fd, STDIN_FILENO);
		dup2(data->pipe[WRITE_END], STDOUT_FILENO);
		if (execve(data->cmd1->path, data->cmd1->argv, env) == -1)
			exit(EXIT_FAILURE);
	}
	close(data->pipe[WRITE_END]);
}

void	execute_second_command(t_data *data, char *env[])
{
	int	pid;

	pid = fork();
	if (pid == 0)
	{
		dup2(data->pipe[READ_END], STDIN_FILENO);
		dup2(data->outfile_fd, STDOUT_FILENO);
		if (execve(data->cmd2->path, data->cmd2->argv, env) == -1)
			exit(EXIT_FAILURE);
	}
	close(data->pipe[READ_END]);
}

int	wait_processes(void)
{
	int	count;
	int	wait_pid;
	int	status;

	count = 0;
	while (count < 2)
	{
		wait_pid = wait(&status);
		if (wait_pid == -1)
		{
			perror("wait");
			return (EXIT_FAILURE);
		}
		count++;
	}
	return (EXIT_SUCCESS);
}
