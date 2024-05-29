/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rolee <rolee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 19:57:09 by rolee             #+#    #+#             */
/*   Updated: 2024/05/28 20:42:46 by rolee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	execute_first_command(t_data *data, char *env[])
{
	int	pid; // TODO : 다른 자료형?

	pid = fork();
	if (pid == 0)
	{
		close(data->pipe[READ_END]);
		dup2(data->infile_fd, STDIN_FILENO);
		dup2(data->pipe[WRITE_END], STDOUT_FILENO);
		if (execve(data->cmd1->path, data->cmd1->argv, env) == -1)
		{
			// TODO : clear data?
			exit(EXIT_FAILURE);
		}
	}
	close(data->pipe[WRITE_END]); // TODO 여기 맞나?
}

void	execute_second_command(t_data *data, char *env[])
{
	int	pid; // TODO

	pid = fork();
	if (pid == 0)
	{
		close(data->pipe[WRITE_END]);
		dup2(data->pipe[READ_END], STDIN_FILENO);
		dup2(data->outfile_fd, STDOUT_FILENO);
		if (execve(data->cmd2->path, data->cmd2->argv, env) == -1)
		{
			// TODO
			exit(EXIT_FAILURE);
		}
	}
	close(data->pipe[READ_END]); // TODO
}

void	wait_processes()
{
	int	count;
	int	wait_pid; // TODO
	int	status;

	count = 0;
	while (count < 2)
	{
		wait_pid = wait(&status);
		if (wait_pid == -1)
		{
			perror("wait"); // TODO
			exit(EXIT_FAILURE); // TODO : return? clear data?
		}
		if (WEXITSTATUS(status) == EXIT_FAILURE)
		{
			// TODO
		}
		count++;
	}
}